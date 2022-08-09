/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:25:54 by mbarylak          #+#    #+#             */
/*   Updated: 2022/08/09 20:57:40 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philo(t_input *in, t_philo *p)
{
	int	i;

	i = 0;
	while (i < in->p_num && !in->death && !in->all_ate)
	{
		pthread_join(p[i].philo_t, NULL);
		i++;
	}
	i = 0;
	while (i < in->p_num && !in->death && !in->all_ate)
	{
		pthread_mutex_destroy(&(in->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(in->eating));
	pthread_mutex_destroy(&(in->msging));
}

void	check_death(t_input *in, t_philo *p)
{
	int	i;

	i = -1;
	while (!in->all_ate)
	{
		while (++i < in->p_num && !in->death)
		{
			pthread_mutex_lock(&(in->eating));
			if ((get_time() - p[i].last_meal) > in->d_time)
			{
				print_action(in, p[i].id, "died");
				in->death = 1;
				break ;
			}
			pthread_mutex_unlock(&(in->eating));
			usleep(100);
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

int	one_philo(t_input *in)
{
	t_philo	*p;

	p = in->philo;
	in->first_time = get_time();
	if (pthread_create(&(p[0].philo_t), NULL, lone_r, &p[0]))
		return (1);
	pthread_join(p[0].philo_t, NULL);
	return (0);
}

int	create_philo(t_input *in)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = in->philo;
	in->first_time = get_time();
	if (in->p_num == 1)
		return (one_philo(in));
	while (i < in->p_num && !in->death && !in->all_ate)
	{
		if (pthread_create(&(p[i].philo_t), NULL, routine, &p[i]))
			return (1);
		p[i].last_meal = get_time();
		i++;
	}
	check_death(in, in->philo);
	kill_philo(in, p);
	return (0);
}
