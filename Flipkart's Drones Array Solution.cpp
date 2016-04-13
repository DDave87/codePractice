#include <iostream>
#include <list>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
inline int scan(){register int n=0,c=gc();while(c<'0'||c>'9')c=gc();while(c<='9'&&c>='0')n=(n<<1)+(n<<3)+c-'0',c=gc();return n;} 

bool findPath(int X, int Y, bool V[],int T[],int N){
	if(T[X]==Y) {
		//cout<<X<<Y<<"\n";
		return true;
		}
	else if(V[X]==false && T[X]!=Y && T[X]<N ){
		//cout << "temp="<<X<<"-"<<T[X]<<"\n";
		V[X]=true;
		return findPath(T[X],Y,V,T,N);
	}
	else return false;
}
int findPathUtil(int X, int Y,int A[], int B[],int N){
	bool VA[200]={0};
	bool VB[200]={0};
	bool ans = false;
	//char a='a',b='b';
	ans = ans || findPath(X,Y,VA,A,N) || findPath(X,Y,VB,B,N);
	return ans;
}

int main()
{
    int t,N,M,Q,nn,mm,X,Y;
    t=scan();
    int A[200],B[200];
    while(t--){
    	N=scan();
    	M=scan();
    	//int A[N],B[N];
    	mm=M;
    	while(M--){
    		int t1=scan();
    		int t2=scan();
    			A[t1]=t2;
    			B[t2]=t1;
    			//added all entries in A,B array
    	}
    }
    /*for(int i=0;i<mm;i++){
    	cout << i << "=" <<A[i]<<"\n";
    }*/
    
    Q=scan();
    while(Q--){
    X=scan();
    Y=scan();
    if(X<N && Y<N){
      if(findPathUtil(X,Y,A,B,N)==true)cout<<"YES\n";
      else cout <<"NO\n";
    }
    else cout << "NO\n";
    }
    return 0;
}