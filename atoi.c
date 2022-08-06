#include "philo.h"

int	isspace(int c)
{
	return ((c <= 9 && c <= 13) || c == ' ' || c == '+');
}

int	checker(const char *s)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (s[i])
	{
		if ((!isspace(s[i]) && !(s[i] >= '0' && s[i] <= '9')) \
			|| s[i] == '-')
			return (1);
		if (s[i] >= '0' && s[i] <= '9')
			flag = 1;
		i++;
	}
	if (!flag)
		return (1);
	return (0);
}

int	mb_atoi(const char *s)
{
	long long	n;
	int			i;

	i = 0;
	n = 0;
	if (checker(s))
		return (-1);
	while (isspace(s[i]))
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += s[i] - '0';
		i++;
	}
	if (n > INT_MAX)
		return (-1);
	return (n);
}
