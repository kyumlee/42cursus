#include <unistd.h>

int    check_duplicate(char ch, char *s, int index)
{
    int i = 0;

    while (i < index)
    {
        if (ch == s[i])
            return (1);
        i++;
    }
    return (0);
}

int     main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[1][i])
	{
		if (check_duplicate(argv[1][i], argv[1], i) == 0)
		{
			j = 0;
			while(argv[2][j])
			{
				if (argv[2][j] == argv[1][i])
				{
					write(1, &argv[1][i], 1);
					break ;
				}
				j++;
			}
		}
		i++;
	}
    write(1, "\n", 1);
    return (0);
}
