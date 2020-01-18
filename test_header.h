# ifndef __TEST_HEADER_H__
# define __TEST_HEADER_H__

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

typedef struct s_s
{
	char	s;
	char	s1;
	char	s2;
	int		zero;
	int		point;
	int		numb;
	int		decim;
	int 	plus;
	int 	minus;
	int		backsp;
	char	sign;
	int		hash;
}				t_s;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef union
{
	double dbl;
	struct {
		long mantissa: 52;
		uint exponent: 11;
		uchar sign: 1;
	} parts;
} u_double;

typedef union
{
	long double l_dbl;
	struct {
		long mantissa: 64;
		uint exponent: 15;
		uchar sign: 1;
	} parts;
} u_long_dbl;

typedef struct s_long
{
	uint *whole;
	uint *decimal;
	ulong flag;
} t_long;

//arithm.c
uint	*add_arithmetics(uint *a, uint *b);
uint	*set_arithmetic_zeros(int n);
uint	*add_arithmetics_minus(uint *a, uint *b);
//check_inf_nan1.c
int		put_inf(t_s *sp);
int		put_dlng_inf(t_s *sp);
void	ft_put_nan(t_s *sp);
int		check_double_inf(double a, t_s *sp);
int		check_dlng_inf(u_long_dbl *num_dbl, t_s *sp);
//check_inf_nan2.c
int		ft_negative_double_inf(void);
//functions1.c
int		ft_putchar(char c);
void	ft_put_zeros_backsp(t_s *sp);
int		ft_putchar_c(char c, t_s *sp);
size_t	ft_strlen(const char *s);
int		ft_putstr(char const *s);
//functions2.c
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s1);
int     ft_cut_backspaces(const char *s);
int     ft_atoi(const char *str);
int     ft_atoi2(const char *str, char *end);
//functions3.c
int     digits_in_base(long value, int base);
int     digits_in_base_unsigned(ulong u_value, int base);
int     ft_putnbr_positive(int n);
int     ft_putlong(long n);
//functions4.c
int     ft_itoa_base_unsigned(ulong u_value, int base, int lett_type);
//print_double.c
void	print_memory(uint *s);
int		print_double_whole_part(uint *s);
int		print_double_decimal_part(uint *s, int n);
void	print_binary_uint(uint num, int dig);
void	print_binary_ulong(ulong num, int dig);
//process_sp1.c
void	print_sp(t_s *sp);
void	clear_spec(t_s *sp);
void	handle_lhl(char *p, t_s *sp);
char	*find_spec(char *p, t_s *sp);
void	set_zero(char *p, char *s, t_s *sp);
//process_sp2.c
void	set_plus(char *p, char *s, t_s *sp);
void	set_minus(char *p, char *s, t_s *sp);
void	set_backsp(char *p, char *s, t_s *sp);
char *set_point(char *p, char *s, t_s *sp);
void	set_numb(char *p, char *s, t_s *sp);
//process_sp3.c
void	set_decimal(char *p, t_s *sp);
void	set_hash(char *p, char *s, t_s *sp);
char	*parse_sier(char *p, t_s *sp);
int		process_x_o(t_s *sp);
int		process_integers(t_s *sp);
//process_sp4.c
int		process_specifier_double(t_s *sp);
int		process_specifier_long_double(t_s *sp);
int		process_specifier(char *ptr, t_s *sp, va_list ap);
char	*process_specifier_s1_s2(char *s, char sp2);
int		process_specifier_main(t_s *sp, char *p, va_list ap);
//process_sp5.c
int		ft_printf(char *fmt, ...);
//put_d1.c
void	ft_put_n_chars(char c, int n);
void	ft_put_long(long num);
int		ft_put_int_min(int k, t_s *sp);
void	ft_put_int_min_ze_nmi(int k);
int		ft_put_int_min_with_point(t_s *sp);
//put_d2.c
int		ft_put_int_min_with_spec(int num, t_s *sp);
int		ft_put_d_without_numb_point(long num, t_s *sp);
void	ft_put_d_pl_si_mi(long num, int k, int l, t_s *sp);
void	ft_put_d_pl_nsi_ze(long num, int k, int l, t_s *sp);
void	ft_put_d_pl_nsi(long num, int k, int l, t_s *sp);
//put_d3.c
void	ft_put_d_npl_nsi_mi_ba(long num, int *k, int l, t_s *sp);
void	ft_put_d_npl_nsi_ze(long num, int k, int l, t_s *sp);
void	ft_put_d_npl_nsi_mi(long num, int k, int l, t_s *sp);
void	ft_put_d_si_mi(long num, int k, int l);
void	ft_put_si_ze(long num, int k, int l, t_s *sp);
//put_d4.c
void	ft_put_int_min_minus(t_s *sp, int k, int l);
int		ft_put_si_ba(long num, int k, int l);
void	ft_put_else(long num, int k, int l, t_s *sp);
int		ft_put_npl_nsi_ba(long num, int k, int l, t_s *sp);
int		ft_put_npl_nsi_ze_ba(long num, int k, int l, t_s *sp);
//put_d5.c
long	ft_cast_num(long num, t_s *sp);
int		ft_put_d_if_specif1(long num, t_s *sp, int k, int l);
int		ft_put_d_if_specif2(long num, t_s *sp, int k, int l);
int		ft_put_d_with_numb_point(long num, t_s *sp, int dig);
int		ft_put_d(long num, t_s *sp);
//put_double1.c
void	normalize(uint *a, uint *s, int i);
t_long	*create_long_whole_pre(u_double *num_union_f);
t_long	*create_long_whole(u_double *num_union_f);
uint	*ft_temp_b_floats(u_double *num_union_f, int n);
t_long	*create_long(double x, t_s *sp);
//put_double2.c
void	free_long_arithm(t_long *lng);
int		put_double_new(double x, t_s *sp);
int		ft_put_f_double(double a, t_s *sp);
int		ft_memory_float(double a, t_s *sp);
int		ft_memory_ldbl(long double a, t_s *sp);
//put_ee1.c
void	ft_put_sign(t_s *sp);
void	ft_put_exp(t_s *sp, int dig);
int		ft_put_exp_value(int exp_);
void	normalize_sci(uint *s, int d);
uint	*create_one_array_e(t_long *lng);
//put_ee2.c
int		ft_find_exp(t_long *lng);
void	ft_fill_in_one_arr_e(uint *arr, t_long *lng, int j);
int		ft_put_value_in_e(uint *arr, t_s *sp, int j);
int		ft_put_e_zero(t_s *sp);
int		ft_put_sci(double x, t_s *sp);
//put_ee3.c
int		ft_dig_db(double a);
int		ft_get_k_for_e(double x, t_s *sp);
int		ft_put_whole_sci(double x, t_s *sp);
//put_f1.c
int		ft_put_double_help_pl_nsi(double a, t_s *sp);
int		ft_put_doubel_set_k(t_s *sp, int dig);
void	ft_put_double_help_pl_mi(double a, t_s *sp, int k);
void	ft_put_double_help_pl_nsi_ze(double a, t_s *sp, int k);
void	ft_put_double_help_pl_nsi2(double a, t_s *sp, int k);
//put_f2.c
void	ft_put_double_help_npl_nsi_mi_ba(double a, t_s *sp, int k);
void	ft_put_double_help_pl_mi(double a, t_s *sp, int k);
void	ft_put_double_help_npl_mi(double a, t_s *sp, int k);
void	ft_put_double_help_npl_nsi_ba(double a, t_s *sp, int k);
void	ft_put_double_help_si_ze(double a, t_s *sp, int k);
//put_f3.c
void	ft_put_double_help_si_ba(double a, t_s *sp, int k);
void	ft_put_double_help_else(double a, t_s *sp, int k);
void	process_sp_for_double(double a, t_s *sp, int k);
int		ft_put_whole_double(double a, t_s *sp);
//put_hex_oct1.c
void	ft_put_prelimenaries(long num, t_s *sp);
int		ft_put_integer_u(ulong u_value, t_s *sp);
int		ft_dig_from_spec(ulong num, t_s *sp);
ulong	ft_cast_num_ulong(ulong num, t_s *sp);
//put_hex_oct2.c
int		ft_put_x_o_npo_nmi(ulong num, t_s *sp, int k);
int		ft_put_x_o_npo(ulong num, t_s *sp, int dig);
int		ft_put_x_o_mi_nmi(ulong num, t_s *sp, int k, int l);
int		ft_x_o_point_get_k(t_s *sp, int dig, int l);
int		ft_put_x_o_fet_l(t_s *sp, int dig);
//put_hex_oct3.c
int		ft_put_x_o(ulong num, t_s *sp);
void	ft_modify_from_hash(ulong num, t_s *sp);
//put_long_e.c
int		ft_put_sci_ldbl(long double x, t_s *sp);
int		ft_dig_long(long double a);
int		ft_get_k_for_e_ldbl(long double x, t_s *sp);
int		ft_put_whole_sci_ldbl(long double x, t_s *sp);
//put_long_dbl1.c
t_long	*ft_create_long_pre(u_long_dbl *num_dbl);
t_long	*ft_create_long_whole(u_long_dbl *num_dbl);
int		ft_create_n_temp(uint exp_, int d);
uint	*ft_create_b_temp(uint exp_, int d, int n);
void	ft_create_long_decimal(t_long *lng2, u_long_dbl *num_dbl, int d);
//put_long_dbl2.c
int		ft_put_long_only(u_long_dbl *num_dbl, t_s *sp);
int		ft_dig_ldbl(long double a);
void	ft_put_from_specif_ldbl_minus(u_long_dbl *num_dbl, t_s *sp, int k);
void	ft_put_from_specif_ldbl(u_long_dbl *num_dbl, t_s *sp, int k);
int		ft_get_k_for_ldbl(t_s *sp, int dig);
//put_long_dbl3.c
int		ft_put_long_double(long double x, t_s *sp);
//put_p.c
int		ft_put_p_zero(t_s *sp);
int		ft_put_p_minus(long num, int l, int k);
int		ft_put_p(long num, t_s *sp);
//put_strings1.c
int		ft_put_percentage(t_s *sp);
int		ft_put_null(t_s *sp);
int		ft_get_l_strings(t_s *sp, int n);
int		ft_get_k_strings(t_s *sp, int l, int n);
void	ft_put_str_k_l(t_s *sp, char *str, int k, int l);
//put_strings2.c
int		ft_put_string(char *str, t_s *sp);
//two.c
uint	*raise_to_power_2(uint *s);
uint	*power_of_2(uint pow, int n);
int		ft_divide_by_2_i(uint *s);
uint	*divide_by_2(uint *s);
uint	*divide_by_minus_2(uint *s, int n);



