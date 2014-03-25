#ifndef MIPS_MEM_H
#define MIPS_MEM_H
/* Headers: stdio.h, stdlib.h, stdint.h */
#define MEMORY_SIZE  256 /* 256*sizeof(uint32_t) = 1K byte */

typedef struct Memory{
	uint32_t *s;
	uint32_t init;

	
	uint32_t (*lwu)(struct Memory *mem, uint32_t id);


}Memory;

Memory *new_Memory(char *image_name);
void    del_Memory(Memory *mem);

/* Load word unsigned */
static uint32_t lwu(Memory *mem, uint32_t id);

#endif


