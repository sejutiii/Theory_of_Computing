#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void generateString(char alph[]);
int strLen(char str[]);
bool identifyString(char alph[], char str[]);
void concatString();

int main()
{
    char alph[]= {'0', '1'};
    for(int i=0; i<5; i++)
    {
        generateString(alph);
    }

    char str[10];
    printf("Enter a string: ");
    scanf("%s", str);
    bool x= identifyString(alph, str);
    if(x== true) printf("The string is in the alphabets\n");
    else printf("The string is not in the alphabets\n");
    concatString();
    return 0;
}

void generateString(char alph[])
{
    char str[10];
    int k= rand() % 9;
    for(int i=0; i<k; i++)
    {
        int index= rand()%2;
        str[i]= alph[index];
    }
    str[k]= '\0';
    printf("%s\t", str);
    int len= strLen(str);
    printf("length= %d\n", len);

}

int strLen(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

bool identifyString(char alph[], char str[])
{
    int i=0;
    bool flag= true;
    while(str[i] != '\0')
    {
        if(str[i] != alph[0] && str[i] != alph[1])
        {
            flag= false;
            break;
        }
        i++;
    }
    return flag;
}

void concatString()
{
    char x[10], y[10], z[20];
    printf("Enter a string: ");
    scanf("%s", x);
    printf("Enter another string: ");
    scanf("%s", y);

    int i=0, j=0;
    while(x[i] != '\0')
    {
        z[j]= x[i];
        i++;
        j++;
    }

    i=0;
     while(y[i] != '\0')
    {
        z[j]= y[i];
        i++;
        j++;
    }
    z[j] = '\0';
    printf("z= %s\n", z);
}