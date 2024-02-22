read -p "enter your name " name
read -p "enter your age : " age
if [[ $name == "Kshitij" && $age -gt 18 ]]; then
    echo "you are allowed to vote in 2024 "
else 
    echo "Hi $name is now allowed to vote"
fi
