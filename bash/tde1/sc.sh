#!/bin/bash

if [[ $# -lt 1 ]] ; then
	echo "Usage : script [filename]"
	exit 1
fi

cp $1 `basename $1 ".txt"`.xyz

nlines=$(wc -l < $1)

while read row ; do 
	/bin/echo -n $(wc -w <<< "$row") 
	/bin/echo -n " $nlines"
	/bin/echo -n "    $row"
	echo
	
done < $1 > fileTmp

cat fileTmp | sort -k 1 -n > $1
rm -rf fileTmp

