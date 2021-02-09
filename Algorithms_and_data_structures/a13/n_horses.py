from enum import Enum, auto

class valid(Enum):
    Allowed = auto()
    Forbidden = auto()

class chessboard:
    def __init__(self, n : int):
        board = {}
        for i in range(0,n):
            for j in range(0, n):
                board[i,j] = valid.Allowed
        self.board = board
        self.dimension = n 
        self.horsepositions = []

    def generatepossiblemoves(self , i, j):
        moves = [[2,-1],[1,-2],[2,1],[1,2],[-1,-2],[-2,-1],[-2,1],[-1,2]]
        possible_future_position = []
        for m in moves:
            horizontal_pos = i + m[0]
            vertical_pos = j + m[1]
            if(horizontal_pos >= 0 and horizontal_pos < self.dimension and vertical_pos >= 0 and vertical_pos < self.dimension):
                possible_future_position.append([horizontal_pos,vertical_pos])
        return possible_future_position     
        
    def placehorse(self,i,j):
        if self.board[i,j] == valid.Forbidden:
            return False
        else:
            self.horsepositions.append([i,j])
            self.board[i,j] = valid.Forbidden
            can_move_to = self.generatepossiblemoves(i,j)
            for k in can_move_to:
                self.board[k[0],k[1]] = valid.Forbidden
            return True

    def printboard(self):
        for i in range(0, self.dimension):
            for j in range(0,self.dimension):
                if [i,j] in self.horsepositions:
                    print('X', end=' ')
                else:
                    print('O', end= ' ')
            print("\n", end='')
        print("_"*self.dimension)

    def solution(self, vector):
        if vector.cursor + 1 != self.dimension:
            return False 
        for i in vector.stack:
            possible = self.placehorse(i[0],i[1])
            if possible == False:
                return False
        return True

    def reset(self):
        for i in range(0,self.dimension):
            for j in range(0, self.dimension):
                self.board[i,j] = valid.Allowed
        self.horsepositions = []

class stack_of_lists:
    def __init__(self, n):
        self.stack = []
        self.cursor = -1
        possiblevalues = []
        for i in range(0,n):
            for j in range(0,n):
                possiblevalues.append([i,j])
        self.valuebank = possiblevalues
        
    def add(self, n):
        self.stack.append(n)
        self.cursor += 1

    def remove(self):
        return self.stack.pop()

    def isempty(self):
        if self.stack == []:
            return True

    def isValid(self):
        k = self.stack[-1]
        for i in range(0,self.cursor):
            if self.stack[i] == k:
                return False
        return True
        
    def __str__(self):
        return self.stack.__str__()

    def successor(self):
        if self.stack[-1] == self.valuebank[-1]:
            return False
        else:
            k = self.valuebank.index(self.stack[-1])
            self.stack[-1] = self.valuebank[k+1]
            return True

def backtrack(board : chessboard , n):
    solutionlist = []
    vector = stack_of_lists(n)
    print("Stack of lists created")
    vector.add([0,0])
    while not vector.isempty():
        possible_for_new = True
        valid_new = False
        if vector.cursor < n:
            while not valid_new and possible_for_new:
                possible_for_new = vector.successor()   #moving to the next element allowed by the possibilities
                if possible_for_new:
                    valid_new = vector.isValid()        #to make all the positions in the vector unique
        if possible_for_new:
            if board.solution(vector):
                board.printboard()
                solutionlist.append(board.horsepositions)
                board.reset()
            else:
                board.reset()
                if vector.cursor + 1 < n:
                    vector.add([0,0])
        else:
            vector.remove()
    return solutionlist

def main():
    n = int(input("Enter the dimension of the chessboard"))
    A = chessboard(n)
    print("All the possible solutions of the n horse problem are as follows")
    l = backtrack(A, n)
    for i in l:
        print(i)

if __name__ == "__main__":
    main()