///убрать тех кто ниже...
int		ft_putdouble(double a, t_s *sp);
int		ft_putscientific(double a, t_s *sp);
void	set_sign(char *p, char *s, t_s *sp);
void	set_numb(char *p, char *s, t_s *sp);
void	set_decimal(char *p, t_s *sp);
void	set_hash(char *p, char *s, t_s *sp);
char	*parse_sier(char *p, t_s *sp);

int		ft_put_percentage(t_s *sp);
int		ft_put_parsed_integer_u(uint num, t_s *sp);
int		ft_put_string(char *str, t_s *sp);

int		ft_put_d_with_numb_point(long num, t_s *sp, int dig);

//f, F, Lf, e, E


uint	*set_whole_part(u_double *N);
void	normalize(uint *a, uint *s, int dig);
int		put_double_new(double x, t_s *sp);
void	free_long_arithm(t_long *lng);
int		ft_put_whole_double(double a, t_s *sp);
int		ft_put_f_double(double a, t_s *sp);
t_long *create_long(double x, t_s *sp);
int		ft_put_whole_sci(double x, t_s *sp);

//p
int		ft_put_p(long num, t_s *sp);
//e
void ft_put_exp(t_s *sp, int dig);
int ft_put_exp_value(int exp_);
void normalize_sci(uint *s, int d);
uint *create_one_array_e(t_long *lng);
int ft_find_exp(t_long *lng);
void ft_fill_in_one_arr_e(uint *arr, t_long *lng, int j);
int ft_put_value_in_e(uint *arr, t_s *sp, int j);
int ft_put_e_zero(t_s *sp);
int ft_put_sci(double x, t_s *sp);
int ft_dig_db(double a);
int ft_get_k_for_e(double x, t_s *sp);
int ft_put_whole_sci(double x, t_s *sp);



int		ft_put_long_double(long double x, t_s *sp);

//sign
void	ft_put_sign(t_s *sp);
//memory print
int		ft_memory_float(double a, t_s *sp);
int		ft_memory_ldbl(long double a, t_s *sp);

#endif
