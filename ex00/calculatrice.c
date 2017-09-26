#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 999999

void	cb_bzero(void *buff, int size)
{
	int	i;
	char	*tmp;

	i = -1;
	tmp = (char *)buff;
	while (++i < size)
		tmp[i] = '\0';
}

int	main(int ac, char **av)
{
	int	rand_value;
	int	nbr_coups;
	int	user_coup;
	int	ret;
	char	buff[BUFF_SIZE];

	srand(time(NULL));
	rand_value = rand() % 100;
	if (ac != 2 || ((nbr_coups = atoi(av[1])) == 0))
		return (1);
	while (nbr_coups > 0)
	{
		cb_bzero(buff, BUFF_SIZE);
		if ((ret = read(0, buff, BUFF_SIZE - 1)) == 0)
			return (0);
		user_coup = atoi(buff);
		if (user_coup > rand_value)
			printf("C'est moins\n");
		else if (user_coup < rand_value)
			printf("C'est plus\n");
		else
		{
			printf("C'est gagné !\n");
			nbr_coups = 0;
		}
		nbr_coups--;
	}
	if (nbr_coups == 0)
		printf("C'est perdu\n");
	return (0);
}
