#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_space(char	c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_valid(char c)
{
	if (c > '0' && c < '5')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_is_valid_input(char *str)
{
	int	count;

	count = 0;
	while(*str != '\0' && count != 16)
	{
		if (ft_valid(*str))
		{
			count++;
			str++;
		}
		else if (ft_space(*str))
		{
			str++;
		}
		else
			return (0);
	}
	if (count == 16 && *str == '\0')
		return (1);
	return (0);
}

char	*ft_triminputs(char *av)
{
	int		i;
	int		j;
	char	*inputs;

	i = 0;
	j = 0;
	inputs = malloc(16);
	while (av[i] != '\0')
	{
		if (av[i] >= '0' && av[i] <= '9')
		{
			inputs[j] = av[i];
			j++;
		}
		i++;
	}
	return (inputs);	
}

void	ft_answerscol(int i, char *inputs, char *outputs)
{
	int		count;
	int		fix;

	count = 0;
	fix = i;
	if (inputs[i] == '1')
	{
		outputs[i] = '4';
	}
	else if (inputs[i] == '4')
	{
		outputs[i] = '1';	
	}
	while (count < 3)
	{
		if (inputs[fix] == '1')
		{
			outputs[i + 4] = '3' - count;
		}
		else if (inputs[fix] == '4')
		{
			outputs[i + 4] = '2' + count;
		}
		i += 4;
		count++;
	}
}

void	ft_answersrow(int i, char *inputs, char *outputs)
{
	int		count;
	int		fix;
	int		j;

	count = 0;
	fix = i;
	j = (i - 8) * 4;
	if (inputs[i] == '1')
	{
		outputs[j] = '4';
	}
	else if (inputs[i] == '4')
	{
		outputs[j] = '1';	
	}
	while (count < 3)
	{
		if (inputs[fix] == '1')
		{
			outputs[j + 1] = '3' - count;
		}
		else if (inputs[fix] == '4')
		{
			outputs[j + 1] = '2' + count;
		}
		j++;
		i++;
		count++;
	}
}

void	ft_ifcol14(char *inputs, char *outputs)
{
	int		i;

	i = 0;
	while (i < 4)
		{
			if (inputs[i] == '1') 
			{
				if (inputs[i + 4] == '4')
				{
					ft_answerscol(i, inputs, outputs);
				}
			}
			if (inputs[i] == '4') 
			{
				if (inputs[i + 4] == '1')
				{
					ft_answerscol(i, inputs, outputs);
				}
			}
			i++;
		}
}

void	ft_ifrow14(char *inputs, char *outputs)
{
	int		i;

	i = 8;
	while (i < 12)
		{
			if (inputs[i] == '1') 
			{
				if (inputs[i + 4] == '4')
				{
					ft_answersrow(i, inputs, outputs);
				}
			}
			if (inputs[i] == '4') 
			{
				if (inputs[i + 4] == '1')
				{
					ft_answersrow(i, inputs, outputs);
				}
			}
			i++;
		}
}

void	ft_putchar(char *outputs)
{
	int	a;
	int i;
	int	j;
	char s;

	a = 4;
	i = 0;
	j = 0;
	while (i < a)
	{
		while (j < a)
		{
			s = outputs[i * a + j];
			write(1, &s, 1);
			if (j < 3)
			{
			 write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

int	main(int ac, char **av)
{
	char	*inputs;
	char	*outputs;

	if (ac == 2)
	{
		if (ft_is_valid_input(av[1]))
		{
			outputs = malloc(16);
			inputs = ft_triminputs(av[1]);
			ft_ifcol14(inputs, outputs);
			ft_ifrow14(inputs, outputs);
			ft_putchar(outputs);
			free(inputs);
			free(outputs);
		}
	}
}
