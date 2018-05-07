#include<bits/stdc++.h>
using namespace std;
int precedence(char ch)
{
    if(ch=='^')return 4;
    else if(ch=='*')return 3;
    else if(ch=='/')return 3;
    else if(ch=='+')return 2;
    else if(ch=='-')return 2;
    else return 0;
}
int main()
{
    char str[1000];
    char ch;
    while(gets(str))
    {
        string ss="";
        int len=strlen(str);
        int i,j,k,order;
        stack<char>stk;
        for(i=0;i<len;i++)
        {
            ch=str[i];
            if(ch=='(')
                stk.push(ch);
            else if(ch==')')
            {
                while(!stk.empty() && stk.top()!='(')
                {
                    ss+=stk.top();
                    stk.pop();
                }
                if(!stk.empty()&& stk.top()=='(')
                    stk.pop();
            }
            else
            {
                order=precedence(ch);
                if(order==0)
                    ss+=ch;
                else
                {
                    if(stk.empty())
                        stk.push(ch);
                    else
                    {
                        while(!stk.empty()&& stk.top()!='(' && order<=precedence(stk.top()))
                        {
                            ss+=stk.top();
                            stk.pop();
                        }
                        stk.push(ch);
                    }
                }
            }
        }
        while(!stk.empty())
        {
            ss+=stk.top();
            stk.pop();
        }
        cout<<ss<<endl;
    }

}
