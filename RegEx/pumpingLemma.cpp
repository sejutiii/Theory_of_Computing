#include<bits/stdc++.h>

using namespace std;

//string input= "0^n1^n";
int n= 10;

int inputparsing(string str)
{
    int index=5, num;
    if(str[0]=='0' && str[1]== '^' && str[2]== 'n' && str[3]== '1' && str[4]== '^')
    {
        char a= str[5];
        if(a == 'n') num=1;
        else
        {
            char b[10];
            int ind=0;
            for(int i=5; i<str.length()-1; i++)
            {
            b[ind++]= str[i];
            }
            num= atoi(b);
        }
    }
    else num= -1;
    cout << num << endl;
    return num;
}
int main()
{
    string input;
    cout << "Enter the input str: ";
    cin >> input;
    int num= inputparsing(input);

    string w,x,y,z;
    for(int i=0; i<n; i++)
    {
        w.append("0");
    }
    for(int i=n; i<num*n; i++)
    {
        w.append("1");
    }
    
   int p1, p2;
   p1= n/2;
   p2= n;

   for(int i=0; i<p1; i++)
   {
        x = x + w[i];
   }

    for(int i=p1; i<p2; i++)
   {
        y+= w[i];
   }


    for(int i=p2; i<2*n; i++)
   {
        y+= w[i];
   }

   int k=0; 
   bool flag = false;
   while(k>=0)
   {
        string temp= x;
        for(int i=0; i<k; i++)
        {
            temp += y;
        }
        temp += z;

        int i, count1, count2=0;
        for(i=0; i<temp.length(); i++)
        {
            if(temp[i]== '0') continue;
            else break;
        }
        count1= i;
        for( ; i<temp.length(); i++)
        {
            count2++;
        }
        if(count1 == n && count2== num*n) continue;
        else
        {
            flag= false;
            break;
        }
   }

   if(flag== false)
   {
    cout << "Not a regular language" << endl;
   }
    
}