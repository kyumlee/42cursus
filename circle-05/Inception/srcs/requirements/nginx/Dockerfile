FROM	debian:buster

RUN		apt-get -y update && \
		apt-get install -y \
			nginx \
			openssl && \
			mkdir /etc/nginx/ssl && \
			openssl req -x509 -sha256 -nodes -days 365 -subj "/C=KR/L=Seoul/O=Seoul/OU=42" -newkey rsa:4096 -keyout /etc/nginx/ssl/private.key -out /etc/nginx/ssl/certificate.crt && \
			rm /etc/nginx/sites-available/default /etc/nginx/sites-enabled/default

COPY	./conf/nginx.conf /etc/nginx/sites-available/nginx.conf

EXPOSE	443
