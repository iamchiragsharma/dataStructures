heap_raw = [31,10,16,9,8,14,12,3,1,5,7] #list(map(int,input().split()))
broke = False

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


def insertion(heap,element=19):
    heap.append(element)
    i = len(heap) - 1
    while i>1:
        if heap[(i-1)//2] < heap[i]: #Parent < Child
            heap[(i-1)//2],heap[i] = heap[i],heap[(i-1)//2]
        else:
            pass
        i = i//2
    print(heap)

insertion(heap)
 