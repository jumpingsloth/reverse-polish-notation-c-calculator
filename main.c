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

double stack[MAXIN];
int pointer;

int main()
{
	char usrin[MAXIN];
	int i;
	bool end = FALSE;
	pointer = 0;

	while (!end) {
		input(usrin);
		if (is_number(usrin)) {
			push(atof(usrin));
		} else {
			switch( usrin[0]) {
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
				case '.':
					end = TRUE;
					break;

				default:
					printf("Invalid input : %s\n", usrin);
			}
		}
		printstack();
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
	for (i=0; i < pointer; ++i) {
		printf("stack at %d: %f\n", i, stack[i]);
	}
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
	double first, last, out;
	int i;
	last = pop();
	first = pop();
	out = first;
	for (i=2; i <= last; ++i)
		out = out * first;
	push(out);
}

void squareroot(void) {
	push(sqrt(pop()));
}