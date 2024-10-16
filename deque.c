#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct Deque {
    int items[SIZE];
    int front;
    int rear;
};

typedef struct Deque dq;

void initializeDeque(dq *d) {
    d->front = -1;
    d->rear = -1;
}

int isFull(dq *d) {
    if ((d->front == 0 && d->rear == SIZE - 1) || (d->front == d->rear + 1)) {
        return 1;
    }
    return 0;
}

int isEmpty(dq *d) {
    if (d->front == -1) return 1;
    return 0;
}

void insertFront(dq *d, int value) {
    if (isFull(d)) {
        printf("Deque is Full\n");
        return;
    }

    if (d->front == -1) {
        d->front = 0;
        d->rear = 0;
    } else if (d->front == 0) {
        d->front = SIZE - 1;
    } else {
        d->front--;
    }

    d->items[d->front] = value;
    printf("Inserted %d at front\n", value);
}

void insertRear(dq *d, int value) {
    if (isFull(d)) {
        printf("Deque is Full\n");
        return;
    }

    if (d->rear == -1) {
        d->rear = 0;
        d->front = 0;
    } else if (d->rear == SIZE - 1) {
        d->rear = 0;
    } else {
        d->rear++;
    }

    d->items[d->rear] = value;
    printf("Inserted %d at rear\n", value);
}

int deleteFront(dq *d) {
    int value;
    if (isEmpty(d)) {
        printf("Deque is Empty\n");
        return -1;
    }

    value = d->items[d->front];

    if (d->front == d->rear) {
        d->front = -1;
        d->rear = -1;
    } else if (d->front == SIZE - 1) {
        d->front = 0;
    } else {
        d->front++;
    }

    return value;
}

int deleteRear(dq *d) {
    int value;
    if (isEmpty(d)) {
        printf("Deque is Empty\n");
        return -1;
    }

    value = d->items[d->rear];

    if (d->front == d->rear) {
        d->front = -1;
        d->rear = -1;
    } else if (d->rear == 0) {
        d->rear = SIZE - 1;
    } else {
        d->rear--;
    }

    return value;
}

void displayDeque(dq *d) {
    int i;
    if (isEmpty(d)) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque: ");
    for (i = d->front; i != d->rear; i = (i + 1) % SIZE) {
        printf("%d ", d->items[i]);
    }
    printf("%d\n", d->items[i]);
}

int main() {
    dq d;
    initializeDeque(&d);

    insertRear(&d, 1);
    insertRear(&d, 2);
    insertFront(&d, 3);
    insertFront(&d, 4);

    displayDeque(&d);

    printf("Deleted from front: %d\n", deleteFront(&d));
    displayDeque(&d);

    printf("Deleted from rear: %d\n", deleteRear(&d));
    displayDeque(&d);

    return 0;
}
