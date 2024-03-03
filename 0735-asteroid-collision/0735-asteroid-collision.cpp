class Solution {
public:
    vector<int> asteroidCollision(std::vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stack;
        stack.push(asteroids[n - 1]);
        int i = n - 2;
        while (i >= 0) {
            int a = asteroids[i];
            if (stack.empty()) {
                stack.push(a);
                i--;
                continue;
            }
            int b = stack.top();
            stack.pop();
            if (isSameDirection(a, b) ||(a<0 && b>0)) {
                stack.push(b);
                stack.push(a);
            } else if(abs(a) > abs(b)){
                 stack.push(a);
            }else if (abs(a) < abs(b)){
                 stack.push(b);
            }
            
            // else {
            //     if (a < 0 && b > 0) {
            //         stack.push(b);
            //         stack.push(a);
            //     } else {
            //         if (abs(a) > abs(b))
            //             stack.push(a);
            //         else if (abs(a) < abs(b))
            //             stack.push(b);
            //     }
            // }
            if (stack.size() > 1) {
                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                stack.push(b);
                stack.push(a);

                if (!isSameDirection(a, b)) {
                    if (a < 0 && b > 0) {
                        // do nothing
                    } else {
                        stack.pop();
                        continue;
                    }
                }
            }
            i--;
        }
        vector<int> ans;
        while (!stack.empty()) {
            ans.push_back(stack.top());
            stack.pop();
        }
        return ans;
    }
    bool isSameDirection(int a, int b) {
        return (a > 0 && b > 0) || (a < 0 && b < 0);
    }
};