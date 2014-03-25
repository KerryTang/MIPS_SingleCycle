#ifndef MIPS_CORE_H
#define MIPS_CORE_H

typedef struct MIPSCore{
	Register *r0;
	Inst     *mInst;
	uint32_t pc, cycle;
	
	void (*exec)(struct MIPSCore *mCore, Memory *imem, Memory *dmem);

}MIPSCore;

MIPSCore *new_Core();
void      del_Core(MIPSCore *mCore);

static void exec(MIPSCore *mCore, Memory *imem, Memory *dmem);
#endif
