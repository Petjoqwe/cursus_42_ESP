#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
	{
		int s = 0;

		while(s1[s] && s1[s] == s2[s])
			{
				s++;
			}
		return(s1[s] - s2[s]);
	}

//int main()
//{	int res = 0;
//       res = ft_strcmp("abc", "abd");
//       printf("%d", res);
//       return(0);

//}
