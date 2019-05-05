/*
https://leetcode.com/problems/design-circular-queue/

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".
One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.
Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
 

Example:
    MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
    circularQueue.enQueue(1);  // return true
    circularQueue.enQueue(2);  // return true
    circularQueue.enQueue(3);  // return true
    circularQueue.enQueue(4);  // return false, the queue is full
    circularQueue.Rear();  // return 3
    circularQueue.isFull();  // return true
    circularQueue.deQueue();  // return true
    circularQueue.enQueue(4);  // return true
    circularQueue.Rear();  // return 4
 
Note:
    All values will be in the range of [0, 1000].
    The number of operations will be in the range of [1, 1000].
    Please do not use the built-in Queue library.
*/

#include <stdio.h>

typedef struct {
    int head;
    int tail;
    int size;
    int *data;
} MyCircularQueue;

/** Checks whether the circular queue is empty or not. */
bool IsEmpty(MyCircularQueue* obj) {
    if (obj == NULL) {
        printf ("%s: please create data\n", __func__);
        return false;
    }

    if (obj->head < 0)
        return true;

    return false;
}

/** Checks whether the circular queue is full or not. */
bool IsFull(MyCircularQueue* obj) {
    if (obj == NULL) {
        printf ("%s: please create data\n", __func__);
        return false;
    }

    if (obj->head == (obj->tail + 1) % obj->size)
        return true;

    return false;
}

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (obj == NULL) { 
        printf("ERROR malloc MyCircularQueue\n");
        return NULL;
    }
    obj->data = malloc (sizeof(int) * k);
    if (obj->data == NULL) {
        printf("ERROR malloc data\n");
        return NULL;
    }
    obj->size = k;
    obj->head = -1;
    obj->tail = -1;
    return obj;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj == NULL) {
        printf ("%s: please create data\n", __func__);
        return false;
    }

    if (IsFull(obj)) {
        printf ("%s: buffer is full, failed to add %d\n", __func__, value);
        return false;
    }

    if (IsEmpty(obj))    obj->head = 0;
    obj->tail = (obj->tail + 1) % obj->size;
    obj->data[obj->tail] = value;
    printf ("[%d][%d] %d is stored\n", obj->head, obj->tail, value);

    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj == NULL) {
        printf ("%s: please create data\n", __func__);
        return false;
    }

    if (IsEmpty(obj)) {
        printf ("%s: buffer is empty, failed to DeQueue\n", __func__);
        return false;
    }
    printf ("[%d][%d] %d is deleted\n", obj->head, obj->tail, obj->data[obj->head]);
    if (obj->head == obj->tail) {
        obj->head = -1;
        obj->tail = -1;
    } else {
        obj->head = (obj->head + 1) % obj->size;
    }
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj == NULL) {
        printf ("%s: please create data\n", __func__);
        return -1;
    }
    
    if (IsEmpty(obj)) {
        printf ("%s: buffer is empty, failed to get first data\n", __func__);
        return -1;
    }
    printf ("[%d] %d\n", obj->head, obj->data[obj->head]);
    return obj->data[obj->head];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj == NULL) {
        printf ("%s: please create data\n", __func__);
        return -1;
    }

    if (IsEmpty(obj)) {
        printf ("%s: buffer is enpty, failed to get last data%d\n", __func__);
        return -1;
    }
    printf ("[%d] %d\n", obj->tail, obj->data[obj->tail]);

    return obj->data[obj->tail];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return IsEmpty(obj);
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return IsFull(obj);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/

/***********************************************/
typedef struct {
    int* items;

    unsigned int head;
    unsigned int tail;
    unsigned int cap;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    printf("NEW: %d\n", k);

    MyCircularQueue* queue = malloc(sizeof(MyCircularQueue));
    queue -> items = malloc(sizeof(int)*(k+1));
    queue -> head = 0;
    queue -> tail = 1;
    queue -> cap  = k+1;

    return queue;
}


bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);


