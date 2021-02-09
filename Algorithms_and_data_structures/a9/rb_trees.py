from enum import Enum, auto

class color(Enum):
    RED = auto()
    BLACK = auto()

class node:
    def __init__(self, newkey = 0, newparent = None, newright = None, newleft = None, newcolor = color.RED):
        self.key = newkey
        self.parent = newparent
        self.right = newright
        self.left = newleft
        self.mycolor = newcolor
    
class RBtrees:
    def __init__(self, newroot = None):
        self.__root = newroot
        self._nil = node(0,None, self.__root, self.__root, color.BLACK)

    def __getroot(self):
        return self.__root

    def __setroot(self, newroot):
        self.__root = newroot
        self._nil.left = self._nil.right = self.__root

    __reachroot = property(__getroot, __setroot) #this line and the above two methods ensure that the right and the left of the sentinel 
                                                # always point to the root of the tree
                                            
    def _leftrotate(self, x):
        y = x.right
        x.right = y.left
        if y.left == self._nil:
            y.left.parent = x
        y.parent = x.parent
        if x.parent == self._nil:
            self.__reachroot = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y
        y.left = x
        x.parent = y

    def _rightrotate(self, y):
        x = y.left
        y.left = x.right
        if x.right == self._nil:
            x.right.parent = y
        x.parent = y.parent
        if y.parent == self._nil:
            self.__reachroot = x
        elif y.parent.left == y:
            y.parent.left = x
        else:
            y.parent.right = x
        x.right = y
        y.parent = x

    def _transplant(self, a, b):
        if a.parent == self._nil:
            self.__reachroot = b
        elif a.parent.left == a:
            a.parent.left = b
        else:
            a.parent.right = b
        if b != self._nil:
            b.parent = a.parent

    def getminimum(self, rooted_at):
        while(rooted_at.left != self._nil):
            rooted_at = rooted_at.left
        return rooted_at

    def getmaximum(self, rooted_at):
        while(rooted_at.right != self._nil):
            rooted_at = rooted_at._right
        return rooted_at
     
    def successor(self, nodeof):
        if(nodeof.right != self._nil):
            return self.getminimum(nodeof.right)
        p = nodeof.parent
        while p != self._nil and nodeof == p.right:
            nodeof = p
            p = nodeof.parent
        return p

    def predecessor(self, nodeof):
        if(nodeof.left != self._nil):
            return self.getmaximum(nodeof.left)
        elif(nodeof.parent.right == node):
            return nodeof.parent
        else:
            return self._nil