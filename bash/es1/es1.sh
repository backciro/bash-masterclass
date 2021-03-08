#! /bin/sh

if [ $# -lt 2 ] ; then
	echo "Inserire 2 numeri interi"
	read n1 n2
else
	n1=$1
	n2=$2
fi

echo "MATRICE di $n1 x $n2"

let max=n1*n2
let val=0
let cntRow=0
let cntCol=0

while [ $cntRow -lt $n1 ] ; do
	let cntCol=0;
	while [ $cntCol -lt $n2 ] ; do
		/bin/echo -n "$val "
		let val=val+1
		let cntCol=cntCol+1
	done
	echo ""
	let cntRow=cntRow+1
done

exit 0
