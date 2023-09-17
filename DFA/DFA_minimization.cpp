#include<bits/stdc++.h>

using namespace std;

void substringGenerator(int i, int k, char*substring, vector<string> &substr)
{
    if(i==k)
    {
        //substring[i]= '\0';
        //printf("%s\n", substring);
        substr.push_back(substring);
        return;
    }

    substring[i]= '0';
    substringGenerator(i+1, k, substring, substr);

    substring[i]= '1';
    substringGenerator(i+1, k, substring, substr);
    return;
}

bool stateCompare(char state1, char state2, int numFinalstate, char* finalstates)
{
    int a=3, b=4;
    for(int i=0; i<numFinalstate; i++)
    {
        if(state1==finalstates[i])
            a=1;
        if(state2 == finalstates[i])
            b=1;
    }

    if(a==b) return true;
    else return false;

}

int main()
{
    //freopen("DFA.txt", "r", stdin);
    int numAlph, numstates;
    cout << "Enter the number of alphabets: ";
    cin >> numAlph;

    char alph[numAlph];
    cout <<"Enter the alphabets: ";
    for(int i=0; i<numAlph; i++)
    {
        cin >> alph[i];
    }

    cout << "Enter the number of states: ";
    cin >> numstates;

    cout << "Enter the states: ";
    char states[numstates];

    for(int i=0; i<numstates; i++)
    {
        cin >> states[i];
    }

    char transitionTable[numstates][numAlph], initialState;

    cout << "Enter the transition table (row-> states and column-> alphabets): ";

    for(int i=0; i<numstates; i++)
    {
        for(int j=0; j<numAlph; j++)
        {
            cin >> transitionTable[i][j];
        }
    }

    cout << "Enter the initial state: ";
    cin >> initialState;

    int numFinalState;
    char finalStates[numFinalState];

    cout << "Enter the number of final states: ";
    cin >> numFinalState;

    for(int i=0; i<numFinalState; i++)
    {
        cin >> finalStates[i];
    }

    char minimizationTable[numstates-1][numstates-1];

    for(int i=0; i<numstates-1; i++)
    {
        for(int j=0; j<=i; j++)
        {
            minimizationTable[i][j]= '=';
        }
    }

    bool isAfinalstate= false;
    for(int i=0; i<numstates-1; i++)
    {
        for(int j=0; j<=i; j++)
        {  
           for(int k=0; k<numAlph; k++)
           {
            char newState1= transitionTable[i+1][k];
            char newState2= transitionTable[j][k];
            bool flag= stateCompare(newState1, newState2, numFinalState, finalStates);
            if(flag== false)
            {
                minimizationTable[i][j]= 'x';
                break;
            }
           }

            // vector<string> substr;
            // char substring[3];
            int len= 2;
            // substringGenerator(0, len, substring, substr);

            //int n= substr.size();

            char substr[4][2]= {
                {0,0},
                {0,1},
                {1,0},
                {1,1}
            };
            for(int k=0; k<4; k++)
            {
                // string str= substr.back();
                // substr.pop_back();
                char newState1, newState2;
                int stateIndex1= i+1, stateIndex2=j;
                for(int l=0; l<len; l++)
                {
                    int alphIndex;
                    for(int m=0; m<numAlph; m++)
                    {
                        if(substr[k][l]== alph[m]) alphIndex=m;
                    }

                    newState1= transitionTable[stateIndex1][alphIndex];
                    for(int m=0; m<numstates; m++)
                    {
                        if(newState1== states[m]) stateIndex1=m;
                    }
                    newState2= transitionTable[stateIndex2][alphIndex];
                    for(int m=0; m<numstates; m++)
                    {
                        if(newState2== states[m]) stateIndex2=m;
                    }
                }

                bool flag= stateCompare(newState1, newState2, numFinalState, finalStates);
                if(flag== false)
                {
                    minimizationTable[i][j]= 'x';
                    break;
                }
            }
        }
    }

    for(int i=0; i<numstates-1; i++)
    {
        for(int j=0; j<=i; j++)
        {
           printf("%c\t", minimizationTable[i][j]);
        }
        printf("\n");
    }
    
}