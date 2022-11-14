FROM	debian:buster

RUN	apt update && apt install -y curl php php-fpm php-mysqli && \
mkdir /run/php && sed -i "s/\/run\/php\/php7.3-fpm.sock/0.0.0.0:9000/" /etc/php/7.3/fpm/pool.d/www.conf && sed -i "s/;clear/clear/" /etc/php/7.3/fpm/pool.d/www.conf && \
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

COPY	./conf/wp-config.php /tmp
COPY	./tools/install_wp.sh /tmp

ENTRYPOINT	[ "sh", "/tmp/install_wp.sh" ]

EXPOSE	9000

CMD	[ "/usr/sbin/php-fpm7.3", "-F" ]
