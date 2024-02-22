#!/bin/bash
num=2
name="ishwar"
float_value=2.5
echo "The value of num is " $num "and value of name" is $name
echo "the value of float_value is " $float_value
num1=8
num2=4
num3=$(( $num1+$num2 ))
echo "$num1 + $num2 = " $num3
num3=$(( $num1-$num2 ))
echo "$num1 - $num2 = " $num3
res=$(( $num1*$num2 ))
echo "$num1 * $num2 = " $res
num3=$(( $num1/$num2 ))
echo "$num1 / $num2 = " $num3
num3=$(( $num1%$num2 ))
echo "$num1 % $num2  = " $num3