from min_heap import MinHeap

if __name__ == "__main__":
    heap=MinHeap()
    for value in [40,10,30,5,12,6]:heap.insert(value)
    print("Heap array:",heap.display());print("Minimum:",heap.peek())
    print("Extract order:",end=" ")
    while not heap.is_empty():print(heap.extract_min(),end=" ")
    print()
