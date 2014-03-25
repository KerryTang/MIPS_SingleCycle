#include <stdlib.h>
#include <stdint.h>
#include <MIPS_inst.h>

Inst *new_Inst(){
	Inst *inst;
	inst = (Inst *)malloc(sizeof(Inst));
	
	inst->decode  = decode;

	return inst;
}

void del_Inst(Inst *inst){
	free(inst);
	return;
}

static void decode (Inst *inst, uint32_t bytecode){

}
