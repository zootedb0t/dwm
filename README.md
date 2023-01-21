# dwm - dynamic window manager
dwm is an extremely fast, small, and dynamic window manager for X. This fork aims to remain close to `base dwm` and be functional at the same time, so only limited patches have been applied. I try to keep it updated with latest commits from [suckless](https://git.suckless.org/st/).

# Requirements
In order to build dwm you need the Xlib header files. In addition to this use may need to install some additional dependencies.
- [Nerd Font](https://github.com/ryanoasis/nerd-fonts) - I personally like JetBrains font. Don't use mono fonts they tend to make icon smaller.
- [picom](https://github.com/yshui/picom) - Compositor for X11 window.
- [xwallpaper](https://github.com/stoeckmann/xwallpaper) - For setting wallpaper for x window.
- [dmenu](https://tools.suckless.org/dmenu/) - A suckless program that can be used as application launcher and has been used in various scripts.
- [slstatus](https://tools.suckless.org/slstatus/) - Used to set statusbar in dwm.

## Installation
``` 
git clone https://github.com/zootedb0t/dwm
cd dwm
sudo make clean install
```

In scripts directory there is autostart script this used to autostart app and dwm itself. Symlink this `autostart` script to `~/.config/dwm/autostart`.

`ln -s ~/dwm/scripts/autostart ~/.config/dwm/autostart`

Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm: `sudo make clean install`

# Running dwm

## With startx
Add the following line to your `.xinitrc` to start dwm using startx:

`exec ~/.config/dwm/autostart`

## With display manager
Copy `dwm.desktop` into `/usr/share/xsessions/dwm.desktop`
Make sure to change username in `dwm.desktop` file.

## Configuration
The configuration of dwm is done by editing config.def.h and (re)compiling the source code. After editing `config.def.h` remove `config.h` and recompile the program.
