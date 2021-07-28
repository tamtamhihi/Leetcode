#define ll long long
class Solution {
public:
    int nthUglyNumber(int n) {
        // A min heap to store all possible ugly numbers.
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        pq.push(1); // Smallest ugly number.
        
        // Pop first n-1 ugly numbers.
        for (int i = 0; i < n-1; ++i) {
            // Smallest candidate.
            ll t = pq.top();
            pq.pop();
            // Pop all other candidates with the same value.
            while (!pq.empty() && pq.top() == t)
                pq.pop();
            // Push 3 other candidates.
            pq.push(t * 2);
            pq.push(t * 3);
            pq.push(t * 5);
        }
        // n-th ugly number.
        return (int)pq.top();
    }
};
