"""Expression tree built from whitespace-separated postfix tokens."""
import math

class _Node:
    def __init__(self, token): self.token, self.left, self.right = token, None, None

class ExpressionTree:
    OPERATORS = {"+", "-", "*", "/", "^"}
    def __init__(self): self.root = None
    def build_from_postfix(self, expression):
        tokens = expression.split()
        if not tokens: raise ValueError("Postfix expression cannot be empty")
        stack = []
        for token in tokens:
            node = _Node(token)
            if token in self.OPERATORS:
                if len(stack) < 2: raise ValueError("Invalid postfix expression")
                node.right = stack.pop(); node.left = stack.pop()
            stack.append(node)
        if len(stack) != 1: raise ValueError("Invalid postfix expression")
        self.root = stack.pop()
    def inorder(self):
        def visit(n):
            if n is None: return ""
            if n.token in self.OPERATORS: return f"({visit(n.left)} {n.token} {visit(n.right)})"
            return n.token
        return visit(self.root)
    def postorder(self):
        result=[]
        def visit(n):
            if n: visit(n.left); visit(n.right); result.append(n.token)
        visit(self.root); return result
    def evaluate(self):
        def calc(n):
            if n is None: raise ValueError("Expression tree is empty")
            if n.token not in self.OPERATORS: return float(n.token)
            a,b=calc(n.left),calc(n.right)
            if n.token=="+": return a+b
            if n.token=="-": return a-b
            if n.token=="*": return a*b
            if n.token=="/": return a/b
            return math.pow(a,b)
        return calc(self.root)
