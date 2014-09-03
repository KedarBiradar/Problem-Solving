#include <cstdio>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{

	int t;
	scanf("%d",&t);
	string str,str1,str2;
	char oprnd1[100],oprnd2[100];	
	std::string::size_type sz = 0;
	while(t--)
	{

		int i,k,l,len;
		cin>>str;
		len=str.size();
		str1=str;

		//calculate max
		size_t found = str.find_first_of("+");
		while(found!=string::npos)
		{
			i=found-1;
			k=0;
			while(i>=0 && str[i]!='*' && str[i]!='+')
			{
				i--;
				//oprnd1[k++]=str[i--];
			}
			int start=i+1;
			i++;
			while(i<found)
				oprnd1[k++]=str[i++];
			oprnd1[k]='\0';
			i=found+1;
			l=0;
			while(i < len && str[i]!='*' && str[i]!='+')
			{
				oprnd2[l++]=str[i++];
			}
			int end=i;
			char *pend;
			oprnd2[l]='\0';
			long long int res=strtoll(oprnd1,&pend,10)+strtoll(oprnd2,&pend,10);
			char buffer[33];
			sprintf(buffer,"%lld",res);
			//cout<<start<<" "<<end<<endl;
			str.replace(start,end-start,string(buffer));
			//cout<<endl<<str<<endl;
			found = str.find_first_of("+");
		}

		
		found = str.find_first_of("*");
		while(found!=string::npos)
		{
			i=found-1;
			k=0;
			while(i>=0 && str[i]!='*' && str[i]!='+')
			{
				i--;
				//oprnd1[k++]=str[i--];
			}
			int start=i+1;
			i++;
			while(i<found)
				oprnd1[k++]=str[i++];

			oprnd1[k]='\0';
			i=found+1;
			l=0;
			while(i < len && str[i]!='*' && str[i]!='+')
			{
				oprnd2[l++]=str[i++];
			}
			int end=i;

			char *pend;
			oprnd2[l]='\0';
			//cout<<oprnd1<<"\t"<<oprnd2;
			long long int res=strtoll(oprnd1,&pend,10)*strtoll(oprnd2,&pend,10);
			char buffer[33];
			sprintf(buffer,"%lld",res);
			//cout<<start<<" "<<end<<endl;
			str.replace(start,end-start,string(buffer));
			//cout<<endl<<str<<endl;
			found = str.find_first_of("*");
		}
		

		//calculate min
		found = str1.find_first_of("*");
		while(found!=string::npos)
		{
			i=found-1;
			k=0;
			while(i>=0 && str1[i]!='*' && str1[i]!='+')
			{
				i--;
				//oprnd1[k++]=str[i--];
			}
			int start=i+1;
			i++;
			while(i<found)
				oprnd1[k++]=str1[i++];

			oprnd1[k]='\0';
			i=found+1;
			l=0;
			while(i < len && str1[i]!='*' && str1[i]!='+')
			{
				oprnd2[l++]=str1[i++];
			}
			int end=i;

			char *pend;
			oprnd2[l]='\0';
			//cout<<oprnd1<<"\t"<<oprnd2;
			long long int res=strtoll(oprnd1,&pend,10)*strtoll(oprnd2,&pend,10);
			char buffer[33];
			sprintf(buffer,"%lld",res);
			//cout<<start<<" "<<end<<endl;
			str1.replace(start,end-start,string(buffer));
			//cout<<endl<<str1<<endl;
			found = str1.find_first_of("*");
		}


		found = str1.find_first_of("+");
		while(found!=string::npos)
		{
			i=found-1;
			k=0;
			while(i>=0 && str1[i]!='*' && str1[i]!='+')
			{
				i--;
				//oprnd1[k++]=str[i--];
			}
			int start=i+1;
			i++;
			while(i<found)
				oprnd1[k++]=str1[i++];
			oprnd1[k]='\0';
			i=found+1;
			l=0;
			while(i < len && str1[i]!='*' && str1[i]!='+')
			{
				oprnd2[l++]=str1[i++];
			}
			int end=i;
			char *pend;
			oprnd2[l]='\0';
			//cout<<oprnd1<<"\t"<<oprnd2;
			long long int res=strtoll(oprnd1,&pend,10)+strtoll(oprnd2,&pend,10);
			char buffer[33];
			sprintf(buffer,"%lld",res);
			//cout<<start<<" "<<end<<endl;
			str1.replace(start,end-start,string(buffer));
			//cout<<endl<<str1<<endl;
			found = str1.find_first_of("+");
		}
		cout<<str<<" "<<str1<<endl;
	}

	
	return 0;
}


/*

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N) FOR(I,0,N)
#define ALL(A) (A).begin(), (A).end()

using namespace std;

int main(){
  int n;
  cin >> n;
  while(n--){

    string tmp;
    cin >> tmp;

    vector<int> numbers;
    vector<char> operators;

    FOR(i, 0, tmp.size()){
if(i % 2 == 0){
numbers.push_back(atoi(&tmp[i]));
} else {
operators.push_back(tmp[i]);
}
    }

    vector< vector<long long> > min_costs(numbers.size() + 1, vector<long long>(numbers.size() + 1, numeric_limits<int>::max()));
    vector< vector<long long> > max_costs(numbers.size() + 1, vector<long long>(numbers.size() + 1, 0));
    FOR(i, 0, numbers.size() + 1){ max_costs[i][i] = min_costs[i][i] = numbers[i]; }

    int numbers_total = numbers.size();
    FOR(l, 2, numbers_total + 1){
      FOR(i, 0, numbers_total - l + 1){
        int j = i + l - 1;
        FOR(k, i, j){
int min_tmp = 0;
int max_tmp = 0;
if(operators[k] == '+'){
              min_tmp = min_costs[i][k] + min_costs[k+1][j];
              max_tmp = max_costs[i][k] + max_costs[k+1][j];
}else if(operators[k] == '*'){
              min_tmp = min_costs[i][k] * min_costs[k+1][j];
              max_tmp = max_costs[i][k] * max_costs[k+1][j];
}
          if(min_tmp < min_costs[i][j]){
            min_costs[i][j] = min_tmp;
          }
          if(max_tmp > max_costs[i][j]){
            max_costs[i][j] = max_tmp;
          }
        }
      }
    }
    cout << max_costs[0][numbers_total-1] << " " << min_costs[0][numbers_total-1] << endl;
  }
}

*/
