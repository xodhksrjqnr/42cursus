FROM debian:buster

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && apt-get install -y \
	nginx \
	openssl \
	mariadb-server \
	php7.3-fpm php7.3-mysql \
	wget

RUN mkdir -p etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout etc/nginx/ssl/private.key\
	-out etc/nginx/ssl/private.crt -subj '/C=KR'

COPY srcs tmp

RUN mv tmp/default etc/nginx/sites-available/

RUN service mysql start && mysql -u root < tmp/mysqlset.sql

RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-all-languages.tar.gz && \
	tar -xvf phpMyAdmin-latest-all-languages.tar.gz && \
	rm -r phpMyAdmin-latest-all-languages.tar.gz && \
	mv phpMyAdmin-* var/www/html/phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz && \
	tar -xvf latest.tar.gz -C var/www/html/ && \
	rm -r latest.tar.gz && \
	mv tmp/wp-config.php var/www/html/wordpress && \
	chown www-data.www-data var/www/html/wordpress/* -R

ENV AUTOINDEX_USE 0

RUN sed -i -e 's/\r$//' tmp/entrypoint.sh

ENTRYPOINT ["sh", "tmp/entrypoint.sh"]

RUN mv tmp/index.php var/www/html/

EXPOSE 80 443
