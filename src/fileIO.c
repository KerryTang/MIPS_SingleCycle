#include <stdio.h>
#include <stdint.h>
#include <MIPS_fileIO.h>

uint32_t get_LE_32bits(FILE *fin){
    
	uint32_t i, temp, bits;

	temp = 0;
	bits = 0;

    for(i = 0 ; i < 4; i++){
      if(fread(&temp, 1, 1, fin))
		  /* image is stored in little-endian */
          bits += temp<<(i*8);
      else{
        printf("ERROR#: fread fail or eof.\n");
        return 0;
      }
   }

   return bits;
}

void read_image(char *image_name, uint32_t *s, int size, uint32_t *init){
	FILE *image;
	uint32_t dat_num, dat_cnt, load_init;
	
	image = fopen(image_name, "rb");
	
	if(image == NULL){
		printf("WARNING#: Required file %s doesn't exist in the directory, read_image doesn't initialized.\n", image_name);
		return;
	}
	if( (s == NULL) || (init == NULL)){
		printf("ERROR#: Missing target storage, read_image doesn't initialized.\n");
		fclose(image);
		return;
	}

	*init   = get_LE_32bits(image);
	dat_num = get_LE_32bits(image);
	dat_cnt   = 0;
	load_init = 0;	
	
	if(strcmp(image_name, IIMAGE_NAME) == 0){
		/* Memory is byte indexing. since applying uint32_t(4 bytes) as memory, counter need to be devided by 4 */
		*init = (*init>>2);
		load_init = *init;
	}
	
	/* Memory address overflow */
	/* WARNING# load_init(uint32_t)+dat_num(uint32_t) may cause overflow. */
	if((dat_num > size) || (load_init + dat_num > size)){
		printf("WARNING#: #Data is greater than target storage size.\n");
		fclose(image);
		return;
	}
	
	while(dat_cnt < dat_num){
		s[load_init + dat_cnt] = get_LE_32bits(image);
		dat_cnt++;
	}
	
	fclose(image);
	return;
}
