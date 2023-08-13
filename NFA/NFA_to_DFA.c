#include<stdio.h>
#include<math.h>
#include<stdbool.h>

#define n 10

void NFA_to_DFA(int numStates, int numAlph, char alph[], char states[], int next[numStates][numAlph], char initialState, char FinalState, char transf[numStates][numAlph][numStates], int index)
{
    int numSubstates= pow(numAlph, numStates);
}

int main()
{
    int numAlph, numstates;
   // freopen("input.txt", "r", stdin);
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

}