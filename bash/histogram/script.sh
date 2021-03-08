#! /bin/bash

while read data ; do 
	
	let n=$data
	
	for (( i=0; i<$n; i++ )) ; do
		/bin/echo -n "*"
	done

	echo 
done < $1
