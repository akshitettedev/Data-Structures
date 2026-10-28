from hash_table import HashTable

if __name__ == "__main__":
    table=HashTable(7)
    for value in [10,17,24,5]:table.insert(value)
    print("Search 17:",table.search(17));table.delete(17)
    print("Search 17 after delete:",table.search(17))
    print("Slots:",table.display())
