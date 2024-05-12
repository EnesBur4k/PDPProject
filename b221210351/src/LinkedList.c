#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Liste başına eleman ekleme
void insertAtBeginning(struct Node **headRef, void *data, char *c)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Bellek tahsisi basarisiz.\n");
        return;
    }
    newNode->c = (char *)malloc(sizeof(char) * 10);
    strcpy(newNode->c, c);
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Liste sonuna eleman ekleme
void insertAtEnd(struct Node **headRef, void *data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Bellek tahsisi basarisiz.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    struct Node *lastNode = *headRef;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Veriye sahip düğümü silme
void deleteNode(struct Node **headRef, void *data)
{
    struct Node *current = *headRef;
    struct Node *prev = NULL;

    // İlk düğümü silme
    if (current != NULL && current->data == data)
    {
        *headRef = current->next;
        free(current);
        return;
    }

    // Diğer düğümleri silme
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Veri bulunamadi.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

// Liste içeriğini görüntüleme
void displayList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%p -> ", current->data); // void* olduğu için doğrudan adresi yazdırıyoruz
        current = current->next;
    }
    printf("NULL\n");
}
