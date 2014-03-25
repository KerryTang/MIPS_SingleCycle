#ifndef MIPS_REG_H
#define MIPS_REG_H
/* Header: stdio.h, stdlib.h, stdint.h */

/* Register number defined in MIPS R300A*/
#define REGISTER_SIZE 32
#define REG_ZERO 0
#define REG_SP   29

typedef struct Register{
	uint32_t  *s;

	uint32_t  (*get) (struct Register *reg, int id);
	void      (*set) (struct Register *reg, int id, uint32_t value);

}Register;

Register *new_Register();
void	  del_Register(Register *reg);

static uint32_t  get (Register *reg, int id);
static void      set (Register *reg, int id, uint32_t value);

#endif
