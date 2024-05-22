#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data [MAX_SIZE];
    int front, rear;
}Queue;

void initQueue(Queue *queue){
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue){
    return(queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue *queue, int waktu) {
    if (isFull(queue)) {
        printf("Antrian penuh\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = waktu;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Antrian kosong\n");
        return -1;
    }
    int removed = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return removed;
}

int totalWaktu(Queue *queue, int kapasitas){
    int total = 0;
    int waktuSekarang = 0;

     while (!isEmpty(queue)) {
        int waktu = dequeue(queue);
        if (waktu > kapasitas) {
            total += waktu;
            waktuSekarang += kapasitas;
        } else {
            total += waktuSekarang + waktu;
            waktuSekarang += waktu;
        }
    }
    return total;
}

int main(){
    Queue queue;
    initQueue(&queue);

    int kapasitas;
    printf("Masukkan kapasitas jumlah pengunjung didalam rumah makan : ");
    scanf("%d", &kapasitas);

    int n;
    printf("Masukkan jumlah pengunjung : ");
    scanf("%d", &n);

    printf("Masukkan waktu kedatangan masing-masing pengunjung:\n");
    for (int i = 0; i < n; i++) {
        int waktu;
        printf("Pengunjung %d: ", i + 1);
        scanf("%d", &waktu);
        enqueue(&queue, waktu);
    }

    int total = totalWaktu(&queue, kapasitas);
    printf("Total waktu untuk semua pengunjung masuk ke dalam rumah makan: %d menit\n", total);

    return 0;
}