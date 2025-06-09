

#include "../inc/untar.h"

char *get_name(char *header)
{
	return ft_strdup(header + NAME_OFFSET , 100);
}

char *get_mode(char *header)
{
	return ft_strdup(header + MODE_OFFSET , 8);
}

char *get_uid(char *header)
{
	return ft_strdup(header + UID_OFFSET , 8);
}

char *get_gid(char *header)
{
	return ft_strdup(header + GID_OFFSET , 8);
}
char *get_size(char *header)
{
	return ft_strdup(header + SIZE_OFFSET , 12);
}
char *get_mtime(char *header)
{
    return ft_strdup(header + MTIME_OFFSET, 12);
}

char *get_chksum(char *header)
{
    return ft_strdup(header + CHKSUM_OFFSET, 8);
}

char get_typeflag(char *header)
{
    return header[TYPEFLAG_OFFSET];
}

char *get_linkname(char *header)
{
    return ft_strdup(header + LINKNAME_OFFSET, 100);
}

char *get_magic(char *header)
{
    return ft_strdup(header + MAGIC_OFFSET, 6);
}

char *get_uname(char *header)
{
    return ft_strdup(header + UNAME_OFFSET, 32);
}

char *get_gname(char *header)
{
    return ft_strdup(header + GNAME_OFFSET, 32);
}

char *get_devmajor(char *header)
{
    return ft_strdup(header + DEVMAJOR_OFFSET, 8);
}

char *get_devminor(char *header)
{
    return ft_strdup(header + DEVMINOR_OFFSET, 8);
}

char *get_prefix(char *header)
{
    return ft_strdup(header + PREFIX_OFFSET, 155);
}

void make_header_struct(struct HEADER* header_struct , char *header)
{
	struct HEADER tmp = {
		.name = get_name(header),
		.mode = get_mode(header),
		.uid = get_uid(header),
		.gid = get_gid(header),
		.size = get_size(header),
		.mtime = get_mtime(header),
		.chksum = get_chksum(header),
		.typeflag = get_typeflag(header),
		.linkname = get_linkname(header),
		.magic = get_magic(header),
		.uname = get_uname(header),
		.gname = get_gname(header),
		.devmajor = get_devmajor(header),
		.devminor = get_devminor(header),
		.prefix = get_prefix(header),
	};
	
	*header_struct = tmp;
	
	
}
