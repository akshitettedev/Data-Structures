from linear_queue import LinearQueue

if __name__ == "__main__":
    queue=LinearQueue(5)
    for value in [10,20,30]:queue.enqueue(value)
    print("Queue:",queue.display());print("Dequeued:",queue.dequeue());print("Front:",queue.peek())
