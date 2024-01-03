class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevR = 0;
        int currR = 0;
        int total = 0;
        int row = bank.size();
        int col = bank[0].size();
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(bank[i][j] == '1')currR++;
            }
            total += prevR*currR;
            if(currR != 0)
            {
                prevR = currR;
                currR = 0;
            }
        }
        return total;
    }
};