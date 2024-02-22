#!/bin/bash
# case EXPRESSION in
# PATTERN_1)
# STATEMENTS
# ;;
# PATTERN_2)
# STATEMENTS
# ;;
# PATTERN_N)
# STATEMENTS
# ;;
# *)
# STATEMENTS
# ;;
# esac
read -p "Enter any sign among add, div, mul, and sub : " options
case $options in
    add) 
        echo "----- I am in add block ----"
    ;;
    sub) 
        echo "----- I am in Subtraction block ----"
    ;;
    mul) 
        echo "----- I am in multiplication block ----"
    ;;
    div) 
        echo "----- I am in division block ----"
    ;;
    *)
        echo "----- Please Enter a valid option ----"
    ;;
    esac