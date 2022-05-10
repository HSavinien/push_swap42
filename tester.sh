#!/bin/sh

NBRS=$(./get_nbrs $1 $2 $3)
echo "list to sort is "$NBRS
./push_swap $NBRS
echo -n '\e[1;7m'
./push_swap $NBRS | ./checker_linux $NBRS
