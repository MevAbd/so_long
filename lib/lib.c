#include "../soo_loong.h"

int	ft_strlen_bis(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}
