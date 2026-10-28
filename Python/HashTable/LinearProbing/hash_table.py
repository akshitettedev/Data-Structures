"""Integer set using open addressing and linear probing with tombstones."""
_EMPTY=object();_DELETED=object()
class HashTable:
    def __init__(self,capacity):
        if capacity<=0:raise ValueError("Capacity must be positive")
        self._slots=[_EMPTY]*capacity;self._size=0
    def __len__(self):return self._size
    def _hash(self,key):return key%len(self._slots)
    def insert(self,key):
        first_deleted=None;start=self._hash(key)
        for offset in range(len(self._slots)):
            index=(start+offset)%len(self._slots);slot=self._slots[index]
            if slot is key or (slot is not _EMPTY and slot is not _DELETED and slot==key):return False
            if slot is _DELETED and first_deleted is None:first_deleted=index
            if slot is _EMPTY:
                target=first_deleted if first_deleted is not None else index
                self._slots[target]=key;self._size+=1;return True
        if first_deleted is not None:self._slots[first_deleted]=key;self._size+=1;return True
        raise OverflowError("Hash table is full")
    def search(self,key):
        start=self._hash(key)
        for offset in range(len(self._slots)):
            index=(start+offset)%len(self._slots);slot=self._slots[index]
            if slot is _EMPTY:return False
            if slot is not _DELETED and slot==key:return True
        return False
    def delete(self,key):
        start=self._hash(key)
        for offset in range(len(self._slots)):
            index=(start+offset)%len(self._slots);slot=self._slots[index]
            if slot is _EMPTY:return False
            if slot is not _DELETED and slot==key:self._slots[index]=_DELETED;self._size-=1;return True
        return False
    def display(self):
        result=[]
        for i,slot in enumerate(self._slots):
            label="<empty>" if slot is _EMPTY else "<deleted>" if slot is _DELETED else slot
            result.append((i,label))
        return result
