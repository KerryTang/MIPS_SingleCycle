/* debug */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <MIPS_inst.h>
#include <MIPS_reg.h>
#include <MIPS_mem.h>
#include <MIPS_core.h>

MIPSCore *new_Core(uint32_t pc, uint32_t sp){
	MIPSCore *mCore;
	
	mCore = (MIPSCore *)malloc(sizeof(MIPSCore));
	mCore->r0    = new_Register();
	mCore->mInst = new_Inst();
	
	/* Intial state of core and register */
	mCore->pc = pc;
	mCore->r0->set(mCore->r0, REG_SP, sp);

	mCore->exec = exec;

	return mCore;
}

void del_Core(MIPSCore *mCore){
	del_Register(mCore->r0);
	del_Inst(mCore->mInst);
	free(mCore);

	return;
}

static void exec(MIPSCore *mCore, Memory *imem, Memory *dmem){
	/* Pointer alias */
	
	Inst *mInst = mCore->mInst;

	/* The core will stop only when after executing the halt instruction. */
	/* Opcode in while condition is the instruction in last cycle. */
	while(mInst->opcode != INST_HALT){
		
		mInst->decode(mInst, imem->lwu(imem, mCore->pc));

	}
	
	return;
}
