# Longest Common Subsequence
- Problem: https://leetcode.com/problems/longest-common-subsequence/


``` cadence
Here state lcs(i,j) defines - length of lcs from (i,j) to (m,n)

// Recursion + Memo
    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i==s1.length() || j==s2.length()){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;

        if(s1[i]==s2[j]){
            ans = 1+lcs(i+1,j+1,s1,s2, dp);
        }else{
            ans = max(lcs(i+1,j,s1,s2, dp), lcs(i,j+1,s1,s2, dp));
        }

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return lcs(0,0,s1,s2,dp);


        //Iterative
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        return dp[0][0];

        // Space Optimised
        vector<int> next(n+1, 0);

        for(int i=m-1;i>=0;i--){
            vector<int> cur(n+1, 0);

            for(int j=n-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    cur[j] = 1 + next[j+1];
                }else{
                    cur[j] = max(next[j], cur[j+1]);
                }
            }
            next = cur;
        }

        return next[0];
    }
```


## To Print the LCS
- Form the DP table using iterative the parse it based on the answers of each state

``` cadence
    string findLCS(int n, int m, string &s1, string &s2){
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=n-1;i>=0;i--){
	    for(int j=m-1;j>=0;j--){
		if(s1[i]==s2[j]) dp[i][j] = 1 + dp[i+1][j+1];
		else{
		    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
		}
	    }
	}

	string ans = "";
	int i,j;
	i=j=0;

	while(i<=n && j<=m && dp[i][j]!=0){
	    if(s1[i]==s2[j]){
		ans+=s1[i];
		i+=1;j+=1;
	    }else{
		if(dp[i][j]==dp[i+1][j]){
		    i+=1;
		}else{
		    j+=1;
		}
	    }
	}

	return ans;
    }
```


## Problems:
1. [Longest Common Substring](https://www.naukri.com/code360/problems/longest-common-substring_1235207)
2. [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/description/)
3. [Min Insertions to make String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/)
4. [Delete Operations to make two Strings Same](https://leetcode.com/problems/delete-operation-for-two-strings/description/)
