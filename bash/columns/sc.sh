#! /bin/sh

vetc1=()
vetc2=()
ind=0

while read c1 c2 ; do 

	vetc1[ind]=$c1		
	vetc2[ind]=$c2		
	
	let ind=ind+1
done < $1

insert=0
echo "" > $1

while [[ $ind -gt 0 ]] ; do
	echo "${vetc2[$insert]} ${vetc1[$insert]}" >> $1

	let ind=ind-1
	let insert=insert+1
done

echo done
exit 0
