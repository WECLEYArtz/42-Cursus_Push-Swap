#!/bin/bash
CMD="./push_swap \$1 | wc-l"
RES=$(cat << EOF | python3 | sed -e 's/(/"/g' -e 's/)/"/g' -e 's/,/ /g' | xargs -I ... echo ...
from itertools import permutations

perm = permutations([1, 2, 3])

for i in perm:
    print(i)
EOF
)

while read line; do
	RES=$(./push_swap $line | wc -l)
	STATUS=$(./push_swap $line | ./checker_linux $line)
	if [ $RES -gt 5 ]; then
		printf "Failed With $RES Moves For: $line - $STATUS\n" 
		exit
	else
		printf "$RES moves for: $line - $STATUS\n"
	fi
done <<< "$RES"
