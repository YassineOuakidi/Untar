#include "../inc/untar.h"


void write_to_file(int dest , struct HEADER header , int src)
{
	int size = get_decimal(atoi(header.size));

	char *text = malloc(size);
	read( src , text , size);
	
	write(dest , text , size);
	free(text);
	
	int nearest_multiple = get_nearest_mult(size);
	char *offset_text = malloc(nearest_multiple - size);
	
	read(src , offset_text , nearest_multiple - size);
	free(offset_text);
}


void write_changes(struct HEADER header , int fd)
{
	printf("%s\n" , get_dirname(header.name)); 
	if(mkdir(get_dirname(header.name) , 0755 ) == -1 && errno != EEXIST)
	{
		not_done = 0;
		write(STDERR_FILENO , "Error: Something went wrong creating directory\n", 47);
		return;
	}
	int fd2 = open(header.name , O_CREAT | O_WRONLY , get_decimal(atoi(header.mode)));
	if(fd2 == -1)
		return ;
	write_to_file(fd2 , header , fd);
	close(fd2);
}


void process(int fd)
{
	while(not_done == 1)
	{ 
		struct HEADER header_struct;
		
		char *header = get_header(fd);
		if(header==NULL)
			break;
		fflush(stdout);
		make_header_struct( &header_struct , header);
	
		write_changes(header_struct , fd);
	}
}