/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))
        return false;

    obj -> items[obj -> tail] = value;
    obj -> tail = (obj -> tail + 1) % (obj -> cap);
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;
    
    obj -> head = (obj -> head + 1) % (obj -> cap); return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    return (myCircularQueueIsEmpty(obj)) ? -1 : obj -> items[(obj -> head + 1) % obj -> cap];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    printf("TAIL: %d\n", obj -> tail);
    return (myCircularQueueIsEmpty(obj)) ? -1 : obj -> items[(obj -> tail != 0) ? (obj -> tail - 1) : (obj -> cap - 1)];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return ((((obj -> head) + 1) % (obj -> cap)) == (obj -> tail % obj -> cap));
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj -> head) == (obj -> tail) % (obj -> cap));
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj -> items);
    free(obj);
}
/***********************************************/
typedef struct {
    int* buffer;
    int ptr_insert;
    int ptr_remove;
    int is_empty;
    int length;
    int num_obj;
} MyCircularQueue;

static head = 0;
static tail = 0;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
    printf("create queue of size %d\r\n", k);
    MyCircularQueue* queue = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    queue->buffer = (int*)malloc(k*sizeof(int));
    queue->ptr_insert = -1;
    queue->ptr_remove = 0;
    queue->length = k;
    queue->num_obj = 0;
    
    return queue;
}

int increment(int counter, int length){
    if(counter >= (length-1)){
        counter = 0;
    }
    else{
        counter++;
    }
    return counter;
}

int decrement(int counter, int length){
    if(counter <= (0)){
        counter = (length-1);
    }
    else{
        counter--;
    }
    return counter;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    int len = obj->length;
    printf("insert = %d\r\n", value);
     // printf("len = %d\r\n", obj->length);
    if(obj->num_obj >= obj->length){
        printf("full\r\n");
        return false;
    }
    obj->ptr_insert = increment(obj->ptr_insert, len);
    printf("inserting at index = %d\r\n", obj->ptr_insert);
    obj->buffer[obj->ptr_insert] = value;
    obj->num_obj++;
    return true;

}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    int len = obj->length;
    int length = obj->length;
    printf("num obj %d\r\n", obj->num_obj);
    if(obj->num_obj <= 0){
        return false;
    }
    else{
        obj->ptr_remove = increment(obj->ptr_remove, len);
        printf("remove ptr now at %d\r\n", obj->ptr_remove);
        obj->num_obj--;
        return true;
    }
    
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    int len = obj->length;
    if(obj->num_obj <= 0){
        printf("queue is empyty\r\n");
        return -1;
    }
    printf("front index is %d\r\n", obj->ptr_remove);
    return obj->buffer[obj->ptr_remove];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
        if(obj->num_obj <= 0)
            return -1;
        printf("rear index is %d\r\n", obj->ptr_insert);
        return obj->buffer[obj->ptr_insert];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if(obj->num_obj <= 0){
        return true;
    }
    else{
        return false;
    }
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if(obj->num_obj >= obj->length){
        return true;
    }
    else{
        return false;
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->buffer);
    free(obj);
}


/***********************************************/
typedef struct {
    int *first; // points to first
    int *fp;    // points to front (first inserted)
    int *rp;    // points to rear (last inserted)
    int *last;  // points to last
    bool full;
    bool empty;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * queue = malloc(sizeof(MyCircularQueue));
    queue->first = malloc(sizeof(int) * k);
    queue->fp = queue->first;
    queue->rp = queue->first;
    queue->last = queue->first + (k-1);
    queue->full = false;
    queue->empty = true;
    //MyCircularQueue * queue = malloc(sizeof(MyCircularQueue *) * k);
    return queue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->full) {
        return false;
    }
    
    obj->rp++;
    if(obj->rp > obj->last) {
        obj->rp = obj->first;
    }
    
    if(obj->fp == obj->rp) {
        obj->full = true;
    }
    
    *(obj->rp) = value;
    obj->empty = false;
    
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->empty) {
        return false;
    }
        
    obj->fp++;
    if(obj->fp > obj->last) {
        obj->fp = obj->first;
    }
    
    if(obj->rp == obj->fp) {
        obj->empty = true;
    }
    
    obj->full = false;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->empty) {
        return -1;
    }
    
    int *ptr = obj->fp + 1;
    if(ptr > obj->last) {
        ptr = obj->first;
    }
    
    return *(ptr);
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->empty) {
        return -1;
    }    
    return *(obj->rp);
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->empty;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->full;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->first);
    free(obj);
}
