#include <stdlib.h>

typedef struct LinkedList {
    void *table;
    struct LinkedList *next;
}LinkedList;


LinkedList *create_list() {
    LinkedList *head = (LinkedList*) malloc(sizeof(LinkedList));
    head->table = NULL;
    head->next = NULL;
    return head;
}

void add_table(LinkedList *head, void *table) {

    if(head->table == NULL) {
        head->table = table;
        return;
    }

    LinkedList *ptr;
    for(ptr=head; ptr->next!=NULL; ptr=ptr->next);

    ptr->next = (LinkedList*)malloc(sizeof(LinkedList));
    ptr->next->table = table;
}