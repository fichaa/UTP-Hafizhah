#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char nama[50];
    char pesanan[100];
} Pengunjung;

typedef struct {
    Pengunjung data[MAX_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue *queue) {
    return queue->front == -1;
}

int isFull(Queue *queue){
    return(queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(Queue *queue, Pengunjung pengunjung) {
    if (isFull(queue)) {
        printf("Antrian penuh\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->data[queue->rear] = pengunjung;
}

Pengunjung dequeue(Queue *queue) {
    Pengunjung pengunjung;
    if (isEmpty(queue)) {
        printf("Antrian kosong\n");
        strcpy(pengunjung.nama, "");
        strcpy(pengunjung.pesanan, "");
        return pengunjung;
    }
    pengunjung = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return pengunjung;
}

void tampilkanQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Antrian kosong\n");
        return;
    }
    printf("Antrian Pengunjung Kafe:\n");
    int i = queue->front;
    do {
        printf("Nama: %s, Pesanan: %s\n", queue->data[i].nama, queue->data[i].pesanan);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
}

int main() {
    Queue queue;
    initQueue(&queue);

    int choice;
    Pengunjung pengunjung;
    do {
        printf("==== Pilih Menu ====\n");
        printf("1. Tambah pengunjung\n");
        printf("2. Layani pengunjung\n");
        printf("3. Tampilkan antrian\n");
        printf("4. Keluar\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan nama pengunjung: ");
                scanf(" %[^\n]s", pengunjung.nama);
                printf("Masukkan pesanan: ");
                scanf(" %[^\n]s", pengunjung.pesanan);
                enqueue(&queue, pengunjung);
                printf("Pengunjung telah ditambahkan ke dalam antrian.\n");
                break;
            case 2:
                if (!isEmpty(&queue)) {
                    pengunjung = dequeue(&queue);
                    printf("Pengunjung %s dengan pesanan %s telah dilayani dan keluar dari antrian.\n", pengunjung.nama, pengunjung.pesanan);
                } else {
                    printf("Antrian kosong. Tidak ada yang dilayani.\n");
                }
                break;
            case 3:
                tampilkanQueue(&queue);
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (choice != 4);

    return 0;
}
    