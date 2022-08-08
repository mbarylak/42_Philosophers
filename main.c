#include "philo.h"

int	init_mutex(t_input *in)
{
	int	i;

	i = 0;
	while (i < in->p_num)
	{
		if (pthread_mutex_init(&(in->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(in->msging), NULL))
		return (1);
	return (0);
}

void	init_philos(t_input *in)
{
	int	i;

	i = 0;
	while (i < in->p_num)
	{
		in->philo[i].id = i;
		in->philo[i].left_fork = i;
		in->philo[i].right_fork = (i + 1) % in->p_num;
		in->philo[i].last_meal = 0;
		in->philo[i].ate = 0;
		in->philo[i].in = in;
		i++;
	}
}

int	init(t_input *in, char **argv)
{
	in->p_num = mb_atoi(argv[1]);
	in->d_time = mb_atoi(argv[2]);
	in->e_time = mb_atoi(argv[3]);
	in->s_time = mb_atoi(argv[4]);
	in->death = 0;
	in->first_time = 0;
	in->all_ate = 0;
	if (in->p_num <= 0 || in->d_time < 0 || in->e_time < 0 \
		|| in->s_time < 0 || in->p_num > 300)
		return (1);
	if (argv[5])
	{
		in->e_num = mb_atoi(argv[5]);
		if (in->e_num <= 0)
			return (1);
	}
	else
		in->e_num = -1;
	if (init_mutex(in))
		return (2);
	init_philos(in);
	return (0);
}

int	main(int argc, char **argv)
{
	t_input	in;
	int		ret;

	if (argc != 5 && argc != 6)
		return (error_msg("Wrong number of arguments"));
	ret = init(&in, argv);
	if (ret == 1)
		return (error_msg("Wrong input"));
	else if (ret == 2)
		return (error_msg("Fatal error while creating mutex"));
	if (create_philo(&in))
		return (error_msg("Fatal error while creating threads"));
	return (0);
}
