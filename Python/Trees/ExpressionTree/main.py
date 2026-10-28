from expression_tree import ExpressionTree

if __name__ == "__main__":
    tree = ExpressionTree()
    tree.build_from_postfix("3 4 + 2 * 7 /")
    print("Infix:", tree.inorder())
    print("Postfix:", tree.postorder())
    print("Value:", tree.evaluate())
