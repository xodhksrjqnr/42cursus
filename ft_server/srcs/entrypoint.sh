#!/bin/bash

if [ "$AUTOINDEX_USE" -eq 1 ]; then
    sed -i '22s/off/on/' etc/nginx/sites-available/default && \
    sed -i '16s/^/#/' etc/nginx/sites-available/default
fi
service nginx start
service mysql start
service php7.3-fpm start
bash