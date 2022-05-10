#!/bin/sh

NBRS=$(./get_nbrs $1 $2 $3)
echo $NBRS
./push_swap $NBRS
