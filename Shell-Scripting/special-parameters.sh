#!/bin/bash
<<notes
$0 ----> Script name (file name of the program)
$# ----> number of arguments passed to shell


notes
echo "Script name : " $0
echo $#
if [[ $# -gt 2 ]]; then
    echo "Minimum two parameters are mandetory from CLI"
    exit 0
fi
echo "value of $1 and $2 is -> " $1 $2
echo "Total cli parameters passed " $#
echo "values passed via CLI = " $*

# to check the PID of the below run firefox & first and then type echo $!
echo "The PID of last running process in background " $!
#To print the exit status of the last command that executed
# - 0 for success > 0 for failure

echo "The Exit status of last command : " $?
echo "PID of the current shell " $$
echo "Parameters passed to shell :" $@


