#!/bin/sh

c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o test
./test | cat -e
