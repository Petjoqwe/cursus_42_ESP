#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;
	size_t j = 0;
	size_t match = 0;
	
	while(s[i])
	{
		j = 0;
		match = 0;
		while(accept[j])
		{
			if(s[i] == accept[j])
			{
				match = 1;
				break;
			}

			j++;
				
		}
		if(!match)
			break;
		i++;
	}
	return i;
}
int main()
{
	size_t result = ft_strspn("abcabc", "abc");
	printf("%zu", result);
	return 0;
}
