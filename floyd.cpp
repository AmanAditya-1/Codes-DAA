#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    int m[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>m[i][j];
        }
    }

    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(m[i][k]>0)
            {
                for(int j=1;j<=n;j++)
                {
                    if(m[k][j]>0 && m[i][j]>(m[i][k]+m[k][j]))
                    {
                        m[i][j]=m[i][k]+m[k][j];
                    }
                }
            }
        }
    }

    cout<<"Output:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
    

    return 0;
}