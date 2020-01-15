#include "test_header.h"

//!! if (j == s[0] - 1) is still an open question.
//possibly just make function for x = 0.0
int ft_find_exp(t_long *lng)
{
	int i;
	int j;
//find exponent which is j

	i = lng->whole[0];
	while (i > 0 && lng->whole[i] == 0)
		i--;
	j = i;
	// printf("j = %d\n", j);
	if (j <= 0)
	{
		i = 1;
		while (i < lng->decimal[0] && lng->decimal[i] == 0)
			i++;
		j = -i;
	}
	return (j);          
}

void ft_fill_in_one_arr_e(uint *arr, t_long *lng, int j)
{
	int i;
	int k;

	if (j > 0)
	{
		i = j + 1;
		while (--i > 0)
			arr[j - i + 1] = lng->whole[i];
		i = 1;
		while (i < lng->decimal[0])
		{
			arr[j + i] = lng->decimal[i];
			i++;
		}
	}
	else
	{
		// printf("j = %d\n", j);
		// print_memory(lng->decimal);
		i = 1;
		while (i <= lng->decimal[0] + j)
		{
			// ft_putnbr_positive(i);
			// write(1, " ", 1);
			// ft_putnbr_positive(lng->decimal[i - j - 1]);
			// write(1, "\n", 1);

			arr[i] = lng->decimal[i - j - 1];
			i++;

		}
		// print_memory(lng->decimal);
		// print_memory(arr);
	}
}


int ft_put_value_in_e(uint *arr, t_s *sp, int j)	
{
	int dig;
	int i;

	dig = sp->decim + 1;
	normalize_sci(arr, dig);
	if (arr[1] > 9)
	{
		ft_putchar('1');
		if (dig > 1)
			write(1, ".", 1);
		ft_put_n_chars(48, dig - 1);
		j++;
	}
	else
	{
		ft_putchar(arr[1] + '0');
		if (dig > 1)
			write(1, ".", 1);
		i = 1;
		while (++i <= dig)
			ft_putchar(arr[i] + '0');
	}
	free(arr);
	// sp->decim--;
	ft_put_exp(sp, j);
	return (j);
}

int ft_put_e_zero(t_s *sp)
{
	write(1, "0", 1);
	if(sp->decim > 0)
	{
		write(1, ".", 1);
		ft_put_n_chars(48, sp->decim);			
	}
	if (sp->s == 'e')
		write(1, "e+00", 4);
	else if (sp->s == 'E')
		write(1, "E+00", 4);
	return (sp->point + sp->decim + 5);
}

//ниже x = 0 рассматривается отдельно
int ft_put_sci(double x, t_s *sp)
{
	int i;
	int j; //кол-во записанных в "arr" целых чисел
	t_long *lng;
	uint *arr; //new array where whole and decimal parts stored
	int count;

	if (x == 0)
		return (ft_put_e_zero(sp));
	if (!(lng = create_long(x, sp)))
		return (0);
    // print_memory(lng->decimal);

	if (!(arr = create_one_array_e(lng)))
		return (0);
	j = ft_find_exp(lng);
	ft_fill_in_one_arr_e(arr, lng, j);
	j = ft_put_value_in_e(arr, sp, j);

    // print_memory(lng->decimal);
	// print_memory(arr);


//write down exponent value
	count = 1 + 2 + (sp->plus || sp->sign); //целая часть и e+
	if (sp->decim > 0)
		count += sp->decim + 1; //точка
	return (count + ft_put_exp_value(j));
}
