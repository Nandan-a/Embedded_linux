# BHIoT$ expr 2+2
# 2+2
# BHIoT$ expr 2 + 2
# 4
# BHIoT$ expr 3 * 2
# expr: syntax error: unexpected argument ‘break_demo.sh’
# BHIoT$ expr 3 \* 2
# 6
# BHIoT$ expr 5 % 2
# 1
read -p "Enter value of num1 " num1
read -p "Enter value of num2 " num2
res=`expr $num1 + $num2`
echo "$num1 + $num2 = $res"
