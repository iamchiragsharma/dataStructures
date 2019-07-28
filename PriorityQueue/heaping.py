heap_raw = list(map(int,input().split()))

for i in range(len(heap_raw)):
    try:
        if heap_raw[i] >= max(heap_raw[2*i+1],heap_raw[2*i+2]):
            pass
        else:
            print("Heaping broke at index",i)
            broke = True
    except IndexError:
        break

heap = heap_raw

if broke == True:
    for i in range(len(heap_raw)):
        try:
            if heap[i] >= max(heap[2*i+1],heap[2*i+2]):
                pass
            else:
                if heap[2*i+1] == max(heap[2*i+1],heap[2*i+2]):
                    heap[i],heap[2*i+1] = heap[2*i+1],heap[i]
                else:
                    heap[i],heap[2*i+2] = heap[2*i+2],heap[i]
        except IndexError:
            break

print(heap)