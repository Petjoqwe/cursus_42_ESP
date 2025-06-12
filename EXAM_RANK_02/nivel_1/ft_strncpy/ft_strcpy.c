#include <unistd.h>
#include <string.h>
#include <stdio.h>

char *ft_strcpy(char *dest, const char *src)
{
	 size_t i = 0;
	 while(src[i])
	 {
		dest[i] = src[i];
			i++;
	 }
	 	dest[i] = '\0';
               return dest;

}

int main()
{
	char *src = "hola";
	char dest[5];
	ft_strcpy(dest, src);
	printf("%s", dest);
	return(0);
}
