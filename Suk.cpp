#include<bits/stdc++.h>
using namespace std;
string str;


void leftMostDerivation(string input)
{
    string s ="S";
    cout<< "Leftmost" << s;
    

    while(s!=input){
        bool flag = false;
        
        if(s[0]=='A' ){
            
            s="0A" + s.substr(1);
        }
        else if(s[0]=='B'){
            char c=input[s.length()-1];
            if(c == '0'){
                s = "0B" + s.substr(1);
            }else if ( c == '1'){
                s = "1B" + s.substr(1);
                flag = true;
            }
        }
        if(!flag){
            break;
        }
        cout <<"=>" << s;
        
      }
    cout<< endl;
    
}

// void rightMostDerivation(string input)
// {

// }
int main(){
    cin>>str;
    for(auto s :str){
        if(s!='1' && s!='0'){
            cout<<"Invalid input";
        }

    }
    
 leftMostDerivation(str);
}