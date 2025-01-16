FROM debian:bullseye

RUN apt update -y && apt upgrade -y && apt install nginx -y
RUN apt install vim -y
RUN apt install curl -y
RUN apt install openssl -y
RUN mkdir -p /etc/nginx/ssl 
RUN openssl req -x509 -nodes \
    -keyout /etc/nginx/ssl/inception.key \
    -out /etc/nginx/ssl/inception.crt \
    -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=egiubell.42.fr"
RUN mkdir -p /var/run/nginx
RUN mkdir -p /var/www/wordpress
COPY conf/nginx.conf /etc/nginx/nginx.conf
RUN chmod 755 /var/www/wordpress
RUN chown -R www-data:www-data /var/www/wordpress

CMD [ "nginx", "-g", "daemon off;" ]