class LinkedListNode:
    def LinkedListNode(self):
        self.data = 0
        self.pLink = {'HeaderClass':0, 'CurrentClass': 0, 'NextClass':0 }
        self.pLink['CurrentClass'] = self
        self.currentCount = 0

print('LinkedListNode test')
Node = LinkedListNode()
Node.LinkedListNode()
print(Node)
print(Node.data)
print(Node.pLink)



def LinkedList(Node):
    LinkedListNode()
    Node.pLink['HeaderClass'] = Node
    return Node

LinkedList(Node)


print('\nLinkedList test')
print(Node)
print(Node.data)
print(Node.pLink)



def createLinkedList(Node):
    Node = LinkedListNode()
    Node.LinkedListNode()
    Node.data = 'HeaderNode'
    LinkedList(Node)
    return Node

print('\ncreateLinkedList test')
Node = createLinkedList(Node)
print(Node)
print(Node.data)
print(Node.pLink)



def getLinkedListData(pList, position):
    i = 0
    pCurrentNode = LinkedListNode()
    pCurrentNode.LinkedListNode()
    pCurrentNode = pList.pLink['HeaderClass']

    for i in range(position):
        pCurrentNode = pCurrentNode.pLink['NextClass']

    return pCurrentNode.data


print('\ngetLinkedListData test')
print(getLinkedListData(Node, 0))



def addLinkedListData(pList, position, data):
    i = 0
    pNewNode = LinkedListNode()
    pNewNode.LinkedListNode()
    pPreNode = LinkedListNode()
    pPreNode.LinkedListNode()

    pNewNode.data = data

    pPreNode = pList.pLink['HeaderClass']
    for i in range(position-1) :
        pPreNode = pPreNode.pLink['NextClass']

    pNewNode.pLink['NextClass'] = pPreNode.pLink['NextClass']
    pPreNode.pLink['NextClass'] = pNewNode

    pList.currentCount += 1

    return pList



print('\naddLinkedListData test')

Node = addLinkedListData(Node, 1,10)
Node = addLinkedListData(Node, 2,20)
Node = addLinkedListData(Node, 3,30)

print(getLinkedListData(Node, 0))
print(getLinkedListData(Node, 1))
print(getLinkedListData(Node, 2))
print(getLinkedListData(Node, 3))


def removeLinkedListData(pList, position):
    if position == 0 :
        print('\n헤더노드는 지울 수 없습니다.\n')
        return
    i = int(0)
    pDelNode = LinkedListNode()
    pDelNode.LinkedListNode()
    pPreNode = LinkedListNode()
    pPreNode.LinkedListNode()

    pPreNode = pList.pLink['HeaderClass']

    for i in range(position - 1):
        pPreNode = pPreNode.pLink['NextClass']

    pDelNode = pPreNode.pLink['NextClass']
    pPreNode.pLink['NextClass'] = pDelNode.pLink['NextClass']

    pList.currentCount -= 1

print('\nremoveLinkedListData test')
removeLinkedListData(Node, 1)
removeLinkedListData(Node, 0)
print(getLinkedListData(Node, 1))


def deleteLinkedList(pList):
    pDelNode = LinkedListNode()
    pDelNode.LinkedListNode()
    pPreNode = LinkedListNode()
    pPreNode.LinkedListNode()

    pPreNode = pList.pLink['HeaderClass']

    while(pPreNode.pLink['NextClass'] != 0 ):
        pDelNode = pPreNode
        pPreNode = pPreNode.pLink['NextClass']

        pDelNode.data = 0
        pDelNode.pLink.clear()

'''
print('\ndeleteLinkedList test')
deleteLinkedList(Node)
print(Node.pLink)
print(Node.data)
'''


def getLinkedListLength(pList):
       return pList.currentCount

print('\ngetLinkedListLength')
print(getLinkedListLength(Node))

def displayList(pList):
    i = 0
    print('\n일반 순회')
    for i in range(pList.currentCount + 1):
        print("{} = {}".format(i,getLinkedListData(pList,i)))

displayList(Node)


def iterateLinkedList(pList):
    count = int(0)
    pNode = LinkedListNode()
    pNode.LinkedListNode()

    pNode = pList.pLink['HeaderClass']

    print('\n로직 처리 순회')
    while(pNode.pLink['NextClass'] != 0):
        print('{} = {}'.format(count, pNode.data))
        count += 1

    print('노드 개수 : {}'.format(count))

iterateLinkedList(Node)

'''

def concatLinkedList(pListA, pListB):
    pNodeA = LinkedListNode()
    pNodeB = LinkedListNode()

    if pListA.pLink['HeaderClass'] != 0 and pListB.pLink['HeaderClass'] != 0:
        pNodeA = pListA.pLink['HeaderClass']
        pNodeA = pNodeA.pLink['NextClass']

        pNodeB = pListB.pLink['HeaderClass']
        pNodeB = pNodeB.pLink['NextClass']

        while pNodeA.pLink['HeaderClass'] and pNodeA.pLink['NextClass'] :
            pNodeA = pNodeA.pLink['NextClass']

        pNodeA.pLink['NextClass'] = pNodeB.pLink['CurrentClass']
        pListB.pLink.clear()

pList = createLinkedList()
addLinkedListData(pList, 0, 10)
addLinkedListData(pList, 1, 20)
addLinkedListData(pList, 1, 30)

value = getLinkedListData(pList, 1)
print('위치 : {}\n값 : {}\n'.format(1,value))

displayList(pList)

iterateLinkedList(pList)

removeLinkedListData(pList, 0)
deleteLinkedList(pList)

pListA = createLinkedList()
pListB = createLinkedList()

addLinkedListData(pListA, 0, 10)
addLinkedListData(pListA, 1, 20)
addLinkedListData(pListA, 2, 30)

addLinkedListData(pListB, 0, 40)
addLinkedListData(pListB, 1, 50)

print('연결 리스트 결합 전')
print('\n연결 리스트A\n')
iterateLinkedList(pListA)
print('\n연결 리스트B\n')
iterateLinkedList(pListB)

concatLinkedList(pListA, pListB)
print('\n연결 리스트 결합 후\n')
print('\n연결 리스트A\n')
iterateLinkedList(pListA)
print('\n연결 리스트B\n')
iterateLinkedList(pListB)

deleteLinkedList(pListA)
deleteLinkedList(pListB)
'''