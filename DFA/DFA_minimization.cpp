#include<bits/stdc++.h>

using namespace std;

bool stateCompare(char state1, char state2, int numFinalstate, char* finalstates)
{
    int a=3, b=3;
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
    freopen("input.txt", "r", stdin);
    int numAlph, numstates;
    cout << "Enter the number of alphabets: ";
    cin >> numAlph;
    getchar();

    char alph[numAlph];
    cout <<"Enter the alphabets: ";
    for(int i=0; i<numAlph; i++)
    {
        cin >> alph[i];
    }
    getchar();

    cout << "Enter the number of states: ";
    cin >> numstates;
    getchar();

    cout << "Enter the states: ";
    char states[numstates];

    for(int i=0; i<numstates; i++)
    {
        cin >> states[i];
    }
    getchar();

    char transitionTable[numstates][numAlph], initialState;

    cout << "Enter the transition table (row-> states and column-> alphabets): ";

    for(int i=0; i<numstates; i++)
    {
        for(int j=0; j<numAlph; j++)
        {
            cin >> transitionTable[i][j];
        }
        getchar();
    }

    cout << "Enter the initial state: ";
    cin >> initialState;
    getchar();

    int numFinalState;

    cout << "Enter the number of final states: ";
    cin >> numFinalState;
    getchar();
    char finalStates[numFinalState];

    for(int i=0; i<numFinalState; i++)
    {
        cin >> finalStates[i];
    }
    getchar();

    char minimizationTable[numstates][numstates];

    for(int i=0; i<numstates; i++)
    {
        for(int j=0; j<numstates; j++)
        {
            minimizationTable[i][j]= '=';
        }
    }

    for(int k=0; k<numFinalState; k++)
    {
        for(int i=0; i<numstates; i++)
        {
            if(finalStates[k]== states[i])
            {
                for(int j=0; j<numstates; j++)
                {
                    if(j<i)
                        minimizationTable[i][j]= 'x';
                    else if(j>i)
                        minimizationTable[j][i]= 'x';
                }
            }
        }
    }

    bool isAfinalstate= false;
    for(int i=1; i<numstates; i++)
    {
        for(int j=0; j<i; j++)
        {  
           for(int k=0; k<numAlph; k++)
           {
            char newState1= transitionTable[i][k];
            char newState2= transitionTable[j][k];
            bool flag= stateCompare(newState1, newState2, numFinalState, finalStates);
            if(flag== false)
            {
                minimizationTable[i][j]= 'x';
                break;
            }
           }

            int len= numAlph;

            char substr[4][len]= {
                {'0','0'},
                {'0','1'},
                {'1','0'},
                {'1','1'}
            };
            for(int k=0; k<4; k++)
            {
                char newState1, newState2;
                int stateIndex1= i, stateIndex2=j;
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

    vector<pair<int, int>> equivalents;
    for(int i=1; i<numstates; i++)
    {
        for(int j=0; j<i; j++)
        {
           if(minimizationTable[i][j]== '=')
           {
            equivalents.push_back({i, j});
           }
        }
    }

    int x=  equivalents.size();
    int newNumStates= numstates-x;

    char newstates[newNumStates], newtransitionTable[newNumStates][numAlph];
    int index=0;
    for(int i=0; i<numstates; i++)
    {
        bool flag = false;
        for(int j=0; j<equivalents.size(); j++)
        {
            if(i == equivalents[j].first)
            {
                flag= true;
                break;
            }
            newstates[index]= states[i];
        }
        if(flag== true) continue;
        index++;
    }

    cout << "Number of states for the new DFA: " << newNumStates << endl;
    cout << "The new states are- " << endl;

    for(int i=0; i<newNumStates; i++)
    {
        cout << newstates[i] << " ";
    }

    for(int i=0; i<numstates; i++)
    {
        for(int j=0; j<numAlph; j++)
        {
            for(int k=0; k<equivalents.size(); k++)
            {
                if(transitionTable[i][j]== states[equivalents[k].first])
                {
                    transitionTable[i][j]= states[equivalents[k].second];
                }
            }
        }
    }
   
    index=0;

    for(int i=0; i<numstates; i++)
    {
        for(int j=0; j<numAlph; j++)
        {
            newtransitionTable[index][j]= transitionTable[i][j];
        }
        index++;
    }

    cout << endl;
    cout << "The transition table for the minimized DFA- " << endl;
    cout << "  0 1"<< endl;
    for(int i=0; i<newNumStates; i++)
    {
        cout << newstates[i] << " ";
        for(int j=0; j<numAlph; j++)
        {
           cout << newtransitionTable[i][j] << " ";
        }
        cout << endl;
    }
}