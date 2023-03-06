#include <stdio.h>
#include <string.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define lenth 300
typedef enum { false, true } bool; // объявляем новый тип "bool" для более удобной реализации функции

bool treatment(char* stroke) { // функция проверки строки на соответсвие условяим задачи
    char str[lenth];
    strcpy(str, stroke);
    if ((strstr(str, ".") == NULL)) { // проверка на наличие символа конца строки
        printf(ANSI_COLOR_RED"Нет символа конца строки\n");
        return false;
    }
    strtok(str, ".");
    if (strlen(str) == 2 && str[0] == '.'){ // проверка на то, что строка не содержит ничего, кроме точки
        return true;
    }
    else{ // по ASCII-кодам проверям строку на наличие недопустимых символов
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 48 && str[i] <= 57) {
            } else if (str[i] >= 65 && str[i] <= 90) {
            } else if (str[i] >= 97 && str[i] <= 122) {
            } else if (str[i] == 32) {
            } else {
                printf(ANSI_COLOR_RED "В строке присутствуют недопустимые символы\n");
                return false;
            }
        }
    }
    return true; // строка соответствует условию
}
char * _last(char string[]) // вспомогательная функция выделения последнего слова в строке
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
void squeeze (char s1[], const char s2[]) { // вспомогательная функция, удаляющая все символы строки s2 из строкки s1
    int k, i, j;
    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        s1[j] = '\0';
    }
}
int main(){

    // ввод строки для обработки
    char str [lenth];
    printf("Введите исходную строку:\n");
    fgets(str, lenth, stdin);

    // вызываем функцию "treatment" для проверки строки на соответствие условию
    if (treatment(str) == false){
        return 0;
    }

    // строка соответсвтвует условию
    else {
        printf("\n");

        // объявление всех, необходимых для решения задачи, переменнных
        char new[lenth] = "";
        char counts[30] = "1234567890";
        char sep[10] = " ";
        char* last;
        char* istr;
        char str_copy[lenth];
        int wrd_count = 0;

        strcpy(str_copy, str); // копирование исходной строки
        strtok(str, ".");
        last = _last(str); // выделяем последнее слово с помощью функции "_last"
        istr = strtok(str, sep);
        while (istr != NULL){
            wrd_count ++;
            if (wrd_count>30){ // проверка на то, что в исходной строке допустимое число слов
                printf(ANSI_COLOR_RED "Превышено количество слов в строке\n");
                return 0;
            }
            if (strlen(istr) > 10) // проверка на то, что в каждос слове допсутимое число символов
            {
                printf(ANSI_COLOR_RED "Превышено количество символов в слове\n");
                return 0;
            }
            if (strcmp(istr, last) != 0) { // сравниваем текущее слово с последним
                strcat(new, sep);
                strcat(new, istr);
            }
            istr = strtok(NULL, sep);
        }
        // получили новую строку, в которой все слова отличаются от последнего

        istr = strtok(new, sep);
        while (istr != NULL) {
            for (int i = 0; i < strlen(istr); i++) {
                if (istr[i] >= 48 && istr[i] <= 57) { // в каждом слове новой строки ищем цифры
                    squeeze(istr, counts); // при помощи функции "squeeze" исключаем из слова все цифры
                    puts(istr);
                    // все выведенные на экран слова соответсвуют условию задачи
                }
            }
            istr = strtok(NULL, sep);
        }
        printf("Исходная строка: " ANSI_COLOR_GREEN "%s\n", str_copy); // выводим на экран копию исходной строки
        return 0;
    }
}