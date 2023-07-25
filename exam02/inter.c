#include <unistd.h>

int check_av(char c, char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int check_av1(char c, char *str, int repeat)
{
	int i = 0;

	while (i < repeat)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	int i = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check_av(av[1][i], av[2]))
			{
				if (check_av1(av[1][i], av[1], i))
					write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

