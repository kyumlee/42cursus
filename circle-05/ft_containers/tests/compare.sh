#!/bin/bash

bash my_containers.sh
./a.out $1 > my

bash containers.sh
./a.out $1 > stl

rm a.out

diff my stl > result
