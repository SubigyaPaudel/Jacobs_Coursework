from math import inf, floor

class minheap:
    def __init__(self, array):
        self.heap = list(array)
    
    def isempty(self): #checks if the priority heap is empty
        if len(self.heap) == 0:
            return True
        else:
            return False

    def extractmin(self): #extracts the node having the minimum distacne from the heap
        for i in range(len(self.heap) - 1, -1, -1):
            if i % 2 == 0:
                workingnumber = i - 1
            else:
                workingnumber = i
            if(self.heap[workingnumber].distance < self.heap[floor((workingnumber/2))].distance):
                self.heap[floor(workingnumber/2)], self.heap[workingnumber] = self.heap[workingnumber], self.heap[floor(workingnumber/2)]
        self.heap[0], self.heap[-1] = self.heap[-1], self.heap[0]
        return self.heap.pop()
        
class node:
    def __init__(self, name, distance, adjlist = set()):
        self.name = name
        self.distance = distance
        self.adjlist = adjlist
        self.predecessor = None

class edge:
    def __init__(self, start : node, stop : node, weight : int):
        self.start = start
        self.stop = stop
        self.weight = weight   # here the time represents the weight

class graph:
    def __init__(self, nodes, adjacencymatrix : dict):
        self.vertices = set()
        self.edgeset = list()
        self.adjacencymatrix = adjacencymatrix
        i = 0
        for i in nodes:
            self.vertices.add(node(i,0))
        for i in self.vertices:
            for j in self.vertices:
                if adjacencymatrix[i.name,j.name] != inf:  # if the weight between the vertices i and j is not infinite then j is in the adjacency list of i
                    i.adjlist.add(j)
        for i in self.vertices:             #adding all the edges in the edge list
            for j in self.vertices:
                if adjacencymatrix[i.name,j.name] != inf:
                    newedge = edge(i, j, adjacencymatrix[i.name,j.name])
                    self.edgeset.append(newedge)


"""produces a dictionary with key as a city and the minimum distance of the city from another city called "source" as the value"""

def run_dijkstra(map : graph, sourcename): 
    source = None
    for i in map.vertices:
        if i.name == sourcename:
            source = i
            i.distance = 0
            break
    for i in map.vertices:
        if i != source:
            i.distance = inf 
    solution = set()
    queue = minheap(map.vertices)
    while(not queue.isempty()):
        u = queue.extractmin()
        solution.add(u)
        for v in u.adjlist:
            if v.distance > u.distance + map.adjacencymatrix[u.name,v.name]:
                v.distance = u.distance + map.adjacencymatrix[u.name,v.name]
                v.predecessor = u
    min_map = {}
    for i in map.vertices:
        min_map[i.name] = i.distance
    return min_map