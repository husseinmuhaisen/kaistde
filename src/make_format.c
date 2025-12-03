#include "../inc/kaistde.h"
#include <stdlib.h>
#include <string.h>

int main(void){
    kaistde_file_t kst = {0};

    kst.header.version = 1;
    kst.header.flags = 0;
    kst.header.entry_count = 2;
    kst.header.reserved = 0;

    // kst.entries = calloc()
}