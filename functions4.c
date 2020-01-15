#include "test_header.h"

int		ft_itoa_base_unsigned(ulong u_value, int base, int lett_type)
{
	char	*s;
	int		n;
	int		i;
	char	*letters;

	if (u_value == 0)
		return (ft_putchar('0'));
	if (lett_type)
		letters = ft_strdup("0123456789ABCDEF");
	else 
		letters = ft_strdup("0123456789abcdef");
	n = digits_in_base_unsigned(u_value, base);
	s = (char *)malloc(sizeof(char) * (n + 1));
	s[n] = '\0';
	i = n - 1;
	while (u_value)
	{
		s[i] = letters[u_value % base];
		u_value /= base;
		i--;
	}
	ft_putstr(s);
	free(letters);
	free(s);
	return (n);
}