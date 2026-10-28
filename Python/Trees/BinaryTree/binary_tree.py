"""Basic binary tree and traversal operations."""
from collections import deque

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, root=None):
        self.root = root

    def preorder(self):
        result = []
        def visit(node):
            if node:
                result.append(node.data); visit(node.left); visit(node.right)
        visit(self.root)
        return result

    def inorder(self):
        result = []
        def visit(node):
            if node:
                visit(node.left); result.append(node.data); visit(node.right)
        visit(self.root)
        return result

    def postorder(self):
        result = []
        def visit(node):
            if node:
                visit(node.left); visit(node.right); result.append(node.data)
        visit(self.root)
        return result

    def level_order(self):
        if not self.root:
            return []
        result, queue = [], deque([self.root])
        while queue:
            node = queue.popleft(); result.append(node.data)
            if node.left: queue.append(node.left)
            if node.right: queue.append(node.right)
        return result
