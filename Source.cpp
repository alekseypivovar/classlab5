#include <stdio.h>
#include <string.h>
#define N 256

int main()
{
	char str[N];
	int i = 0, count = 0;
	int state = 0; //0 - вне слова, 1-внутри слова
	printf("Enter a string: ");
	fgets(str, N, stdin);
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';

	while (str[i])
	{
		if (str[i] != ' ' && state == 0)
		{
			state = 1;
			count++;
		}
		else if (str[i] == ' ' && state == 1)
			state = 0;
		i++;
	}
	printf("There are %d words in your string\n", count);

	return 0;
}