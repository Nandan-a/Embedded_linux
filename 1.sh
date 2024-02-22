read  num1
read -sp "Enter Value of Number1 : " num2
echo "-----------------------------------"
echo "$num1+$num2" | bc
# echo "$num1-$num2" | bc
# echo "$num1*$num2" | bc
# echo "$num1/$num2" | bc
# echo " for getting the correct division output for example 10/2.3 alsways use scale"
echo " scale=4;$num1/$num2" | bc
# echo "$num1%$num2" | bc

