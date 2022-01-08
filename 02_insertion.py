class Node:
    def __init__(self, data):
        self.index = 0
        self.data = data
        self.next = None
        self.prev = None

class LList:
    def __init__(self):
        self.head = None
    
    def find(self, item):
        if self.head is None:
            print ("Nothing in list.")
            return
        
        search = self.head
        while (search):
            if search.data == item:
                return search
            search = search.next

        print(item + " not found in list.")
        return

    def length(self):
        if self.head is None:
            return 0

        last = self.head
        while (last.next):
            last = last.next

        size = last.index + 1
        return size

    def incrementAfter(self, new_node):
        increase = new_node
        
        while (increase.next):
            increase = increase.next
            increase.index = increase.index + 1

    def decrement(self, new_node):
        increase = new_node
        
        while (increase.next):
            increase = increase.next
            increase.index = increase.index - 1

    def push(self, new_data):
        new_node = Node(new_data)

        # new.next is the head
        new_node.next = self.head

        self.head.prev = new_node
        
        self.incrementAfter(new_node)

        self.head = new_node

    def append(self, new_data):
        new_node = Node(new_data)
        
        # if list is empty, new node is head
        if self.head is None:
            self.head = new_node
            return

        # else move to the end of the list
        last = self.head
        while (last.next):
            last = last.next
        
        # assign the new.prev to last
        # and last.next to new
        new_node.prev = last
        new_node.index = last.index + 1
        last.next = new_node
 
    def insertBefore(self, next_node, new_data):
        next_node = self.find(next_node)

        if next_node is None:
            print("Invalid previous node.")
            return

        if next_node.prev is None:
            self.push(new_data)
        else:
            new_node = Node(new_data)
            new_node.prev = next_node.prev
            new_node.index = next_node.index
            new_node.next = next_node
            next_node.prev = new_node
            prev = new_node.prev
            prev.next = new_node
            self.incrementAfter(new_node)


    def insertAfter(self, prev_node, new_data):
        prev_node = self.find(prev_node)

        if prev_node is None:
            print("Invalid previous node.")
            return

        new_node = Node(new_data)
        new_node.next = prev_node.next
        new_node.index = prev_node.index + 1

        self.incrementAfter(new_node)

        prev_node.next = new_node

    def out(self):
        temp = self.head
        while (temp):
            print(str(temp.index) + " " + temp.data)
            temp = temp.next

if __name__=='__main__':
    linked = LList()

    linked.append("D")
    linked.push("B")
    linked.push("A")
    linked.append("E")
    linked.insertAfter("B", "C")
    linked.append("G")
    linked.insertBefore("G", "F")
    linked.out()
    print(linked.length())
