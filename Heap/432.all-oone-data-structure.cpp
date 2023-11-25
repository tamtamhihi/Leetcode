/*
https://leetcode.com/problems/all-oone-data-structure/

Keep track of the count of each string using a map.
To easily find min and max count, I use a min-heap and a max-heap. Each element in the heap should be a pair of (count, key).
- Increase, decrease: update in the map and push 2 new elements to the min and max heap 
- Get max, min: pop from heap. But remove the redundant pairs (which have the count different than the count stored in the map)

Optimization:
To save space, I will give each string an index, so that the heap element is now 2 integers (count, index).
*/

#define pii pair<int, int>

struct MaxCount {
    bool operator() (const pii& a, const pii& b) {
        return a.first < b.first;
    }
};

struct MinCount {
    bool operator() (const pii& a, const pii& b) {
        return a.first > b.first;
    }
};

class AllOne {
private:
    priority_queue<pii, vector<pii>, MaxCount> maxHeap;
    priority_queue<pii, vector<pii>, MinCount> minHeap;
    unordered_map<string, int> stringIndex;
    unordered_map<int, string> indexToString;
    unordered_map<int, int> stringCount;
    int index;
public:
    AllOne() {
        index = 0;
    }
    
    void inc(string key) {
        int idx;
        if (stringIndex.find(key) != stringIndex.end()) {
            idx = stringIndex[key];
            stringCount[idx] += 1;
        } else {
            idx = index++;
            stringIndex[key] = idx;
            indexToString[idx] = key;
            stringCount[idx] = 1;
        }
        maxHeap.push(make_pair(stringCount[idx], idx));
        minHeap.push(make_pair(stringCount[idx], idx));
    }
    
    void dec(string key) {
        int idx = stringIndex[key];
        stringCount[idx] -= 1;
    }
    
    string getMaxKey() {
        while (!maxHeap.empty()) {
            pii key = maxHeap.top();
            if (key.first != stringCount[key.second]) {
                maxHeap.pop();
            } else {
                break;
            }
        }
        if (maxHeap.empty()) {
            return "";
        }
        return indexToString[maxHeap.top().second];
    }
    
    string getMinKey() {
        while (!minHeap.empty()) {
            pii key = minHeap.top();
            if (key.first != stringCount[key.second]) {
                minHeap.pop();
            } else {
                break;
            }
        }
        if (minHeap.empty()) {
            return "";
        }
        return indexToString[minHeap.top().second];
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
