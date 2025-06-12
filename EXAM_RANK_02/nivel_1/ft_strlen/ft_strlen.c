#include <unistd.h>
#include <stdio.h>
int	ft_strlen(char *str)
{
	int s = 0;

	while(str[s])
	{
		s++;
	}
	return(s);
}

//int  main()
//{
//	char *buffer = "hola";
//	int a = ft_strlen(buffer);
//	printf("%d", a);
//	return(0);
//}
