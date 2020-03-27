#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXIN 100
#define TRUE 1
#define FALSE 0
typedef unsigned char bool;

void input(char in[]);
void push(double);
double pop(void);
bool is_number(char item[]);
void add(void);
void printstack(void);
void multiply(void);
void subtract(void);
void divide(void);
void power(void);
void squareroot(void);
void clearstack(void);
void help(void);
void handle(char in[]);
void const_pi(void);
void const_e(void);

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

void add(void) {
	push(pop() + pop());
}

void printstack(void) {
	int i;
	printf("\n");
	for (i=0; i < pointer; ++i) {
		printf("%d:\t%f\n", i, stack[i]);
	}
	printf("\n");
}

void multiply(void) {
	push(pop() * pop());
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

void squareroot(void) {
	push(sqrt(pop()));
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
	printf("'+':\tadd\n'-':\tsubtract\n'*':\tmultiply\n'/':\tdivide\n'p':\tconstant pi\n'e':\tconstant e\n");
	printf("'^':\tpower\n'r':\tsquare root\n\n'!':\tclear stack\n'?':\thelp\n'.':\tquit\n");
}

void handle(char in[]) {

	if (is_number(in)) {
		push(atof(in));
	} else {
		switch( in[0]) {
			case '+':
				add();
				break;
			case '-':
				subtract();
				break;
			case '*':
				multiply();
				break;
			case '/':
				divide();
				break;
			case '^':
				power();
				break;
			case 'r':
				squareroot();
				break;
			case 'p':
				const_pi();
				break;
			case 'e':
				const_e();
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
	printstack();
}

void const_pi(void) {
	push(M_PI);
}

void const_e() {
	push(M_E);
}
