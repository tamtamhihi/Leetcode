# https://leetcode.com/problems/lfu-cache/

from collections import defaultdict

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.freq = 1
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    def remove(self, node): # Remove a node from doubly linked list
        if node == None:
            return
        if node == self.head:
            self.head = self.head.next
            if self.head != None:
                self.head.prev = None
            else:
                self.tail = None
        elif node == self.tail:
            self.tail = self.tail.prev
            if self.tail != None:
                self.tail.next = None
            else:
                self.head = None
        elif node.prev and node.next:
            node.prev.next = node.next
            node.next.prev = node.prev
        node.prev = None
        node.tail = None
    def append(self, node): # Append a node to the tail
        if self.head == None:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node
    def pop_front(self): # Pop a node from the head
        if self.head == None:
            return -1
        key = self.head.key
        self.remove(self.head)
        return key
    def is_empty(self): # Check if doubly linked list is empty
        return self.head == None

class LFUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.count = 0
        self.nodes = dict()
        self.freq_orders = defaultdict(DoublyLinkedList)
        self.min_freq = 10 ** 9

    def _increment_freq(self, node): # Increment the frequency of this node
        # Remove the node from the old frequency's doubly linked list
        self.freq_orders[node.freq].remove(node)
        
        # Update min_freq
        if node.freq == self.min_freq and self.freq_orders[node.freq].is_empty():
            self.min_freq += 1
        
        # Append node to new frequency's doubly linked list
        # (because it's the most recently used of this frequency)
        node.freq += 1
        self.freq_orders[node.freq].append(node)

    def get(self, key: int) -> int:
        if key in self.nodes and self.nodes[key] != None:
            node = self.nodes[key]
            self._increment_freq(node)
            return node.value
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.nodes and self.nodes[key] != None:
            node = self.nodes[key]
            self._increment_freq(node)
            self.nodes[key].value = value
        elif self.capacity > 0:
            if self.count < self.capacity:
                self.count += 1
            else:
                removed_key = self.freq_orders[self.min_freq].pop_front()
                self.nodes[removed_key] = None
            new_node = Node(key, value)
            self.nodes[key] = new_node
            self.freq_orders[1].append(new_node)
            self.min_freq = 1
