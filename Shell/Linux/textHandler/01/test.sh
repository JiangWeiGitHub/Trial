#!/bin/bash
city_name="`cat ./test.csv | awk -F, '{ print $1; }'`"
echo -e "City name is : ${city_name}"
