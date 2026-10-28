from binary_tree import BinaryTree, Node

if __name__ == "__main__":
    root = Node(1); root.left = Node(2); root.right = Node(3)
    root.left.left = Node(4); root.left.right = Node(5)
    tree = BinaryTree(root)
    print("Preorder:", tree.preorder())
    print("Inorder:", tree.inorder())
    print("Postorder:", tree.postorder())
    print("Level order:", tree.level_order())
