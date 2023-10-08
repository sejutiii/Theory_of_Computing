#include<bits/stdc++.h>

using namespace std;

//string input= "0^n1^n";
int n= 10;

int power_0, power_1;
int inputparsing(string str)
{
    int i;
    if(str[0] != '0' || str[1] != '^' ) return -1;
    else
    {
        i=2;
        if(str[i]== 'n') power_0= 1;
        else
        {
            char temp[10];
            int ind=0;
            while(str[i] != 'n')
            {
                temp[ind++]= str[i++];
            }
            
            power_0= atoi(temp);
        }
    }
    i++;
    if(str[i] != '1' || str[++i] != '^') return -1;
    else
    {
        i++;
        if(str[i]== 'n') power_1= 1;
        else
        {
            char temp[10];
            int ind=0;
            while(str[i] != 'n')
            {
                temp[ind++]= str[i++];
            }
            
            power_1= atoi(temp);
        }
    }

    return power_1;
}
int main()
{
    string input;
    cout << "Enter the input str: ";
    cin >> input;
    int co_eff1= inputparsing(input);
    if(co_eff1== -1) 
    {
        cout << "Invalid input format" << endl;
        exit (1);
    }
    int co_eff0= power_0;
    string w,x,y,z;
    for(int i=0; i<co_eff0*n; i++)
    {
        w.append("0");
    }
    for(int i=n; i<co_eff1*n; i++)
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
        int new_n= count1/co_eff0;
        if(co_eff1*new_n == count2) continue;
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