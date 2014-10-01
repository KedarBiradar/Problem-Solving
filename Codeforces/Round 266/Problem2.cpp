#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;
int main()
{
	ll n,a,b;
	scanf("%lld%lld%lld",&n,&a,&b);
	ll total=6*n;
	bool flip=false;
	if(a>b)
	{
		ll tmp=a;
		a=b;
		b=tmp;
		flip=true;
	}
	
	ll aa=a;
	ll bb=b;
	ll best=-1;
	ll m=sqrt(total);

	for(ll i=a;i<=max(m,a);i++)
	{
		ll low=b,high=total;
		while(low<high)
		{
			ll mid=(low+high)/2;
			if((mid*i)>=total)
			{
				high=mid;
			}
			else
				low=mid+1;
		}
		if(low*i < best || best==-1)
		{
			best=low*i;
			aa=i;
			bb=low;
		}
	}

	if(flip)
	{
		ll tmp=aa;
		aa=bb;
		bb=tmp;
	}
	printf("%lld\n%lld %lld\n",best,aa,bb);
	return 0;
/*	ll area=a*b;
	ll diff=total-area;
	if(diff<=0)
	{
		printf("%lld\n%lld %lld\n",area,a,b);
		return 0;
	}
	ll d1,d2;
	if(diff%a!=0)
		d1=(diff/a)+1;
	else
		d1=diff/a;

	if(diff%b!=0)
		d2=(diff/b)+1;
	else
		d2=diff/b;

	ll tmp1=a*(b+d1);
	ll tmp2=(a+d2)*b;

	ll aa=a,bb=b;
	ll tmp3=aa*bb;

	while(tmp3<total)
	{
		aa++;
		bb++;
		tmp3=aa*bb;
	}
	if((tmp3<tmp1 && bb<=b+d1) ||(aa<=a+d2 && tmp3<tmp2))
		printf("%lld\n%lld %lld\n",tmp3,aa,bb);

	else if(tmp1<tmp2)
		printf("%lld\n%lld %lld\n",tmp1,a,b+d1);
	else
		printf("%lld\n%lld %lld\n",tmp2,a+d2,b);

	return 0;
int main ()
{
    #if defined (FILEIN)
      freopen("466.in","r",stdin);
    #endif
    //freopen("*.out","w",stdout);

    ll n,a,b;
    cin >> n >> a >> b;
    bool f=0;
    if (a > b)
    {
        swap(a,b);
        f = 1;
    }

    ll k=6*n;
    ll besta=a , bestb=b;
    ll best = -1;
    ll m = sqrt(k);
    for (ll i=a ; i<=max(m,a) ; i++)
    {
        ll low=b , high = k;
        while (low < high)
        {
            ll mid = (low+high)/2;
            if (mid*i >= k)
            {
                high = mid;
            }
            else low = mid+1;
        }
        if (low*i < best || best == -1)
        {
            best = low*i;
            besta = i;
            bestb = low;
        }
    }

    if (f) swap(besta,bestb);
    cout << best << endl;
    cout << besta << " " << bestb << endl;
}

*/
}
