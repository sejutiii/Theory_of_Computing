#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define n 10

char inputString[100];
bool isNFA;

bool NFA(int numStates, int numAlph, char alph[], char states[], int next[numStates][numAlph], char initialState, char FinalState, char transf[numStates][numAlph][numStates], int index)
{
    //printf("Iter %d\n", index);
    if(inputString[index] == '\0')
    {
        return isNFA;
    }

    if(initialState== FinalState)
    {
        isNFA= true;
    }

    if(initialState == '#')
    {
        isNFA= false;
        return isNFA;
    }

    int i,j;
    for(i=0; i<numStates; i++)
    {
        if(initialState == states[i]) break;
    }

    for(j=0; j<numAlph; j++)
    {
        if(inputString[index]== alph[j]) break;
    }

    int k= next[i][j];

    while(k--)
    {
        char newState = transf[i][j][k];
        if(newState != initialState)
        {
            initialState= newState;
            NFA(numStates, numAlph, alph, states, next, initialState, FinalState, transf, index);
        }
    }

    if(initialState != FinalState) return false;
    
    NFA(numStates, numAlph, alph, states, next, initialState, FinalState, transf, index+1);
}

int main()
{
    int numAlph, numstates;
    freopen("input.txt", "r", stdin);
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

    bool flag= NFA(numstates, numAlph, alph, states, next, initialState, FinalState, transitionFunction, 0);

    if(flag== true)
    {
        printf("True\n");
    }
    else printf("False\n");
}