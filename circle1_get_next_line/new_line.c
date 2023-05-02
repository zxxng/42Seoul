#include "get_next_line.h"
#include <stdio.h>
int	check_new_line(char *buf)
{
	int	idx;

	idx = 0;
	if (buf)
	{
		while (buf[idx])
		{
			if (buf[idx] == '\n')
				return (idx + 1);
			idx++;
		}
	}
	return (0);
}

char	*ft_read_line(int fd, char *backup)
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	read_size;

	buff[0] = '\0';
	while (!check_new_line(buff))
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == 0)
			return (backup);
		if (read_size < 0)
		{
			if (backup)
				free(backup);
			return (NULL);
		}
		buff[read_size] = '\0';
		if (!backup)
			backup = ft_strdup(buff);
		else
			backup = ft_strjoin(backup, buff);
	}
	return (backup);
}

char	*ft_get_line(char **str)
{
	char	*ret_line;
	int		l;
	int		i;
	int		slen;

	slen = ft_strlen(*str);
	i = 0;
	l = check_new_line(*str);
	ret_line = (char *)malloc(sizeof(char) * (l +1));
	if (!ret_line)
		return (NULL);
	while (i < l)
	{
		ret_line[i] = *(*str + i);
		i++;
	}
	ret_line[i] = '\0';
	ft_memmove(*str, *str + l, slen - l);
	(*str)[slen - l] = '\0';
	return (ret_line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*ret_line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = ft_read_line(fd, backup);
	printf("%s\n", backup);
	if (!backup)
		return (NULL);
	if (!check_new_line(backup))
	{
		if ((*backup))
			ret_line = ft_strdup(backup);
		else
			ret_line = NULL;
		free(backup);
		backup = NULL;
		return (ret_line);
	}
	ret_line = ft_get_line(&backup);
	if (!ret_line)
		free(backup);
	return (ret_line);
}

// #include <fcntl.h>
// #include <stdio.h>

//int	main(void)
//{
//  int fd;
//  //atest.txt 를 읽음
//  //fd = open("./atest.txt", O_RDONLY);
//  //fd= open("./1chartest.txt",O_RDONLY);
// //fd= open("./newline.txt",O_RDONLY);
// fd= open("./41_with_nl",O_RDONLY);
//  char *result ;
//  int i =0;
//  while (1)
//  {
//	  result = get_next_line(fd);
//	  if (!result)
//	  {
//			printf("malloc no\n");
//			return (0);
//	  }
//	  printf("\n------first:%d------\n",i);
//	  printf("%s", result);
//	//   printf("%p\n",result);
//	  //free(result);
//	  printf("-----end : %d----\n",i);
//	  i++;
//  }
//  return (0);
//}
/*read를 실패한다.
*/
//
