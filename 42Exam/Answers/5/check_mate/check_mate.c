#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;
	int k = 0;
	int e = 1;
	int b = 0;

	if(argc > 1)
	{
		argc--;
		while(argc > 0)
		{
			while(argv[argc][i])
			{
				if(argv[argc][i] == 'K')
					k = 1;
				if(argv[argc][i] == 'B')
					b = 1;
				if(argv[argc][i] == 'T' || (argv[argc][i] == 'P'))
					e = 0;
				i++;
			}
			i = 0;
			argc--;
		}
		if(k && e && b)
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
	return 0;
}