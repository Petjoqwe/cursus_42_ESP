#include <unistd.h>

void	print_bit(unsigned char octet)
{
	int i = 7;
	while(i >= 0)
	{
		unsigned char bit = (octet >> i) & 1;
		bit  = bit + '0';
		write(1, &bit, 1);
		i--;
	}
}

int main()
{
	unsigned char bit = 255;
		print_bit(bit);
		write(1, "\n", 1);
		print_bit(bit);
		return 0;
}
