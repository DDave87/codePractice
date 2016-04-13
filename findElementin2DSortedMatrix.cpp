#include <stdio.h>
#include <iostream>

#include <stdio.h>
using namespace std;
#define gc getchar_unlocked
inline int scan(){register int n=0,c=gc();while(c<'0'||c>'9')c=gc();while(c<='9'&&c>='0')n=(n<<1)+(n<<3)+c-'0',c=gc();return n;}


int main()
{
    int n,m,p,t,k=1;
    int A[5][5]={{-10,-5,-3,4,9},{-6,-2,0,5,10},{-4,-1,1,6,12},{2,3,7,110,115},{100,120,130,140,150}};
    n=5,m=5;
	t=scan();
	while(t--)
	{
		
		p=100;
		cout<<"finding "<<p<<endl;
		int i=0,j=m-1;
		bool f=false;
		
  		 while(i<n && j>=0)
   		{
   			if(A[i][j]==p)
   			{
   				cout<<"at round(k)"<<++k<<" got i,j="<<i<<"-"<<j<<endl;
   				f=true;
   				break;
   			}
   			else if(A[i][j]>p)
   			{
                
   				j--;
                  
   			}
   			else if(A[i][j]<p)
   			{
                   
   				i++;
   			}k++;
   		
  		}
  		if(f==false) cout<<"at round(k)"<<k<<" Final -1 -1"<<endl;
	}
   

	return 0;
}
