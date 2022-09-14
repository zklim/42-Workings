#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (!(*s <= 32))
	{
		i++;
		s++;
	}
	return (i);
}

int	word_count(char *s)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(s[i] <= 32))
			if (((s[i - 1] >= 9 && s[i - 1] <= 13) || s[i - 1] == 32 || s[i - 1] == 0))
				count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int	i;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (!(*s <= 32))
	{
		res[i] = *s;
		s++;
		i++;
	}
	return (res);
}

char	**ft_split(char *s)
{
	char	**str;
	int	word;
	int	i;
	int	j;

	i = 0;
	j = 0;
	word = word_count(s);
	if (!(str = (char **)malloc(sizeof(char*) * word + 1)))
		return (NULL);
	while (s[i])
	{
		if (!(s[i] <= 32))
			if (((s[i - 1] >= 9 && s[i - 1] <= 13 )|| s[i - 1] == 32 || s[i - 1] == 0))
			{
				str[j] = ft_strdup(&s[i]);
					while (!str[j])
						str[j] = ft_strdup(&s[i]);
				j++;
			}
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	main(int ac, char **av)
{
	char 	**b;
	int	i;

	if (ac == 2)
		b = ft_split(av[1]);
	for (i = 0; b[i]; i++)
		printf("%s\n", b[i]);
}
