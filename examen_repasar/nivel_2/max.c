#include <stdio.h>


int max(int* tab, unsigned int len)
	{
		int max; 

		max = tab[0];
			
		int i = 1;

		if(len == 0)
			return(0);

		while(i < len)
		{
			if(tab[i] > max)
				max = tab[i];
			i++;
		}
		return max;
	}

int main ()
{
		int arr[] = {5, 3, 65, 9};
		int result = max(arr, 4);
		printf("%d", result);
		return (0);
}

