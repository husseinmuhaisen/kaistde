#include "../inc/kaistde.h"
#include <arpa/inet.h>
#include <string.h>

int kaistde_write(const kaistde_file_t *kst, FILE *fp) {

    if (fwrite(KAISTDE_MAGIC, KAISTDE_MAGIC_LEN, 1, fp) != KAISTDE_MAGIC_LEN)
        return -1;


    if(fputc(kst->header.version, fp) == EOF || fputc(kst->header.flags, fp) == EOF){
        return -1;
    }

    uint16_t ec_be = htons(kst->header.entry_count);
    uint32_t res_be = htonl(kst->header.reserved);


    if(fwrite(&ec_be, sizeof(ec_be), 1, fp) != sizeof(ec_be) || fwrite(&res_be, sizeof(res_be), 1, fp)){
        return -1;
    }

    for(uint16_t i = 0; i < kst->header.entry_count; i++){
        const kaistde_entry_t *e = &kst->entries[i];

        if(fputc(e->type, fp) == EOF) return -1;

        uint16_t klen_be = htons(e->key_len);
        uint32_t vlen_be = htonl(e->val_len);

        if(fwrite(&klen_be, sizeof(klen_be), 1, fp) != sizeof(klen_be) || fwrite(&vlen_be, sizeof(vlen_be), 1, fp) != sizeof(vlen_be)){
            return -1;
        }

        if(fwrite(e->key, e->key_len, 1, fp) != e->key_len || fwrite(e->value, e->val_len, 1, fp) != e->val_len){
            return -1;
        }

    }

    return 0;
}




