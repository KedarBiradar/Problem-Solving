/*

'We fought far under the living earth, where time is not counted. Ever he clutched me, and ever I hewed him, till at last he fled into dark tunnels. Ever up now we went, until we came to the Endless Stair. Out he sprang, and even as I came behind, he burst into new flame. Those that looked up from afar thought that the mountain was crowned with storm. Thunder they heard, and lightning, they said, smote upon Celebdil, and leaped back broken into tongues of fire.' - Gandalf, describing his fight against the Balrog.

 

Although Gandalf would not go into the details of his battle, they can be summarized into the following simplified form: both Gandalf and the Balrog have a set of N attacks they can use (spells, swords, brute-force strength etc.). These attacks are numbered from 1 to N in increasing order of Power. When each has chosen an attack, in general, the one with the higher power wins. However, there are a few ("M") anomalous pairs of attacks, in which the lesser-powered attack wins.

 

Initially, Gandalf picks an attack. Then the Balrog counters it with one of the remaining attacks. If the Balrog's counter does not defeat Gandalf's, then we say Gandalf receives a score of 2. If however it does, then Gandalf has exactly one more opportunity to pick an attack that will defeat the Balrog's. If he manages to defeat him now, his score will be 1, whereas if he is still unable to defeat him, his score will be 0.

 

Your task is to determine, given N and the M anomalous pairs of attacks, what will be Gandalf's score, given that both play optimally. Further, in case Gandalf gets a score of 2, you must also determine which attack he could have chosen as his first choice.

 

Note 1: The Balrog can choose only one attack, whereas Gandalf can choose upto two.

Note 2: The relation A defeats B is not transitive within the attacks. For example, attack A can defeat attack B, attack B can defeat attack C, and attack C can defeat attack A.

Note 3: Between any two attacks A and B, either attack A defeats attack B or attack B defeats attack A.

 

Input (STDIN):

The first line will consist of the integer T, the number of test-cases.

Each test case begins with a single line containing two integers N and M.

This is followed by M lines consisting of 2 integers each x and y, denoting that x and y are an anomalous pair.

 

Output (STDOUT):

For each test-case, output a single line either

2 A, if Gandalf can defeat any attack the Balrog chooses if he picks attack A,

1, if Gandalf can choose an attack such that even if the Balrog chooses an attack to defeat him, he can choose an attack to defeat the Balrog's chosen card,

0, if none of the above two options are possible for all possible choices of Gandalf's attack(s).

Between successive test cases, there should not be any blank lines in the output.

 

Constraints:

1 <= T <= 15

3 <= N <= 1,000,000

0 <= M <= min(N(N-1)/2, 300,000)

1 <= x < y <= N for all the anomalous pairs (x,y)

The sum of M over all test-cases will not exceed 300,000.

 

Sample Input:

2

3 0

3 1

1 3 

 

Sample Output:

2 3

1

 

Notes/Explanation of Sample Input:

In the first case, attack 3 can beat both attacks 1 and 2. So Gandalf just chooses attack 3.

In the second case, attack 1 beats 3 which beats 2 which beats 1. No matter which attack Gandalf chooses, the Balrog can pick the one which defeats his, but then he can pick the remaining attack and defeat the Balrog's.
*/


#include <cstdio>
#include <algorithm>

using namespace std;
int main()
{
	int t;
	long int n,m,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld",&n,&m);
		if(m==0)
		{
			printf("2 %ld\n",n);
			continue;
		}
		
		int arr[n+1];
		for(i=1;i<=n;i++)
			arr[i]=i-1;
		for(i=0;i<m;i++)
		{
			scanf("%ld%ld",&a,&b);
			arr[a]++;
			arr[b]--;
		}
		for(i=1;i<=n;i++)
		{
			if(arr[i]==n-1)
			{
				printf("2 %ld\n",i);
				break;
			}
		}
		if(i==n+1)
			printf("1\n");
	}

	return 0;
}
