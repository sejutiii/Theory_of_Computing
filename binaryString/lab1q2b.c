#include<stdio.h>
#include<stdbool.h>

bool palindrome(char str[]);

int strLen(char str[]);

int main()
{
    char str[20];
    printf("Enter a string: ");
    scanf("%s", str);
    bool x= palindrome(str);
    if(x== true) printf("Is a palindrome\n");
    else printf("Not a palindrome\n");
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

bool palindrome(char str[])
{
    bool flag= true;
    int len= strLen(str);
    char newStr[len];
    for(int i=0; i<=len; i++)
    {
        newStr[i] = str[i];
    }

    for(int i=0, j=len-1; i<len/2; i++)
    {
        if(str[i] != newStr[j])
        {
            flag= false;
        }
        j--;
    }

    return flag;
}