Problem Description
You are given an array A of integers of size N.

Your task is to find the equilibrium index of the given array

The equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.

NOTE:

Array indexing starts from 0.
If there is no equilibrium index then return -1.
If there are more than one equilibrium indexes then return the minimum index.



Problem Constraints
1 <= N <= 105
-105 <= A[i] <= 105


Input Format
First arugment is an array A .


Output Format
Return the equilibrium index of the given array. If no such index is found then return -1.


Example Input
Input 1:
A=[-7, 1, 5, 2, -4, 3, 0]
Input 2:

A=[1,2,3]



int Solution::solve(vector<int> &A) {

    int sum = 0;
    int leftsum = 0;

    int  n = A.size();

    for(int i=0; i<n; i++)
    {
        sum += A[i];
    }

    for(int i=0; i<n; i++)
    {
        sum -= A[i];

        if(leftsum == sum)
        {
            return i;
        }

        leftsum += A[i]; 
    }

    return -1;
}
