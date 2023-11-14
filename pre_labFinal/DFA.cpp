#include<bits/stdc++.h>
using namespace std;

// DFA 5 tuples
int numAlph, numStates;
vector<char> alphabets, states;
vector<vector<char>> transitionFunction;
char start_state;
vector<char> final_states;

//RE
vector<vector<vector<string>>> regEx;

void get_DFA_Input()
{
    //cout << "Enter the number of states: ";
    cin >> numStates;
    //cout << "Enter the states: ";
    char temp;
    for(int i=0; i<numStates; i++)
    {
        cin >> temp;
        states.push_back(temp);
    }

    //cout << "Enter the number of alphabets: ";
    cin >> numAlph;
    //cout << "Enter the alphabets: ";
    for(int i=0; i<numAlph; i++)
    {
        cin >> temp;
        alphabets.push_back(temp);
    }

    //cout<< "Enter the transition function (row->states and column->alphabets):"<< endl;
    transitionFunction.resize(numStates, vector<char>(numAlph));

    for(int i=0; i<numStates; i++)
    {
        //cout << "State "<< states[i] <<": " << endl;
        for(int j=0; j<numAlph; j++)
        {
            //cout << "Alphabet " << alphabets[j] << ": ";
            cin>> transitionFunction[i][j];
        }
    }

    //cout <<"Enter the start state: ";
    cin >> start_state;

    //cout <<"Enter the number of final states: ";
    int numFinalStates;
    cin >> numFinalStates;

    //cout << "Enter the final states: ";
    for(int i=0; i<numFinalStates; i++)
    {
        cin>> temp;
        final_states.push_back(temp);
    }
}

int getStateIndex(char state)
{
    for(int i=0; i<numStates; i++)
    {
        if(states[i]== state) return i;
    }
    return -1;
}

int getAlphIndex(char alph)
{
    for(int i=0; i<numAlph; i++)
    {
        if(alphabets[i]== alph) return i;
    }
    return -1;
}

bool check_DFA_language(string input)
{
    char currentState= start_state;
    for(int i=0; i<input.size(); i++)
    {
        int state_index= getStateIndex(currentState);
        int alph_index= getAlphIndex(input[i]);
       
        cout << currentState << " -> ";  // path of transition print 

        currentState= transitionFunction[state_index][alph_index];

        cout << currentState << endl;  // path of transition print
    }

    for(int i=0; i<final_states.size(); i++)
    {
        if(currentState == final_states[i]) return true;
    }
    return false;
}

void DFA_to_RE()
{
    regEx.resize(numStates, vector<vector<string>>(numStates, vector<string>(numStates)));
    
    for(int i=0; i<numStates; i++) //For source
    {
        for(int j=0; j<numStates; j++) //For destination
        {
            bool flag= false; // open bracket
            if(i==j)
            {
                regEx[0][i][j] += "(e";
                flag= true;
            }

            for(int x=0; x<numAlph; x++)
            {
                if(transitionFunction[i][x]== states[j])
                {
                    if(flag)
                    {
                        regEx[0][i][j] += "+";
                        regEx[0][i][j] += alphabets[x];
                    }
                    else{
                        regEx[0][i][j] += "(";
                        regEx[0][i][j] += alphabets[x];
                        flag= true;
                    }
                }
            }
            if(flag) regEx[0][i][j] += ")";
            else regEx[0][i][j] += "";
        }
    }

    for(int k=1; k<numStates; k++)
    {
        for(int i=0; i<numStates; i++)
        {
            for(int j=0; j<numStates; j++)
            {
                regEx[k][i][j] += regEx[k-1][i][j];
                if(regEx[k-1][i][j] != "") regEx[k][i][j] += "+";
                regEx[k][i][j] += regEx[k-1][i][k];
                regEx[k][i][j] += "(";
                regEx[k][i][j] += regEx[k-1][k][k];
                regEx[k][i][j] += ")*";
                regEx[k][i][j] += regEx[k-1][k][j];
            }
        }
    }

    for(int k=0; k<numStates; k++)
    {
        cout << "RE(" << k << ")" << endl;
        cout << "------------------------------------" << endl;
        for(int i=0; i<numStates; i++)
        {
            for(int j=0; j<numStates; j++)
            {
                cout << "R" <<i <<j << ": ";
                cout << regEx[k][i][j] << endl;
            }
        }
        cout << endl;
    }
}

int main()
{
    freopen("DFA.txt", "r", stdin);
    get_DFA_Input();
    // string input;
    // cout <<"Enter the input string: ";
    // cin >> input;
    // check_DFA_language(input)? cout<< "Accepted" : cout <<"Rejected";
    // cout << endl;
    DFA_to_RE();
}