#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[1000002];
    int test,i,flag,check,l,m,k;
    scanf("%d\n",&test);
    while(test--)
    {
        flag=1;
        gets(a);
        l=strlen(a);
        // baseof(length / 2) in integer.
        k=l>>1; 
        //printf("k=%d\n",k);
        check=0;
        for(i=0;i<l;i++)
        {
            if(a[i]!='9')
            {
                flag=0;
                //printf("a\n");
                break;
            }
        }
        //handaling case when 9, 99, 999 is given.(only 9s)
        if(flag==1)
        {
            a[0]='1';
            for(i=1;i<l;i++)
            a[i]='0';
            a[l]='1';
            a[l+1]='\0';
            check=1; //to check palindrom or not number
        }
        
        flag=0;
        if(check!=1)
        {
            for(i=0;i<k;i++)
            {
                if(a[i]<a[l-1-i]){
                flag=-1;
                //printf("flag=-1\n");
                }
                else if(a[i]>a[l-1-i]){
                //printf("flag=1\n");
                flag=1;}
                a[l-1-i]=a[i];
            }
 
            if(!(l&1))
            m=k-1;
            else m=k;
            if(flag==0||flag==-1)
            {
                i=0;
                while(a[m-i]=='9')
                {
                    a[m-i]='0';
                    a[l-1-m+i]='0';
                    i++;
                }
 
                a[m-i]++;
                a[l-1-m+i]=a[m-i];
        }
    }
    printf("%s\n",a);
    }
    return 0;
}