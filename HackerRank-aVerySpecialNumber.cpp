//Author Dhaval Dave 
//Working Code at  : http://ideone.com/QgHCR9
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <stack>
 
#define ll long long 
using namespace std;
 
 
ll powsAB(ll a,ll b)
{
	int c=0;
	while(a>=b && a%b==0)
	{
		c++;
		a/=b;
	}
	return c;
}
ll moda(ll a,ll b,ll x)
{
	if(a<b) swap(a,b);
	if(a==0) return 0;
	if(b==0) return 0;
	if(a==1 || b==1) return (a*b)%x;
	a%=x;
	b%=x;
	if(b==0) return 0;
	if(b==1) return a%x;
	ll c = moda(a,b/2,x);
	c*=2;
	c%=x;
	if(b&1) c+=a;
	c%=x;
	return c;
}
ll modp(ll a,ll b,ll x)
{
  a%=x;
  if(b==0) return 1%x;
  if(b==1) return a%x;
  ll c= modp(a,b/2,x);
  c=moda(c,c,x);
 
  if(b&1)c=moda(c,a,x);
 
  return c;
 
}
vector<ll> p;
 
void scheck()
{
  int isp[100001]={0};
  for(ll i=2;i<=100000;i++)
  {
	  if(isp[i]) continue;
	  p.push_back(i);
	  for(ll j=i*i;j<=100000;j+=i)
	  {
		  isp[j]=1;
	  }
  }	
}
vector<ll> factors(ll n)
{
 vector<ll> f;
 if(n<=1) return f;
 ll x=n;
 ll s =sqrt(n);
 for(int i=0;i<(int)p.size();i++)
 {
 
	 ll pp=p[i];
	 if(pp>s) break;
	 if(n%pp>0) continue;
	 f.push_back(pp);
	 while(x>=pp && x%pp==0)
	 {
		 x/=pp;
	 }
 }
 if(x!=1) 
 {
	 f.push_back(x);
 } 
 return f;
}
ll gcd(ll a,ll b)
{
	if(!b) return a;
	else return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	ll g=gcd(a,b);
 
	return (b/g)*a;
}
ll pow(ll a,ll b)
{
	if(!b ) return 1;
	if(b==1) return a;
	ll c= pow(a,b/2);
	c*=c;
	if(b&1)
	c*=a;
 
	return c;
}
 
ll afind(ll y,ll x,ll b)
{
 
	if(x%3==0) 
	{
		return x;
	}
 
	ll phi=(x/y)*(y-1ll);
	ll mina=phi;
	ll a =10ll%x;
 
    ll s = floor(sqrt(phi));
 
	for(ll i=1;i<=s;i++)
	{
		if(phi%i==0)
		{
			if(modp(a,i,x)==1)
			mina=min(mina,i);
			if(modp(a,phi/i,x)==1)
			mina=min(mina,phi/i);
		}
 
	} 
	return mina;
 
}
int main()
{
   scheck();
   int t;
   cin>>t;
   while(t--)
   {
	   ll n;
	   cin>>n;
	   ll twos,fives;
	   twos = powsAB(n,2ll);
	   fives = powsAB(n,5ll);
	   ll b= max(fives,twos-2);
	   n/=pow(2ll,twos);
	   n/=pow(5ll,fives);
	   ll a =1;
	   vector<ll>f=factors(n);
	   for(int i=0;i<(int)f.size();i++)
	   {
 
		   ll powers=powsAB(n,f[i]);
		   a=lcm(a,afind(f[i],pow(f[i],powers),b));
	   }
	   cout<<2ll*a+b<<endl;
   } 
   return 0;
}
