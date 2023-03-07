#!/bin/sh

muted="$(wpctl get-volume @DEFAULT_AUDIO_SINK@ | awk -F' ' '{print $3}' | awk -F'[][]' '{print $2}')"
vol=$(amixer sget Master | grep 'Right:' | awk -F'[' '{print $2}' | awk -F'%' '{print $1}')

if [ "$muted" = "MUTED" ]; then
	echo " muted"
else
	echo " $vol"
fi
