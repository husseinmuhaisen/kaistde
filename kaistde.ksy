meta:
    id: kaistde
    endian: be
seq:
    - id: magic
      contents: [0x4b, 0x41, 0x49, 0x53, 0x54, 0x44, 0x45, 0x00]
    - id: version
      type: u1
    - id: flags
      type: u1
    - id: entry_count
      type: u2
    - id: reserved
      type: u4
    - id: entries
      type: entry
      repeat: expr
      repeat-expr: entry_count 
types:
  entry: 
    seq: 
      - id: type
        type: u1
      - id: key_len
        type: u2
      - id: val_len
        type: u4
      - id: key
        type: str
        size: key_len
        encoding: ASCII
      - id: value
        size: val_len
