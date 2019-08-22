#include <unistd.h>

void	ft_initialize(int tab[10][10])
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
			tab[i][j++] = 0;
		i++;
	}
}

void	print_tab_tenxten(int tab[10][10])
{
	int i;
	int j;
	int to_print;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			to_print = tab[i][j++] + 48;
			write(1, &to_print, 1);
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

int		main(void)
{
	int		tab[10][10];

	ft_initialize(tab);

	print_tab_tenxten(tab);
	return (0);
}
