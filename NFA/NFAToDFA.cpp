#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<char>>> NFA_transTable;
char NFA_startState;
vector<char> NFA_finalState;
vector<char> NFA_states, NFA_alphabets;
int NFA_numStates, NFA_numAlph;

set<set<char>> DFA_states;
//vector<vector<string>> DFA_transTable;
vector<pair<set<char>, vector<set<char>>>> DFA_transTable;
set<char> DFA_startState;
vector<set<char>> DFA_finalStates;

void getInput()
{
    freopen("NFAtoDFA.txt", "r", stdin);
    cout << "Enter the number of states and alphabets in the NFA: "; 
    cin>> NFA_numStates>> NFA_numAlph;
    cout << "Enter the states: ";
    char temp;
    for(int i=0; i<NFA_numStates; i++)
    {
        cin >> temp;
        NFA_states.push_back(temp);
    }

    cout << "Enter the alphabets: ";
    for(int i=0; i<NFA_numAlph; i++)
    {
        cin >> temp;
        NFA_alphabets.push_back(temp);
    }

    cout<< "Enter the start state: ";
    cin>> NFA_startState;
    cout << "Enter the number of final states: ";
    int numF;
    cin>> numF;
    for(int i=0; i<numF; i++)
    {
        cin>> temp;
        NFA_finalState.push_back(temp);
    }

    int numTrans;
    //NFA_transTable.resize(NFA_numStates, vector<vector<char>>(NFA_numAlph, vector<char>(NFA_numStates)));
    cout << "Enter the transition table: ";
    for(int i=0; i<NFA_numStates; i++)
    {
        cout<< "For state " << NFA_states[i]<< " ";
        vector<vector<char>> temp3;
        for(int j=0; j<NFA_numAlph; j++)
        {
            cout<< "alphabet "<< NFA_alphabets[j] << endl;
            cout << "number of transitions: ";
            cin>> numTrans;
            cout << "Enter the transitions: ";
            vector<char> temp2;
            for(int k=0; k<numTrans; k++)
            {
                cin>> temp;
                temp2.push_back(temp);
            }
            temp3.push_back(temp2);
        }
        NFA_transTable.push_back(temp3);
    }
}

bool isVisited(set<char> tempStates, set<set<char>> &visited)
{
    for(auto state: visited)
    {
        if(tempStates== state) return true;
    }
    return false;
}

void insert_NewState(char state, char alph, set<char> &newStates)
{
    int i, j;
    for(i=0; i<NFA_numStates; i++)
    {
        if(NFA_states[i]== state) break;
    }
    for(j=0; j<NFA_numAlph; j++)
    {
        if(NFA_alphabets[j]== alph) break;
    }

    for(auto st: NFA_transTable[i][j])
    {
        newStates.insert(st);
    }
}

void getDFA_states()
{
    set<char> temp;
    set<set<char>> VisitedStates;
    temp.insert(NFA_startState);
    DFA_startState.insert(NFA_startState);
    DFA_states.insert(temp);

    for(int i=0; i<DFA_states.size(); i++)
    {
        auto it= next(DFA_states.begin(), i);
        set<char> currenState= *it;
        if(isVisited(currenState, VisitedStates))
        {
            continue;
        }

        for(auto alph: NFA_alphabets)
        {
            set<char> unvisitedStates;
            for(auto state: currenState)
            {
                insert_NewState(state, alph, unvisitedStates);
                DFA_states.insert(unvisitedStates);
            }
        }
        VisitedStates.insert(currenState);
    }
}

void getTransition(set<char> states, vector<set<char>> &trans)
{
    int i,j;
    for(j=0; j<NFA_numAlph; j++)
    {
        set<char> temp;
        for(auto st: states)
        {
            for(i=0; i<NFA_numStates; i++)
            {
            if(NFA_states[i]== st) break;
            }
            for(auto letter: NFA_transTable[i][j])
            {
                temp.insert(letter);
            }
        }
        trans.push_back(temp);
    }
}

void makeDFA_transTable()
{
    for(auto state: DFA_states)
    {
        pair<set<char>, vector<set<char>>> temp;
        temp.first= state;
        getTransition(state, temp.second);
        DFA_transTable.push_back(temp);
    }

}

void getDFA_finalstates()
{
    for(auto state: DFA_states)
    {
        for(auto st: state)
        {
            for(auto fin: NFA_finalState)
            {
                if(st== fin)
                {
                    DFA_finalStates.push_back(state);
                    break;
                }
            }
        }
    }
}

void printDFA_transTable()
{
    cout << "DFA transition table: " << endl;
    for(auto row: DFA_transTable)
    {
        cout << "[";
        for(auto from: row.first)
        {
            cout << from << "";
        }
        cout << "]=  " ;

        for(auto to: row.second)
        {
            cout << "[";
            for(auto sub: to)
            {
                cout << sub << "";
            }
            cout << "] " ;
        }
        cout << endl;
    }
}

void print_DFA_finalstates()
{
    cout << "DFA Final State: " << endl;
    for(auto fin: DFA_finalStates)
    {
        cout << "[";
        for(auto st: fin)
        {
            cout << st << "";
        }
        cout << "] ";
    }
    cout << endl;
}

void print_DFAstates()
{
    cout << "DFA states: " << endl;
    for(auto state: DFA_states)
    {
        for(auto st: state)
        {
            cout<< st << " ";
        }
        cout << endl;
    }
}

void NFA_to_DFA()
{
    getDFA_states();
    makeDFA_transTable();
    getDFA_finalstates();
}

void printDFA()
{
    cout << endl;
    cout << "-----------------DFA--------------" << endl;
    print_DFAstates();
    cout << "start state: [";
    for(auto st: DFA_startState)
    {
        cout << st;
    }
    cout << "]" << endl;
    print_DFA_finalstates();
    printDFA_transTable();
}

int main()
{
    getInput();
    NFA_to_DFA();
    printDFA();
   // cout << endl << endl;
   // print_DFAsubstates();
}