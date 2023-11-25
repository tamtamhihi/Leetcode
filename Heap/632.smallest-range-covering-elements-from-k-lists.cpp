/*
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

1. We first merge the k-sorted list into a single sorted list. 
The merged list contains both element value + the index of the array it belongs to (from 0 to k-1).

2. We use 2 pointers to find the minimum window (in value) that contains elements from all k lists.
*/

// ==== Struct to store a value together with the array index ====
class Val {
public:
    int value;
    int arrayIndex;
    int index;
    Val(int value, int arrayIndex, int index) : value(value), arrayIndex(arrayIndex), index(index) {}
};

// ==== Comparator class to create min-heap for Val class when we merge k-sorted list ====
class Option {
public:
    bool operator() (const Val& a, const Val& b) {
        return a.value > b.value;
    }
};

class Solution {
public:
    vector<Val> mergeLists(vector<vector<int>>& nums) {
        int k = nums.size();

        // put the first value in each array to the min-heap
        priority_queue<Val, vector<Val>, Option> pq;
        for (int i = 0; i < k; ++i) {
            pq.push(Val(nums[i][0], i, 0));
        }

        // merge k-sorted list
        vector<Val> results;
        while (!pq.empty()) {
            Val val = pq.top();
            pq.pop();

            if (val.index < nums[val.arrayIndex].size() - 1)  {
                pq.push(Val(nums[val.arrayIndex][val.index + 1], val.arrayIndex, val.index + 1));
            }

            results.push_back(val);
        }

        return results;
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<Val> merged = mergeLists(nums);

        vector<int> minimumRange = {-1, -1};
        int minimumRangeDiff = 1e9;

        // Keep track for the current window
        vector<int> countGroup(k, 0); // countGroup[i] = the number of values in the current "window" that belongs to group i
        int noGroups = 0;

        // 2 pointers
        int left = 0;
        for (int right = 0; right < merged.size(); ++right) {
            int groupId = merged[right].arrayIndex;
            countGroup[groupId] += 1;
            if (countGroup[groupId] == 1) {
                noGroups += 1;
            }
          
            // shrink the "left" pointer to obtain the minimum range
            while (noGroups == k) {
                int leftGroupId = merged[left].arrayIndex;
                if (countGroup[leftGroupId] == 1) {
                    // stop shrinking or else we do not have enough k groups
                    break;
                }
                countGroup[leftGroupId] -= 1;
                left += 1;
            }
          
            if (noGroups == k) {
                int currentRange = merged[right].value - merged[left].value;
                if (currentRange < minimumRangeDiff) {
                    minimumRangeDiff = currentRange;
                    minimumRange = {merged[left].value, merged[right].value};
                }
            }
        }

        return minimumRange;
    }
};
