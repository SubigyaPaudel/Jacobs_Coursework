from enum import Enum, auto

class arrows(Enum):
    flat = auto()
    vertical = auto()
    diagonal = auto()

class entry:
    def __init__(self, length, arrow: arrows):
        self.length = length
        self.direction = arrow

    def __str__(self):
        if self.direction == arrows.flat:
            return "{} <-".format(self.length)
        elif self.direction == arrows.vertical:
            return "{} |".format(self.length)
        else:
            return "{} \\".format(self.length)
    
def createtable(a,b):
    table = list()
    for i in range(0, len(a) + 1):
        arow = list()
        for j in range(0, len(b) + 1):
            if(i == 0 or j == 0):
                arow.append(entry(0, None))
            else:
                if(a[i-1] == b[j-1]):
                    anentry = entry(table[i-1][j-1].length + 1, arrows.diagonal)
                    arow.append(anentry)
                elif(arow[-1].length > table[-1][j].length):
                    arow.append(entry(arow[-1].length, arrows.flat))
                else:
                    arow.append(entry(table[-1][j].length, arrows.vertical))
        table.append(arow)
    return table

def printsubsequence(a,table):
    a = []
    for i in table:
        for j in i:
            a.append(j.length)
    b = max(a)
    start = []
    for i in table:
        for j in i:
            if(j.length == b):
                start.append([i,j])
    for j in start:
        target = j
        while not 0 in target:
            if(table[target[0]][target[1]].direction == arrows.diagonal):
                print(a[target[0]])
                target = [target[0] - 1, target[1] - 1]
            elif(table[target[0]][target[1]].direction == arrows.vertical):
                target = [target[0] - 1, target[1]]
            else:
                target = [target[0], target[1] - 1]



a = "BDCABA"
b = "ABCBDAB"
table = createtable(a,b)
printsubsequence(a,table)

