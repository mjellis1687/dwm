# DWM - Dynamic Window Manager

dwm is an extremely fast, small, and dynamic window manager for X.

## Repository Setup

- Clone the repository
- Setup upstream remote:
	```bash
	git remote add upstream https://git.suckless.org/dwm
	git remote set-url --push upstream DISABLE
	git checkout -b upstream upstream/master
	```

## Patches

- [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/) via [patch](https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20211013-cb3f58a.diff): Actually toggle fullscreen for a window, instead of toggling the status bar and the monocle layout.
- [bartoggle](https://dwm.suckless.org/patches/bartoggle/) via [patch](https://dwm.suckless.org/patches/bartoggle/dwm-bartoggle-keybinds-6.4.diff): Allows you to toggle every part of the dwm bar with keybinds.
- [colorbar](https://dwm.suckless.org/patches/colorbar/) via [patch](https://dwm.suckless.org/patches/colorbar/dwm-colorbar-6.3.diff): Lets you change the foreground and background color of every statusbar element.
- [hidevacanttags](https://dwm.suckless.org/patches/hide_vacant_tags/) via [patch](https://dwm.suckless.org/patches/hide_vacant_tags/dwm-hide_vacant_tags-6.4.diff): Prevents dwm from drawing tags with no clients (i.e. vacant) on the bar.
- [scratchpads](https://dwm.suckless.org/patches/scratchpads/) via [patch](https://dwm.suckless.org/patches/scratchpads/dwm-scratchpads-20200414-728d397b.diff): Enables multiple scratchpads, each with one asigned window. Accessible with MODKEY+shift+enter.
- [stacker](https://dwm.suckless.org/patches/stacker/) via [patch](https://dwm.suckless.org/patches/stacker/dwm-stacker-6.6.diff): Provides comprehensive utilities for managing the client stack.
- [statuscmd](https://dwm.suckless.org/patches/statuscmd/) via [patch](https://dwm.suckless.org/patches/statuscmd/dwm-statuscmd-20260124-a9aa0d8.diff): Add clickable status bar sections.
- [sticky](https://dwm.suckless.org/patches/sticky/) via [patch](https://dwm.suckless.org/patches/sticky/dwm-sticky-6.5.diff): Press MODKEY+s (default) to make a client 'sticky'. A sticky client is visible on all tags.
- [swallow](https://dwm.suckless.org/patches/swallow/) via [patch](https://dwm.suckless.org/patches/swallow/dwm-swallow-6.3.diff): Adds "window swallowing" to dwm as known from Plan 9's windowing system rio.
- [xresources](https://dwm.suckless.org/patches/xresources/) via [patch](https://dwm.suckless.org/patches/xresources/dwm-xresources-6.2.diff): Allows to handle settings from Xresources (works with `pywal`).

### Additional Layouts

- [rmaster](https://dwm.suckless.org/patches/rmaster/) via [patch](https://dwm.suckless.org/patches/rmaster/dwm-rmaster-6.2.diff): Enables swapping the master- and stack area such that the master-client appears on the right and the stack-clients appear on the left.
