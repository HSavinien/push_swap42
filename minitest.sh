nbr=$(./get_nbrs $1 $2 $3)
./push_swap $nbr | ./checker $nbr
