#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"
#include "lab_5.h"


int main_task2() {
    double op2; // для записи временных значений
    char input;
    double buffer = 0.0;
    int count = 0;
    double multiplier = 1.0;

    for (int i = 0; (input = getchar()) != '\0'; ++i) {
        switch (input) {
            case ' ':
                multiplier = 1.0;
                count = 0;
                buffer = 0;
                continue;
            case '0':
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
                if (count > 0)
                    buffer = pop() * 10 * multiplier + atof(&input)*pow(multiplier, count);
                else
                    buffer = buffer * 10 * multiplier + atof(&input)*pow(multiplier, count);
                ++count;
                push(buffer);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop(); // нужно тк мы из нижнего элемента в стеке будем вычитать верхний
                push(pop() - op2);
                break;
            case '/' :
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else {
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case '^': // возведение в степень
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case '%' : // целочисленное деление
                op2 = pop();
                if (op2 != 0.0)
                    push((int) (pop() / op2));
                else {
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case 's': // sin(x)
                push(sin(pop()));
                break;
            case 'c': // cos(x)
                push(cos(pop()));
                break;
            case '\n' :
                printf("\t%.8g\n", pop());
                break;
            case '.':
                count = 1;
                multiplier = 0.1;
                break;
            default:
                printf("error: unknown command %s\n", &input);
                return -1;
        }
    }
    return 0;
}