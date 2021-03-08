#! /bin/bash

while : ; do 
	
	echo "select a mode for searching"
	echo "1 for list all file"
	echo "2 for list all .c"
	echo "3 for list all POSIX.c"
	echo "0 for breakout!"

	read selector

	if [[ $selector -eq 0 ]] ; then 
		exit 0
	elif [[ $selector -eq 1 ]] ; then 
		find . -d 1
	elif [[ $selector -eq 2 ]] ; then 
		find . -name "*.c" -d 1		
	elif [[ $selector -eq 3 ]] ; then
		find . -name "*.c" -d 1	| grep POSIX	
	fi



done
