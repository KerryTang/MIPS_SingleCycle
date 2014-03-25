#ifndef MIPS_FILEIO_H
#define MIPS_FILEIO_H

#define IIMAGE_NAME "iimage.bin"
#define DIMAGE_NAME "dimage.bin"

uint32_t get_LE_32bits(FILE *fin);
void     read_image   (char *image_name, uint32_t *s, int size, uint32_t *init);

#endif
