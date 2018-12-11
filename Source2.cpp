// analog funkcii "atoi"
// "1234" -> 1234 insigned int
// "+1234abc56" -> 1234 int

#include <stdio.h>
#include <string.h>
#define N 256

int main()
{
	char str[N];
	int i = 0;
	int value = 0;
	int count = 0;

	printf("Enter a string: ");
	fgets(str, N, stdin);
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';

	char sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[0] == '+')
		i++;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9' && count<9)
		{
			value = value * 10 + (str[i] - '0');
			count++;
		}
		else
			break;
		i++;
	}

	printf("Yor string -> %d\n", value*=sign);
	
	return 0;
}