from kaistde import Kaistde

with open("niessuh.kaistde", "rb") as f:
    data = f.read()
kst = Kaistde.from_bytes(data)
print(kst.version, kst.flags, kst.entry_count)

for e in kst.entries:
    print(e.type, e.key, e.value)