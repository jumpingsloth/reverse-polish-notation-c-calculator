#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXIN 100
#define TRUE 1
#define FALSE 0
typedef unsigned char bool;

void input(char in[]);
void push(double);
double pop(void);
double top(void);
bool is_number(char item[]);
void printstack(void);
void subtract(void);
void divide(void);
void power(void);
void clearstack(void);
void help(void);
void handle(char in[]);

double stack[MAXIN];
int pointer = 0;
bool end = FALSE;

int main(int argc, char **argv)
{
	char usrin[MAXIN];
	int j;

	if (argc < 2) {
		printf("\nEnter your calculation\n");
		while (!end) {
			input(usrin);
			handle(usrin);
		}
	} else if (strcmp(argv[1], "-o") == 0) {
		for (j=2; j < argc; ++j) {
			handle(argv[j]);
		}
		printf("\nEnter your calculation\n");
		while (!end) {
			input(usrin);
			handle(usrin);
		}
	} else {
		for (j=1; j < argc; ++j) {
			handle(argv[j]);
		}
	}
	return 0;
}

bool is_number(char item[]) {
	return item[0]>='0' && item[0]<='9';
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

void push(double number) {
	stack[pointer] = number;
	++pointer;
}

double pop(void) {
	if (pointer > 0) {
		--pointer;
		return stack[pointer];
	} else {
		perror("Error: stack is empty");
	}
	return 0;
}

double top(void) {
	if (pointer > 0) {
		return stack[pointer - 1];
	} else {
		perror("Error: stack is empty");
	}
	return 0;
}

void printstack(void) {
	int i;
	printf("\n");
	for (i=0; i < pointer; ++i) {
		printf("%d:\t%f\n", i, stack[i]);
	}
	printf("\n");
}

void subtract(void) {
	double first, last;
	last = pop();
	first = pop();
	push(first - last);
}

void divide(void) {
	double first, last;
	last = pop();
	first = pop();
	push(first / last);
}

void power(void) {
	double first, last;
	last = pop();
	first = pop();
	push(pow(first, last));
}

void clearstack(void) {
	int i;
	for (i=0; i<=MAXIN; ++i) {
		stack[i] = 0;
	}
	pointer = 0;
}

void help(void) {
	printf("\nCommands:\n");
	printf("'+':\tadd\n'-':\tsubtract\n'*':\tmultiply\n'/':\tdivide\n'pi':\tconstant pi\n'e':\tconstant e\n");
	printf("'^':\tpower\n'r':\tsquare root\n'sin':\tsinus\n'cos':\tcosinus\n\n'dup':\tduplicate last item on stack\n'!':"\
		"\tclear stack\n'?':\thelp\n'.':\tquit\n");
}

void handle(char in[]) {

	if (is_number(in)) {
		push(atof(in));
	} else {
		if (strcmp(in, "pi") == 0) {
			push(M_PI);
		} else if (strcmp(in, "sin") == 0) {
			push(sin(pop()));
		} else if (strcmp(in, "cos") == 0) {
			push(cos(pop()));
		} else if (strcmp(in, "log") == 0) {
			push(log(pop()));
		} else if (strcmp(in, "dup") == 0) {
			push(top());
		} else {
			switch (in[0]) {
				case '+':
					push(pop() + pop());
					break;
				case '-':
					subtract();
					break;
				case '*':
					push(pop() * pop());
					break;
				case '/':
					divide();
					break;
				case '^':
					power();
					break;
				case 'r':
					push(sqrt(pop()));
					break;
				case 'e':
					push(M_E);
					break;
				case '!':
					clearstack();
					printf("Ok, clear stack\n");
					break;
				case '?':
					help();
					break;
				case '.':
					end = TRUE;
					printf("Ok, quit\n");
					break;

				default:
					printf("Invalid input : %s\n", in);
			}
		}
	}
	printstack();
}

