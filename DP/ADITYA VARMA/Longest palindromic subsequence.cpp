//LONGEST PALINDROMIC SUBSEQUENCE
//X:
//Y:ABFCE
//aakashaggarwal
//aakanshagga
//choice-ok longest DP

#include<bits/stdc++.h>
using namespace std;

int recursion(string x,string y,int n,int m);
string topdown2(string x,string y,int n,int m);
string topdown1(string x,string y,int n,int m);



int main()
{
    time_t start, end;
    time(&start);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x,y;
    cin>>x;

    int n=x.size();
    y=x;
    reverse(y.begin(),y.end());
    //RECURSION METHOD

    //cout<<recursion(x,y,n,m)<<"\n";

    //TOPDOWN1
    cout<<topdown1(x,y,n,n)<<"\n";
    //TOPDOWN2
    cout<<topdown2(x,y,n,n)<<"\n";


    time(&end);
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed<< time_taken << setprecision(5)<< " sec " << endl;


}

//RECURSION
int recursion(string x,string y,int n,int m)
{
    if(n==0 || m==0)
    {
        return 0;
    }


    if(x[n-1]==y[m-1])
    {
        return 1+recursion(x,y,n-1,m-1);

    }
    else
    {
        return max(recursion(x,y,n-1,m),recursion(x,y,n,m-1));
    }

}


//TOPDOWN1
string topdown1(string x,string y,int n,int m)
{
    string lcs;
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        dp[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;

            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    //return dp[n][m];

    int a=n;
    int b=m;

    while(a!=0 && b!=0)
    {
        if(x[a-1]==y[b-1])
        {
            lcs+=x[a-1];
            a--;
            b--;
        }
        else
        {
            if(dp[a-1][b]>dp[a][b-1])
            {
                a--;
            }
            else
            {
                b--;
            }
        }
    }

    reverse(lcs.begin(),lcs.end());

    return lcs;


}



//TOPDOWN2
string topdown2(string x,string y,int n,int m)
{
    //string lcs;
    string dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        dp[i][0]="";
    }
    for(int i=0;i<=m;i++)
    {
        dp[0][i]="";
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+x[i-1];

            }
            else
            {
                if(dp[i-1][j].size()>dp[i][j-1].size())
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }

    return dp[n][m];



}
