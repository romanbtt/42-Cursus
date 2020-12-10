#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'
FILE=/root/autoindex.conf

# Check if autoindex.conf exist
if test -f "$FILE";
then
    CURRENT=$(cat /root/autoindex.conf | awk '{print $2}' | sed 's/.$//')
else
    echo "autoindex on;" > /root/autoindex.conf
    CURRENT=$(cat /root/autoindex.conf | awk '{print $2}' | sed 's/.$//')
fi

# Check the parameter
if [[ "$1" == "on" || "$1" == "off" ]];
then
	echo "autoindex $1;" > /root/autoindex.conf
	service nginx restart
    echo -e "${GREEN}Auto index is $1.${NC}"
else
    echo -e "${RED}'$@' is an invalid input. Please select : [ on | off ] --- AUTO_INDEX remains ${CURRENT}.${NC}"
fi