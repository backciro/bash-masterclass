#! /bin/bash

flag=1
for val in `cat $1`
do
	if [ $flag -eq 1 ] ; then
		let f=3*val*val
	elif [ $flag -eq 2 ] ; then
	 	let f=f+4*val
	elif [ $flag -eq 3 ] ; then 
		let f=f+5*val
		flag=0
		echo "$f "
	fi
	
	let flag=flag+1
done
