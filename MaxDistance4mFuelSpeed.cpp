#include <iostream>
using namespace std;
#define max 100

int main()
{	int N,T;
	int s,f,i=0;
	int speed[max];
	int fuel[max];
	double frac=0.0;
	double maxFrac=0.0;
	int maxFuel;
	
	cin >>N;
	T=N;
	while(T){
		cin >> s;
		speed[i]=s;
		T--;
		i++;
	}
	T=N;
	i=0;
	while(T){
		cin>>f;
		fuel[i]=f;
		T--;
		i++;
	}
	cin>>maxFuel;
	for(i=0;i<N;i++){
		frac = (double)speed[i]/(double)fuel[i];
		cout<<frac<<endl;
		if(frac>maxFrac)
			maxFrac=frac;
	}
	

    cout << maxFrac*maxFuel << endl;
    return 0;
}
