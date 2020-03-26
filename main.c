#include <stdio.h>
#include <stdlib.h>
#define MAXIN 100
#define TRUE 1
#define FALSE 0
void input(char in[]);
/*char get_operator(void);*/

int main()
{
	char usrin[MAXIN];
	double stack[MAXIN];
	int pointer, end, i;
	double output;
	output = 0;
	end = FALSE;
	pointer = 0;
	while (!end) {
		input(usrin);
		if (pointer >= 1 && usrin[0] == '+') {
			for (i=0; i <= (pointer-1) ; ++i) {
				printf("\nstack at %d: %f", i, stack[i]);
			}
			stack[pointer-2] = (stack[pointer-1] + stack[pointer-2]);
			stack[pointer-1] = 0;
			printf("\n\noutput: %f\n", stack[pointer-2]);
		} else if (usrin[0] == '.') {
			end = TRUE;
		} else {
			stack[pointer] = atof(usrin);
			printf("%f\n", stack[pointer]);
			++pointer;
		}
	}
	return 0;
}

void input(char in[]) {
	int c, i;
	i = 0;
	while ((c=getchar()) != '\n') {
		/*if (c=='+' || c== '-' || c== '*' || c=='/')
			return c;*/

		in[i] = c;
		++i;
	}
	if (i < MAXIN)
		in[i] = '\0';
	else
		in[MAXIN - 1] = '\0';
}

/*char get_operator(void) {
	int i;
	char operator, c;
	while ((c=getchar()) != '\n' && (c=='+' || c== '-' || c== '*' || c=='/')) {
		operator = c;
	}
	return operator;
}*/