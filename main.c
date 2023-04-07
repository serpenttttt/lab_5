#include <stdio.h>
#include <malloc.h>
#include "lab_5.h"
#include "calc.h"

int main() {
    puts("Task1");
    char *s1, *s2; // указатель на массив
    s1 = (char *) malloc(sizeof(char) * 1);
    s2 = (char *) malloc(sizeof(char) * 1);
    puts("Input s1.");
    insert_string(s1);
    puts("Input s2.");
    insert_string(s2);
    find_position_of_element_in_s1(s1, s2);

    puts("Task2");
    return main_task2();
}
