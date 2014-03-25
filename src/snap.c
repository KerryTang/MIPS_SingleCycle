#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <MIPS_inst.h>
#include <MIPS_reg.h>
#include <MIPS_mem.h>
#include <MIPS_core.h>
#include <MIPS_snap.h>

SnapManager *new_SnapManager(MIPSCore *mCore){
	SnapManager *mSnapManager = (SnapManager *)malloc(sizeof(SnapManager));

	mSnapManager->mCore = mCore;
}

void del_SnapManager(SnapManager *mSnapManager){
	free(mSnapManager);	
	return;
}

static void snap(Register *reg, FILE *fp, uint32_t cycle, uint32_t pc){
    
	int i;

    fprintf(fp, "cycle %d\n",cycle);
   
	for(i = 0 ; i < REGISTER_SIZE; i++)
		fprintf(fp, "$%02d: 0x%08X\n", i, reg->s[i]);
    
	fprintf(fp, "PC: 0x%08X\n\n\n", pc);
	
	return;
}
