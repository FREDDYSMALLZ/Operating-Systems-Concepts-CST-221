#!/bin/bash

#First, Prompt the user to enter the password and check for the various conditions

echo "Please Enter your password?";
read pw;
length=${#pw}

#initialize count

count='0';

#Check if password contains special characters

if [[ $pw == *[^a-zA-Z0-9]* ]]

then
	count=$((count + 1))
else
	echo "Password entered must have special characters"
fi

#Check if password entered holds a numeric character

regex='[0-9]'

if [[ $pw =~ $regex ]]

then
	count=$((count + 1))
else
	echo "Password entered must have numeric characters"
fi

#check the length of the password.

if [[ $length > '7' ]]

then
	count=$((count + 1))

else
	echo "Password entered is too short. Password must have minimum of 8 characters"
fi

#Check if the password passed all the conditions set.

if [[ $count == 3 ]]
then
	echo "Congratulations!!!. The password entered has passed all checks"
fi
