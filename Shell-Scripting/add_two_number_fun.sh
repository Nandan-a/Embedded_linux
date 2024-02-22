# : '
# Accept two Arguements from user and pass the sum of two numbers
# '
sum(){
    read -p "Enter value of num1 " num1
    read -p "Enter value of num2 " num2
    let result=$num1+$num2
    echo $result
}
#call the function
sum

