#define ll long long

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Min heap to store all possible ugly numbers.
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        
        // Smallest ugly number.
        pq.push(1);
        
        for (int i = 0; i < n-1; ++i) {
            // Get smallest candidate to be the next ugly number.
            ll nextUgly = pq.top();
            
            while (!pq.empty() && pq.top() == nextUgly)
                pq.pop();
            
            // Push other candidates.
            for (int prime : primes) {
                pq.push(nextUgly * prime);
            }
        }
        
        return (int)pq.top();
    }
};
