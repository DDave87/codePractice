    #include <iostream>
    #include <string>
    using namespace std;
     
    int isMatch(string text, string pattern, int n, int m){
    int i,j,t;
     
    for(i=0;i<(n-m+1);i++){
    	for(j=0;j<m && text[i+j]==pattern[j];j++);
    		if (j == m ) return 1;
     
    }//for
    return 0;
    }//isMAtch
     
    int main() {
    	string pattern, text;
    	int plen, tlen;
     
    	getline(cin, text);
    	getline(cin, pattern);
     
     
    	plen=pattern.length();
    	tlen=text.length();
      
    	cout<<isMatch(text, pattern, tlen, plen);
    }