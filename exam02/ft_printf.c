# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i = 0;

	if (!str)
		str = "(null)";
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int ft_len(long long n, int base)
{
	int len = 1;

	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= base)
	{
		n = n  / base;
		len++;
	}
	return (len);
}

int ft_putnbr(int n, int base, char *arr)
{
	long long nb;

	nb = (long long)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base)
		ft_putnbr(nb / base, base, arr);
	ft_putchar(arr[nb % base]);
	return (ft_len(n, base));
}

int ft_printf_type(char str, va_list *ap)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(*ap, int));
	else if (str == 's')
		len += ft_putstr(va_arg(*ap, char *));
	else if (str == 'd')
		len += ft_putnbr(va_arg(*ap, int), 10, "0123456789");
	else if (str == 'x')
		len += ft_putnbr(va_arg(*ap, unsigned int), 16, "0123456789abcdef");
	return (len);
}

int ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i++]);
		else
		{
			len += ft_printf_type(str[i + 1], &ap);
			i += 2;
		}
	}
	va_end(ap);
	return (len);
}

int main()
{
	char *str = NULL;
	int num1 = 3847;
	int num2 = 74995663;
	ft_printf("hello testeeee %s aaaa %d Aaaaaa %x", str, num1, num2);
}
