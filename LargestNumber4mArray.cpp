#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(string x,string y){
	string xy = x.append(y);
	string yx = y.append(x);
	return xy.compare(yx)>0?1:0;
}

void printLargestNumber(vector<string> arr){
	sort(arr.begin(),arr.end(),compare);
	
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i];
	}
	cout<<endl;
}
int main()
{	int T;
	int num;
	string s;
	//ostringstream o;
    vector <string> a;
    cin>>T;
	while(T){
		cin>>num;
		ostringstream o;
		o << num;
		s = o.str();
		cout<<s<<endl;
		//sprintf(s,"%d",num);
		//a.push_back(to_string(num));
		a.push_back(s);
	    T--;
	}
	
	
	printLargestNumber(a);
    return 0;
}
