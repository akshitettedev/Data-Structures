from avl_tree import AVLTree

if __name__ == "__main__":
    tree = AVLTree()
    for value in [10, 20, 30, 40, 50, 25]: tree.insert(value)
    print("Balanced inorder:", tree.inorder())
    print("Height:", tree.height)
    print("Search 25:", tree.search(25))
    tree.delete(40)
    print("After deleting 40:", tree.inorder())
