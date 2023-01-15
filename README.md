# DWM - Dynamic Window Manager

dwm is an extremely fast, small, and dynamic window manager for X.

## Patches

- [xresources](https://dwm.suckless.org/patches/xresources/): This patch allows to handle settings from Xresources (works with `pywal`)
- [scratchpad](https://dwm.suckless.org/patches/scratchpads/): enables multiple scratchpads, each with one asigned window. Accessible with MODKEY+shift+enter.
- Layouts - All bound to keys MODKEY+(shift+)t/y/u/i.
	- [bottomstack](https://dwm.suckless.org/patches/bottomstack/): `bstack` and `bstackhoriz` are two stack layouts for dwm
	- [fibonacci](https://dwm.suckless.org/patches/fibonacci/): This patch adds two new layouts (spiral and dwindle) that arranges all windows in Fibonacci tiles
	- [centeredmaster](https://dwm.suckless.org/patches/centeredmaster/): centeredmaster and centeredfloatingmaster are two stack layouts for dwm
	- [deck](https://dwm.suckless.org/patches/deck/): a dwm-layout which is inspired by the TTWM window manager
- [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/): Actually toggle fullscreen for a window, instead of toggling the status bar and the monocle layout.
- [sticky](https://dwm.suckless.org/patches/sticky/): Press MODKEY+s (default) to make a client 'sticky'. A sticky client is visible on all tags.
- [hidevacanttags](https://dwm.suckless.org/patches/hide_vacant_tags/): This patch prevents dwm from drawing tags with no clients (i.e. vacant) on the bar.
- [stacker](https://dwm.suckless.org/patches/stacker/): This patch provides comprehensive utilities for managing the client stack.
	- Move windows up the stack manually (MODKEY-K/J).
- [shift-tools](https://dwm.suckless.org/patches/shift-tools/): A group of functions that shift
	- `shiftview`: Cycle through tags (MODKEY+g/;).
- [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): adds (inner) gaps between client windows and (outer) gaps between windows and the screen edge in a flexible manner.
- [swallow](https://dwm.suckless.org/patches/swallow/): This patch adds "window swallowing" to dwm as known from Plan 9's windowing system rio
