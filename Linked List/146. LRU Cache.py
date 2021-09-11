class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    def remove_node(self, node):
        # Change the links inside doubly linked list
        if node == self.head:
            self.head = self.head.next
            if self.head != None:
                self.head.prev = None
        elif node == self.tail:
            self.tail = self.tail.prev
            if self.tail != None:
                self.tail.next = None
        elif node != None:
            node.prev.next = node.next
            node.next.prev = node.prev
        # Recover the prev and next of removed node
        if node != None:
            node.prev = None
            node.next = None
    def append(self, node):
        if self.head == None:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
    def pop_front(self):
        if self.head == None:
            return
        key = self.head.key
        self.remove_node(self.head)
        return key

class LRUCache:
    def __init__(self, capacity: int):
        # Mark how many keys are included
        self.count = 0
        self.capacity = capacity
        
        # Map a key to its node in the doubly linked list
        self.nodes = dict()
        
        # Nodes in time order. The head of this is the LRU node
        self.orders = DoublyLinkedList()

    def get(self, key: int) -> int:
        # Check if key exists
        if key in self.nodes and self.nodes[key] != None:
            node = self.nodes[key]
            # Remove the node and append to the tail of doubly linked list.
            self.orders.remove_node(node)
            self.orders.append(node)
            return node.value
        return -1
        
    def put(self, key: int, value: int) -> None:
        # If key already in list
        if key in self.nodes and self.nodes[key] != None:
            # Change the value and append to the tail
            node = self.nodes[key]
            node.value = value
            self.orders.remove_node(node)
            self.orders.append(node)
        else:
            if self.count < self.capacity: # enough capacity
                self.count += 1
            else: # Exceeds capacity -> remove LRU
                removed_key = self.orders.pop_front()
                self.nodes[removed_key] = None
            # Append new node to tail
            node = Node(key, value) 
            self.orders.append(node)
            self.nodes[key] = node
