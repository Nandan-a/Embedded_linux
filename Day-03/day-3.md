#user and group management
---------------------------------
How to create a new user
------------------------------
#Way-01 - With full details
using adduser command

BHIoT$ sudo adduser diot-23
Adding user `diot-23' ...
Adding new group `diot-23' (1018) ...
Adding new user `diot-23' (1016) with group `diot-23' ...
Creating home directory `/home/diot-23' ...
Copying files from `/etc/skel' ...
New password: 
Retype new password: 
passwd: password updated successfully
Changing the user information for diot-23
Enter the new value, or press ENTER for the default
	Full Name []: Bhupendra
	Room Number []: 103
	Work Phone []: 9086244169
	Home Phone []: NA
	Other []: NA
Is the information correct? [Y/n] Y
----------------------------------------------------------
#Add the user to run the command with sudo 

#-- Entry must be created in the sudoers file --> /etc/sudoers

diot-23    ALL=(ALL:ALL) ALL

#add this line to not to ask for password

bhupendra ALL=NOPASSWD: ALL

----------------------------------------------------------------
Now logout and login with new user and try to run some commands with sudo
to verify the changes has been applied?
------------------------------------------------------------------------
#Way-02 (With Less details)
sudo useradd <username>
------------------------------
#verify the newly created user in the passwd file
cat /etc/passwd
-------------------------------------------------------
diot-23:x:1016:1018:Bhupendra,103,9086244169,NA,NA:/home/diot-23:/bin/bash
diot-23v1:x:1018:1020::/home/diot-23v1:/bin/sh

username:encrypted-password:UID:GID:Comments-if-any:home-diretcory:shellname
---------------------------------------------------------------------------

#remove/Delete a user

BHIoT$ sudo userdel diot-23v1

#Create a new group

sudo groupadd <groupname>

#Example
BHIoT$ sudo groupadd pgdiot

#Verify the entry
------------------------------------------
BHIoT$ cat /etc/group | tail -1
pgdiot:x:1020:
-----------------------------------------

What does pipe do : pass the standard output of one process as standard input to another process
-----------------------------------------------------------------------

cat /etc/group ----> stanard output is standard input of tail -1

head and tail commands - print lines from file (top and bottom)
#from top
head <-linenumber> <filename>
#from bottom
tail <-linenumber> <filename>

print the first line from the top
head -1 <filename>
#print the last line 
tail -1 <filename>
------------------------------------
How to cheeck members of group
cat /etc/group
#For Example:
sudo:x:27:bhupendra,bhupendraps,bhupendr
sudo group  has users : bhupendra,bhupendraps,bhupendr
------------------------------------------------------------

Lets add a user to group pgdiot
#creating a user
sudo useradd diotpg
#add user to group (-a append - G group)
sudo usermod -a -G <groupname> <username>
sudo usermod -a -G pgdiot diotpg
----------------------------------------
#Example:
BHIoT$ cat /etc/group | grep pgdiot
pgdiot:x:1020:
BHIoT$ sudo usermod -a -G pgdiot diotpg
BHIoT$ cat /etc/group | grep pgdiot
pgdiot:x:1020:diotpg
---------------------------------------------------------
BHIoT$ sudo usermod -a -G pgdiot $USER
BHIoT$ cat /etc/group | grep pgdiot
pgdiot:x:1020:diotpg,bhupendra

-------------------------------------------------------------------
Chnage ownership/user and group on a file

BHIoT$ touch newfile.txt
BHIoT$ ls -l newfile.txt 
-rw-rw-r-- 1 bhupendra bhupendra 0 Apr 14 21:47 newfile.txt
---------------------------------------------------------------
BHIoT$ chgrp pgdiot newfile.txt 
chgrp: changing group of 'newfile.txt': Operation not permitted
BHIoT$ sudo chgrp pgdiot newfile.txt 
BHIoT$ ls -l newfile.txt 
-rw-rw-r-- 1 bhupendra pgdiot 0 Apr 14 21:47 newfile.txt
-------------------------------------------------------------------
#change default user
#chown <username> filename
BHIoT$ sudo chown diotpg newfile.txt 
BHIoT$ ls -l newfile.txt 
-rw-rw-r-- 1 diotpg pgdiot 0 Apr 14 21:47 newfile.txt
-------------------------------------------------------
BHIoT$ sudo chown bhupendra newfile.txt
BHIoT$ ls -l newfile.txt 
-rw-rw-r-- 1 bhupendra pgdiot 0 Apr 14 21:47 newfile.txt
-------------------------------------------------------------
BHIoT$ chmod 060 newfile.txt 
------------------------------------------------------------


























