#!/bin/bash

#    Author: Fredrick Onduso Ondieki
#    Course: CST - 221 Operating system Concepts
#    CST-221: Script bash to manage Users
#    Instructor: John Zupan
#    Date: April, 21 2019

#   This script is meant to manage users. It takes three agruments: A file input of users, A group name and Operation flag
#   The input file should have atleast five users

#   The scrpt also adds and removes users from the Linux system via the input file.

#   Lastly, the scrpt also checks if the group exists.


group="testGroup"
if grep -q $group /etc/group
then
echo "group exists"
else
groupadd $group
fi

filename="users.txt"
while read -r username password
do
name="$username"
pass="$password"
echo "Username: $name"
echo "Password: $pass"
if [ $(id -u) -eq 0 ]; then
egrep "^$name" /etc/passwd >/dev/null
if [ $? -eq 0 ]; then
echo "$name exists!"
exit 1
else
useradd -m -p $pass $name
[ $? -eq 0 ] && echo "New user has been added to the system!" || echo "Failed to add a user to the system!"
fi
else
echo "Only root may add a user to the system!"
exit 2
fi
usermod -aG $group $name
done < "$filename"

filename="users.txt"
while read -r username password
do
name="$username"
pass="$password"
userdel -r $name
echo "User Deleted."
done < "$filename"

if grep -q $group /etc/group
then
groupdel $group
else
echo "The group entered does not exist."
fi
