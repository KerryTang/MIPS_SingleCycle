#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <MIPS_fileIO.h>
#include <MIPS_inst.h>
#include <MIPS_reg.h>
#include <MIPS_mem.h>
#include <MIPS_core.h>

int main(int argc, char *argv[]){

	Memory	    *imem, *dmem;
	MIPSCore    *mCore;
	
	/* File name defined in MIPS_fileIO.h */	
	imem = new_Memory(IIMAGE_NAME);
	dmem = new_Memory(DIMAGE_NAME);
	
	/* Core takes pc and $sp as argv */	
	mCore = new_Core(imem->init, dmem->init);
	
	mCore->exec(mCore, imem, dmem);
	
	
	del_Core(mCore);
	del_Memory(dmem);
	del_Memory(imem);
	
	return 0;
}

