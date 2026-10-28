"""Binary Search Tree for integer keys; duplicate keys are ignored."""
class _Node:
    def __init__(self, key):
        self.key, self.left, self.right = key, None, None

class BinarySearchTree:
    def __init__(self): self.root = None

    def insert(self, key):
        def add(node):
            if node is None: return _Node(key)
            if key < node.key: node.left = add(node.left)
            elif key > node.key: node.right = add(node.right)
            return node
        self.root = add(self.root)

    def search(self, key):
        node = self.root
        while node:
            if key == node.key: return True
            node = node.left if key < node.key else node.right
        return False

    def delete(self, key):
        def remove(node, value):
            if node is None: return None
            if value < node.key: node.left = remove(node.left, value)
            elif value > node.key: node.right = remove(node.right, value)
            else:
                if node.left is None: return node.right
                if node.right is None: return node.left
                successor = node.right
                while successor.left: successor = successor.left
                node.key = successor.key
                node.right = remove(node.right, successor.key)
            return node
        self.root = remove(self.root, key)

    def inorder(self):
        result = []
        def visit(n):
            if n: visit(n.left); result.append(n.key); visit(n.right)
        visit(self.root); return result

    def preorder(self):
        result = []
        def visit(n):
            if n: result.append(n.key); visit(n.left); visit(n.right)
        visit(self.root); return result

    def postorder(self):
        result = []
        def visit(n):
            if n: visit(n.left); visit(n.right); result.append(n.key)
        visit(self.root); return result
