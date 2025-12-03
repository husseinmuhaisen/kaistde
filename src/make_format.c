#include "../inc/kaistde.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

int main(void){
    kaistde_file_t kst = {0};

    kst.header.version = 1;
    kst.header.flags = 0;
    kst.header.entry_count = 1;
    kst.header.reserved = 0;

    kst.entries = calloc(kst.header.entry_count, sizeof(kaistde_entry_t));

    // First entry: 0

    kst.entries[0].type = 0x01;
    kst.entries[0].key_len = 6;
    kst.entries[0].key = strdup("niessh");
    const char *value0 = "niessh.lol.com";
    kst.entries[0].val_len = (uint32_t)strlen(value0);
    kst.entries[0].value = (uint8_t *)strdup(value0);

    FILE *fp = fopen("niessuh.kaistde", "wb");
    if(!fp) return 1;
    if(kaistde_write(&kst, fp) !=0) return 1;
    fclose(fp);

    return 0;
}