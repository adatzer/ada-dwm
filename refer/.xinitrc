compton --config ~/.config/compton.conf &
feh --no-fehbg --bg-fill /home/ada/data/wallpapers/purple_landscape.jpg &
dwmstatus 2>&1 >/dev/null &
xephyr-helper &
exec dwm
