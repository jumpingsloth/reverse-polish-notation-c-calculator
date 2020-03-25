#include <stdio.h>
#define MAXIN 100

void input(char in);

int main()
{
	char in[100];
	input(in);
}

void input(char in) {
	int c, i;
	i = 0;
	while ((c=getchar()) != EOF) {
		in[i] = c;
		++i;
	}
	if (i < MAXIN)
		in[i] = '\0';
	else
		in[MAXIN - 1] = '\0';
}