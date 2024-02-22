#Create files with range
----------------------------------------------
BHIoT$ touch a{1..5}.txt
BHIoT$ ls
a  a1.txt  a2.txt  a3.txt  a4.txt  a5.txt
----------------------------------------------
ToDo:
---
test1 - (all files should be copied to ) test2
-------------------------------------------------------
cp * /destinationdir

for nested dirs

cp -r * /destinationdir

--------------------------------------------------------

while doing move operation no need to use (-r)

BHIoT$ mv -r * ../test3
mv: invalid option -- 'r'
Try 'mv --help' for more information.
BHIoT$ mv * ../test3
BHIoT$ ls
BHIoT$ ls ../test3
a1.md  a2.md  a3.md  a4.md  a5.md  b10.c  b11.c  b12.c  b13.c  b14.c  b15.c  pra-1
BHIoT$ ls ../test3/pra-1/
123.txt
-------------------------------------------------------------------------------
test_dir
--
a.c b.c a.py b.py

copy the file which have .c extension to another place say c_pro
------------------------------------------------------------------------
cp *.c /destinationdir

#print history of commands

history

#save in a file

history > commandnotes.md

#clear the history

history -c

--------------------------------------------------------------------------
check version of a command (Not all but with most) 

mkdir --version


#How to check details about a coomand

man mkdir   #display manual page

#Avaialble flags with commands

mkdir --help

-----------------------------------------------------------------
To Print Permission of a file:

BHIoT$ ls -l notest.txt 
-rw-rw-r-- 1 bhupendra bhupendra 29124 Apr 12 19:59 notest.txt
There are 10 fields (column - 1)
field-1
------------
- nature of the content
regular file : -
directory   : d
symbolic link : l
pipe   : p
socket : s

drwxrwxr-x 3 bhupendra bhupendra 4096 Apr 11 21:22 a
-rw-rw-r-- 1 bhupendra bhupendra    0 Apr 12 19:12 a1.txt
---------------------------------------------------------------
HIoT$ ls -l newfile.txt 
-rw-rw-r-- 1 bhupendra bhupendra 0 Oct 28 19:44 newfile.txt

r - read
w - write
x- execute
-------------------
A file is managed by three entities:
1. user/owner
2. Group
3. Others
What can be at first place

- > d/-/s/p/
d -> directory
- -> file
l -> symlink/links
p -> pipe
s -> socket

--- (user)rwx
--- (group)rwx
---(others)rwx

BHIoT$ ls -l
total 4
drwxrwxr-x 2 bhupendra bhupendra 4096 Oct 28 19:43 a
-rw-rw-r-- 1 bhupendra bhupendra    0 Oct 28 19:44 newfile.txt

mkdir -m a=rwx test

---------------------------------------------------------------------
Assignment:
1. create a directory elx2022 inside home directory (~)
2. under this create a directory m/n/o/p/i [with one command]
3. under m/n create a empty file n.txt
4. create an empty file inside p as p.md
5. create a directory under p as p.1
6. from p go to m and create a dir m.1 with rwx permission to user,group and others

#Create multiple empty files/dirs in one go

touch {1.10}.txt

mkdir {1..10}

mkdir {1..10}-diot




BHIoT$ touch {1..10}.txt
BHIoT$ ls
10.txt  2.txt  4.txt  6.txt  8.txt  a            test
1.txt   3.txt  5.txt  7.txt  9.txt  newfile.txt
BHIoT$ mkdir {1..10}
BHIoT$ ls
1       2      4      6      8      a
10      2.txt  4.txt  6.txt  8.txt  newfile.txt
10.txt  3      5      7      9      test
1.txt   3.txt  5.txt  7.txt  9.txt
BHIoT$ mkdir {1..10}-diot
BHIoT$ ls
1        2       4       6       8       a
10       2-diot  4-diot  6-diot  8-diot  newfile.txt
10-diot  2.txt   4.txt   6.txt   8.txt   test
10.txt   3       5       7       9
1-diot   3-diot  5-diot  7-diot  9-diot
1.txt    3.txt   5.txt   7.txt   9.txt

#To remove a file -- rm <filename>

