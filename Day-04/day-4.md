#All User details

cat /etc/passwd   #with sudo

#Encrypted password along with user

cat /etc/shadow

#How to change user:

su <username>

#How to change user password:
#Enter the new password after prompt

sudo passwd <username> 

#Shell in the system

cat /etc/shells

#How to change shell 

sudo chsh -s <SHELLNAME> <USERNAME>
----------------------------------------------
BHIoT$ cat /etc/passwd | tail -1
dev_v1:x:1018:1021::/home/dev_v1:/bin/sh
BHIoT$ sudo chsh -s /bin/bash dev_v1
-----------------------------------------------
BHIoT$ cat /etc/passwd | tail -1
dev_v1:x:1018:1021::/home/dev_v1:/bin/bash
----------------------------------------------
Alternate way:
sudo nano /etc/passwd

#verify the login shell:

echo $SHELL
-----------------------------------------------
What is /usr/sbin/nologin?

It means user doesn't have any shell associated
-----------------------------
MAC Shell Name:
Zsh
---------------------------------------------














