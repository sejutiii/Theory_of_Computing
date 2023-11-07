#include<bits/stdc++.h>

using namespace std;

map<char, vector<string>> production;
vector<char> variables= {'S', 'A', 'B'};
string input;
vector<string> output;

string replacedWith(char state, char terminal)
{
    int i;
    for(i=0; i<production[state].size(); i++)
    {
        if(production[state][i][0]== terminal) break;
    }
    if(i== production[state].size()) return production[state][i-1];
    return production[state][i];
}

void leftmost(string temp, int index)
{
    // cout << temp << endl;
    output.push_back(temp);
    if(index== temp.size()) return;
    char term= input[index];
    string replace= replacedWith(temp[index], term);
    // cout << replace << endl;
    temp= temp.substr(0, index)+ replace + temp.substr(index+1);
    int i;
    for(i=0; i<temp.size(); i++)
    {
        bool flag= false;
        for(int j=0; j<variables.size(); j++)
        {
            if(temp[i]== variables[j]) 
            {
                flag= true;
                break;
            }
        }
        if(flag) break;
    }
    // cout << temp[i] << endl;
    leftmost(temp, i);
}

void rightMost()
{
    
}

void printOutput()
{
    cout << output[0];
    for(int i=1; i< output.size(); i++)
    {
        cout << " -> " << output[i];
    }
    cout << endl;
}

int main()
{
    production['S']= {"A1B"};
    production['A']= {"0A", ""};
    production['B']= {"0B", "1B", ""};
    cout << "Enter the input: ";
    cin>> input;
    int i;
    for(i=0; i<input.size(); i++)
    {
        if(input[i]== '1') break;
    }
    string temp= "S";
    leftmost(temp, 0);
    printOutput();
}