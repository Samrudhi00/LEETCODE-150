class Solution {
public:
    void reverseWords(string &s) {
        s=s+" ";
    	string str="";
    	string ret="";
    	for(int i=0;i<s.length();i++){
    		if(s[i]!=' '){
    			str+=s[i];
    		}
    		else if(s[i]==' '){
    			ret=str+" "+ret;
    			str="";	
    		}
    	}
    	s=ret;
    	int i,k;
        for(i=0,k=0;i<s.length();i++){
            if((s[i]==' ')){
                k++;
            }
            else if(s[i]!=' '){
                break;
            }
        }
        s.erase(0,k);
    }
};