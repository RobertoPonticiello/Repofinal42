#!/bin/bash

sleep 15

cd /var/www/wordpress

wp config create --allow-root \
                    --dbname="$DB_SQL" \
                    --dbuser="$USER_DB" \
                    --dbpass="$PASSWORD_DB" \
                    --dbhost=mariadb:3306

wp core install --url="egiubell.42.fr" --title="$WP_TITLE" --admin_user="$ADMIN_USER" --admin_password="$ADMIN_PASSWORD" --admin_email="$ADMIN_EMAIL" --allow-root

wp user create "$USER_NAME" testemail@gmail.com --role=author --user_pass="$USER_PASSWORD" --allow-root

echo "Wordpress is ready!"

/usr/sbin/php-fpm7.4 -F
