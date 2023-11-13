#include<bits/stdc++.h>

using namespace std;

vector<char> variables= {'S'};
vector<char> terminal= {'a', 'b'};
pair<char, vector<string>> production= {'S', {"aS", "aSbS", ""}};
string input;
vector<string> output;

void getInput()
{
    cout << "Enter the input string: ";
    cin >> input;
}

int containsVariable(string str) // Finds the index of the variable in the string
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

bool terminalMatch(string temp)
{
    int count = 0;
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i]== 'a' || temp[i]== 'b') count++;
    }
    if(count >= input.size()) return true;
    else return false;
}

bool count_term(string temp)
{
    int temp_a=0, temp_b=0;
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i]== 'a') temp_a++;
        else if(temp[i]== 'b') temp_b++; 
    }

    int count_a=0, count_b=0;
    for(int i=0; i<input.size(); i++)
    {
        if(input[i]== 'a') count_a++;
        if(input[i]== 'b') count_b++;
    }
    count_a -= temp_a;
    count_b -= temp_b;
    if(count_a == count_b) return true;
    return false;
}

string replace_production1(string temp, int index)
{
    if(terminalMatch(temp)) return production.second[2];
    if(count_term(temp)) return production.second[1];
    return production.second[0];
}

void leftMost_derivation1(string temp, int input_index)
{
    output.push_back(temp);
    int var_index= containsVariable(temp);
    if (var_index == -1) return;
    string replace= replace_production1(temp, input_index);
   // cout << replace << " " << input_index << endl;
    temp= temp.substr(0, var_index)+ replace + temp.substr(var_index+1);
    leftMost_derivation1(temp, input_index+1);

}

bool match_for_b(string temp)
{
    int count_temp=0, count_input=0;
    for(int i=0; i<input.size(); i++)
    {
        if(input[i]== 'b') count_input++;
    }
    for(int i=0; i<temp.size(); i++)
    {
        if(temp[i]== 'b') count_temp++;
    }
    if(count_temp < count_input) return true;
    else return false;
}

string replace_production2(string temp, int index)
{
    if(terminalMatch(temp)) return production.second[2];
    if(match_for_b(temp)) return production.second[1];
    return production.second[0];
}

void leftMost_derivation2(string temp, int input_index)
{
    output.push_back(temp);
    int var_index= containsVariable(temp);
    if (var_index == -1) return;
    string replace= replace_production2(temp, input_index);
    temp= temp.substr(0, var_index)+ replace + temp.substr(var_index+1);
    leftMost_derivation2(temp, input_index+1);
}

int main()
{
    getInput();
    leftMost_derivation1("S", 0);
    cout << "leftMost derivation 1: ";
    cout << output[0];
    for(int i=1; i<output.size(); i++)
    {
        cout << " -> " << output[i];
    }
    output.clear();
    cout << endl;
    leftMost_derivation2("S", 0);
    cout << "leftMost derivation 2: ";
    cout << output[0];
    for(int i=1; i<output.size(); i++)
    {
        cout << " -> " << output[i];
    }
}