#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define n 10

char inputString[100];
char path[100];
int path_index;
bool isNFA;

void NFA(int numStates, int numAlph, char alph[], char states[], int next[numStates][numAlph], char initialState, char FinalState, char transf[numStates][numAlph][numStates], int index)
{
   // printf("Iter %d, str= %c, state= %c, isNFA= %d\n", index+1, inputString[index], initialState, isNFA);
    if(inputString[index] == '\0')
    {
        if(initialState == FinalState)
        {
            isNFA= true;

            path[path_index]= initialState;
            path_index++;
            path[path_index]= '\0';

            printf("\n path= ");

            for(int i=0; path[i] != '\0'; i++)
            {
                printf("%c\t", path[i]);
            }

        }
        else{
            path_index--;
        }
        return;
    }

    path[path_index]= initialState;
    path_index++;
    path[path_index]= '\0';

    // if(initialState== FinalState)
    // {
    //     isNFA= true;
    // }

    // if(initialState == '#')
    // {
    //     //isNFA= false;
    //     return;
    // }

    int i,j;
    for(i=0; i<numStates; i++)
    {
        if(initialState == states[i]) break;
    }

    for(j=0; j<numAlph; j++)
    {
        if(inputString[index]== alph[j]) break;
    }

    if(next[i][j]== 0) 
    {
        path_index--;
        return;
    }

    int k= 0;

    while(k < next[i][j] && isNFA == false)
    {
        char newState = transf[i][j][k];
        //if(newState != initialState)
        initialState= newState;
        NFA(numStates, numAlph, alph, states, next, initialState, FinalState, transf, index+1);
        k++;    
    }
}

int main()
{
    int numAlph, numstates;
    //freopen("input.txt", "r", stdin);
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
    getchar();

    char states[numstates];
    printf("Enter the states: ");
    for(int i=0; i<numstates; i++)
    {
        scanf("%c", &states[i]);
        getchar();
    }

    char transitionFunction[numstates][numAlph][numstates];
    int next[numstates][numAlph];

    for(int i=0; i<numstates; i++)
    {
        printf("For State- %c \n", states[i]);
        for(int j=0; j<numAlph; j++)
        {
            printf("and alphabet %c enter the number of next states: ", alph[j]);
            scanf("%d", &next[i][j]);
            getchar();
            printf("Enter the next states: ");
            for(int k=0; k<next[i][j]; k++)
            {
                scanf("%c", &transitionFunction[i][j][k]);
                getchar();
            }
        }
    }

    char initialState, FinalState;
    printf("Enter the initial State: ");
    scanf("%c", &initialState);
    getchar();

    printf("Enter the final state: ");
    scanf("%c", &FinalState);
    getchar();

    printf("Enter the input String: ");
    scanf("%s", inputString);

    isNFA= false;
    path_index=0;
    NFA(numstates, numAlph, alph, states, next, initialState, FinalState, transitionFunction, 0);

    if(isNFA == true)
    {
        printf("Aceepted\n");
    }
    else printf("Not Accepted\n");
}