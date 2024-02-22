#Check Current Desktop
BHIoT$ echo $XDG_CURRENT_DESKTOP
ubuntu:GNOME

#Linux follows the standard process to declare environment variables (always in CAPS)

What is Env variable?
Values are already stored for example PATH, HOME, PWD

BHIoT$ echo $PWD
/home/bhupendra
BHIoT$ echo PWD
PWD
BHIoT$ x=2
BHIoT$ echo x
x
BHIoT$ echo $x
2

#Current Logged in Shells- 

BHIoT$ echo $SHELL

/bin/bash

#Default shell in Ubuntu ---- BASH (Bourne Again Shell)
---------------------------------------------------------------------
#How to check path of a specific command
-- whereis
BHIoT$ whereis bash
bash: /bin/bash /etc/bash.bashrc /usr/share/man/man1/bash.1.gz
BHIoT$ whereis ls
ls: /bin/ls /usr/share/man/man1/ls.1.gz

#List Block devices

lsblk -f 

#Print Disk Parition Table

sudo fdisk -l 

#Check Disk Usage

df - report file system disk space usage

df -h 

#Linux treats everything as a file even harddisk --> sda
------------------------------------------------------------------

Linux file system (Storage options) (Preferred/default(Ubuntu)  - EXT4) others ext3, ext2

Other popular : Btrfs, xfs (RHEL 7.0 default file system)

few more : NTFS (Windows and Linux) (Vfat - Windows only)

---------------------------------------------------------------------
Copy command
--------------------
cp <srcfile> <destinationpath>

say copy the file hi.txt from home/diot/a/b/c to Desktop

#if you present working directory is : home/diot/a/b/c 

cp hi.txt /home/diot/Desktop

#copy from any location
---------------------------------------------------------------------
cp home/diot/a/b/c/hi.txt /home/diot/Desktop
---------------------------------------------------------------------
Move command: (move content from one place to another location)
---------------------------------------------------------------------
mv home/diot/a/b/c/hi.txt /home/diot/Desktop

