#include"myheader.h"

int substr(const char *string1, const char *string2, size_t *argz_len)
{
	int str2 = strlen(string2);
	int str1 = *argz_len;

	int i,j;
	int result =- 1;

	if (str2 > str1)
	{
		printf("string too large\n");
		return -1;
	}

	for (i=0; i < str1 - str2 + 1; i++)		
		for(j = 0; j < str2; j++)
		{
			if (string2[j] != string1[i+j])
				break;
			else
				if (j == str2 - 1)
					result = i;
		}

	return result;
}

error_t argz_create_sep (const char *string, int sep, char **argz, size_t *argz_len)
{
	int i;
	*argz_len = strlen(string);
	if (NULL == (*argz=(char*)malloc((*argz_len+1)*sizeof(char))))
	{
		printf("Allocation fail");
		exit(1);
	}
	for (i=0; i < *argz_len; i++)
		if (string[i] == sep)
			(*argz)[i] = '\0';
		else
			(*argz)[i] = string[i];

	return OK;
}

void argz_print(const char *argz, size_t argz_len)
{
	int i;
	if (argz != NULL)
		for (i = 0; i < argz_len; i++)
			printf("%c", argz[i]);
	printf("\n\n");

}

size_t argz_count (const char *argz, size_t argz_len)
{  
	int i, count = 0;

	if (argz != NULL)
		for (i = 0; i < argz_len; i++)
			if (argz[i] == '\0' && argz[i+1] != '\0')
				++count;
	if (argz[argz_len - 1] != '\0') 
		++count;

	return count;
}

error_t argz_add (char **argz, size_t *argz_len, const char *str)
{
	int i,j;
    int str_l = strlen(str);
	char *arg = NULL;

	if (NULL == (arg=(char*)malloc((*argz_len + str_l + 1)*sizeof(char))))
	{
		printf("Allocation fail");
		exit(1);
	}

	for (i = 0; i < (*argz_len+1); i++)
		arg[i] = (*argz)[i];

	j = *argz_len;
	for(i=0; i<str_l; i++,j++)
		arg[j] = str[i];
	arg[*argz_len+str_l] = '\0';

	free(*argz);
	(*argz) = arg;

	*argz_len = *argz_len+str_l + 1;

	return OK;
}

void argz_delete (char **argz, size_t *argz_len, char *entry)
{
	int poz, j, l_ent; 
	char *arg = NULL, *pointer = NULL;  

	pointer = *argz; 
	poz = substr(*argz, entry, argz_len);
	pointer = (*argz)+poz;

	l_ent = strlen(pointer) + 1; 
	if (NULL == (arg = (char*)malloc((*argz_len - l_ent + 1)*sizeof(char))))
	{ 
		printf("Allocation is failed\n"); 
		exit(1); 
	} 

	for (j=0; j< poz; j++)
		arg[j] = (*argz)[j]; 
	
	j = j + l_ent; 
	while (j <= *(argz_len)) 
	{
		arg[poz] = (*argz)[j]; 
		++j; ++poz;
	}

	*(argz_len) = *(argz_len) - l_ent; 

	free(*argz); 
	(*argz) = arg; 

}

error_t argz_insert (char **argz, size_t *argz_len, char *before, const char *entry)
{
	int poz, j, k, l_ent; 
	char *pointer, *arg; 

	if (NULL == before)
	{ 
		argz_add(argz, argz_len, entry); 
		return OK; 
	} 

	l_ent = strlen(entry) + 1; 
	if (NULL == (arg = (char*)malloc(((*argz_len) + l_ent + 1)*sizeof(char)))) 
	{ 
		printf("Allocation fail\n"); 
		exit(1); 
	} 

	pointer = *argz; 
	poz = substr(*argz, before, argz_len);
	pointer = (*argz) + poz;

	j = k = 0; 
	if (poz <= *argz_len) 
	{
		for (j=0; j< poz; j++)
			arg[j] = (*argz)[j];
	}
	else 
		poz = 0; 

	while (k < l_ent) 
		arg[j++] = entry[k++]; 

	while (poz <= *(argz_len)) 
	{
		arg[j] = (*argz)[poz]; 
		++j; ++poz;
	}

	*(argz_len) = *(argz_len) + l_ent; 

	free(*argz); 
	(*argz) = arg;  

	return OK; 
}

error_t argz_replace(char **argz, size_t *argz_len, const char *str, const char *with)
{
	int poz;
	
	poz = substr(*argz, str, argz_len);
	
	if (poz != -1)	
	{
		if (argz_insert (argz, argz_len, str, with) != ENOMEM)
			argz_delete (argz, argz_len, str);
				return OK;	
	}
	else
		return  ENOMEM;

}

char * argz_next (char *argz, size_t argz_len, const char *entry)
{
	int poz, len;
	char *pointer = NULL;

	if (entry == NULL)
		return argz;

	poz = substr(argz, entry, &argz_len);

	pointer = argz+poz;

	len = strlen(pointer);

	if (poz + len < argz_len)
	{
		pointer = argz + poz + len + 1;
		return pointer;
	}

	return NULL;
}
