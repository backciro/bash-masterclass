#! /bin/sh

vet=()
let cnt=0

echo "insert VAL or 0 to abort" 

while : ; do
	read input

	if [ "$input" = "0" ] ; then 
		break;	
	fi

	vet[$cnt]="$input"	
	let cnt=cnt+1
done

let cnt=cnt-1
while [ $cnt -ge 0 ] 
do
	echo "${vet[$cnt]} "
	let cnt=cnt-1
done
