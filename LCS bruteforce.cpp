#include<bits/stdc++.h>
using namespace std;
void lcs()
{
    char str1[100],str2[100];
    cout<<"Enter text1:"<<endl;
    cin>>str1;
    getchar();
    cout<<"Enter text2:"<<endl;
    cin>>str2;
    getchar();
    //cout<<str1<<" :::::: "<<str2<<endl;
    int len1=strlen(str1),len2=strlen(str2);
    int ara[100][100];
    memset(ara,-1,sizeof(ara));
    for(int i=0; i<=len1+1; i++)
    {
        ara[i][0]=0;
    }
    for(int i=0; i<=len2+1; i++)
    {
        ara[0][i]=0;
    }
    int kk=0,pev=0,mx=0;
    char path[100];
    for(int i=1; i<=len1+1; i++)
    {
        for(int j=1; j<=len2+1; j++)
        {
            if(str2[i-1]==str1[j-1])
            {
                ara[i][j]=ara[i-1][j-1]+1;
                if(ara[i][j]>mx)
                {
                    mx=ara[i][j];
                    if(ara[i-1][j-1]<ara[i][j])
                        path[kk++]=str2[i-1];
                }
            }
            else
            {
                ara[i][j]=max(ara[i-1][j],ara[i][j-1]);
                if(ara[i][j]>mx)
                {
                    mx=ara[i][j];
                }
            }
        }
    }
    path[kk]='\0';
    /*for(int i=0; i<=len1+1; i++)
    {
        for(int j=0; j<=len2+1; j++)
        {
            cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    cout<<"Longest common subsequence "<<ara[len1+1][len2+1]<<endl;
    for(int i=0; i<strlen(path); i++)
    {
        cout<<path[i];
    }
    cout<<endl;

}
int main()
{
    lcs();
}
