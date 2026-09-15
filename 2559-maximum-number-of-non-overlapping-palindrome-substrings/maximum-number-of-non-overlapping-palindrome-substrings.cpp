class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int maximumPalindrome(string &s,int k,int i,int j,vector<vector<int>>&dp){
        if(j>=s.size()) return 0;
        //take or not take
        //if i take this part and there is two condition if it is palindrome so i stop and if not i have to increase j
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(isPalindrome(s,i,j)){
           ans=ans+1+maximumPalindrome(s,k,j+1,j+k,dp);
        }
        else{
            ans=ans+max(maximumPalindrome(s,k,i,j+1,dp),maximumPalindrome(s,k,i+1,j+1,dp));

        }
        return dp[i][j]=ans;
    }
    int maxPalindromes(string s, int k) {
        if(k>s.size()) return 0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return maximumPalindrome(s,k,0,k-1,dp);
    }
};