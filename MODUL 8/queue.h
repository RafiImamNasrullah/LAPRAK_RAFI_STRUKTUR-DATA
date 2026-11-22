#ifndef QUEUE_H
#define QUEUE_H

#define MAXQ 5   // ukuran array

typedef int infotype;

struct Queue {
    infotype info[MAXQ];   // index array dimulai dari 0
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
