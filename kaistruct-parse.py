import struct
import sys

MAGIC = b"KAISTDE\0"

def read_file_header(data, i=0):
    file_sig = struct.unpack(">8s", data[i:i+8])[0]
    if file_sig != MAGIC:
        raise ValueError(f"Invalid Magic: {file_sig!r}")
    i += 8
    version, flags, entry_count, reserved = struct.unpack(">BBHI", data[i:i+8])
    i += 8

    header = {
        "version": version,
        "flags": flags,
        "entry_count": entry_count,
        "reserved": reserved,
    }

    return header, i

def read_file_entry(data, i):
    entry_type, key_len, val_len = struct.unpack(">BHI", data[i:i+7])
    i += 7

    key_bytes = data[i:i + key_len]
    i += key_len

    value_bytes = data[i:i + val_len]
    i += val_len
    
    try:
        key = key_bytes.decode("utf-8")
    except UnicodeDecodeError:
        key = key_bytes

    entry = {
        "type": entry_type,
        "key_len": key_len,
        "val_len": val_len,
        "key": key,
        "value": value_bytes,
    }

    return entry, i

def parse_kaistde_file(path):
    with open(path, "rb") as f:
        data = f.read()

    i = 0
    header, i = read_file_header(data, i)
    entries = []
    for _ in range(header["entry_count"]):
        entry, i = read_file_entry(data, i)
        entries.append(entry)

    return header, entries

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <kaistde-file>")
        sys.exit(1)

    header, entries = parse_kaistde_file(sys.argv[1])
    print("Header:", header)
    print("Entries:")
    for e in entries:
        print(e)
