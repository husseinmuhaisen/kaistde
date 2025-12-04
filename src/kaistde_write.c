#include "../inc/kaistde.h"
#include <arpa/inet.h>
#include <string.h>

int kaistde_write(const kaistde_file_t *kst, FILE *fp) {

    if(fwrite(KAISTDE_MAGIC, 1, KAISTDE_MAGIC_LEN, fp) != KAISTDE_MAGIC_LEN){
        return -1;

    }


    if(fputc(kst->header.version, fp) == EOF || fputc(kst->header.flags, fp) == EOF){
        return -1;
    }

    uint16_t ec_be = htons(kst->header.entry_count);
    uint32_t res_be = htonl(kst->header.reserved);


    if(fwrite(&ec_be, sizeof(ec_be), 1, fp) != 1 ||
        fwrite(&res_be, sizeof(res_be), 1, fp) != 1) {
        return -1;
    }


    for(uint16_t i = 0; i < kst->header.entry_count; i++){
        const kaistde_entry_t *e = &kst->entries[i];

        if(fputc(e->type, fp) == EOF) return -1;

        uint16_t klen_be = htons(e->key_len);
        uint32_t vlen_be = htonl(e->val_len);

       if (fwrite(&klen_be, sizeof(klen_be), 1, fp) != 1 ||
        fwrite(&vlen_be, sizeof(vlen_be), 1, fp) != 1) {
        return -1;
    }


        if (fwrite(e->key, 1, e->key_len, fp) != e->key_len ||
            fwrite(e->value, 1, e->val_len, fp) != e->val_len) {
            return -1;
}


    }

    return 0;
}




