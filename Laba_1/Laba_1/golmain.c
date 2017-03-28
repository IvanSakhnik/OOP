#include"mystring.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,n;
	double *p;
	char string[100], string1[100], string2[100], *string3="3.12;;4.5;";

	strcpy(string,"ent");
	strcpy(string1,"student");
	strcpy(string2,"docent");
	
	printf("substring on the position: %s %s\n",string1,string);
	printf("%d\n\n",substr(string1,string));
	
	/*printf("the longest substring: %s %s\n",string1,string2);
	printf("%d\n\n",subseq(string1,string2));

	printf("%s\n",string);
	if (inspal(string))
		printf("string is palindrom\n\n");
	else
		printf("string not palindrom\n\n");

	printf("%s\n",string);
	printf("%s\n\n",makepal(string));

	p = txt2double(string3, &n);

	if (p!=NULL)
	{
		printf("double count %d\n",n);
		for (i = 0; i < n; i++)
			printf("Num[%d]=%.3f\n", i, p[i]);
	}
	else
		printf("String error\n");

*/
	system("pause");

	return 0;
}