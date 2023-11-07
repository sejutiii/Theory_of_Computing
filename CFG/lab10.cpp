#include<bits/stdc++.h>

using namespace std;

vector<char> variables= {'S', 'A', 'B'};
int numVariable= 3;
vector<char> terminal= {'0', '1'};
vector<pair<char, vector<string>>> production;
string input;
vector<string> output;

void getInput()
{
    pair<char, vector<string>> node;
    node.first= 'S';
    node.second.push_back("A1B");
    production.push_back(node);

    node.first= 'A';
    node.second.push_back("0A");
    node.second.push_back("");
    production.push_back(node);

    node.first= 'B';
    node.second.push_back("0B");
    node.second.push_back("1B");
    node.second.push_back("");

    char state= 'S';

    output.push_back("S");

    cout << "Enter the input string: ";
    cin >> input;
}

bool containsVariable(string str)
{
    for(int i=0; str[i]!= '\0'; i++)
    {
        for(auto var: variables)
        {
            if(str[i]== var) return true;
        }
    }
    return false;
}

string replaceProduction(char state, string input_val, int index)
{
    for(auto prod: production)
    {
        if(state == prod.first)
        {
            if(prod.second.size()==1) return prod.second.back();
            else{
                char temp= input_val[index];
                for(auto tempProd: prod.second)
                {
                    if(tempProd[0] == temp) return tempProd;
                }
                return prod.second.back();
            }
        }
    }
    return "Invalid";
}

void leftmost_derivation(string inp)
{
    string temp= output.back();
    for(int i=0; i< temp.size(); i++)
    {
        string replace;
        for(auto var: variables)
        {
            if(var == temp[i]) 
            {
                replace= replaceProduction(var, inp, i);
                if(replace== "Invalid") return;
                break;
            }
        }
        temp= temp.substr(0, i) + replace+ temp.substr(i+1);
        output.push_back(temp);
    }
    if(containsVariable(temp)) leftmost_derivation(input);
}

void printOutput_left()
{
    for(auto val: output)
    {
        cout << val << " -> ";
    }
    cout<<endl;
}

int main()
{
    getInput();
    leftmost_derivation(input);
    printOutput_left();
}