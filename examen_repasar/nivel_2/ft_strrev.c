#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while(str[i])
	{
		i++;
	}
	return i;
}

char    *ft_strrev(char *str)
{	
	int i = 0;
	int len = ft_strlen(str) - 1;
	char temp;
	while(i < len)
	{
	temp = str[len]; // le metemos el final a temp
	str[len] = str[i]; // str[len] ahora tiene el principio
	str[i] = temp; // le pasamos el final a str[i]
	
	i++;
	len--;	
	}
	return(str);
}

int main ()
{
	char str[] = "hola";
	printf("original: %s\n", str);
	printf("modificado: %s\n", ft_strrev(str));
	return 0;
}
