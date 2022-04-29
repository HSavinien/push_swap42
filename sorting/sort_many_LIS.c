#include "push_swap.h"

//LIS mean longest increasing sublist.
//LDS mean longest decreasing sublist.
//LSS mean longest sorted sublist, so either of the two above.

void	sort_many(t_stack sa, t_stack sb)
{
	t_lss	*lis;
	t_lss	*lds;

	while (!is_stack_sorted(sa) || get_stack_len(sa) > 3)
	{
		lis = find_lis(sa);
		lds = find_lds(sa);
		if (lis->len >= lds -> len)
			swap_lss(lis, sb);
		else
			swap_lss(lds sa);
	}

}
