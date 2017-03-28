#include "mem_dispatcher.h"

int main()
{
	mem_dispatcher *md =(mem_dispatcher*)malloc(sizeof(mem_dispatcher));
	int size, block_id, ch=0;

	init(md);

	while (ch != 5)
	{
		printf("1. Allocate :\n");
		printf("2. Deallocate :\n");
		printf("3. Show memory map :\n");
		printf("4. Defragment :\n");
		printf("5. Exit :\n");
		printf("Enter command : ");

		scanf("%d", &ch);
		switch (ch)
		{
			case 1:
				printf("\nEnter block size : ");
				scanf("%d", &size);
				if (allocate(md, size) == -1) 
					printf("\nAllocation failed");
				break;
			case 2:
				printf("\nEnter block id : ");
				scanf("%d", &block_id);
				if (deallocate(md, block_id) == -1) 
					printf("\nDeallocated failed");
				break;
			case 3:
				show_memory_map(md);
				break;
			case 4:
				defragment(md);
				break;
			case 5: break;
			default:
				printf("\nWrong command"); 
		}
		printf("\n\n");
	} 

	return 0;
}