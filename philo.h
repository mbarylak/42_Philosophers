#ifndef	PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	pthread_t		philo_t;
	struct s_input	*in;
}	t_philo;

typedef struct	s_input
{
	int				p_num;
	int				d_time;
	int				e_time;
	int				s_time;
	int				e_num;
	long long		first_time;
	int				death;
	t_philo			philo[300];
	pthread_mutex_t	forks[300];
	pthread_mutex_t	msging;
}	t_input;

/**		CREATE PHILO	**/

int			create_philo(t_input *in);

/**		ROUTINE		**/

void		*routine(void *p);

/**		UTILS		**/

int			mb_atoi(const char *s);
long long	get_time(void);
void		print_action(t_input *in, int id, const char *s);
void		pause_time(long long time, t_input *in);

/**		ERROR		**/

int			error_msg(const char *s);

#endif
