# read -p "Enter the user Name : " user_name
# read -sp "Enter the Password : " password
# echo " "
# echo your password is $password
# read -p "enter your age : "
# echo $REPLY
# read number     #here number is variable (without prompt)
# echo $number
# read num1 num2
# echo $num1
# echo $num2
# echo $(($num1+$num2))
# read -t 5 input            # t - timeout in seconds
# echo $input
read -n 5 input_string   #Set limit on characters
echo $input_string

#read -a

read -a array_of_words <<< "Hello I am from CDAC"
echo ${array_of_words[0]}
echo ${array_of_words[1]}
echo ${array_of_words[2]}
echo ${array_of_words[3]}
echo ${array_of_words[4]}


