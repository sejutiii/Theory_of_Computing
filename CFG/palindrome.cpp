#include<bits/stdc++.h>

using namespace std;

vector<char> variables= {'S', 'A', 'B'};
int numVariable= 3;
vector<char> terminal= {'0', '1'};
vector<pair<char, vector<string>>> production;

bool isVariable(char c)
{
    for(int i=0; i<numVariable; i++)
    {
        if(c == variables[i]) return true;
    }
    return false;
}

int main()
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

    string input;
    vector<string> output;
    output.push_back("S");

    cout << "Enter the input string: ";
    cin >> input;

    for(int i=0; i<input.size(); i++)
    {
        string temp= output.back();
        
        for(int j=0; j<temp.size(); j++)
        {
            if(temp[j] == terminal[0] || temp[j]== terminal[1]) continue;

            else{
                
                string pre= temp.substr(0, j);
                string post= temp.substr(j+1);

                for(int k=0; k<numVariable; k++)
                {
                    if(temp[j] == production[k].first)
                    {
                        for(int l=0; l<production[k].second.size(); l++)
                        {
                            
                            if(input[i] == production[k].second[l][0])
                            {
                                cout << production[k].second[l] << endl;
                                temp= pre;
                                temp += production[k].second[l];
                                temp += post;
                                break;
                            }

                            else if(production[k].second.size()==1)
                            {
                                cout << "hello " << production[k].second[l]<<endl;
                                temp= pre;
                                temp += production[k].second[l];
                                temp += post;
                                break;
                            }
                            // else{
                            //     temp= pre;
                            //     temp += post;
                            //     break;
                            // }
                        }
                        break;
                    }
                }
                break;
            }
        }

        output.push_back(temp);
    }

    cout << "leftmost -> ";
    for(int i=0; i<output.size()-1; i++)
    {
        cout << output[i] << " -> ";
    }
    cout << output.back() << endl;
}