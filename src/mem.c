#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <MIPS_fileIO.h>
#include <MIPS_mem.h>

Memory *new_Memory(char *image_name){
	Memory *mem;
	
	mem = (Memory *)malloc(sizeof(Memory));
	mem->s = (uint32_t *)calloc(MEMORY_SIZE, sizeof(uint32_t));
	
	mem->lwu = lwu;
	
	read_image(image_name, mem->s, MEMORY_SIZE, &mem->init);

	return mem;
}

void del_Memory(Memory *mem){
	free(mem->s);
	free(mem);
	
	return;
}

static uint32_t lwu(Memory *mem, uint32_t id){
	return mem->s[id];
}
