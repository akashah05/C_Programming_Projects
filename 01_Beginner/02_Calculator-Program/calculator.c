#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b == 0) return 0;
    return (float)a / b;
}

void showCalc(char operator, int numOne, int numTwo) {
    if (operator == '+') {
        printf("The Result of Adding %d + %d is: %d\n", numOne, numTwo, add(numOne, numTwo));
    } else if (operator == '-') {
        printf("The Result of Subtracting %d - %d is: %d\n", numOne, numTwo, subtract(numOne, numTwo));
    } else if (operator == '/') {
        printf("The Result of Dividing %d / %d is: %.1f\n", numOne, numTwo, divide(numOne, numTwo));
    } else if (operator == '*') {
        printf("The Result of Multiplying %d * %d is: %d\n", numOne, numTwo, multiply(numOne, numTwo));
    }
}


int main() {

    while (1) {
        char operator;

        printf("\nWhat Operation (+, -, *, /) you want to Do (e to exit): ");
        scanf(" %c", &operator);

        if (operator == 'e' || operator == 'E') break;

        if (operator != '+' && operator != '-' && operator != '*' && operator != '/') {
        printf("Invalid operator!\n");
        continue;
        }

        int numOne; int numTwo;
    
        printf("Enter First Number: \n");
        if (scanf("%d", &numOne) != 1) continue;

        printf("Enter Second Number: \n");
        if (scanf("%d", &numTwo));

        showCalc(operator, numOne, numTwo);
    }
    

    
    return 0;
}