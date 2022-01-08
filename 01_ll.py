class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def Lprint(self):
        temp = self.head
        while(temp):
            print(temp.data)
            temp = temp.next

if __name__=='__main__':
    linked=LinkedList()
    
    linked.head = Node("First")
    second = Node("Segunda")
    third = Node("Tertiary")

    linked.head.next = second
    second.next = third

    linked.Lprint()
