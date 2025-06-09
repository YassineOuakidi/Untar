

#include "../inc/untar.h"

int get_nearest_mult(int n)
{
	int ans = 512;
	while(n>=ans)
		ans+=512;
	return ans;
}

char *ft_strdup(const char *src , size_t len)
{
	char *ans = malloc(len + 1);
	if(!ans)
		return NULL;

	size_t i = 0;
	while(i<len)
	{
		ans[i] = src[i];
		i++;
	}
	ans[i] = '\0';
	return ans;
}

int get_decimal(int octal)
{
	int ans = 0;
	int power = 1;
	while(octal!=0)
	{
		ans += (octal%10) * power;
		power *= 8;
		octal /=10;
	}
	return ans;
}

size_t ft_strlen(char *str)
{
	size_t 		i;
	
	i = 0;
	while(str[i])
		i++;
	return i;
}

char *get_header(int fd)
{
	char *header = malloc(512);
	ssize_t bytes_read = read(fd , header , 512);
	if(bytes_read<512)
	{
		free(header);
		return NULL;
	}

	int all_zeros = 1;
	for(int i = 0 ; i <512 ; i++){
		if(header[i]!='\0')
		{
			all_zeros = 0;
			break;
		}
	}

	if(all_zeros==1)
	{
		free(header);
		return NULL;
	}
	return header;
}

size_t get_last_pos(char *name)
{
	int 	i = ft_strlen(name) - 1;
	while(i>=0 && name[i]!='/')
		i--;
	return i;
}

char *get_dirname(char *name)
{
	size_t 		i;
	if(name[ft_strlen(name)-1]=='/')
		return name;
	char dirname[100];
	i = 0;
	size_t last_slash_pos = get_last_pos(name);
	while(i<=last_slash_pos)
	{
		dirname[i] = name[i];
		i++;
	}
	return ft_strdup(dirname , 100);
}


int get_mode_decimal(char *mode)
{
	int ans = 0;
	for(int i = 0 ; mode[i] ; i++)
		ans += ans * 8 + (mode[i] - '0');
	return ans;
}



