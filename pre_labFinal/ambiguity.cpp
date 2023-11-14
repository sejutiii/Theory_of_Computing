#include<bits/stdc++.h>
using namespace std;
vector<string> leftD;
unordered_map<char,vector<string>> mp;
string str;
int val = 0;
void check(string current){
    if(current == str){
        val++;
        cout << leftD[0];
        for(int i=1; i<leftD.size(); i++){
            cout << " => " << leftD[i];
        }
        cout << " => " << current;
        cout << endl << endl;
        return;
    }
    if(current.find('S') == string::npos){
        return;
    }
    for(auto prod: mp['S']){
        int i;
        for(i=0; i<current.size(); i++){
            if(current[i] == 'S') break;
        }
        if(i > str.size()){
            return;
        }
        leftD.push_back(current);
        string present = current.substr(0,i) + prod + current.substr(i+1,current.size());
        check(present);
        leftD.pop_back();
    }
}
// S = aS = aaSbS = aabS = aab
// S = aSbS = aaSbS = aabS
int main(){
    mp['S'] = {"aS","aSbS",""};
    cout << "Enter a string: ";
    cin >> str;
    for(auto s: str){
        if(s != 'a' && s!= 'b'){
            cout << "Your input is invalid !" << endl;
            return 0;
        }
    }
    cout << endl;
    string present = "S";
    check(present);
    if(val > 1){
        cout << "This grammer is Ambigous!" << endl;
    }
    else{
        cout << "This grammer is not Ambigous!" << endl;
    }
    return 0;
}