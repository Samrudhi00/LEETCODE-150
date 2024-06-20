class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> num;
        while(x!=0){
            int digit= x%10;
            num.push_back(digit);
            x=x/10;
        }
        int n= num.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(num[i]!=num[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
        
    }
};