class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i =0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i =k;i<nums.size();i++){
            int ele = nums[i];
            if(ele>pq.top()){
                pq.pop();
                pq.push(ele);

            }
        }
        return pq.top();
    }
};