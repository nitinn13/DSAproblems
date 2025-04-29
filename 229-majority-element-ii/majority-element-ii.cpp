class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Initialize two candidates and their counts
        int candidate1 = -1, candidate2 = -1;
        int count1 = 0, count2 = 0;
        
        // Step 2: Find the candidates
        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        // Step 3: Verify the candidates
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }
        
        vector<int> ans;
        if (count1 > n / 3) ans.push_back(candidate1);
        if (count2 > n / 3) ans.push_back(candidate2);
        
        return ans;
    }
};
