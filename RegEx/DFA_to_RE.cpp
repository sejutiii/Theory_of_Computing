#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("DFA.txt", "r", stdin);
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

    char transitionTable[numstates][numAlph], initialState, finalState;

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

    cout << "Enter the final state: ";
    cin >> finalState;

    int numRE_perState= numstates*numstates;
    string regEx[numstates][numRE_perState];

    int k=0, m=0;
    for(int i=0; i<numstates; i++)
    {
        for(int j=0; j<numstates; j++)
        {
            bool x= false;
            if(i == j)
            {
                regEx[k][m] += "(";
                regEx[k][m] += "e";
                x= true;
            }

            for(int a=0; a<numAlph; a++)
            {
                if(states[j]== transitionTable[i][a])
                {
                    if(x==true)
                    {
                        regEx[k][m] += "+";
                        regEx[k][m] += alph[a];
                    }
                    else
                    {
                    
                        regEx[k][m] += "(";
                        regEx[k][m] += alph[a];
                    
                        x= true;
                    }
                    
                }
            }

            if(!x) 
            {
                regEx[k][m] += "";
                m++;
                continue;
            }
            regEx[k][m] += ")";
            m++;
        }
    }
    int n=0;
    for(k=1; k<numstates; k++)
    {
        m=0; n=0;
        for(int i=0; i<numstates; i++)
        {
            for(int j=0; j<numstates; j++)
            {
                int l= k-1;
                regEx[k][m] = regEx[k-1][i+j+n];
                if(regEx[k][m] != "")
                    regEx[k][m] += "+";
                regEx[k][m] += regEx[k-1][i+l+n];
                regEx[k][m] += regEx[k-1][l+l+n];
                if(regEx[k-1][l+l+n] != "")
                    regEx[k][m] += "*";
                regEx[k][m] += regEx[k-1][l+j+n];

                m++;
            }
            n +=2;
        }
    }

    cout << endl;
    for(k=0; k<numstates; k++)
    {
        cout << "RE(" << k << ")" << endl;
        cout << "------------------------------------" << endl;
        for(m=0; m<numRE_perState; m++)
        {
            cout<< regEx[k][m] << endl;
        }
        cout << endl;
    }

}