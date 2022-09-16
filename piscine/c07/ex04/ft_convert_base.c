#include <stdlib.h>
#include <stdio.h>

int     ft_check(char *base)
{
        int     i;
        int     j;

        i = 0;
        while (base[i])
        {
                if (base[i] == '+' || base[i] == '-')
                        return (0);
                j = i + 1;
                while (base[j])
                {
                        if (base[i] == base[j])
                                return (0);
                        j++;
                }
                i++;
        }
        if (i <= 1)
                return (0);
        return (i);
}

int     ft_index(char c, char *base)
{
        int     i;

        i = 0;
        while (base[i])
        {
                if (c == base[i])
                        return (i);
                i++;
        }
        return (0);
}

int     ft_atoi(char *str, char *base, int size)
{
        int     sign;
        int     res;
        int     i;
        int     index;

        sign = 1;
        res = 0;
        i = 0;
        index = 0;
        while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
                i++;
        while (str[i] == '+' || str[i] == '-')
        {
                if (str[i] == '-')
                        sign *= -1;
                i++;
        }
        while (str[i])
        {
                index = ft_index(str[i], base);
                res = res * size + index;
                i++;
        }
        return (res * sign);
}

char    *ft_allocate(int nb, char *base, int size, int count, char *res)
{
        int     i;

        i = 0;
        if (nb < 0)
        {
                res[i] = '-';
                nb *= -1;
        }
        while (nb)
        {
                i++;
                res[count - i] = base[nb % size];
                nb /= size;
        }
        res[count] = '\0';
        return (res);
}

char	*ft_itoa(int nb, char *base, int size)
{
	char	*str;
        int     count;
        int     tmp;

        count = 0;
        tmp = nb;
        if (tmp < 0)
        {
                tmp *= -1;
                count++;
        }
        while (tmp)
        {
                tmp /= size;
                count++;
        }
        if(!(str = (char *)malloc(sizeof(char) * count + 1)))
                return (NULL);
        return (ft_allocate(nb, base, size, count, str));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
        int     size;
	int	size2;
	int	nb;
	char	*res;

        size = ft_check(base_from);
	size2 = ft_check(base_to);
        if (size > 1 && size2 > 1)
	{
                nb = ft_atoi(nbr, base_from, size);
		res = ft_itoa(nb, base_to, size2);
                return (res);
	}
        return (NULL);
}

int     main(int ac, char **av)
{
        char    *a;

        if (ac == 4)
        {
                a = ft_convert_base(av[1], av[2], av[3]);
                if (!a)
                        printf("Error\n");
                else
                        printf("%s\n", a);
        }
        return (0);
}
