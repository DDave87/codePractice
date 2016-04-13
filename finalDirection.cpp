#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int NSValue(char exp){
if (exp == 'N' or exp == 'n') return 1;
else if(exp == 'S' or exp == 's') return -1;
}//NSValue
int EWValue(char exp){
if (exp == 'E' or exp == 'e') return 1;
else if(exp == 'W' or exp == 'w') return -1;
}//EWValue

int getDirection(char exp[]){
int east=0;
int north=0;
int i,j,temp,l;
l=strlen(exp);
for(i=0;i<l;i++){
	if((exp[i]=='N' or exp[i]=='n') || (exp[i]=='S' or exp[i]=='s')){north+=NSValue(exp[i]);}
	if((exp[i]=='E' or exp[i]=='e') || (exp[i]=='W' or exp[i]=='w')){east+=EWValue(exp[i]);}
}//for
if(east>0){for(i=0;i<east;i++){printf("%c",'E');}}//if
else if(east<0){east=-east;
	for(i=0;i<east;i++){printf("%c",'S');}
}//if


if(north>0){for(i=0;i<north;i++){printf("%c",'N');}}//if
else if(north<0){north=-north;
	for(i=0;i<north;i++){printf("%c",'S');}
}//elseif

}//getDirection
int main() {
 //char exp[100] = "NESNWES";
 char exp[100] = "SSSNEEEW";
 getDirection(exp);
 return 0;
}