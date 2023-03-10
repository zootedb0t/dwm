# dwm - dynamic window manager

dwm is an extremely fast, small, and dynamic window manager for X. This build aims to remain close to `base dwm` and be functional at the same time, so only limited patches have been applied. I try to keep it updated with latest commits from [suckless](https://git.suckless.org/st/).

# Look

![Screenshot_2023-03-08-02-00-15_1920x1080](https://user-images.githubusercontent.com/62596687/223662506-c51c8a76-7064-48a4-8e12-1d00ddd89b3d.png)

![Screenshot_2023-02-22-10-45-34_1920x1080](https://user-images.githubusercontent.com/62596687/220877843-f0fdd2b4-c384-4aab-b37b-cc114e78f3e2.png)

![Screenshot_2023-01-24-01-02-01_1920x1080](https://user-images.githubusercontent.com/62596687/214235380-078d83a6-66e9-4ecd-92de-8fde8776db11.png)

![Screenshot_2023-01-20-11-47-44_1920x1080](https://user-images.githubusercontent.com/62596687/213862029-809b0d77-6489-4edf-85ee-26449d865cc3.png)

![Screenshot_2023-02-21-07-05-29_1920x1080](https://user-images.githubusercontent.com/62596687/220269662-bf4271c2-0168-48be-838e-ff3821b0a334.png)

# Requirements

In order to build dwm you need the `Xlib` header files. In addition to this use may need to install some additional dependencies like `XCB` header files for `swallow` patch.

- [Nerd Font](https://github.com/ryanoasis/nerd-fonts) - I personally like JetBrains font. You can use whatever you like. Don't use monospace fonts they tend to make icon smaller.
- [picom](https://github.com/yshui/picom) - Compositor for X11 window.
- [xwallpaper](https://github.com/stoeckmann/xwallpaper) - For setting wallpaper.
- [dmenu](https://tools.suckless.org/dmenu/) - A suckless program that can be used as application launcher and has been used in various scripts. Check my [build](https://github.com/zootedb0t/suckless-tools/tree/main/dmenu).
- [st](https://st.suckless.org/) - Default terminal. Change `termcmd` value in `config.def.h` to change default terminal.
- [slstatus](https://tools.suckless.org/slstatus/) - For statusbar in dwm. Check my [build](https://github.com/zootedb0t/suckless-tools/tree/main/slstatus).
- [pywal](https://github.com/dylanaraps/pywal) - A tool that generates a color palette from the dominant colors in an image. Allows dwm to change colors according to wallpaper.
- [sxhkd](https://github.com/baskerville/sxhkd) - For external [keybindings](https://github.com/zootedb0t/dotfiles/blob/main/sxhkd/.config/sxhkd/sxhkdrc).
- [xmenu](https://github.com/phillbush/xmenu) - Menu utility for X.
- [xclickroot](https://github.com/phillbush/xclickroot) - xclickroot runs a command every time a given mouse button is pressed on the root window.

# Features

- Various layout have been added like `spiral`, `dwindle`, `deck`, `bstack`, `horizgrid`, `gaplessgrid`, `centerdmaster`, `centeredfloatingmaster`, etc.
  Right click on layout icon and you get a list of all layouts to choose from. Change layout order by editing `layoutmenu.sh`. Make sure this script is in your path.
- Read `.Xresources` colors, so dwm changes colors according to wallpaper without compiling or restarting the dwm.
- Window swallowing. If a program starts from terminal, the program will temporarily take its place to save space. This behavior is controlled through `isterminal`
  and `noswallow` values in `config.def.h`
- Gaps are allowed across all layouts.
- Support `actual fullscreen` for any window using single keybindings and `fake fullscreen` the ability to have windows go fullscreen within the size and position the window is currently in.
- Both `mfact` and `cfact` can be changed. This provides the ability to assign different weights to clients in their respective stack.
- Statusbar can be made transparent while keeping text opaque. Just change `baralpha` to your liking in `config.def.h`.
- DWM bar support system-tray. So `wifi`, `bluetooth`, `vpn` can be managed from statusbar.
- Support scratchpad.
- Floating clients always open in center.
- Floating window can be `resized`, `moved` from keyboard.
- Supports right click on root window to get a menu. Menu entries are defined in a shell [script](https://github.com/zootedb0t/dotfiles/blob/main/scripts/.local/bin/menu.sh).

# Keybindings

- <kbd>super+shift+enter</kbd> - Open terminal window. Default is `st` terminal.
- <kbd>super+p</kbd> - Open dmenu launcher.
- Gap can be turned `on` or `off` through <kbd>super+ctrl+0</kbd>.
- Toggle `actual fullscreen` with <kbd>super+f</kbd> and `fake fullscreen` with <kbd>super+shift+f</kbd>.
- Cycle through non-vacant tags using <kbd>super+g/;</kbd>
- Change layout with <kbd>super+/</kbd> goto next layout <kbd>super+shift+/</kbd> goto previous layout.
- To change `mfact` <kbd>super+l</kbd>(increase) for `cfact` use <kbd>super+\\</kbd>(increase),<kbd>super+shift+\\</kbd>(decrease)
- <kbd>super+~</kbd> - Toggle scratchpad window with.
- <kbd>super+up,down,left,right</kbd> to move floating window <kbd>super+shift+up,down,left,right</kbd> to resize window.

# Running dwm

## Installation

```
git clone https://github.com/zootedb0t/dwm
cd dwm
make
sudo make clean install
```

In scripts `directory` there is `autostart` script this is used to autostart app and dwm itself. Symlink this `autostart` script to `~/.config/dwm/autostart`. Like this: `ln -s ~/dwm/scripts/autostart ~/.config/dwm/autostart`.

Edit `config.mk` to match your local setup (dwm is installed into
the /usr/local namespace by default).

## With startx

Add the following line to your `.xinitrc` to start dwm using startx:

`exec ~/.config/dwm/autostart`

## With display manager

Copy `dwm.desktop` into `/usr/share/xsessions/dwm.desktop`
Make sure to give `Exec` your autostart script path.

## Configuration

The configuration of dwm is done by editing `config.def.h`. After editing remove `config.h` and recompile the program.
If you want dwm to change colors according to your wallpaper. Then include `pywal` colors in `Xresources` [file](https://github.com/zootedb0t/dotfiles/blob/main/xresources/.Xresources).

## Misc notes

### Bar

The bar is slstatus. All the script used in slstatus can be found in `scripts` directory. My slstatus [build](https://github.com/zootedb0t/suckless-tools/tree/main/slstatus).

### Menu
Menu is generated using `xmenu`. Entries are written in [shell script](https://github.com/zootedb0t/dotfiles/blob/main/scripts/.local/bin/menu.sh).

### patches

All applied patches can be found in `patches` directory.

<details><summary>Click to view</summary>

- [dwm-alpha-systray](https://github.com/bakkeby/patches/blob/master/dwm/dwm-alpha-systray-6.3.diff) - Add tranparency to systray and dwm bar.

- [dwm-center](https://dwm.suckless.org/patches/center/) - Center floating client window.

- [dwm-cfacts-vanitygaps](https://github.com/bakkeby/patches/blob/master/dwm/dwm-cfacts-vanitygaps-6.3.diff) - This patch differentiates between inner and outer gaps as well as horizontal and vertical gaps.

- [dwm-cyclelayouts](https://dwm.suckless.org/patches/cyclelayouts/) - Cycles through all avaiable layouts.

- [dwm-fullscreen-compilation](https://github.com/bakkeby/patches/blob/master/dwm/dwm-fullscreen-compilation-6.3.diff) - Fake fullscreen and acutal fullscreen patch.

- [dwm-inplacerotate](https://dwm.suckless.org/patches/inplacerotate/) - This patch provides keybindings to perform 'in place' rotations.

- [dwm-moveresize](https://dwm.suckless.org/patches/moveresize/) - This allows you to move and resize dwm's floating clients using keyboard bindings.

- [dwm-pertag](https://dwm.suckless.org/patches/pertag/) - This patch keeps layout, mwfact, barpos and nmaster per tag.

- [dwm-status2d](https://dwm.suckless.org/patches/status2d/) - Status2d allows colors and rectangle drawing in your dwm status bar.

- [dwm-statuspadding](https://dwm.suckless.org/patches/statuspadding/) - This makes the amount of horizontal and vertical padding in the status bar into configurable options.

- [dwm-swallow](https://dwm.suckless.org/patches/swallow/) - Clients marked with isterminal in config.h swallow a window opened by any child process.

- [dwm-xrdb](https://dwm.suckless.org/patches/xrdb/) - Allows dwm to read colors from xrdb `.Xresources` at run time.

- [dwm-scratchpad](https://dwm.suckless.org/patches/scratchpad/) - Allows you to spawn or restore a floating terminal window.

- [dwm-layoutmenu](https://dwm.suckless.org/patches/layoutmenu/) - This patch adds a context menu for layout switching. Right click on layout icon to bring a menu prompt, and switches to selected one.

</details>

### picom

To prevent picom from drawing shadow on your statusbar add therse to your `picom.conf`

```
shadow-exclude = [
    "class_g *= 'dwm'",
    "name *= 'dwm'"
]
```

If you have `blur-background = true` then add these to prevent picom from blurring dwm bar `"class_g = 'dwm'"`
