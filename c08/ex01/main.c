#include "ft_boolean.h"
#include <unistd.h>

int main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
	ft_putstr(EVEN_MSG);
	else
	ft_putstr(ODD_MSG);
	return (SUCCESS);
}
