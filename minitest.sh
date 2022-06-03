nbr=$(./get_nbrs $1 $2 $3)
#echo $nbr
#out=$(./push_swap $nbr)
#echo $out
./push_swap $nbr | ./checker $nbr
