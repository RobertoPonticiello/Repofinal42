FROM debian:bullseye

RUN apt update -y && apt upgrade -y \
&& apt install mariadb-server -y

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/script.sh /tmp/mariadb/script.sh

RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld
RUN chmod +x /tmp/mariadb/script.sh

CMD ["/tmp/mariadb/script.sh"]