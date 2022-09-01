FROM	debian:buster

RUN		apt-get update && apt-get install -y nginx openssl

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gon/CN=kyumlee" -keyout /etc/ssl/private/localhost.dev.key -out /etc/ssl/certs/localhost.dev.crt

RUN		chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

COPY	./conf/nginx.conf /etc/nginx/conf.d

EXPOSE	443

CMD		["nginx", "-g", "daemon off;"]
