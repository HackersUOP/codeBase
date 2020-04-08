# Name  - Thilakarathna W M D U
# Email - dtdinidu7@gmail.com
# Date  - 08/04/2020

class Graph():                # this class is used to check whether the graph is bipartite graph you can find this code with an explanation in geeksforgeeks
	def __init__(self, V): 
		self.V = V 
		self.graph = [[0 for column in range(V)] 
						for row in range(V)] 

		self.cAr = [-1 for i in range(self.V)]   # this array is filled with -1 and 2 as the colors 
		
	def isBipUti(self, src): 		
		q = [] 
		q.append(src) 
		while q: 
			u = q.pop() 
			if self.graph[u][u] == 1: 
				return False

			for v in range(self.V): 
				if (self.graph[u][v] == 1 and
					self.cAr[v] == -1): 

					self.cAr[v] = 1 - self.cAr[u] 
					q.append(v) 

				elif (self.graph[u][v] == 1 and
					self.cAr[v] == self.cAr[u]): 
					return False
		return True
		
	def isBip(self): 
		self.cAr = [-1 for i in range(self.V)] 
		for i in range(self.V): 
			if self.cAr[i] == -1: 
				if not self.isBipUti(i): 
					return False
		#print(self.cAr)
		return True


def isOverlap(s1, e1, s2, e2): # check whether two slots are overlap with each other
    if (s1 >= e2 and s2 < s1):
        return False
    if (s2 >= e1 and s1 < s2):
        return False
    return True
					
tm = int(input()) # number of the test cases

for t in range(1, tm+1): # loop through the test cases
    timeLine = []
    for i in range(1445):
        timeLine.append([])

    #print(timeLine)
    v = int(input())
    g = Graph(v)
    g.graph = []
    #lis = []
    for i in range(v): # adding events to the timeline
        g.graph.append([0]*v)
        strat, end = [int(i) for i in input().split()]
        #lis.append((strat, end))
        timeLine[strat].append(i+1)
        timeLine[end].append(-(i+1))

    dinQ = set()
    #print(timeLine)

    for i in timeLine:  # checking for overlaps
        if len(i) > 0:
            for j in i:
                if (j > 0):
                    dinQ.add(j-1)
                else:
                    dinQ.remove((-j)-1)

            if len(dinQ)>2: # if three slots overlap each other then two people can't dewide them among themselves without overlaping
                print("Case #{}: IMPOSSIBLE".format(t))
                break
            
            tmp = list(dinQ)

            for x in range(len(dinQ)):
                for y in range(x+1, len(dinQ)):
                    g.graph[tmp[x]][tmp[y]] = 1
                    g.graph[tmp[y]][tmp[x]] = 1
    else:
        #print()
        #print(g.graph)

        if (g.isBip()):
            strg = ""
            for i in g.cAr:
                if (i == -1):
                    strg += "C"
                else:
                    strg += "J"
            print("Case #{}: {}".format(t, strg))
        else:
            print("Case #{}: IMPOSSIBLE".format(t))