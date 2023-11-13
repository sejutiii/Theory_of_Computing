#include<bits/stdc++.h>
using namespace std;

vector<string> production;
vector<string> output;
string input;

int main()
{
    production= {"", "0", "1", "0p0", "1p1"};
    cout << "Enter the input string: ";
    cin >> input;
    int len = input.length();

    for(int i=0; i<len; i++)
    {
        if(input[i]== '0' || input[i]== '1')
            continue;
        else 
        {
            cout << "Invalid input" << endl;
            exit(1);
        }
    }
    
    output.push_back("p");

    int temp_len= len;
    string temp_str= input;

    for(int i=0; i<=len/2; i++)
    {
        string temp= output.back();
        int index= temp.length()/2;

        string pre= temp.substr(0, index);
        string post= temp.substr(index+1);

        if(temp_len== 0)
        {
            temp= pre;
            temp += post;
           // break;
        }
        else if(temp_len == 1)
        {
            if(temp_str== production[1])
            {
                temp = pre;
                temp += production[1];
                temp += post;
            }

            else if(temp_str== production[2])
            {
                temp = pre;
                temp += production[2];
                temp += post;
            }
           // break;
        }

        else
        {
            if(input[i]== '0')
            {
                temp= pre;
                temp += production[3];
                temp += post;
            }

            else if(input[i]== '1')
            {
                temp= pre;
                temp += production[4];
                temp += post;
            }

            temp_len -= 2;
            temp_str= input.substr(i+1, temp_len);
        }

        output.push_back(temp);
        //cout << temp_len << endl;
    }

    if(output.back()== input)
    {
        int i;
        for(i=0; i<output.size()-1; i++)
        {
            cout << output[i] << "-> ";
        }
        cout << output[i]<< endl;
    }
    else cout << "Not in this grammar"<< endl;
    
}