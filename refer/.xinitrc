compton --config ~/.config/compton.conf &
feh --no-fehbg --bg-fill /path/to/wallpaper &
dwmstatus 2>&1 >/dev/null &
xephyr-helper &
exec dwm
