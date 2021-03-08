#! /bin/bash

if [[ $# -ne 1 ]] ; then
	echo "USAGE $0 [file]" 
	exit 1 
fi

if [[ -f $1 ]] ; then 
	ls -l ~/ > $1
else
	echo error
	exit 1
fi

echo "" > risultati.txt
while read row ; do
	data=$(echo $row | cut -d " " -f 1 | cut -c 1-4)

	fD=$(echo $data | cut -c 1)
        executable=$(echo $data | cut -c 4)

        if [[ $fD = "-" ]] ; then 
                if [[ $executable = "x" ]] ; then
			echo $row | grep -E .*[b]+.*[a]$ >> risultati.txt
                fi
        fi

done < $1

