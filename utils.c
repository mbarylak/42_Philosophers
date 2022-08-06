#include "philo.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	print_action(t_input *in, int id, const char *s)
{
	pthread_mutex_lock(&(in->msging));
	if (!in->death)
	{
		printf("%lli ms: ", get_time() - in->first_time);
		printf("philosopher %i ", id + 1);
		printf("%s\n", s);
	}
	pthread_mutex_unlock(&(in->msging));
}

void	pause_time(long long time, t_input *in)
{
	long long	i;

	i = get_time();
	while (!in->death)
	{
		if ((get_time() - i) >= time)
			break ;
		usleep(50);
	}
}
