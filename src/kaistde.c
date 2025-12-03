#include "../inc/kaistde.h"
#include <string.h>
#include <arpa/inet.h>

int kaistde_write(const kaistde_file_t *kst, FILE *fp) {
    if (fwrite(KAISTDE_MAGIC, KAISTDE_MAGIC_LEN, 1, fp) != KAISTDE_MAGIC_LEN)
        return -1;


    if(fputc(kst->header.version, fp) == EOF || fputc(kst->header.flags, fp) == EOF)
    {
        return -1;
    }

    

    return 0;
}




