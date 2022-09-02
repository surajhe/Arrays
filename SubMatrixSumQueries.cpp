Given a matrix of integers A of size N x M and multiple queries Q, for each query, find and return the submatrix sum.

Inputs to queries are top left (b, c) and bottom right (d, e) indexes of submatrix whose sum is to find out.
  
  
 vector<int> Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E) {

  int n=A.size();
   int m=A[0].size();
   
  
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<m;j++)
        {
           // A[i][j]%=1000000007;
          A[i][j]=A[i][j]+(count);
          if(A[i][j]<0)
          {
              A[i][j]+=1000000007;
          }
          else
          {
              A[i][j]%=1000000007;
          }
          count=A[i][j];
          
        }
    }
    for(int i=0;i<m;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
          // A[j][i]%=1000000007; 
          A[j][i]+=count;
          if(A[j][i]<0)
          {
              A[j][i]+=1000000007;
          }
          else
          {
              A[j][i]%=1000000007;
          }
          count=A[j][i];
          
        }
    }
    vector<int> f(B.size(),0);
    for(int i=0;i<B.size();i++)
    {
      int  a=B[i]-1;
        int b=C[i]-1;
        int c=D[i]-1;
        int d=E[i]-1;
        int l=A[c][d];
        
        int m=0;
        int n=0;
        int o=0;
        if(b!=0)
        {
        m=A[c][b-1];
        }
        else
        {
           m=0;
        }
        if(a!=0)
        {
        n=A[a-1][d];
        }
        else
        {
           n=0;
        }
        if(a!=0 && b!=0)
        {
        o=A[a-1][b-1];
        }
        else
        {
          o=0;
        }
      //  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
       // cout<<l<<" "<<m<<" "<<n<<" "<<o<<endl;
    
    
    f[i]=(l-m-n+o);
    if(f[i]<0)
    {
        f[i]+=1000000007;
    }
    else
    {
        f[i]%=1000000007;
    }
    
    
    
    }
    for(int i=0;i<B.size();i++)
    {
        if(f[i]<0)
        {
            f[i]+=1000000007;
        }
    }

return f;

}
 
