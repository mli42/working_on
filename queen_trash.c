void	ft_test_fill(int tab[10])
{
	tab[0] = 6;
	tab[1] = 3;
	tab[2] = 5;
	tab[3] = 1;
	tab[4] = 8;
	tab[5] = 4;
	tab[6] = 9;
	tab[7] = 0;
	tab[8] = 2;
	tab[9] = 7;
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
