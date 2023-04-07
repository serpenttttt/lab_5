#include <stdio.h>
#include <stdlib.h>

void insert_string(char *string) {
    char input;  // Переменная для считывания посимвольно
    for (int i = 0; (input = getchar()) != '\n'; ++i) {
        string = (char *) realloc(string, sizeof(char) * (i + 1));
        string[i] = input;
        string[i + 1] = '\0';
    }
}

void find_position_of_element_in_s1(char *s1, char *s2) {
    int position = -1;
    for (int i = 0; s1[i] != '\0'; ++i) {
        for (int j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                position = i;
                printf("position %d", i);
            }
        }
    }
    if (position < 0)
        puts("-1");
}