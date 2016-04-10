#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int min(int a, int b){return (a<=b)?a:b;}
int main(void) {
	int k=10;
    int a=3,b=5,c=7,x=1;
    queue<int> q3,q5,q7;
    for(int i=1;i<k;i++)
    {
        q3.push(x*3);
        q5.push(x*5);
        q7.push(x*7);
        x=min(q3.front(),min(q5.front(),q7.front()));
        if(x==q3.front()){
            q3.pop();
        }
        if(x==q5.front()){
            q5.pop();
        }
        if(x==q7.front()){
            q7.pop();
        }
    }
    cout<<x<<endl;
	return 0;
}
