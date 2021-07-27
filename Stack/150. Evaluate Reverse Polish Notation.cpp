#define ll long long
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<char> operators;
        operators.insert('+');
        operators.insert('-');
        operators.insert('*');
        operators.insert('/');
        
        stack<ll> s;
        for (string token : tokens) {
            // If we find out and operator, we immediately
            // get out 2 numbers and conduct the operation,
            // then push back to stack.
            if (token.size() == 1 && operators.find(token[0]) != operators.end()) {
                ll num2 = s.top();
                s.pop();
                ll num1 = s.top();
                s.pop();
                if (token[0] == '+')
                    s.push(num1 + num2);
                else if (token[0] == '-')
                    s.push(num1 - num2);
                else if (token[0] == '*')
                    s.push(num1 * num2);
                else {
                    ll div;
                    if (num1 * num2 < 0) {
                        num1 = abs(num1);
                        num2 = abs(num2);
                        div = num1 / num2;
                        div *= -1;
                    } else {
                        div = num1 / num2;
                    }
                    s.push(div);
                }
            }
            
            // If token is a number, we just push into stack.
            else {
                s.push(stoll(token));
            }
        }
        
        return (int)s.top();
    }
};
