#include <iostream>
#include<cstdio>
using namespace std;
int n;
int c=0;
bool Arr[20][20];
bool col[20];
bool check(int row, int col)
{
    int k;
    for(k=0;k<n;k++)
    {
        if(row-k>=0&&col-k>=0)
            if(Arr[row-k][col-k])
            return false;
        if(row-k>=0&&col+k<n)
            if(Arr[row-k][col+k])
            return false;
    }

    return true;
}
bool NQueen(int i=0)
{
    int x=0, j;

    if(i==n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(Arr[i][j]==1)
                    printf("1\t");
                else
                    printf("0\t");
            }
            printf("\n");
        }
        printf("\n");
        c++;
    }
    else if(i<n)
    for(j=0;j<n;j++)
    {

        if(Arr[i][j]==0&&col[j]==0)
        {
            if(check(i, j))
             {
                Arr[i][j]=1;col[j]=1;
            
				x=NQueen(i+1);
        
                if(x==0)
                {
                    Arr[i][j]=0;col[j]=0;
                }
            }
        }
    }
    return 0;
}
int main()
{
    int i, j;
    cout<<"enter the value of n";
    cin>>n;
        for(i=0;i<n;i++)
        {
            col[i]=0;
            for(j=0;j<n;j++)
                Arr[i][j]=0;
        }
        if(n==1)
        {
            printf("1\n");
        }
        if(n>3)
        NQueen(0);
        else
        {
            printf("Not Possible\n");
        }
        cout<<c;
    
    return 0;
}

