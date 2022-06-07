FROM		debian:buster

MAINTAINER	kyumlee

RUN			apt-get -y update && apt-get -y upgrade && apt-get -y install \
			nginx curl openssl vim php-fpm wget mariadb-server php-mysql php-mbstring

COPY		./srcs/default ./tmp
COPY		./srcs/wp-config.php ./tmp
COPY		./srcs/config.inc.php ./tmp
COPY		./srcs/run.sh .

EXPOSE		80 443

CMD			bash run.sh
