Spec for a dummy demo format called: KAISTDE

Endianess: big endian

- Header(16 bytes)
    - magic 8 bytes: "KAISTDE\0"
    - version 1 byte: 0x01
    - flags 1 byte for future use
    - entry_count 2 bytes (BE)
    - reserved 4 bytes (nulled)

- Entry(variable size)
    - type 1 byte
    - key_len 2 bytes (BE)
    - val_len 4 bytes (BE)
    - key key_len bytes (ASCII)
    - value val_len bytes 

Semantics for type:
- 0x01 = PNG
- 0x02 = JPG
- 0X03 - 010Editor
