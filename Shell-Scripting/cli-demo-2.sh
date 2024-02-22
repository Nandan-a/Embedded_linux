#!/bin/bash
<<notes
How to use Flags in command line arguments 
use getopts - retrieves optios from otions argument
OPTARG - To retrieve value
notes

while getopts n:a:d: student_profile  #flags must be single character like for name use n not name or student_name
do
    echo "${student_profile}"
    case "${student_profile}" in
    n)
        name=${OPTARG}
    ;;
    a)
        age=${OPTARG}
    ;;
    d)
       department=${OPTARG}
    ;;
    esac
done
echo "Hello Mr. $name your age is $age and department is $department"
#BHIoT$ ./cli-demo-2.sh -n test -a 23 -d diot
