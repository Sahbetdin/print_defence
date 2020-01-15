#include "test_header.h"

int	process_specifier(char *ptr, t_s *sp, va_list ap)
{
	int i;
	int l;
	int k;

	if (process_x_o(sp))
		return (ft_put_x_o(va_arg(ap, ulong), sp));
	else if (process_integers(sp))
		return (ft_put_d(va_arg(ap, long long), sp));
	else if (sp->s == 'f' || sp->s == 'F' || sp->s == 'e' || sp->s == 'E' || (sp->s == 'l' && sp->s1 == 'f'))
		return (ft_put_whole_double(va_arg(ap, double), sp));
	else if ((sp->s == 'L') && (sp->s1 == 'f' || sp->s1 == 'F' || sp->s1 == 'e' || sp->s1 == 'E'))
		return (ft_put_LONG_double(va_arg(ap, long double), sp));
	else if (sp->s == 'c')
		return (ft_putchar_c(va_arg(ap, int), sp));
	else if (sp->s == 'p')
		return (ft_put_p(va_arg(ap, long), sp));
	else if (sp->s == 's')
		return(ft_put_string(va_arg(ap, char *), sp));
	else if (sp->s == '%')
		return (ft_put_percentage(sp));
	else if (sp->s == 'V')
		return (ft_memory_float(va_arg(ap, double), sp));
	else if (sp->s == 'W')
		return (ft_memory_LDBL(va_arg(ap, long double), sp));
	return (0);
}


int process_specifier_main(t_s *sp, char *p, va_list ap)
{
	char *s;
	int ret;

	ret = 0;
	while (*p)
	{
		if (*p == '%')
		{
			if ((s = parse_sier(p + 1, sp)))
			{
				ret += process_specifier(p + 1, sp, ap);
				if (sp->s1)
				{
					if (sp->s2)
						p = s + 3;
					else
						p = s + 2;
				}
				else
					p = s + 1;
				continue;
			}
		}
		else
			ret += ft_putchar(*p);
		p++;
	}
	return (ret);
}

int     ft_printf(char *fmt, ...)
{
	va_list ap;
	char *p;
	int ret;
	char *s;
	t_s *sp;

	sp = (t_s *)malloc(sizeof(t_s));
	va_start(ap, fmt);
	p = fmt;
	ret = process_specifier_main(sp, p, ap);
	free(sp);
	va_end(ap);
	return (ret);
}
