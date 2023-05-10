#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    double items[MAX_SIZE];
} stack;

void push(stack *s, double c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
    s->items[++s->top] = c;
}

double pop(stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
    return s->items[s->top--];
}

int is_empty(stack *s) {
    return s->top == -1;
}

double peek(stack *s) {
    return s->items[s->top];
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix) {
    stack s;
    s.top = -1;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            i--;
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!is_empty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            pop(&s);
        } else if (infix[i] != ' ') {
            while (!is_empty(&s) && precedence(infix[i]) <= precedence(peek(&s))) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(&s, infix[i]);
        }
        i++;
    }

    while (!is_empty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }

    postfix[--j] = '\0';
}

double evaluate_postfix(char *postfix) {
    stack s;
    s.top = -1;

    int i = 0;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            double num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(&s, num);
        } else if (postfix[i] != ' ') {
            double num2 = pop(&s);
            double num1 = pop(&s);
            double result;

            switch (postfix[i]) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
            }

            push(&s, result);
        }
        i++;
    }
    return pop(&s);
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infix_to_postfix(infix, postfix);

    printf("Result: %.2lf\n", evaluate_postfix(postfix));

    return 0;
}