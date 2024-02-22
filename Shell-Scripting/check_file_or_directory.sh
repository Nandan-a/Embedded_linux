#!/bin/bash
<<notes
-f --> check file

-d --> directory
notes
read -p "check for file and directory : " check
if [[ -d $check ]]; then 
    echo "$check is directory"
elif [[ -f $check ]]; then 
    echo "$check is file"
else
    echo "$check is not a file nor directory"
    exit 1
fi