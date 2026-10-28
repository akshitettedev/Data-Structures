"""AVL self-balancing BST with all four rotation cases and deletion."""
class _Node:
    def __init__(self, key): self.key, self.left, self.right, self.height = key, None, None, 1

class AVLTree:
    def __init__(self): self.root = None
    @staticmethod
    def _height(node): return node.height if node else 0
    @classmethod
    def _balance(cls, node): return cls._height(node.left) - cls._height(node.right) if node else 0
    @classmethod
    def _update(cls, node): node.height = 1 + max(cls._height(node.left), cls._height(node.right))
    @classmethod
    def _rotate_right(cls, y):
        x, middle = y.left, y.left.right
        x.right = y; y.left = middle; cls._update(y); cls._update(x); return x
    @classmethod
    def _rotate_left(cls, x):
        y, middle = x.right, x.right.left
        y.left = x; x.right = middle; cls._update(x); cls._update(y); return y
    @classmethod
    def _rebalance(cls, node):
        cls._update(node); balance = cls._balance(node)
        if balance > 1:
            if cls._balance(node.left) < 0: node.left = cls._rotate_left(node.left)  # LR
            return cls._rotate_right(node)  # LL or LR
        if balance < -1:
            if cls._balance(node.right) > 0: node.right = cls._rotate_right(node.right)  # RL
            return cls._rotate_left(node)  # RR or RL
        return node
    def insert(self, key):
        def add(node):
            if node is None: return _Node(key)
            if key < node.key: node.left = add(node.left)
            elif key > node.key: node.right = add(node.right)
            else: return node
            return self._rebalance(node)
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
                node.key = successor.key; node.right = remove(node.right, successor.key)
            return self._rebalance(node) if node else None
        self.root = remove(self.root, key)
    def inorder(self):
        result=[]
        def visit(n):
            if n: visit(n.left); result.append(n.key); visit(n.right)
        visit(self.root); return result
    @property
    def height(self): return self._height(self.root)
