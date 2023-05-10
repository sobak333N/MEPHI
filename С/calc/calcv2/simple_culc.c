#include <stdio.h>

int main()
{
    double num1;
    double num2;
    double result;
    char operation;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("Enter the second number: ");
    scanf("%lf", &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operation);

    if (operation == '+')
    {
        result = num1 + num2;
        printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
    }
    else if (operation == '-')
    {
        result = num1 - num2;
        printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
    }
    else if (operation == '*')
    {
        result = num1 * num2;
        printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
    }
    else if (operation == '/')
    {
        if (num2 != 0)
        {
            result = num1 / num2;
            printf("%.2lf / %.2lf = %.2lf\n", num1, num2, result);
        }
        else
        {
            printf("Error: Cannot divide by zero.\n");
        }
    }
    else
    {
        printf("Error: Invalid operator.\n");
    }

    return 0;
}