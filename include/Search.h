#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        input = nums;
        minStep = nums.size();
        dfs(0, 0);
        return minStep;
    }
    
    void dfs(int indexBegin, int stepUsed)
    {
        if(indexBegin == input.size() - 1)
        {
            if (minStep > stepUsed)
            {
				minStep = stepUsed;
            }
            return;
        }

        if(stepUsed >= minStep || indexBegin >= input.size() || input[indexBegin] == 0)
        {
            return;
        }

        for(int i = input[indexBegin]; i >= 1; --i)
        {
            dfs(indexBegin+i, stepUsed+1);
        }
        
    }

private:
    vector<int> input;
    int minStep;
};