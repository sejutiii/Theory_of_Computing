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

int containsVariable(string str)
{
    for(int i=0; str[i]!= '\0'; i++)
    {
        for(auto var: variables)
        {
            if(str[i]== var) return i;
        }
    }
   return -1;
}

string replaceProduction(char state, char terminal)
{
    int i, j; 
    bool flag= false;
    for(i=0; i<production.size(); i++)
    {
        if(state == production[i].first)
        {
            for(j=0; j<production[i].second.size(); j++)
            {
                if(production[i].second[j][0]== terminal) 
                {
                    flag= true;
                    break;
                }
            }
        }
        if(flag) break;
    }
    if(i== production.size()) return production[i].second[j-1];
    return production[i].second[j];
}

void leftmost_derivation(string temp, int index)
{
    output.push_back(temp);
    string replace= replaceProduction(temp[index], input[index]);
    temp= temp.substr(0, index) + replace+ temp.substr(index+1);
    index= containsVariable(temp);
    if(index== -1) return;
    leftmost_derivation(temp, index);
}

void printOutput_left()
{
    cout << output[0];
    for(int i=1; i<output.size(); i++)
    {
        cout <<" -> " << output[i];
    }
    cout<<endl;
}

int main()
{
    getInput();
    string temp= "S"; 
    leftmost_derivation(temp, 0);
    printOutput_left();
}