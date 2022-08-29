Q3. Special Index
Solved
character backgroundcharacter
Stuck somewhere?
Ask for help from a TA and get it resolved.
Get help from TA.
Problem Description
Given an array, arr[] of size N, the task is to find the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.



Problem Constraints
1 <= n <= 105
-105 <= A[i] <= 105


Input Format
First argument contains an array A of integers of size N


Output Format
Return the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.



Example Input
Input 1:
A=[2, 1, 6, 4]
Input 2:

A=[1, 1, 1]


Example Output
Output 1:
1
Output 2:

3


Example Explanation
Explanation 1:
Removing arr[1] from the array modifies arr[] to { 2, 6, 4 } such that, arr[0] + arr[2] = arr[1]. 
Therefore, the required output is 1. 
Explanation 2:

Removing arr[0] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Removing arr[1] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Removing arr[2] from the given array modifies arr[] to { 1, 1 } such that arr[0] = arr[1] 
Therefore, the required output is 3.
  
SOLUTION : 
  
  int Solution::solve(vector<int> &A) {

    int n = A.size();

    vector<int> E(n);
    vector<int> O(n);

    E[0] = A[0];
    O[0] = 0;
   
    int evensum = 0, oddsum = 0;

    for(int i=1; i<A.size(); i++)
    {
        if(i%2 == 0)
        {
            E[i] = A[i] + E[i-1];
            O[i] = O[i-1];
        }
        else
        {
            E[i] = E[i-1];
            O[i] = A[i] + O[i-1];
        }
    }

    int count = 0;

    for(int i=0; i<n; i++)
    {
        evensum = E[i-1] + (O[n-1] - O[i]);
        oddsum = O[i-1] + (E[n-1] - E[i]);

        if(evensum == oddsum)
        {
            count++;
        }

    }

    return count;
    
}
