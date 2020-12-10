FROM debian:buster

LABEL maintainer="robitett@student.42sp.org.br"

# ls /etc/php Output php version 
RUN apt-get update && apt-get install -y \
    curl \
    mariadb-server \
    nginx \
    openssl \
    php-curl \
    php-dom \
    php-fpm \
    php-gd \
    php-imagick \
    php-mbstring \
    php-mysql \
    php-zip \
    wget \
    ; rm -rf /var/lib/apt/lists/* \
    ; php -v | awk 'NR==1 {print $2}' | cut -c 1-3 > /root/PHP_VERSION

COPY ./srcs/ /root/

ENV AUTO_INDEX=on

WORKDIR /var/www/localhost

RUN wget https://phpmyadmin.net/downloads/phpMyAdmin-latest-english.tar.gz \
    && mkdir phpmyadmin \
    && tar -xzf phpMyAdmin-latest-english.tar.gz -C ./phpmyadmin/ --strip-components 1 \
    && mv /root/config.inc.php ./phpmyadmin \
    && chown -R www-data:www-data ./phpmyadmin \
    && rm -f phpMyAdmin-latest-english.tar.gz


RUN wget https://wordpress.org/latest.tar.gz \
    && mkdir wordpress \
    && tar -xzf latest.tar.gz -C ./wordpress/ --strip-components 1 \
    && mv /root/wp-config.php ./wordpress \
    && chown -R www-data:www-data ./wordpress \
    && rm -f latest.tar.gz

# This part download a random secret key from wordpress ans put into wp-config.php at the right place
RUN curl -s https://api.wordpress.org/secret-key/1.1/salt/ > wp_key \
    && sed -ie '/\/\* WP_KEYS \*\//r wp_key' ./wordpress/wp-config.php \
    && rm -f wp_key \
    ; echo "alias autoindex='bash /root/autoindex.sh'" >> /root/.bashrc

RUN mkdir /etc/ssl/localhost \
    && openssl req -x509 \ 
    -nodes \
    -days 365 \
    -newkey rsa:2048 \
    -subj "/C=CA/ST=QC/L=Montreal/O=42School/OU=Student/CN=localhost" \
    -keyout /etc/ssl/localhost/priv_localhost.key \
    -out /etc/ssl/localhost/pub_localhost.crt
    
# A symbolic link is created for compability versioning
RUN service mysql start \
    ; service php$(cat /root/PHP_VERSION)-fpm start \
    ; mysql -e "CREATE USER 'marvin'@'localhost' IDENTIFIED BY 'nivram';" \
	; mysql -e "CREATE DATABASE wordpress;" \
    ; mysql -e "CREATE DATABASE phpmyadmin;" \
	; mysql -e "GRANT ALL PRIVILEGES ON *.* TO 'marvin'@'localhost';" \
	; mysql -e "FLUSH PRIVILEGES;" \
    ; mysql < ./phpmyadmin/sql/create_tables.sql \
    ; mysql wordpress < /root/wordpress.sql \
    ; rm /root/wordpress.sql \
    ; mv /root/nginx.conf /etc/nginx/sites-available/default \
    ; ln -s /run/php/php$(cat /root/PHP_VERSION)-fpm.sock /run/php/php-fpm.sock \
    ; bash /root/ascii.sh

CMD bash /root/autoindex.sh ${AUTO_INDEX} \
    ; service mysql start \ 
    ; service php$(cat /root/PHP_VERSION)-fpm start \
    ; sleep inf