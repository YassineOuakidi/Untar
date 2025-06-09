

#include "./inc/untar.h"


int not_done = 1;

int main(int argc , char **argv , char **envp)
{
	if(argc != 2)
	{
		write( STDERR_FILENO , "Error: Usage ./untar <filename>\n" , 32);
		return 1;
	}
	
	int fd = open(argv[1] , O_RDONLY);	
	
	if(fd == -1)
	{
		write( STDERR_FILENO , "Error: No such file\n" , 20);
		return 1;
	}
	process(fd);
	close(fd);
}


