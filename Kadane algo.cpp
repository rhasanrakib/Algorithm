#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ara[100];
    int i,n,start_point,end_point_max;
    printf("Input arrray elemnts numbers:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&ara[i]);
    }
    start_point=0;
    end_point_max=0;
    for(i=0;i<n;i++){
        end_point_max=end_point_max + ara[i];
        if(end_point_max<0){
            end_point_max=0;
        }
        if(start_point<end_point_max){
            start_point=end_point_max;
        }
    }
    printf("Largest Sum Contiguous Subarray is   %  d\n",start_point);
    return 0;
}
