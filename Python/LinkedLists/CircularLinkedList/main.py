from circular_linked_list import CircularLinkedList

if __name__ == "__main__":
    linked=CircularLinkedList();linked.insert_end(10);linked.insert_end(20);linked.insert_front(5)
    print("Circular list:",linked.display());print("Search 20:",linked.search(20))
    linked.delete(10);print("After deleting 10:",linked.display())
