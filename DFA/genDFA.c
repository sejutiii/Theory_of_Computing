#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char inputString[100];

int main()
{
    int numAlph, numstates;
    printf("Enter the number of alphabets: ");
    scanf("%d", &numAlph);
    char alph[numAlph];

    getchar();
    printf("Enter the alphabets: ");
    for(int i=0; i<numAlph; i++)
    {
        scanf("%c", &alph[i]);
        getchar();
    }

    printf("Enter the number of states: ");
    scanf("%d", &numstates);

    int transitionStates[numstates][numAlph], initialState, finalState;

    printf("Enter the transition table (row-> states and column-> alphabets): ");

    for(int i=0; i<numstates; i++)
    {
        for(int j=0; j<numAlph; j++)
        {
            scanf("%d", &transitionStates[i][j]);
        }
    }

    printf("Enter the initial state: ");
    scanf("%d", &initialState);

    printf("Enter the final state: ");
    scanf("%d", &finalState);
    getchar();

    printf("Enter the input string: ");
    scanf("%s", inputString);

    int i=0, k=0;
    int len = strlen(inputString);
    while(i<len)
    {
        // printf("Output=%c", inputString[i]);
        for(k=0; k<numAlph; k++)
        {
            //printf(" k=%c\n",alph[k]);
            if(inputString[i] == alph[k]) 
            {
            //printf("k= %d\n", k);
                break;
            }
        }

        initialState = transitionStates[initialState][k];
        i++;
    }

    if(initialState == finalState) printf("Accepted\n");
    else printf ("Not accepted\n");

    return 0;
}