#include<stdio.h>
#include<string.h>
int expressionvalidator(char *,char *,int);
int main()
{
	char exp[100],tstcse[100];
	int s;
	//printf("Enter the expression\n");
	gets(exp);
	//printf("test case\n");
	gets(tstcse);
	//char exp1='o',tstcse1='p';
	//printf("%d",strlen(exp));
	s=expressionvalidator(exp,tstcse,strlen(exp));
	switch(s)
	{
	case 1: printf("true");
			break;
	case 0: printf("false");
	}
}
int expressionvalidator(char *exp,char *tstcse,int length)
{
	char *ptr,*tpt;int i;
	//printf("%c and %c",*exp,*tstcse);
	if(*exp == '^')
	{
		exp++;
		length--;
	}
	if(*exp == '*' || *exp == '$')
	return 0;
	while((*exp) != '\0')
	{
		
		for(i=0;i<length;i++)
		{
			//printf("Equal1");
			if((*exp) == (*tstcse))
			{
				ptr=exp;
				exp++;
				tstcse++;
				//printf("Equal");
			}
			else if( (*exp) == '*') 
			{
				
				if(*ptr == *tstcse || *ptr == '.')
				{
					if(*ptr == *tstcse)
					{
					while(*ptr == *tstcse)
					{
						tstcse++;
					}
					ptr = exp;
					exp++;
					}
					else
					{
						while(*tpt == *tstcse)
						{
							tstcse++;
						}
						ptr = exp;
						exp++;
					}
					
				}
				else 
				{
					exp++;
					if(*exp == *tstcse)
					{
						ptr=exp;
						exp++;
						tstcse++;
					}
					else
					{
						return 0;
					}
				}
			}
			else if( (*exp) == '.')
			{
					tpt = tstcse;
					ptr=exp;
					exp++;
					tstcse++;
			}
			else if(*exp == '$')
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}
	}
	return 1;
}