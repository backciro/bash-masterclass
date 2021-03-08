#! /bin/bash

cnt=0
while read x y z
do
	let f=3*x*x+4*y+5*z
	echo $f

done < $1

