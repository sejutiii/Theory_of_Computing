#include<stdio.h>

char alph[]= {'0', '1'};

char substring[10];

void substringGenerator(int i, int k);

int main()
{
    int k;
    printf("Enter k: ");
    scanf("%d", &k);

    substringGenerator(0, k);
}

void substringGenerator(int i, int k)
{
    if(i==k)
    {
        substring[i]= '\0';
        printf("%s\n", substring);
        return;
    }

    substring[i]= '0';
    substringGenerator(i+1, k);

    substring[i]= '1';
    substringGenerator(i+1, k);
    return;
}