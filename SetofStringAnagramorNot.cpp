#include <iostream>
#include <string>
#define NCHAR 256
using namespace std;
string checkAnagram(string str1, string str2){
	int c1[NCHAR]={0};
	int c2[NCHAR]={0};
	int i;
	for(i=0; str1[i]&&str2[i]; i++){
		c1[str1[i]]++;
		c2[str2[i]]++;
	}
	if(str1[i]||str2[i])
		return false;
	
	for(i=0;i<NCHAR;i++){
		if(c1[i]!=c2[i]){
			return "NO";
		}
	}
	return "YES";
	
}

int main()
{
	int T;
	string str1;
	string str2;
	cin>>T;
	
	while(T){
		cin>>str1;
		cin>>str2;
		cout<<checkAnagram(str1,str2)<<endl;
		T--;
	}
    return 0;
}
