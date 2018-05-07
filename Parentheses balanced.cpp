#include<bits/stdc++.h>
using namespace std;

int main()
{
    string ss;
    stack<char>stk;
    while(cin>>ss)
    {
        int len=ss.length();
        bool chk=true;
        for(int i=0; i<len; i++)
        {
            if(ss[i]=='(' || ss[i]=='{' || ss[i] == '[')
            {
                stk.push(ss[i]);
            }
            if(ss[i]==')' || ss[i]=='}' || ss[i]==']')
            {
                char a=ss[i];
                char name=stk.top();
                stk.pop();
                if(name==')' && a!='(')
                {
                    chk=false;
                    cout<<"Not Balanced"<<endl;
                    break;
                }
                if(name=='}' && a!='{')
                {
                    chk=false;
                    cout<<"Not Balanced"<<endl;
                    break;
                }
                if(name==']' && a!='[')
                {
                    chk=false;
                    cout<<"Not Balanced"<<endl;
                    break;
                }
            }
        }
        if(stk.empty())
            cout<<"Balanced"<<endl;
        else
            cout<<"Not Balanced"<<endl;
    }
    main() ;
}