rm 1.txt

Delete squence of file/dir(s)
--------------------------------------------------------------------

BHIoT$ rmdir {1..10}
BHIoT$ ls
10-diot  2-diot  4-diot  6-diot  8-diot  a
10.txt   2.txt   4.txt   6.txt   8.txt   newfile.txt
1-diot   3-diot  5-diot  7-diot  9-diot  test
1.txt    3.txt   5.txt   7.txt   9.txt
BHIoT$ rmdir {1..10}-diot
BHIoT$ ls
10.txt  2.txt  4.txt  6.txt  8.txt  a            test
1.txt   3.txt  5.txt  7.txt  9.txt  newfile.txt
BHIoT$ rm {1..10}.txt
BHIoT$ ls
a  newfile.txt  test

#You want prompt to ask before deleting a file

BHIoT$ rm -i 1.txt 
rm: remove regular empty file '1.txt'? y
BHIoT$ rm -i 2.txt 
rm: remove regular empty file '2.txt'? n
BHIoT$ ls
2.txt  a  newfile.txt  test

-------------------------------------------------------------------
Change file permissions :
------------------------------
chmod 
-------------------------------------------
4 - read
2 - write
1 - execute

max possible value - 7
min - 0

rwx - 7
rw - 6
r - 4
rx - 5
wx - 3
---------------------------------
ugo -> 777
---------------------------------
Agenda:
to give readwrite permission to all for file 2.txt

BHIoT$ ls -l 2.txt 
-rw-rw-r-- 1 bhupendra bhupendra 0 Oct 28 20:43 2.txt
BHIoT$ chmod 666 2.txt 
BHIoT$ ls -l 2.txt 
-rw-rw-rw- 1 bhupendra bhupendra 0 Oct 28 20:43 2.txt

Assignment 2: [go -- group and other]
-----------------------------------------------------------------------------------------
Create a file and give permisions 
1. test1.txt read only to user, go no permissions
2. test2.txt read and write to user, go no permissions
3. test3.txt read only to user, rw permissions to group and o - np (no permission)
4. test4.txt np to user, rwx to g and read permissions to others
5. test5.txt rw to all
6. test6.txt rwx to all
7. test7. txt readonly to all

touch test{1..7}.txt
------------------------------------------------------------------------------------------
BHIoT$ touch 7.txt && chmod 444 7.txt
BHIoT$ ls
2.txt  7.txt  a  newfile.txt  test
BHIoT$ ls -l 7.txt 
-r--r--r-- 1 bhupendra bhupendra 0 Oct 28 21:07 7.txt

#handle with care - remove forefully
--------------------------------------------------------
rm -rf <filename>
rm -rf <dirname>
-------------------------------------------------------
rm -rf test/

BHIoT$ mkdir -p 1/2/3/4/5/6/7
BHIoT$ rm -rf 1/*
BHIoT$ pwd
/home/bhupendra/Embedded-Linux-Pro/2022-sept
BHIoT$ ls
1  a  p
BHIoT$ rm -rf *
BHIoT$ ls
BHIoT$ pwd
/home/bhupendra/Embedded-Linux-Pro/2022-sept
----------------------------------------------------------------------------
Write some content to file using echo - if file doesn't exist will be created

echo "Content" > 1.txt 

#Append

echo "new content" >> 1.txt
#Display content of the file
cat <filename>
---------------------------------------------------------
BHIoT$ echo "Hello from IoT" > iot.txt
BHIoT$ ls
iot.txt
BHIoT$ cat iot.txt 
Hello from IoT
BHIoT$ echo "IoT is important domain" >> iot.txt 
BHIoT$ cat iot.txt 
Hello from IoT
IoT is important domain
BHIoT$ echo "PGDIOT-CDAC-ACTS" > iot.txt 
BHIoT$ cat iot.txt 
PGDIOT-CDAC-ACTS
---------------------------------------------------

Secure Copy: (scp - copy files on remote machine)
-------------
scp <filename> username@ipaddress:<Path>

Note:
username --> remote machine
ip address -> remote machine
path ---> remote machine path
----------------------------------------------------






    












