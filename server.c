#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t server_pid;

	server_pid = getpid();
	ft_printf("%d",server_pid);
	while (1)
	{
		usleep(5);
	}
	return (0);
}