#!/bin/bash

if [ $# -ne 2 ] ; then
	echo "error parameters ./sh [nomefile] [1/2 (rows/words)] "
	exit 1 
fi

if [ $2 -eq 1 ] ; then
	cnt=1
	while read row ; do
		echo "      $cnt  $row"
		let cnt=cnt+1
	done < $1
elif [ $2 -eq 2 ] ; then
	cnt=1
	for word in `cat $1` ; do 
		echo "      $cnt $word"
		let cnt=cnt+1
	done
else 
	echo "error parameters ./sh [nomefile] [1/2 (rows/words)] "
        exit 1
fi

exit 0
