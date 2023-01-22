# dwm - dynamic window manager

dwm is an extremely fast, small, and dynamic window manager for X. This build aims to remain close to `base dwm` and be functional at the same time, so only limited patches have been applied. I try to keep it updated with latest commits from [suckless](https://git.suckless.org/st/).

# Look

![Screenshot_2023-01-20-07-25-49_1920x1080](https://user-images.githubusercontent.com/62596687/213846223-01d98ac4-8a52-42a4-a1ef-afaf0612b346.png)

![Screenshot_2023-01-20-11-47-44_1920x1080](https://user-images.githubusercontent.com/62596687/213862029-809b0d77-6489-4edf-85ee-26449d865cc3.png)

# Requirements

In order to build dwm you need the Xlib header files. In addition to this use may need to install some additional dependencies.

- [Nerd Font](https://github.com/ryanoasis/nerd-fonts) - I personally like JetBrains font. You can use whatever you like. Don't use mono fonts they tend to make icon smaller.
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

Edit `config.mk` to match your local setup (dwm is installed into
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

If you want dwm to use pywal colors. Add this your `Xresources` file. Change username in file path.

`#include "/home/stoney/.cache/wal/colors.Xresources"`

## Misc notes

### Bar

The bar is slstatus. All the script used in slstatus can be found in `scripts` directory. My slstatus [build](https://github.com/zootedb0t/suckless-tools).

### patches

All patches that have applied can be found in `patches` directory.

<details><summary>All applied patches</summary>
<p>
<li>
<a href="https://github.com/bakkeby/patches/blob/master/dwm/dwm-alpha-systray-6.3.diff"> dwm-alpha-systray
</a> - Add tranparency and systray to bar.
</li>

<li>
<a href="https://dwm.suckless.org/patches/center/">dwm-center 
</a> - Center client to current window.
</li>

<li>
<a href="https://github.com/bakkeby/patches/blob/master/dwm/dwm-cfacts-vanitygaps-6.3.diff">dwm-cfacts-vanitygaps</a>  - This patch differentiates between inner and outer gaps as well as
horizontal and vertical gaps.
</li>

<li>
<a href="https://dwm.suckless.org/patches/cyclelayouts/">dwm-cyclelayouts</a> - Cycles through all avaiable layouts.
</li>

<li>
<a href="https://github.com/bakkeby/patches/blob/master/dwm/dwm-fullscreen-compilation-6.3.diff dwm-fullscreen-compilation-6.3.diff">dwm-fullscreen-compilation</a> - Fullscreen and acutal fullscreen patch.
</li>

<li>
<a href="https://dwm.suckless.org/patches/inplacerotate/">dwm-inplacerotate</a> - This patch provides keybindings to perform 'in place' rotations.
</li>

<li>
<a href="https://dwm.suckless.org/patches/moveresize/">dwm-moveresize</a> - This changes allows you to move and resize dwm's clients using keyboard bindings.
</li>

<li>
<a href="https://dwm.suckless.org/patches/pertag/">dwm-pertag</a> - This patch keeps layout, mwfact, barpos and nmaster per tag.
</li>

<li>
<a href="https://dwm.suckless.org/patches/reorganizetags/">dwm-reorganizetags</a> - Shifts all clients per tag to leftmost unoccupied tags.
</li>

<li>
<a href="https://dwm.suckless.org/patches/status2d/">dwm-status2d</a> - Status2d allows colors and rectangle drawing in your DWM status bar.
</li>

<li>
<a href="https://dwm.suckless.org/patches/statuspadding/>dwm-statuspadding">dwm-statuspadding</a> - This makes the amount of horizontal and vertical padding in the status bar into configurable options.
</li>

<li>
<a href="https://dwm.suckless.org/patches/swallow/">dwm-swallow</a> - Clients marked with isterminal in config.h swallow a window opened by any child process.
</li>

<li>
<a href="https://dwm.suckless.org/patches/xrdb/">dwm-xrdb</a> - Allows dwm to read colors from xrdb (.Xresources) at run time.
</li>

</p>
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
