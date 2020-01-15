#include "test_header.h"

void	ft_put_sign(t_s *sp)
{
	if (sp->sign)
		write(1, "-", 1);
	else if (sp->plus)
		write(1, "+", 1);
}

void	ft_put_exp(t_s *sp, int dig)
{
	if (sp->s == 'e' || sp->s1 == 'e')
		write(1, "e", 1);
	else if (sp->s == 'E' || sp->s1 == 'E')
		write(1, "E", 1);
	if (dig < 0)
		write(1, "-", 1);
	else
		write(1, "+", 1);
}

int		ft_put_exp_value(int exp_)
{
	// printf("exp_ = %d\n", exp_);
	if (exp_ < 0)
		exp_ = -exp_;
	else
		exp_ -= 1;
	if (exp_ < 10)
	{
		write(1, "0", 1);
		ft_putchar(exp_ + '0');
	}
	else
		ft_putnbr_positive(exp_);
	if (exp_ < 100)
		return (2);
	else if (exp_ < 1000)
		return (3);
	else if (exp_ < 10000)
		return (4);
	else
		return (5);
}


//s это не ДЕСЯТАЯ ЧАСТЬ, это элемент объединенного массива
void	normalize_sci(uint *s, int d)
{
	int i;

	i = d;
	if (s[i + 1] > 4)
	{
		s[i]++;
		while (s[i] > 9 && i > 1)
		{
			s[i] -= 10;
			s[i - 1]++;
			i--;
		}
	}
}


//we create new array "arr" where whole and decimal parts stored
uint	*create_one_array_e(t_long *lng)
{
	uint *arr;
	int i;

	if (!(arr = (uint *)malloc(sizeof(uint) * (lng->whole[0] + lng->decimal[0] + 1))))
		return (NULL);
	arr[0] = lng->whole[0] + lng->decimal[0];
	//malloc and fill in with zeros

	i = 0;
	while (++i < arr[0])
		arr[i] = 0;

	return (arr);
}
