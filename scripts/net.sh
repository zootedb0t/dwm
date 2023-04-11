#!/bin/sh

ssid=$(iwgetid -r)
case "$(cat /sys/class/net/wlan0/operstate 2>/dev/null)" in
  up) printf "󰖩 %s" "$ssid"
  ;;
  down) printf "󰖪 %s" "No Wifi"
  ;;
esac
