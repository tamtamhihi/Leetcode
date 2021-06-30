class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Use a hashed map to map encountered values with its index.
        unordered_map<int, int> valueToIndex;
        vector<int> answer(2);
        
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            
            // If target - num is already encountered,
            // we return these 2 indices because num + (target - num) = target
            if (valueToIndex.find(target - num) != valueToIndex.end()) {
                answer[0] = i;
                answer[1] = valueToIndex[target - num];
                return answer;
            }
            // Else we add num to hashed map.
            valueToIndex.insert(make_pair(num, i));
        }
        return answer;
    }
};