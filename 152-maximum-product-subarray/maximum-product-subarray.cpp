#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(const std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) {
                std::swap(maxProduct, minProduct); // Swap when encountering a negative number
            }
            maxProduct = std::max(nums[i], maxProduct * nums[i]);
            minProduct = std::min(nums[i], minProduct * nums[i]);
            
            result = std::max(result, maxProduct);
        }
        return result;
    }
};
