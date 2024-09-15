#include <stdio.h>

int q[100];
int f = -1, r = -1, i, n;

void insert() {
    if (f == (r + 1) % n) {
        printf("Queue Overflow\n");
    } else {
        if (f == -1) {
            f = 0;
        }
        r = (r + 1) % n;
        printf("Enter the number to insert: ");
        scanf("%d", &q[r]);
    }
}

void delete() {
    if (f == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted number is: %d\n", q[f]);
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % n;
        }
    }
}

void display() {
    if (f == -1) {
        printf("Queue is empty\n");
    } else {
        for (i = f; i != r; i = (i + 1) % n) {
            printf("%d\t", q[i]);
        }
        printf("%d\t", q[r]);
        printf("\n");
    }
}

int main() {
    int ch;
    printf("Enter the size of the array: ");
    scanf("%d", &n); 
    
    do {
        printf("\n**MENU**\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (ch != 0);
    return 0;
}
