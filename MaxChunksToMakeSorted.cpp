int Solution::solve(vector<int> &A) {

    int ma=0, cnt=0, i=0;

    for(auto x:A)
    {
        ma = max(ma,x);

        if(ma == i)
        {
            cnt++;
        }

        i=i+1;
    }

    return cnt;
}
