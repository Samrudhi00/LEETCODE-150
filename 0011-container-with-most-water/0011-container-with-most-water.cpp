class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        for(int L=0;L<height.size();L++){
            for(int R=L+1;R<height.size();R++){
                int area =(R-L) * min(height[L],height[R]);
                ans = max(ans,area);

            }
        }
        return ans;
        
    }
};