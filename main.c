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
void printstack_sci(void);
void subtract(void);
void divide(void);
void power(void);
void clearstack(void);
void help(void);
void handle(char in[]);
void printvar(void);
void clearvar(void);
void faculty(void);

double stack[MAXIN];
double variables[3];
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
	if (item[0] == '-' && item[1]>='0' && item[1]<='9') {
		return TRUE;
	} else if (item[0]>='0' && item[0]<='9') {
		return TRUE;
	} else {
		return FALSE;
	}
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

void printstack_sci(void) {
	int i;
	printf("\n");
	for (i=0; i < pointer; ++i) {
		printf("%d:\t%E\n", i, stack[i]);
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
	for (i=0; i<MAXIN; ++i) {
		stack[i] = 0;
	}
	pointer = 0;
}

void printvar(void) {
	printf("\nVariables:\n");
	printf("a:\t%f\n", variables[0]);
	printf("b:\t%f\n", variables[1]);
	printf("c:\t%f\n", variables[2]);
}

void clearvar(void) {
	int i;
	for (i=0; i<=2; ++i) {
		variables[i] = 0;
	}
}

void faculty(void) {
	int i, in;
	long out;
	out = 1;
	in = (int)pop();
	if (in < 0) {
		printf("Error! Factorial of a negative number doesn't exist.");
	} else {
		for (i = i; i <= in; ++i) {
			out *= i;
		}
		push((double)out);
	}
}

void help(void) {
	printf("\nOperators:\n");
	printf("'+':\tadd\n'-':\tsubtract\n'*':\tmultiply\n'/':\tdivide\n'pi':\tconstant pi\n'e':\tconstant e\n");
	printf("'^':\tpower\n'r':\tsquare root\n'sin':\tsinus\n'cos':\tcosinus\n'log':\tlogarithm\n\n");
	printf("'->a/b/c':\tassign variable a/b/c\n'a/b/c':\tadd variable to stack\n'var':\tprint variables\n'!var':\tclear variables\n\n");
	printf("'c->f/f->c':\tconvert celsius/fahrenheit\n\n");
	printf("Options:\n");
	printf("'-o'\topen rpncc with given parameters\n\n");
	printf("Commands:\n");
	printf("'dup':\tduplicate last item on stack\n'sci':\tprint stack in scientific notation\n'!':\tclear stack\n'?':\thelp\n'.':\tquit\n");
}

void handle(char in[]) {
	bool print = TRUE;

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
		} else if (strcmp(in, "f->c") == 0) {
			push((pop() - 32) * 5/9);
		} else if (strcmp(in, "c->f") == 0) {
			push((pop() * 9/5) + 32);
		} else if (strcmp(in, "dup") == 0) {
			push(top());
		} else if (strcmp(in, "->a") == 0) {
			variables[0] = pop();
			printvar();
		} else if (strcmp(in, "->b") == 0) {
			variables[1] = pop();
			printvar();
		} else if (strcmp(in, "->c") == 0) {
			variables[2] = pop();
			printvar();
		} else if (strcmp(in, "var") == 0) {
			printvar();
		} else if (strcmp(in, "!var") == 0) {
			clearvar();
			printf("Ok, clear variables\n");
		} else if (strcmp(in, "fac") == 0) {
			faculty();
		} else if (strcmp(in, "sci") == 0) {
			printstack_sci();
			print = FALSE;
		} else if (strlen(in) < 2) {
			switch (in[0]) {
				case 'a':
					push(variables[0]);
					break;
				case 'b':
					push(variables[1]);
					break;
				case 'c':
					push(variables[2]);
					break;
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
		} else {
			printf("Invalid input\n");
		}
	}
	if (print==TRUE) {
		printstack();
	}

}
