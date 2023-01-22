#!/bin/sh

muted=$(amixer -D pulse get Master | grep '%' | grep -oE '[^ ]+$' | grep off | head -n 1)
vol=$(amixer sget Master | grep 'Right:' | awk -F'[' '{print $2}' | awk -F'%' '{print $1}')

if [ "$muted" = "[off]" ]; then
	echo " muted"
else
	echo " $vol"
fi
