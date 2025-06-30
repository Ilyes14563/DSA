"""
Palindrome Partitioning
Source: https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
"""

def min_palindrome_cuts(s):
    n = len(s)
    dp = [0] * n
    palindrome = [[False]*n for _ in range(n)]
    for i in range(n):
        min_cut = i
        for j in range(i+1):
            if s[j] == s[i] and (i-j < 2 or palindrome[j+1][i-1]):
                palindrome[j][i] = True
                min_cut = 0 if j == 0 else min(min_cut, dp[j-1]+1)
        dp[i] = min_cut
    return dp[-1]

# Example usage:
if __name__ == "__main__":
    s = "ababbbabbababa"
    print(min_palindrome_cuts(s))  # Output: 3 