#include <unistd.h>

int check_dup(char c, char *str, int position)
{
	int i = 0;

	while (i < position)
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
	int j = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (check_dup(av[1][i], av[1], i))
				write(1, &av[1][i], 1);
			i++;
		}
		while (av[2][j])
		{
			if (check_dup(av[2][j], av[1], i))
			{
				if (check_dup(av[2][j], av[2], j))
					write(1, &av[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n",1);
	return (0);
}
