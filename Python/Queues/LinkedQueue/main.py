from linked_queue import LinkedQueue

if __name__ == "__main__":
    queue=LinkedQueue()
    for value in [100,200,300]:queue.enqueue(value)
    print("Queue:",queue.display());print("Dequeued:",queue.dequeue());print("Size:",queue.size())
