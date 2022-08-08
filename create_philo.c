#include "philo.h"

void	kill_philo(t_input *in, t_philo *p)
{
	int	i;

	i = 0;
	while (i < in->p_num)
	{
		pthread_join(p[i].philo_t, NULL);
		i++;
	}
	i = 0;
	while (i < in->p_num)
	{
		pthread_mutex_destroy(&(in->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(in->msging));
}

void	check_death(t_input *in, t_philo *p)
{
	int	i;

	while (!in->all_ate)
	{
		i = 0;
		while (i < in->p_num && !in->death)
		{
			if ((get_time() - p[i].last_meal) > in->d_time)
			{
				print_action(in, p[i].id, "died");
				in->death = 1;
				break ;
			}
			usleep(100);
			i++;
		}
		if (in->death)
			break ;
		i = 0;
		while (in->e_num != -1 && p[i].ate >= in->e_num && i < in->p_num)
			i++;
		if (i == in->p_num)
			in->all_ate = 1;
	}
}

int	create_philo(t_input *in)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = in->philo;
	in->first_time = get_time();
	while (i < in->p_num)
	{
		if (pthread_create(&(p[i].philo_t), NULL, routine, &p[i]))
			return (1);
		p[i].last_meal = get_time();
		i++;
	}
	check_death(in, p);
	kill_philo(in, p);
	return (0);
}
