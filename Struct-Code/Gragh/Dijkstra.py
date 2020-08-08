def dijkstra2(graph,start):
    vnum = len(graph)
    pqueue = []
    heapq.heappush(pqueue,(0.0,None,start))
    paths = {vertex : None for vertex in graph}
    count = 0
    
    while count < vnum and pqueue:
        pair = heapq.heappop(pqueue)
        distance = pair[0]
        parent = pair[1]
        vertex = pair[2]
        if paths[vertex]:
            continue
        paths[vertex] = (parent,distance)
        edges = graph[vertex]
        for v in edges:
            if paths[v] is None:
                heapq.heappush(pqueue,(distance + graph[vertex][v],vertex,v))
        count += 1
    return paths
#%%
def prim(graph,start): 
    vnum = len(graph)
    pqueue = []
    heapq.heappush(pqueue,(0.0,None,start))
    mst = {vertex : None for vertex in graph}
    count = 0   
    
    while count < vnum and pqueue:
        pair = heapq.heappop(pqueue)
        dist = pair[0]
        parent = pair[1]
        vertex = pair[2]
        if mst[vertex]:
            continue
        mst[vertex]=(parent,dist)
        edges = graph[vertex]
        for v in edges:
            if mst[v] is None:
                heapq.heappush(pqueue,(graph[vertex][v],vertex,v))
        count += 1
    return mst 