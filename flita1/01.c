#include <stdio.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>


int main(void)
{ 
    SetConsoleOutputCP(1251);
    int summ = 0;
    int m, k, n, check; int j = 0; 
    int conversion(char str[]); int inp(char elem[]); int inpu();


    n = inpu(); // ввод кол-ва элементов с проверкой
    int dec[n]; // создаем массив для вывода десятичных чисел
    char elem[n][25]; // создаем двумерный массив для вывода массива строк
    
    while (j <= n - 1) {
        printf("Введите двоичный код: ");
        scanf("%s", elem[j]);
        check = inp(elem[j]);
        while (check != 1) {
            printf("Введите еще раз: ");
            scanf("%s", elem[j]);
            check = inp(elem[j]);
        }
        summ += conversion(elem[j]);
        dec[j] = summ;
        summ = 0;
        j++;
    }
    for (int i = 0;i <= n - 1;i++) { // вывод двоичных чисел
        printf("%s\t", elem[i]);
    }
    printf("\n");
    for (int i = 0; i <= n - 1; i++) {
        printf("%d\t", dec[i]);
    }
    printf("\n");
    printf("Нажмите любую клавишу для завершения...");
    getch();
}
int conversion(char str[]) {
        int m_degree; int res = 0; int num = 0; int i;
        m_degree = strlen(str) - 1;
        for (int i = 0; str[m_degree - i] != '\0'; i++) { // перевод двочиной в десятчиную
            if (str[i] == '1')
                num = 1;
            else
                num = 0;
            num = num * pow(2, m_degree - i);
            res += num;
        }
        return res;
}
int inp(char elem[]) {
    for (int i = 0; i <= strlen(elem) - 1 ;i++) {
        if (elem[i] != '0' && elem[i] != '1') {
            printf("Ошибка\n");
            return 0;
        }
    }
    return 1;
}
int inpu() {
    int flag = 0; char s[5];
    printf("Введите количество элементов: ");
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        for(int j = 48; j < 57; j++) {
            if (s[i] == j) {
                flag = 1; // если число
                break;
            }   
        }
    }
    if (flag == 1)
        return atoi(s);
    else { 
    printf("Ошибка!\n"); // если не число
    inpu();
    }
}




