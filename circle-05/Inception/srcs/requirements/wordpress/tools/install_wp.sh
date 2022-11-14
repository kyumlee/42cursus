#!/bin/sh

cd /var/www/
cp /tmp/wp-config.php /var/www/
wp core download --allow-root
wp core install --url=$DOMAIN_NAME --title=inception --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --allow-root
wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PASSWORD --allow-root
wp theme update twentytwentyone --allow-root

exec "$@"
