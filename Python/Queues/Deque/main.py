from deque_ds import Deque

if __name__ == "__main__":
    dq=Deque(5);dq.insert_rear(20);dq.insert_rear(30);dq.insert_front(10)
    print("Deque:",dq.display());print("Front removed:",dq.delete_front());print("Rear:",dq.get_rear())
