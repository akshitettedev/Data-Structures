from array_stack import ArrayStack

if __name__ == "__main__":
    stack=ArrayStack(5)
    for value in [10,20,30]:stack.push(value)
    print("Stack (top to bottom):",stack.display())
    print("Peek:",stack.peek());print("Pop:",stack.pop());print("Size:",stack.size())
