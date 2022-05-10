#!/bin/sh

NBRS=$(./get_nbrs $1 $2 $3)
echo "list to sort is "$NBRS
./push_swap $NBRS | cat -e
echo $'\e[1;7m'
./push_swap $NBRS | ./checker_mac $NBRS
