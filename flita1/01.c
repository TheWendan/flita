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


    n = inpu(); // ���� ���-�� ��������� � ���������
    int dec[n]; // ������� ������ ��� ������ ���������� �����
    char elem[n][25]; // ������� ��������� ������ ��� ������ ������� �����
    
    while (j <= n - 1) {
        printf("������� �������� ���: ");
        scanf("%s", elem[j]);
        check = inp(elem[j]);
        while (check != 1) {
            printf("������� ��� ���: ");
            scanf("%s", elem[j]);
            check = inp(elem[j]);
        }
        summ += conversion(elem[j]);
        dec[j] = summ;
        summ = 0;
        j++;
    }
    for (int i = 0;i <= n - 1;i++) { // ����� �������� �����
        printf("%s\t", elem[i]);
    }
    printf("\n");
    for (int i = 0; i <= n - 1; i++) {
        printf("%d\t", dec[i]);
    }
    printf("\n");
    printf("������� ����� ������� ��� ����������...");
    getch();
}
int conversion(char str[]) {
        int m_degree; int res = 0; int num = 0; int i;
        m_degree = strlen(str) - 1;
        for (int i = 0; str[m_degree - i] != '\0'; i++) { // ������� �������� � ����������
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
            printf("������\n");
            return 0;
        }
    }
    return 1;
}
int inpu() {
    int flag = 0; char s[5];
    printf("������� ���������� ���������: ");
    scanf("%s", s);
    for (int i = 0; i < strlen(s); i++) {
        for(int j = 48; j < 57; j++) {
            if (s[i] == j) {
                flag = 1; // ���� �����
                break;
            }   
        }
    }
    if (flag == 1)
        return atoi(s);
    else { 
    printf("������!\n"); // ���� �� �����
    inpu();
    }
}




