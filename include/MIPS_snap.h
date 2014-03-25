#ifndef MIPS_SNAP_H
#define MIPS_SNAP_H

#define SNAPSHOT_NAME "snapshot.rpt"

typedef struct SnapManager{
	MIPSCore *mCore;


	void      (*snap)(struct Register *reg, FILE *fp, uint32_t cycle, uint32_t pc);

}SnapManager;

SnapManager *new_SnapManager(MIPSCore *mCore);
void         del_SnapManager(SnapManager *mSnapManager);

static void snap_reg(Register *reg, FILE *fp, uint32_t cycle, uint32_t pc);


#endif
