#include "myheader.h"

int main()
{
	size_t argz_len;
	int i,k;
	char *argz, *entry;
	char *string="Sakhnik:Ivan:Sergiyovych:";
	
	argz_create_sep (string, 58, &argz, &argz_len);
	argz_print(argz, argz_len);

	printf("%d\n\n",argz_count (argz,argz_len));

	argz_add (&argz,&argz_len, "KV-42");
	argz_print(argz, argz_len);

	argz_delete (&argz, &argz_len, "Ivan");
	argz_print(argz, argz_len);

	argz_insert (&argz, &argz_len, "Sergiyovych", "KPI");
	argz_print(argz, argz_len);

	argz_replace(&argz, &argz_len, "KPI", "with");
	argz_print(argz, argz_len);

	entry = NULL; 
	k = argz_count(argz,argz_len); 

	i = 0;
	while (i < k)
	{  
		printf("Argz[%d]=%s\n", i, entry = argz_next(argz,argz_len,entry));
		i++;
	} 

	getchar();
	return 0;
}