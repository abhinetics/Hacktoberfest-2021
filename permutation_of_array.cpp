// C++ code for generating allpermutation of given array
// Leetcode proble 49. permutation (https://leetcode.com/problems/permutations/)

class Solution {
public:
    vector<vector<int>> ans;
    //call function permute() for generate permutation of array
    vector<vector<int>> permute(vector<int>& a) {
        makePermution(0,a);
        return ans;
    }
private:
    void makePermution(int index,vector<int>& a)
    {
        if(index==a.size())
        {
            ans.push_back(a);
        }
        for(int i=index;i<a.size();i++)
        {
            swap(a[i],a[index]);
            makePermution(index+1,a);
            swap(a[i],a[index]);
        }
    }
};
