#include<bits/stdc++.h>

using namespace std;

vector<char> variables= {'S', 'A', 'B'};
vector<char> terminal= {'0', '1'};
vector<pair<char, vector<string>>> production= {
    {'S', {"A1B"}},
    {'A', {"0A", ""}},
    {'B', {"0B", "1B", ""}}
};
string input;
vector<string> output;

void getInput()
{
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

int giveVariableIndex(char state)
{
    for(int i=0; i<production.size(); i++)
    {
        if(production[i].first == state) return i;
    }
    return -1;
}

string replaceProduction(char state, char terminal)
{
    int i= giveVariableIndex(state), j;
    for(j=0; j< production[i].second.size(); j++)
    {
        if(production[i].second[j][0] == terminal) return production[i].second[j];
    }
    return production[i].second[j-1];
}

void leftmost_derivation(string temp, int index)
{
    output.push_back(temp);
    if(index== -1) return;
    string replace= replaceProduction(temp[index], input[index]);
    temp= temp.substr(0, index) + replace+ temp.substr(index+1);
    index= containsVariable(temp);
   // cout << "index= "<< index << endl;
    leftmost_derivation(temp, index);
}

// rightmost starts here >
int indexOf1()
{
    int i;
    for(i=0; i<input.size(); i++)
    {
        if(input[i]== '1') return i;
    }
    return -1;
}

void rightmost_derivation()
{
    output.push_back("S");
    output.push_back("A1B");
    int index= indexOf1();
    string leftside= input.substr(0, index);
    string rightside= input.substr(index+1);
    //cout << leftside << " " << rightside << endl;
    string temp= "B";
    index= containsVariable(temp);
    while(index != -1)
    {
        string replace= replaceProduction(temp[index], rightside[index]);
        temp= temp.substr(0, index)+ replace;
        replace= "A1"+ temp;
        output.push_back(replace);
        index= containsVariable(temp);
    }
    string str= temp;
    temp= "A";
    index= containsVariable(temp);
    while(index != -1)
    {
        string replace= replaceProduction(temp[index], leftside[index]);
        temp= temp.substr(0, index)+ replace;
        replace= temp+ "1"+ str;
        output.push_back(replace);
        index= containsVariable(temp);
    }
}

void printOutput()
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
    printOutput();
    cout << endl;
    output.clear();
    rightmost_derivation();
    printOutput();
}