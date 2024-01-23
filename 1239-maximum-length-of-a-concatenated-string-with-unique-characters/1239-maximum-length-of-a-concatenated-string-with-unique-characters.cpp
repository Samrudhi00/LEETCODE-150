class Solution {
public:
    int maxLength(std::vector<std::string>& arr) {
        int maxLen = 0;
        int n = arr.size();

        for(int i = 0; i < n; i++){
            std::unordered_set<char> st;

            for(int j = i; j < n; j++){
                std::string s = arr[j];

                bool isValid = true;
                for(int k = 0; k < s.length(); k++){
                    if (st.count(s[k]) > 0) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) {
                    for(int k = 0; k < s.length(); k++){
                        st.insert(s[k]);
                    }
                    maxLen = max(maxLen, static_cast<int>(st.size()));
                }
                else {
                    break; // Break the inner loop if concatenation is not valid
                }
            }
        }

        return maxLen;
    }
};


// class Solution {
// public:
//     int maxLength(vector<string>& arr, string curr_str = "", int index = 0) {
	    
//       //Use set => if the string contains all unique characters 
//         unordered_set<char>s(curr_str.begin(), curr_str.end());
//         if (s.size() != (curr_str.length())) 
//         {
//              return 0;
//         }
     
//         int result = curr_str.length();
//         //recursion call
//         for (int i = index; i < arr.size(); i++){
//             result = max(result, maxLength(arr, curr_str+arr[i], i+1));
//         }

//         return result;

//     }
// };