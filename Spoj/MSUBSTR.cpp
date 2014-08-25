#include <cstdio>
#include <string>
#include<iostream>

using namespace std;

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
int len,count;
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);

  ret += "#$";
  return ret;
}

void longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;

    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }

  // Find the maximum element in P.
  int ctr=0,maxLen = 0;
  for (int i = 1; i < n-1; i++) 
  {
    if (P[i] > maxLen) 
    {
      maxLen = P[i];
      ctr=1;
    }
    else if(P[i]==maxLen)
	ctr++;
  }
  delete[] P;
	len=maxLen;
	count=ctr;
}

int main()
{
	int t;
	string str;
	scanf("%d",&t);
	while(t--)
	{
		cin>>str;
		count=len=0;
		longestPalindrome(str);
		printf("%d %d\n",len,count);
	}
	return 0;
}
