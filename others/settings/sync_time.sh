#!/bin/bash

sudo timedatectl set-timezone Asia/Seoul

sudo apt install systemd-timesyncd

sudo systemctl start systemd-timesyncd

timedatectl
