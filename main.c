#include <stdio.h>
#include <stdlib.h>
#define MAXIN 100
#define TRUE 1
#define FALSE 0
typedef unsigned char bool;

void input(char in[]);
void push(double);
double pop();
bool is_number(char item[]);
void add(void);
void printstack(void);


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
					// subtract();
					break;
				case '*':
					// multiply();
					break;
				case '.':
					end = TRUE;
					break;

				default:
					printf("Invalid input : %s", usrin);
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

double pop() {
	if (pointer > 0) {
		--pointer;
		return stack[pointer];
	} else {
		perror("Error: stack is empty");
	}
}

void add(void) {
	push(pop() + pop());
}

void printstack(void) {
	int i;
	for (i=0; i < pointer; ++i) {
		printf("\nstack at %d: %f", i, stack[i]);
	}
}
