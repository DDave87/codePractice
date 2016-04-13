#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 999
    
int getmin(string S) {
    
string fiveBin[] = {"1", "101", "11001", "1111101", "1001110001", "110000110101","11110100001001","10011000100101101","1011111010111100001","111011100110101100101","100101010000001011111001", "10111010010000111011011101", "1110100011010100101001010001", "1001000110000100111001110010101","101101011110011000100000111101001","11100011010111111010100100110001101","10001110000110111100100110111111000001","1011000110100010101111000010111011000101","110111100000101101101011001110100111011001","100010101100011100100011000001001000100111101","10101101011110001110101111000101101011000110001","1101100011010111001001101011011100010111011110101"};
//fiveBin Array contains binary of numbers of power of 5. size 23.
vector<int> v(S.size()+1);
v[0] = 0;
for(int i=0;i<S.size();i++){
    v[i+1] = INF;
    for(int j=0;j<=i;j++){
        string s="";
        if(v[j]>=0){
        	for(int k=j;k<=i;k++){
                s+=S[k];
             	}//for
        }//if
                
        for(int k=0;k<22;k++) //fiveBin's size is 23.
        {
        	 if(s==fiveBin[k]){
                v[i+1] = min(v[i+1], v[j]+1);
                }//if
        }//for
    }//for
            
    if(v[i+1]==INF) v[i+1] = -1;
}//for
        cout << v[S.size()];
        return v[S.size()];
}//getmin

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    string _S;
    getline(cin, _S);
    
    res = getmin(_S);
    fout << res << endl;
    
    fout.close();
    return 0;
}
