#include<bits/stdc++.h>
using namespace std;
#define lmt 1000
vector<int>store;
int state[lmt+10]
void seieve()
{
    for(int i=0;i<=lmt;i++)
        state[i]=0;
    state[0]=state[1]=1;
    for(int i=4;i<=lmt;i++)
        state[i]=1;
    int root =sqrt(lmt);
    for(int i=3;i<lmt;i+=2)
    {
        if(state[i]==0)
        {
            for(int j=i*i;j<root;j+=i)
            {
                state[j]=1;
            }
        }
    }
}
int main()
{
    seive()
    int i,j,k,n;
    cin>>n;

}
