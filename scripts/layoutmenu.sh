#!/bin/sh

# Use tabs to separate not space. If expandtab is set in vim. Disable it set expandtab!.
cat <<EOF | xmenu
[]= Tiled Layout	0
[M] Monocle Layout	1
[@] Spiral Layout	2
[\\] Dwindle Layout	3
D[] Deck Layout	4
TTT Bstack Layout	5
--- Horizgrid Layout	6
::: Gaplessgrid Layout	7
|M| Centeredmaster Layout	8
>M> Centeredfloatingmaster Layout	9
><> Floating Layout	10
EOF
