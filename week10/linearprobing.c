#include <stdio.h>
#define EMPTY -1
int hashTable[100];   
int m;                
int hashFunction(int key) {
    return key % m;
}
void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (hashTable[index] != EMPTY) {
        index = (index + 1) % m;

        if (index == startIndex) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
    printf("Key %d inserted at location %d\n", key, index);
}
void display() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] == EMPTY)
            printf("HT[%d] : EMPTY\n", i);
        else
            printf("HT[%d] : %d\n", i, hashTable[i]);
    }
}
int main() {
    int n, key;
    printf("Enter size of Hash Table (m): ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        hashTable[i] = EMPTY;
    printf("Enter number of employee records (N): ");
    scanf("%d", &n);
    printf("Enter %d employee keys (4-digit integers):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
