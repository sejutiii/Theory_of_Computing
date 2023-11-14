#include<bits/stdc++.h>
using namespace std;

int numAlph, numStates;
vector<char> alphabets, states;
vector<vector<vector<char>>> transitionFunction;
vector<vector<int>> numTransitions;
char start_state;
vector<char> final_states;

vector<char> path;
bool isNFA;

void get_NFA_Input()
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
    transitionFunction.resize(numStates, vector<vector<char>>(numAlph, vector<char>(numStates)));
    numTransitions.resize(numStates, vector<int>(numAlph));
    for(int i=0; i<numStates; i++)
    {
        //cout << "State "<< states[i] <<": " << endl;
        for(int j=0; j<numAlph; j++)
        {
            //cout << "Alphabet " << alphabets[j] << ": " << endl;
            int temp=0;
           // cout << "Number of transitions: ";
            cin >> temp;
            numTransitions[i][j]= temp;
           // if(temp != 0) cout << "Transitions: ";
            for(int k=0; k<temp; k++)
            {
                cin >> transitionFunction[i][j][k];
            }
        }
    }

    //cout <<"Enter the start state: ";
    cin >> start_state;

    //cout <<"Enter the number of final states: ";
    int numFinalStates;
    cin >> numFinalStates;

   // cout << "Enter the final states: ";
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

bool isAFinalState(char state)
{
    for(int i=0; i<final_states.size(); i++)
    {
        if(final_states[i]== state) return true;
    }
    return false;
}

void printPath()
{
    cout << "path: ";
    for(auto p: path)
    {
        cout << p << " ";
    }
    cout << endl;
}

void check_NFA_language(char currentState, string input, int input_index, int path_index)
{
    if(input_index == input.size())
    {
        if(isAFinalState(currentState))
        {
            path[path_index]= currentState;
            isNFA= true;
        }
        return;
    }
    int i= getStateIndex(currentState);
    int j= getAlphIndex(input[input_index]);

    if(numTransitions[i][j]== 0)
    {
        return;
    }
    path[path_index]= currentState;
    int k=0;
    while(k < numTransitions[i][j] && isNFA== false)
    {
        currentState= transitionFunction[i][j][k];
        check_NFA_language(currentState, input, input_index+1, path_index+1);
        k++;
    }
}

int main()
{
    freopen("NFA.txt", "r", stdin);
    get_NFA_Input();
    string input;
    //cout << "Input: ";
    cin >> input;
    path.resize(input.size());
    isNFA= false;
    check_NFA_language(start_state, input, 0, 0);
    if(isNFA == true) cout << "Accepted";
    else cout << "Rejected";
    cout << endl;
    printPath();
    cout << endl;
}