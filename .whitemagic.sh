CMD="./push_swap \$1 | wc-l"
RES=$(cat << EOF | python3 | sed -e 's/(/"/g' -e 's/)/"/g' -e 's/,/ /g' | xargs -I ... echo ...
from itertools import permutations

perm = permutations([1, 2, 3, 4, 5])

for i in perm:
    print(i)
EOF
)

while read line; do
	RES=$(./push_swap $line | wc -l)
	echo $line
	if [ $RES -gt 12 ]; then
		printf "Failed With $RES Moves For: $PEPMS"
		exit
	else
		printf "$RES moves for: $PEPMS"
	fi
done <<< "$RES"
