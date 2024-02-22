: '
Accept two Arguements from user and pass the sum of two numbers
'
sum(){
    let result=$num1+$num2
    echo "$num1 + $num2 = $result"
}
sub(){
    let result=$num1-$num2
    echo "$num1 - $num2 = $result"
}
mul(){
    let result=$num1*$num2
    echo "$num1 * $num2 = $result"
}
div(){
    let result=$num1/$num2
    echo "$num1 / $num2 = $result"
}
#call the function
choice="yes"
while [ $choice == "yes" ]
do
read -p "Enter value of num1 " num1
read -p "Enter value of num2 " num2
echo "Select what you want to do "
echo "----------- 1 to add ------------"
echo "----------- 2 to subtract ------------"
echo "----------- 3 to multiplication ------------"
echo "----------- 4 to division ------------"
read opts
case $opts in
1)
    sum $num1 $num2
;;
2)
    sub $num1 $num2
;;
3)
    mul $num1 $num2
;;
4)
    div $num1 $num2
;;
*)
    echo "Invalid input"
    exit 1
;;
esac
read -p "Do you want to continue : Enter yes " choice
done
