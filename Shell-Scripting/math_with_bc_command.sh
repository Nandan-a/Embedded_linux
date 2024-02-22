#!/bin/bash
: '
How to take input from the user
use read command
BHIoT$ echo 2+2
2+2
BHIoT$ echo 2+2 | bc
4
BHIoT$ bc
bc 1.07.1
Copyright 1991-1994, 1997, 1998, 2000, 2004, 2006, 2008, 2012-2017 Free Software Foundation, Inc.
This is free software with ABSOLUTELY NO WARRANTY.
For details type `warranty
2+2
4
'
read -p "Enter Value of Number1 : " num1
read -p "Enter Value of Number1 : " num2
echo "-----------------------------------"
echo "$num1+$num2" | bc
echo "$num1-$num2" | bc
echo "$num1*$num2" | bc
echo "$num1/$num2" | bc
echo " for getting the correct division output for example 10/2.3 alsways use scale"
echo "scale = 4; $num1/$num2" | bc
echo "$num1%$num2" | bc