#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_triminputs(char *av)
{
	int		i;
	char	*inputs;

	i = 0;
	inputs = malloc(16);
	while (i < 16)
	{
		inputs[i] = av[i * 2];
		i++;
	}
	return (inputs);	
}

void	ft_answerscol4321(int i, char *outputs)
{
	int 	max;

	max = i + 4;
	while (i < max)
	{
		outputs[i + 4] = '4';
		i++;
	}
}

void	ft_checkcol14(char *inputs, char *outputs)
{
	int		i;

	i = 0;
	while (i < 4)
		{
			if (inputs[i] == '1') 
			{
				if (inputs[i + 4] == '4')
				{
					ft_answerscol4321(i, outputs);
					printf("answer below column %d is 4321\n", i + 1);
				}
			}
			if (inputs[i] == '4') 
			{
				if (inputs[i + 4] == '1')
				{
					printf("answer below column %d is 1234\n", i + 1);
				}
			}
			i++;
		}
}

void	ft_checkrow14(char *inputs, char *outputs)
{
	(void)outputs;
	int		i;

	i = 8;
	while (i < 12)
		{
			if (inputs[i] == '1') 
			{
				if (inputs[i + 4] == '4')
				{
					printf("answer from left row %d is 4321\n", i + 1 - 8);
				}
			}
			if (inputs[i] == '4') 
			{
				if (inputs[i + 4] == '1')
				{
					printf("answer from left row %d is 1234\n", i + 1 - 8);
				}
			}
			i++;
		}
}

void	ft_putchar(char *outputs)
{
	int i;

	i = 0;
	while (i < 4)
	{
		write(1, &outputs, 1);
		write(1, " ", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	char	*inputs;
	char	*outputs;

	if (ac == 2)
	{
		outputs = malloc(16);
		inputs = ft_triminputs(av[1]);
		ft_checkcol14(inputs, outputs);
		ft_checkrow14(inputs, outputs);
		ft_putchar(outputs);
	}
}
