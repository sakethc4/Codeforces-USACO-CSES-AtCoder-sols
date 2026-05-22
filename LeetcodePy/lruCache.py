class Node: 
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:
    # Need get and put functions. 
    # Use nodes to represent each individual element in our LRU
    # Capacity tells us the constraints on our cache. 
    # For initialization we can use dummmy nodes 
    # When we retrieve from our cache we can remove and 
    # reinsert a linked list node.
    def __init__(self, capacity: int): 
        self.capacity = capacity 
        self.cache = {} 
        self.left, self.right = Node(-1, -1), Node(-1, -1) 
        self.left.next, self.right.prev = self.right, self.left 

    def remove(self, node): 
        prev, nxt = node.prev, node.nxt 
        prev.next = nxt
        nxt.prev = node 

    def insert(self, node):
        prev, nxt = self.right.prev, self.right
        prev.next = node
        node.prev = prev
        node.next = nxt 
        nxt.prev = node 

    def get(self, key: int) -> int:
        if self.key in cache: 
            self.remove(cache[key])
            self.insert(cache[key])
            return self.cache[key]
            
        return -1             

    def put(self, key: int, value: int) -> None:
        if key in self.cache: 
            self.remove(self.cache[key])
        # Handle max remove value 
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])
        if len(self.cache) > self.capacity:
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key] 



        
        
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)