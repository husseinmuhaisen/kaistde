#ifndef KAISTDE_H
#define KAISTDE_H

#include <stdint.h>
#include <stdio.h>

#define KAISTDE_MAGIC "KAISTDE\0"
#define KAISTDE_MAGIC_LEN 8

typedef struct {
    uint8_t version;
    uint8_t flags;
    uint16_t entry_count;
    uint32_t reserved;
} kaistde_header_t;

typedef struct {
    uint8_t type;
    uint16_t key_len;
    uint32_t val_len;
    char *key;
    uint8_t *value;
} kaistde_entry_t;

typedef struct{
    kaistde_header_t header;
    kaistde_entry_t *entries;
} kaistde_file_t;

#endif