#include<stdio.h>

int main()
{
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);

    char flag= 'x';

    int i=0;
    while(str[i] != '\0')
    {
        switch(flag)
        {
            case 'x':
                printf("x= %c\n", str[i]);
                if(str[i] == '0') flag= 'y';
                else flag= 'x';
                break;
            case 'y':
                printf("y= %c\n", str[i]);
                if(str[i] == '0') flag= 'z';
                else flag= 'x';
                break;
            case 'z':
                printf("z= %c\n", str[i]);
                if(str[i] == '0') flag= 'z';
                else flag= 'x';
                break;
        }
        i++;
    }

    if(flag == 'z') printf("Accepted\n");
    else printf("Not accepted\n");
}