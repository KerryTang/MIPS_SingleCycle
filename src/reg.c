#include <stdint.h>
#include <stdlib.h>
#include <MIPS_reg.h>

Register *new_Register(){
	Register *reg;
	reg = (Register *)malloc(sizeof(Register));
	reg->s = (uint32_t *)calloc(REGISTER_SIZE, sizeof(uint32_t));

	reg->get = get;
	reg->set = set;
	
	return reg;

}

void del_Register(Register *reg){
	free(reg->s);	
	free(reg);
}

static uint32_t get(Register *reg, int id){
	
	if(id < REGISTER_SIZE)
		return reg->s[id];
	else
		return 0;
}
static void set(Register *reg, int id, uint32_t value){
	if(id < REGISTER_SIZE)
		reg->s[id] = value;
	return;

}

