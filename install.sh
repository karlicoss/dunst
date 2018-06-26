#!/bin/bash -eux
sudo apt build-dep dunst
sudo apt install libxrandr-dev # was still missing

make
export PREFIX=/usr
# export SERVICE_PREFIX=/usr/

sudo make install
sudo make activate-mate

# TODO is this necessary?
# replace notification daemon
# sudo pluma /usr/share/dbus-1/services/org.freedesktop.mate.Notifications.service
# [D-BUS Service]
# Name=org.freedesktop.Notifications
# Exec=/L/soft/bin/dunst



