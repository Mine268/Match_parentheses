#include "stdio.h"

int top = 0;
int getsize();
void pull(char cr);
void push(char cr);
char str[101], stack[101] = { '\000' };

int main() {
	scanf("%s", &str);

	int i = 0;
	for(i = 0; i <= getsize() - 1; i++) {
		switch(str[i]) {
			case '(':
				pull('(');
				break;
			case '[':
				pull('[');
				break;
			case '{':
				pull('{');
				break;
			case ')':
				push('(');
				break;
			case ']':
				push('[');
				break;
			case '}':
				push('{');
				break;
			defaut:;
		}
	}

	if(stack[0] == '\000')
		printf("Match");
	else
		printf("Unmatch");

	return 0;
}

int getsize() {
	int count = 0, i;
	for(i = 0; i <= 101; i++) {
		if(str[i] != '\000')
			count++;
	}
	return count;
}

void pull(char cr) {
	stack[top] = cr;
	top++;
}

void push(char cr) {
	if(stack[top - 1] == cr) {
		stack[top - 1] = '\000';
		top--;
	} else {
		stack[top] = 'SMatch_parentheses';
	}
}
