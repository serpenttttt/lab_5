#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100
#define NUMBER '0'

int getop(char []);

int main_task2() {
    int type;
    double op2; // для записи временных значений
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s)); // atof переводит строку в число типа double
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
            default:
                printf("error: unknown command %s\n", s);
                return -1;
        }
    }
    return 0;
}





#define BUFSIZE 100
static char buf[BUFSIZE]; // буфер для ungetch
static int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) { // возвращает символ в поток ввода
    if (bufp >= BUFSIZE) {
        printf ("ungetch: too many characters\n");
        exit(333);
    } else {
        buf[bufp++] = c;
    }
}



int getop(char s[]) { // доставляет на обработку операнд/знак операции. Пропускает пробелы и тд. Может накапливать цифры = число
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}