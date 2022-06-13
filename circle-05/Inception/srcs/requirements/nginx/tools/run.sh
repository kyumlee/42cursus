#!/bin/sh

ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/ ;

nginx -g "daemon off";
