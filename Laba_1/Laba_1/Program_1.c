#include"mystring.h"
#include<string.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

int substr(const char *string1, const char *string2)
{
	int str2 = strlen(string2);
	int str1 = strlen(string1);

	int i,j;
	int result=-1;

	if (str2>str1)
		printf("string too large\n");

	for (i=0; i<str1 - str2 + 1; i++)		
		for(j=0; j<str2; j++)
		{
			if (string2[j]!=string1[i+j])
				break;
			else
				if (j==str2-1)
					result=i;
		}

	return result+1;
}

int inspal(const char *string)
{
	int i;
	int len=strlen(string);

	for(i=0; i<=len/2+1; i++)
		if (string[i]!=string[len-i-1])
			return 0;

	return 1;
}

int subseq(const char *string1, const char *string2)
{
	int i,j,n,k,max,tmp;
	
	int s1 = strlen(string1);
	int s2 = strlen(string2);
	
	n=0; max=0; tmp=0;

    for (i=0; i<s1; i++)		
		for(j=0; j<s2; j++)
		{
			if (s2-j<s1-i) n=s2-j;
			else n=s1-i;

			tmp=-1;
			for(k=0; k<n; k++)
				if (string1[i+k]!=string2[j+k])
				{tmp=k; break;}

            if (tmp==-1) tmp=n;
            if (tmp>max) max=tmp;
		}
	return max;	
}

char* makepal(const char* string)
{
	int length=strlen(string);
	int L=0, R=length-1, count=0, tmpCount;

	char* pal;

	int i,j;

	while (L<R)
	{
		while (string[L]!=string[R])
		{
			L++;
			count++;
		}
		tmpCount=0;

		while (string[L]==string[R])
		{
			L++; R--; tmpCount++;
		}

		if (L<R) 
		{
			R=length-1;
			count +=tmpCount;
		}
	}
    pal=(char*)malloc((length+count+1)*sizeof(char));

	for(i=0; i<length; i++)
		pal[i]=string[i];
	for(j=0; j<count; j++,i++)
		pal[i]=string[count-j-1];
	pal[i]='\0';

	return pal;
}
		    
double* txt2double(const char *string, int *size)
{

	int len1, len2, n = 0, j, i, num;
	char *check =  "0123456789.;" ;
	double *arr;
	char s[100];

	len1 = strlen(string);
	len2 = strlen(check);
	*size = 0;

	for (i = 0; i < len1; i++)
	{
		if (string[i] == ';'|| string[i+1]=='\0')
		{
			if (string[i + 1] != ';')
				n++;
			else
				continue;
		}

		for (j = 0; j < len2; j++)
			if (string[i] == check[j])
				break;
			if (j == len2)
				return NULL;
	}

	arr=(double*)malloc(n*sizeof(double));

	for (i = 0, j = 0, num=0; i <= len1; i++)
		if (string[i] != ';' && string[i]!='\0')
		{
			s[j] = string[i];
			j++;
		}
		else
		{	
			if (j==0) continue;
			s[j]='\0';
			j = 0;	
			arr[num] = atof(s);
			num++;
			(*size)++;
			while (s[j] != '\0')
			{
				s[j] = '\0';
				j++;
			}
			j = 0;
		}

	return arr;

}
				
			
			
		
