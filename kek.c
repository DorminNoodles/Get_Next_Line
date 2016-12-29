#include <string.h>
#include <stdio.h>

int		main()
{
	char a[1024];
	int i = -1;

	memset(a, 'f', 1024);
	while (++i < 384)
		write(1, a, 1024);
}
