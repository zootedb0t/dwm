#!/bin/sh

updates=$(checkupdates 2>/dev/null | wc -l)
echo "$updates"
