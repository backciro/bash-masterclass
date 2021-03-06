#!/bin/bash

if [[ $# -lt 4 ]] ; then
	echo "Usage : script dir1 dir2 dir3 n"
	exit 1
fi


for val1 in `find $1 -name "*.txt"` ; do
	for val2 in `find $2 -name "*.txt"` ; do
		if [ `basename $val1` = `basename $val2` ] \
		    && [ $(wc -l < $val1) -ge $4 ] \
		    && [ $(wc -l < $val2) -ge $4 ] ; then
			
			
			for i in `cat $val1` ; do 
				echo `basename $val1` $i
			done
		fi
	done
done
