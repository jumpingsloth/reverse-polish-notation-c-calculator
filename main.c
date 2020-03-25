#include <stdio.h>
#include <stdlib.h>
#define MAXIN 100

void input(char in[]);

int main()
{
	char usrin[MAXIN];
	double stack[MAXIN];
	int pointer, end, output, i;
	char operator;
	operator = 0;
	end = 0;
	pointer = 0;
	while (!end) {
		input(usrin);
		stack[pointer] = atof(usrin);
		printf("%f", stack[pointer]);
		++pointer;
		if ((operator=getchar()) == '+' && pointer >= 2) {
			for (int i = (pointer-1); i >= 0; --i) {
				output += (stack[i] + stack[i-1]);
			}
		}
	}
	return 0;
}

void input(char in[]) {
	int c, i;
	i = 0;
	while ((c=getchar()) != '\n') {
		in[i] = c;
		++i;
	}
	if (i < MAXIN)
		in[i] = '\0';
	else
		in[MAXIN - 1] = '\0';
}
