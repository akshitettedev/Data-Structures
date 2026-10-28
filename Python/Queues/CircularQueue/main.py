from circular_queue import CircularQueue

if __name__ == "__main__":
    queue=CircularQueue(3)
    for value in [1,2,3]:queue.enqueue(value)
    queue.dequeue();queue.enqueue(4)
    print("Circular queue:",queue.display());print("Front:",queue.peek())
