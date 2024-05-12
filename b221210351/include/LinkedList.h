#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Bitki.h"
#include "Bocek.h"
#include "Sinek.h"
#include "Pire.h"

// Düğüm yapısı
struct Node
{
    char *c;
    void *data;
    struct Node *next;
};
typedef struct Node *Node;

// Bağlı liste fonksiyonları
void insertAtBeginning(struct Node **headRef, void *data, char *c);
void insertAtEnd(struct Node **headRef, void *data);
void deleteNode(struct Node **headRef, void *data);
void displayList(struct Node *head);

#endif