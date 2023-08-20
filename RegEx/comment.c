#include<stdio.h>
#include<string.h>

int main()
{
    char str[200];
    char lines[100][200];

    FILE *fp= fopen("input.txt", "r");

    int i=0, n;

    while(fgets(str, 200, fp) != NULL)
    {
        strcpy(lines[i], str);
        //printf("%s", lines[i]);
        i++;
    }
    fclose(fp);
    n=i; 
    
    // char *linereader;
    // for(i=0; i<n; i++)
    // {
    //     linereader= lines[i];
    //     printf("%s", linereader);
    //     while(*linereader != '/')
    //     {
    //         if(*linereader== '\n') break;
    //         else linereader++;
    //     }
    //     linereader++;
    //     if( *linereader == '*')
    //     {
    //         while(*linereader != '*')
    //         {
    //             printf("%c", *linereader);
    //             linereader++;
    //         }
    //     }
    //     else if(*linereader == '/')
    //     {
    //         while(*linereader != '\n')
    //         {
    //             printf("%c", *linereader);
    //             linereader++;
    //         }
    //     }
    //     else printf("Syntax error\n");

    // }

    int flag=0, k=0;
    char temp[200];

    for(i=0; i<n; i++)
    {
        int len= strlen(lines[i]);
        //printf("len= %d\n", len);

        for(int j=0; j<len; j++)
        {
            if(flag== 1)
            {
                while(lines[i][j] != '*')
                    {
                        if(lines[i][j] == '\n')
                        {
                            //printf("syntax error\n");
                            flag=1;
                            continue;
                        }
                        temp[k]= lines[i][j];
                        k++;
                        j++;
                    }
                    j++;
                    if(lines[i][j] == '/')
                    {
                        temp[k]= '\0';
                        printf("Multiline comment at line %d and %d: %s\n\n", i, i+1, temp);
                        flag=0;
                        break;
                    }
                    else 
                    {
                        printf("Syntax error at line %d\n\n", i+1);
                        flag=0;
                        break;
                    }
            }
            if(lines[i][j] == '/')
            {
                j++;
                if(lines[i][j]== '/')
                {
                    printf("Single line Comment at line %d: ", i+1);
                    j++;
                    while(lines[i][j] != '\n')
                    {
                        printf("%c", lines[i][j]);
                        j++;
                    }
                    printf("\n\n");
                    break;
                }
                else if(lines[i][j] == '*')
                {
                    j++; k=0;
                    while(lines[i][j] != '*')
                    {
                        if(lines[i][j] == '\n')
                        {
                            //printf("syntax error\n");
                            flag=1;
                            break;
                        }
                        temp[k]= lines[i][j];
                        k++;
                        j++;
                    }
                    j++;
                    if(lines[i][j] == '/')
                    {
                        temp[k]= '\0';
                        printf("Multiline comment at line %d: %s\n\n", i+1, temp);
                        break;
                    }

                }
                else{
                    printf("Syntax Error at %d\n\n", i+1);
                    break;
                }
            }
        }
    }
    
}