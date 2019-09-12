#include <unistd.h>

void	ft_test_fill(int tab[10])
{
	tab[0] = 0;
	tab[1] = 2;
	tab[2] = 5;
	tab[3] = 7;
	tab[4] = 9;
	tab[5] = 4;
	tab[6] = 8;
	tab[7] = 1;
	tab[8] = 3;
	tab[9] = 6;
}

void    print_tab_tenxten(int tab[10])
{
	int k;
	int line;

	line = 0;
	while (line < 10)
	{
		k = 0;
		while (tab[k] != line && k < 10)
		{
			write(1, "_", 1);
			write(1, " ", 1);
			k++;
		}
		if (tab[k] == line && k < 10)
		{
			write(1, "Q", 1);
			if (++k < 10)
				write(1, " ", 1);
		}
		while (k++ < 10)
		{
			write(1, "_", 1);
			if (k < 10)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		line++;
	}
}
