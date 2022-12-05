#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> x)
{
    int n=x.size();
    int m[n][n];
    for(int i=1;i<n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j]=INT_MAX;
            for(int k=i;k<=j-1;k++)
            {
                int q=m[i][k]+m[k+1][j]+x[i-1]*x[j]*x[k];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                }
            }
        }
    }
    return m[1][n-1];
}
int main() 
{
    vector<int> v={10,100,20,5,80};
    cout<<"Max no of multiplications is: "<<mcm(v)<<endl;

    return 0;
}