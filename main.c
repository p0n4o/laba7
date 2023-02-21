#include <stdio.h>
#include <string.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define lenth 300
int treatment(char* stroke) {
    char str[lenth];
    strcpy(str, stroke);
    if ((strstr(str, ".") == NULL)) {
        printf(ANSI_COLOR_RED"Нет символа конца строки\n");
        return 0;
    }
    strtok(str, ".");
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 48 && str[i] <= 57) {
        } else if (str[i] >= 65 && str[i] <= 90) {
        } else if (str[i] >= 97 && str[i] <= 122) {
        } else if (str[i] == 32) {
        } else {
            printf(ANSI_COLOR_RED "В строке присутствуют недопустимые символы\n");
            return 0;
        }
    }
    return 1;
}
char * _last(char string[])
{
    char * pk;
    for (pk = string;*pk; pk++);
    while (*(--pk) == ' ' && pk >= string);
    if (pk < string)
        return NULL;
    while (pk != string && *(--pk) != ' ');
    if (pk == string) return string;
    return pk+1;
}
void squeeze (char s1[], char s2[]) {
    int k, i, j;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}
int main(){
    char str [lenth];
    printf("Введите исходную строку:\n");
    fgets(str, lenth, stdin);
    if (treatment(str) == 0){
        return 0;
    }

    else {
        char new[lenth] = "";
        char counts[30] = "1234567890";
        char* last;
        char* istr;
        char str_copy[lenth];
        strcpy(str_copy, str);
        strtok(str, ".");
        char sep[10] = " ";
        last = _last(str);
        istr = strtok(str, sep);
        while (istr != NULL) {
            if (strcmp(istr, last) != NULL) {
                strcat(new, sep);
                strcat(new, istr);
            }
            istr = strtok(NULL, sep);
        }
        istr = strtok(new, sep);
        while (istr != NULL) {
            for (int i = 0; i < strlen(istr); i++) {
                if (istr[i] == '0' || istr[i] == '1' || istr[i] == '2' || istr[i] == '3' || istr[i] == '4' || istr[i] == '5' || istr[i] == '6' || istr[i] == '7' || istr[i] == '8' || istr[i] == '9') {
                    squeeze(istr, counts);
                    puts(istr);
                    printf("\n");
                }
            }
            istr = strtok(NULL, sep);
        }
        printf("Исходная строка: " ANSI_COLOR_GREEN "%s\n", str_copy);
        return 0;
    }
}