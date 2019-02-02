## <u> DEQUE </u>:

* It is an abstract datatype. It can be implemented using the linked lists and dynamic array.

* It says that the queue should allow insertion and deletion at both ends with the run tme complexity **O(n)**.

```c++
struct node{
    int data;
    node* next;
}

node* front = NULL;
node* rear = NULL;
````

* This is linked in one way only since we will use the next pointer to traverse.

```c++
void insertion(node* front, node* rear, int data)
node* newNode = new node;
newNode->next = NULL;
newNode->data = data;

if (rear == front == NULL)
{
    front = newNode;
    rear = newNode;
    return;
}

//For the insertion at front 
newNode->next = front;
front = newNode;

//For the insertion at back
rear->next = newNode;
newNode = rear;

```

* Insertion can be done easily at both ends with the complexity **O(1)** but deletion faces problems. 

**So implementation of double ended queue by singly linked list is not possible. Use the doubly linked list.**



