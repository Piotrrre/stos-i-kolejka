#include <stdio.h>
#include <stdbool.h>

#define MAX 5 // Define the maximum size of the queue

int queue[MAX];
int front = -1;
int rear = -1;

bool isQueueFull() {
    return ((rear + 1) % MAX == front);
}

bool isQueueEmpty() {
    return (front == -1 && rear == -1);
}

void Push(int temp) {
    if (isQueueFull()) {
        printf("Queue is full, cannot push.\n");
        return;
    } else if (isQueueEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = temp;
}

int Top() {
    if (isQueueEmpty()) {
        printf("Queue is empty, cannot read top.\n");
        return -1; // Return a default value when the queue is empty
    }
    return queue[front];
}

int Pop() {
    if (isQueueEmpty()) {
        printf("Queue is empty, cannot pop.\n");
        return -1; // Return a default value when the queue is empty
    }
    int value = queue[front];
    if (front == rear) {
        // Queue is now empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return value;
}

void menu(void) {
    printf("\n");
    printf("1 - Dodaj liczbe do kolejki (Push)\n");
    printf("2 - odczytaj wartosc z poczatku kolejki (Top)\n");
    printf("3 - zdejmij liczbe z poczatku kolejki (Pop)\n");
    printf("4 - sprawdz czy kolejka jest pusta\n");
    printf("5 - sprawdz czy kolejka jest pelna\n");
    printf("6 - koniec programu\n");
    printf("\n");
}

int main() {
    int temp = 0;
    int option = 0;
    printf("KOLEJKA - implementacja w tablicy statycznej\n");
    while (1) {
        menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (!isQueueFull()) {
                    printf("Podaj wartosc: ");
                    scanf("%d", &temp);
                    Push(temp);
                } else {
                    printf("Operacja niedozwolona, KOLEJKA pelna!!!\n\n");
                }
                break;

            case 2:
                if (!isQueueEmpty()) {
                    temp = Top();
                    printf("Odczytana wartosc: %d\n", temp);
                } else {
                    printf("Operacja niedozwolona, KOLEJKA pusta!!!\n\n");
                }
                break;

            case 3:
                if (!isQueueEmpty()) {
                    temp = Pop();
                    printf("Zdjeta wartosc: %d\n", temp);
                } else {
                    printf("Operacja niedozwolona, KOLEJKA pusta!!!\n\n");
                }
                break;

            case 4:
                if (isQueueEmpty()) {
                    printf("KOLEJKA jest pusta.\n");
                } else {
                    printf("KOLEJKA nie jest pusta.\n");
                }
                break;

            case 5:
                if (isQueueFull()) {
                    printf("KOLEJKA jest pelna.\n");
                } else {
                    printf("KOLEJKA nie jest pelna.\n");
                }
                break;

            case 6:
                // Zakonczenie programu
                return 0;

            default:
                printf("Wybierz wlasciwa opcje od 1 do 6.\n\n");
                break;
        }
    }

    return 0;
}
