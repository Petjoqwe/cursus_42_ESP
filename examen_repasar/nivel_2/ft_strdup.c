#include <stdlib.h>
//#include <stdio.h>

char *ft_strdup(const char *s)
{
	int i = 0;

	while(s[i])
	{
		i++;
	}
	char *res = malloc(i + 1);
	if(!res)
		return NULL;
	i = 0;

	while(s[i])
	{
		res[i] = s[i];
		i++;
	}

	res[i] = '\0';
	return res;
}

//int main()
//{
//	char *res = ft_strdup("hola");
//	printf("%s", res);
//	free(res);
//	return 0;
//}
