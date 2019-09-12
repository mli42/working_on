/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:19:39 by mli               #+#    #+#             */
/*   Updated: 2019/09/12 23:42:40 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int        base_check(char *base)
{
    int i;
    int j;

    // Base vide ou de taille 1
    if (base[0] == '\0' || base[1] == '\0')
        return (0);
    // Comporte uniquement chiffres et lettres
    i = 0;
    while (base[i])
    {
        if (!(base[i] >= '0' && base[i] <= '9') &&
                !(base[i] >= 'a' && base[i] <= 'z') &&
                !(base[i] >= 'A' && base[i] <= 'Z'))
            return (0);
        i++;
    }
    // Deux char identiques
    i = 0;
    while (base[i + 1])
    {
        j = i + 1;
        while (base[j])
            if (base[i] == base[j++])
                return (0);
        i++;
    }
    return (i + 1);
}

void    ft_convert(unsigned int nbr, char *base, unsigned int base_len)
{
    if (nbr >= base_len)
    {
        ft_convert((nbr / base_len), base, base_len);
        ft_convert((nbr % base_len), base, base_len);
    }
    else
        write(1, &base[nbr], 1);
}

void    ft_putnbr_base(int nbr, char *base)
{
    unsigned int base_len;
    unsigned int nb;

    nb = nbr;
    base_len = base_check(base);
    if (base_len)
    {
        if (nbr < 0)
        {
            write(1, "-", 1);
            nb = nbr * (-1);
        }
        ft_convert(nb, base, base_len);
        write(1, "\n", 1);
    }
}

int        main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_putnbr_base(atoi(argv[1]), "01");
        ft_putnbr_base(atoi(argv[1]), "0123456789ABCDEF");
        ft_putnbr_base(atoi(argv[1]), "poneyvif");
    }
    return (0);
}
