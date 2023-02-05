#!/bin/bash

make && clear
BIN=conversion

echo -e "\e[1;32mTest 1: convert char 'a'\e[0m"
./$BIN a
echo

echo -e "\e[1;32mTest 2: convert int 42\e[0m"
./$BIN 42
echo

echo -e "\e[1;32mTest 3: convert float nanf\e[0m"
./$BIN nanf
echo

echo -e "\e[1;32mTest 4: convert float 42.42f\e[0m"
./$BIN 42.42f
echo

echo -e "\e[1;32mTest 5: convert double nan\e[0m"
./$BIN nan
echo

echo -e "\e[1;32mTest 6: convert double 42.42\e[0m"
./$BIN 42.42
echo
