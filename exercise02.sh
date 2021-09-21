#!/bin/bash
while true; do
line = $(tail -n 1 exercise02.txt)
line = $((line+1))

while(! ln exercise02.txt.lock 2> null); do
	sleep 0.1
done
echo $line >> exercise02.txt
rm exercise02.txt.lock
done
