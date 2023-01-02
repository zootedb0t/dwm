#!/usr/bin/env bash

# ^c$var^ = fg color
# ^b$var^ = bg color

interval=0

# load colors
black=#21222c
green=#50fa7b
white=#f8f8f2
grey=#282a36
blue=#d6acff
red=#ff5555
darkblue=#bd93f9

cpu() {
  cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)

  printf "^c$white^%s" " "
  printf "^c$white^%s" "$cpu_val"
}

cputemp() {
  PREFIX=' '
  WARNING_LEVEL=80

  CPU_T=$(cat /sys/class/thermal/thermal_zone0/subsystem/thermal_zone9/temp)
  CPU_TEMP=$((CPU_T / 1000))

  if [ "$CPU_TEMP" -ge $WARNING_LEVEL ]; then
    printf "^c$red^$PREFIX%s" "$CPU_TEMP°C"
  else
    printf "^c$white^$PREFIX%s" "$CPU_TEMP°C"
  fi
}

net() {
R1=$(cat /sys/class/net/wlan0/statistics/rx_bytes)
T1=$(cat /sys/class/net/wlan0/statistics/tx_bytes)
sleep 1
R2=$(cat /sys/class/net/wlan0/statistics/rx_bytes)
T2=$(cat /sys/class/net/wlan0/statistics/tx_bytes)
TBPS=$((T2 - T1))
RBPS=$((R2 - R1))
TKBPS=$((TBPS / 1024))
RKBPS=$((RBPS / 1024))
icon=""
icon1=""
printf "^c$white^ %s %s %s %s\\n" "$icon" "$RKBPS kb" "$icon1" "$TKBPS kb"
}

pkg_updates() {
  updates=$(checkupdates | wc -l)   # arch

  if [ "$updates" = '0' ]; then
    printf ""
  else
    printf "^c$white^ %s" "$updates updates"
  fi
}

battery () {
 CHARGING_ICON=''
 DISCHARGE_ICON=''
 capacity="$(cat /sys/class/power_supply/BAT0/capacity)"
 char_status="$(cat /sys/class/power_supply/BAT0/status)"
 if [ "$char_status" == "Charging" ] || [ "$char_status" == "Full" ]; then
   printf "^c$green^$CHARGING_ICON $capacity"  
 fi
 if [ "$char_status" == "Discharging" ] && [ "$capacity" -ge 20 ]; then
   printf "$DISCHARGE_ICON %s"  "$capacity"
 elif [ "$char_status" == "Discharging" ] && [ "$capacity" -lt 20 ]; then
  printf "^c$red^$DISCHARGE_ICON $capacity" 
 fi
}

# brightness() {
#   level="$(cat /sys/class/backlight/nvidia_0/actual_brightness)"
#   printf "^c$red^%s" " "
#   printf "^c$red^%s" "$level"
# }

volume() {
  muted=$(amixer -D pulse get Master | grep '%' | grep -oE '[^ ]+$' | grep off | head -n 1)
  vol=$(amixer -D pulse get Master | grep '%' | head -n 1 | awk -F'[' '{print $2}' | awk -F'%' '{print $1}')

  if [ "$muted" == "[off]" ]; then
    echo "^c$red^ muted"
  else
    if [ "$vol" -ge 65 ]; then
      # echo " $vol%"
      printf "^c$white^%s" " "
      printf "^c$white^%s" "$vol"
    elif [ "$vol" -ge 40 ]; then
      printf "^c$white^%s" "墳"
      printf "^c$white^%s" "$vol"
    elif [ "$vol" -ge 0 ]; then
      printf "^c$white^%s" " "
      printf "^c$white^%s"	"$vol"
    fi
  fi
}

mem() {
  printf "^c$white^%s" " "
  printf "^c$white^%s" "$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)"
}

clock() {
  printf "^c$white^%s" "󱑆 "
  printf "^c$white^%s " "$(date '+%H:%M %a %d %b')"
}

music(){
  status=$(playerctl status)
  if [ "$status" == "Playing" ]; then
    title="$(playerctl metadata xesam:title)"
    length=${#title}
    if [ "$length" -gt 12 ]; then
      # title+=...
      new_title="$(echo "$title" | cut -c 1-10)"
      printf "^c$white^  %s..." "$new_title"
      else
      printf "^c$white^  %s" "$title"
    fi
    else 
      printf ""
    fi
}

while true; do

  [ $interval = 0 ] || [ $((interval % 3600)) = 0 ] && updates=$(pkg_updates)
  interval=$((interval + 1))

  sleep 1 && xsetroot -name "$(music) $(net) $updates $(cputemp) $(battery) $(volume) $(cpu) $(mem) $(clock)"

done
