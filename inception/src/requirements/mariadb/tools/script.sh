#!/bin/bash

sleep 2

mariadbd-safe &

sleep 10
mariadb -u root -p"${DB_ROOT_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS \`${DB_SQL}\`;"

mariadb -u root -p"${DB_ROOT_PASSWORD}" -e "CREATE USER IF NOT EXISTS \`${USER_DB}\`@'localhost' IDENTIFIED BY '${PASSWORD_DB}';"

mariadb -u root -p"${DB_ROOT_PASSWORD}" -e "GRANT ALL PRIVILEGES ON \`${DB_SQL}\`.* TO \`${USER_DB}\`@'%' IDENTIFIED BY '${PASSWORD_DB}';"

mariadb -u root -p${DB_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"

mariadb-admin -u root -p"${DB_ROOT_PASSWORD}" shutdown

exec mariadbd-safe
echo "mariadb is running"
