from optimal_meeting_point import graph, run_dijkstra
from math import inf
from sys import exit

def main():
    n = int(input("Enter the number of cities that you want to enter"))
    cities = []
    for i in range(0,n):
        city = input("Enter a city")
        cities.append(city)
    adjmatrix = {}
    for i in cities:
        for j in cities:
            if i == j:
                adjmatrix[i,j] = 0
            else:
                adjmatrix[i,j] = inf
    print("Enter the two cities and the time that it takes to travel between them")
    while(True):
        print("Enter X for both the cities to exit")
        A = input("Enter the first city")
        B = input("Enter the second city")
        if(A == 'X' and B == 'X'):
            break
        elif(A not in cities or B not in cities):
            print("One or two of the cities not in the list of cities")
        else:
            weight = int(input("Enter the time between {} and {}".format(A, B)))
            adjmatrix[A,B] = weight
    map = graph(cities, adjmatrix)
    while(True):
        yourcity = input("Enter your city")
        friendscity = input("Enter your friend's city")
        if(yourcity in cities and friendscity in cities):
            break
        else:
            print("One or both cities not in the list of cities, enter he two cities again")
    yourmap = run_dijkstra(map, yourcity)
    friendsmap = run_dijkstra(map, friendscity)
    sortlist = {}
    for i in cities:
        sortlist[i] = max(yourmap[i], friendsmap[i])
    min = cities[0]
    for i in cities:
        if sortlist[i] < sortlist[min]:
            min = i
    print(f"The optimal meeting place will be in {min}")  

if __name__ == "__main__":
    main()



