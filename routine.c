#include "philo.h"

void	philo_eat(t_philo *p)
{
	t_input	*in;

	in = p->in;
	pthread_mutex_lock(&(in->forks[p->left_fork]));
	print_action(in, p->id, "has taken left fork");
	pthread_mutex_lock(&(in->forks[p->right_fork]));
	print_action(in, p->id, "has taken right fork");
	print_action(in, p->id, "is eating");
	p->last_meal = get_time();
	pause_time(in->e_time, in);
	pthread_mutex_unlock(&(in->forks[p->left_fork]));
	pthread_mutex_unlock(&(in->forks[p->right_fork]));
}

void	*routine(void *p)
{
	t_philo	*philo;
	t_input	*in;

	philo = (t_philo *)p;
	in = philo->in;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (!in->death)
	{
		philo_eat(philo);
		print_action(in, philo->id, "is sleeping");
		pause_time(in->s_time, in);
		print_action(in, philo->id, "is thinking");
	}
	return (NULL);
}
