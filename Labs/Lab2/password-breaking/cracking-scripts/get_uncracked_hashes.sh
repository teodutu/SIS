#! /bin/bash

hashes=$(cat ../passwords.hash)
cracked=$(cat cracked_hashes.txt | awk '{print $NF}')
uncracked=''

for h in $hashes; do
	if ! grep -q $h <<< $cracked; then
		uncracked+=" $h"
	fi
done

echo $uncracked | tr ' ' '\n'

# 926ddc2e7b1d09e43bda9eeec25356498e721c762356797550454c37862b212d
# cad0535decc38b248b40e7aef9a1cfd91ce386fa5c46f05ea622649e7faf18fb
# 58f91a2aeffd6e0d1a3a4c139df5546be520174fbd48c26dad0c6d6369f7bc88
# bf90d29a5ccb2df544441fe986ac53325b6cb8de08a88ad83790bdb41f8c28c3
# 3e340be4de18e6f6df4404109ac61d3329ab3b73b8745b3d3cac74c41919cd20
# 102f680d00c0809bde4f89d1f251b5d8bb3baf8b3efb283c678379864df0098c
