class Fraction {
public:
    int num, denom, denomInd;
    Fraction(int num, int denom, int denomInd) {
        this->num = num;
        this->denom = denom;
        this->denomInd = denomInd;
    }
};

struct CompareFraction {
    bool operator() (const Fraction& a, const Fraction& b) {
        return (a.num * 1.0 / a.denom) > (b.num * 1.0 / b.denom);
    }
};

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Min heap.
        priority_queue<Fraction, vector<Fraction>, CompareFraction> pq;
        int n = arr.size();
        
        // The last element (arr[n-1]) cannot be the denominator,
        // so we try all possible numerators from arr[0] to arr[n-2].
        // Push the smallest possible fraction (which has arr[n-1] as denom).
        for (int i = 0; i < n-1; ++i) {
            Fraction fraction(arr[i], arr[n-1], n-1);
            pq.push(fraction);
        }
        
        // Pop first k-1 smallest fractions.
        for (int i = 0; i < k-1; ++i) {
            Fraction fraction = pq.top();
            pq.pop();
            // Take this num
            int num = fraction.num;
            // Get the next denom
            int nextDenom = arr[fraction.denomInd - 1];
            // Make sure than numInd < denomInd
            if (num != nextDenom) {
                Fraction newFraction(num, nextDenom, fraction.denomInd - 1);
                pq.push(newFraction);
            }
        }
        
        // k-th smallest
        vector<int> answer(2);
        answer[0] = pq.top().num;
        answer[1] = pq.top().denom;
        return answer;
    }
};
