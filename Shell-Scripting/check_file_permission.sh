#!/bin/bash
read -p "Enter the file name : " filename

if [[ -f $filename ]]; then
    echo "$filename present, proceeding for permission check"
else
    echo "$filename is not present in $PWD"
    exit 1
fi
#check for write permission
if [[ -w $filename ]]
then 
    echo "$filename has write permissions"
else
    echo "$filename has no write permissions"
fi
#check for read permission
if [[ -r $filename ]]
then 
    echo "$filename has read permissions"
else
    echo "$filename has no read permissions"
fi

#check for execute permission
if [[ -x $filename ]]
then 
    echo "$filename has execute permissions"
else
    echo "$filename has no execute permissions"
fi