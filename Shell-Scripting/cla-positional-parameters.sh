#$1 is first command line argument -- $9
num1=$1
num2=$2
echo "$1 + $2 = " $(( $1 + $2 ))    
<< mynotes
$1 - is the first positional parameter
$2 - is the second positional parameter
mynotes
echo "\$1 = " $1 
echo "\$2 = " $2 
echo "\$3 = " $3 
echo "\$4 = " $4
echo "\$5 = " $5 
echo "\$6 = " $6
echo "\$7 = " $7 
echo "\$8 = " $8
echo '$9' " = " $9 
echo "from $10 the cli arguments should be written as ${10}.."
echo "\${10} = " ${10}

<<sample-output
BHIoT$ ./cla-positional-parameters.sh 1 2 3 4 5 6 7 8 9 10
1 + 2 =  3
1 =  1
2 =  2
3 =  3
4 =  4
5 =  5
6 =  6
7 =  7
8 =  8
9 =  9
-------------------------------
10 =  10
BHIoT$ ./cla-positional-parameters.sh 1 2 3 4 5 6 7 8 9 100
1 + 2 =  3
1 =  1
2 =  2
3 =  3
4 =  4
5 =  5
6 =  6
7 =  7
8 =  8
9 =  9
-------------------------------
10 =  10
sample-output



