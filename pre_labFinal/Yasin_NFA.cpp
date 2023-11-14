#include<bits/stdc++.h>
using namespace std;

vector<vector<vector<char>>> transition_table;
vector<char> states,symbols,final_states,path;
map<char,int> state_index,symbol_index;
int state_num,symbol_num,final_state_num;
char starting_state;
string str;
bool is_nfa;
vector<vector<int>> transition_num;

void read_input();
void check_nfa(int str_index,int path_index,char current_state);
void print_path();
void print_nfa();

int main(){
    freopen("yasin.txt","r",stdin);
    read_input();
    print_nfa();
    check_nfa(0,0,starting_state);
    print_path();
    return 0;
}

void read_input(){
    cin>>state_num>>symbol_num;
    int i,j,k,num;
    char ch;
    for(i=0;i<state_num;i++){
        cin>>ch;
        states.push_back(ch);
        state_index[ch]=i;
    }
    for(i=0;i<symbol_num;i++){
        cin>>ch;
        symbols.push_back(ch);
        symbol_index[ch]=i;
    }
    cin>>starting_state;
    cin>>final_state_num;
    for(i=0;i<final_state_num;i++){
        cin>>ch;
        final_states.push_back(ch);
    }
    transition_num.resize(state_num,vector<int>(symbol_num));
    transition_table.resize(state_num,vector<vector<char>>(symbol_num,vector<char>(state_num)));
    for(i=0;i<state_num;i++){
        for(j=0;j<symbol_num;j++){
            num=0;
            transition_table[i][j].clear();
            while(true){
                cin>>ch;
                if(ch=='-'){
                    break;
                }
                transition_table[i][j].push_back(ch);
                num++;
            }
            transition_num[i][j]=num;
        }
    }
    cin>>str;
    path.resize(str.size()+1);
}

void check_nfa(int str_index,int path_index,char current_state){
    if(str_index==str.size()){
        if(find(final_states.begin(),final_states.end(),current_state)!=final_states.end()){
            path[path_index]=current_state;
            cout<<"Current state: "<<current_state<<endl;
            is_nfa=true;
        }
        return;
    }
    char current_symbol=str[str_index];
    if(transition_num[state_index[current_state]][symbol_index[current_symbol]]==0){
        return;
    }
    for(int i=0;i<transition_num[state_index[current_state]][symbol_index[current_symbol]]&&is_nfa!=true;i++){
        path[path_index]=current_state;
        check_nfa(str_index+1,path_index+1,transition_table[state_index[current_state]][symbol_index[current_symbol]][i]);
    }
}

void print_path(){
    if(!is_nfa){
        cout<<"Not accepted!"<<endl;
        return;
    }
    cout<<"Accepted!"<<endl;
    cout<<"Path: ";
    for(auto p:path){
        cout<<p<<" ";
    }
    cout<<endl;
}

void print_nfa(){
    for(auto st:states){
        cout<<"\nFor state-"<<states[state_index[st]]<<":"<<endl;
        for(auto sym:symbols){
            cout<<"For symbol-"<<symbols[symbol_index[sym]]<<": ";
            for(auto e:transition_table[state_index[st]][symbol_index[sym]]){
                cout<<e<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"Starting state: "<<starting_state<<endl;
    cout<<"Final states: ";
    for(auto f:final_states){
        cout<<f<<" ";
    }
    cout<<endl;
}