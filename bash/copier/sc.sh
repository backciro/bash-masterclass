#!/bin/bash

if [[ $# -lt 1 ]] ; then
	echo "Usage: script dir file1 file2 .."
	exit 1
fi

if [[ ! -d $1 ]] ; then 
	echo "creating directory $1..."	
	mkdir $1
fi

for i in $* ; do
	if [[ $i != $1 ]] ; then 
		/bin/echo -n "would you like to copy $i to /$1 ? (Y/n)  "	
		read select
		
		if [ "$select" = "y" ] || [ $select = "Y" ] ; then
			cp $i $1
			if [ $? ] ; then 
				echo "$i copied"
			fi
		fi
	fi	
done
