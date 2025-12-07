# This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild
# type: ignore

import kaitaistruct
from kaitaistruct import KaitaiStruct, KaitaiStream, BytesIO


if getattr(kaitaistruct, 'API_VERSION', (0, 9)) < (0, 11):
    raise Exception("Incompatible Kaitai Struct Python API: 0.11 or later is required, but you have %s" % (kaitaistruct.__version__))

class Kaistde(KaitaiStruct):
    def __init__(self, _io, _parent=None, _root=None):
        super(Kaistde, self).__init__(_io)
        self._parent = _parent
        self._root = _root or self
        self._read()

    def _read(self):
        self.magic = self._io.read_bytes(8)
        if not self.magic == b"\x4B\x41\x49\x53\x54\x44\x45\x00":
            raise kaitaistruct.ValidationNotEqualError(b"\x4B\x41\x49\x53\x54\x44\x45\x00", self.magic, self._io, u"/seq/0")
        self.version = self._io.read_u1()
        self.flags = self._io.read_u1()
        self.entry_count = self._io.read_u2be()
        self.reserved = self._io.read_u4be()
        self.entries = []
        for i in range(self.entry_count):
            self.entries.append(Kaistde.Entry(self._io, self, self._root))



    def _fetch_instances(self):
        pass
        for i in range(len(self.entries)):
            pass
            self.entries[i]._fetch_instances()


    class Entry(KaitaiStruct):
        def __init__(self, _io, _parent=None, _root=None):
            super(Kaistde.Entry, self).__init__(_io)
            self._parent = _parent
            self._root = _root
            self._read()

        def _read(self):
            self.type = self._io.read_u1()
            self.key_len = self._io.read_u2be()
            self.val_len = self._io.read_u4be()
            self.key = (self._io.read_bytes(self.key_len)).decode(u"ASCII")
            self.value = self._io.read_bytes(self.val_len)


        def _fetch_instances(self):
            pass



