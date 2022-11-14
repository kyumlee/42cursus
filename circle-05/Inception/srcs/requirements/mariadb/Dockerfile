FROM	debian:buster

RUN	apt update && apt install -y mariadb-client mariadb-server

COPY	./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY	./tools/create_db.sh /tmp

ENTRYPOINT	[ "sh", "/tmp/create_db.sh" ]

EXPOSE	3306

CMD	[ "mysqld_safe" ]
