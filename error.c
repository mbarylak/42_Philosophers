/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarylak <mbarylak@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:25:40 by mbarylak          #+#    #+#             */
/*   Updated: 2022/08/09 19:25:45 by mbarylak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(2, "Error: ", 7);
	write(2, s, len);
	write(2, "\n", 1);
	return (1);
}
