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
