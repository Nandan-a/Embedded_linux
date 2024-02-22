#!/bin/bash
read -p "Enter your name : " user_name
read -p "Enter your age : " age
if [[ $user_name == "Ishwar" ]]
then
    echo "Hi $user_name !! How are you"
fi
echo "Sorry $user_name You doesn't deserve Hi"
