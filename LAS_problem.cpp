#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
// Utility function to find the length of the longest alternating subsequence.
int util(vector<int> const &A, int start, int end, bool flag)
{
    int result = 0;
    for (int i = start; i <= end; i++)
    {
        if (flag && A[i - 1] < A[i]) {
            result = max(result, 1 + util(A, i + 1, end, !flag));
        }
        else if (!flag && A[i - 1] > A[i]) {
            result = max(result, 1 + util(A, i + 1, end, !flag));
        }
        else {
            result = max(result, util(A, i + 1, end, flag));
        }
    }
 
    return result;
}
 
// Function to find the length of the longest subsequence with alternate
// low and high elements. It calls the `util()` method.
int findLongestSequence(vector<int> const &A)
{
    int n = A.size();
 
    // base case
    if (n == 0) {
        return 0;
    }
 
    // Fix the first element and recur for the remaining elements as the first
    // element will always be part of the longest subsequence
 
    return 1 + max(util(A, 1, n - 1, true), util(A, 1, n - 1, false));
 
}
 
int main()
{
    vector<int> A = { 8, 9, 6, 4, 5, 7, 3, 2, 4 };

    cout << "The length of the longest alternating subsequence is "
         << findLongestSequence(A);
 
    return 0;
}