#!/bin/sh

NBRS=$(./generator $1 $2 $3)
echo 'generated array : '$NBRS$'\nstored in \033[1;34m$NBRS'
