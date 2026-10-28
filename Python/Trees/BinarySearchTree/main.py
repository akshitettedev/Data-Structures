from bst import BinarySearchTree

if __name__ == "__main__":
    tree = BinarySearchTree()
    for value in [50, 30, 70, 20, 40, 60, 80]: tree.insert(value)
    print("Inorder:", tree.inorder())
    print("Search 40:", tree.search(40))
    tree.delete(30)
    print("After deleting 30:", tree.inorder())
