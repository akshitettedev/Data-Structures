from linked_stack import LinkedStack

if __name__ == "__main__":
    stack=LinkedStack()
    for value in [5,15,25]:stack.push(value)
    print("Stack:",stack.display());print("Popped:",stack.pop());print("Top:",stack.peek())
