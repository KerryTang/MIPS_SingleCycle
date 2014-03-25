#ifndef MIPS_INST_H
#define MIPS_INST_H

#define INST_HALT 0x3f

typedef struct Inst{
	uint32_t bytecode;

	uint32_t opcode; /* [31:26]6-bit */
	/* R-format */
	uint32_t rs;     /* [25:21]5-bit */
	uint32_t rt;	 /* [20:16]5-bit */
	uint32_t rd;     /* [15:11]5-bit */
	uint32_t shamt;  /* [10:6] 5-bit */
	uint32_t funct;  /* [5:0]  6-bit */
	/* I-format */
	int C;			 /* 16-bit for constant or address */
	/* J-format, S-format */
	uint32_t addr;   /* 26-bit for constant or address */
	
	void (*decode) (struct Inst* inst, uint32_t bytecode);

}Inst;

Inst *new_Inst();
void del_Inst(Inst *inst);

static void decode (Inst *inst, uint32_t bytecode);
#endif
