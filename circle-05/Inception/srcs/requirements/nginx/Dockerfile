FROM	debian:buster

RUN	apt update && apt install -y nginx openssl

COPY	./tools/kyumlee.42.fr.key /etc/ssl/private/
COPY	./tools/kyumlee.42.fr.crt /etc/ssl/certs/
COPY	./conf/nginx.conf /etc/nginx/conf.d/

EXPOSE	443

CMD	[ "nginx", "-g", "daemon off;" ]
