#include <stdio.h>
#include <stdlib.h>

struct DNode{
    struct DNode* next;
    struct DNode* prev;
    int x;
};

struct DList{
    struct DNode* first;
    struct DNode* last;
    int length;
};

struct DList* createDList(){
    struct DList* head = (struct DList*) malloc(sizeof(struct DList));
    head->first = NULL;
    head->last = NULL;
    head->length = 0;
    return head;
}

void push_front (int x, struct DList* head){
    struct DNode* element = (struct DNode*) malloc(sizeof(struct DNode));
    element->next = NULL;
    element->prev = NULL;
    element->x = x;
    if (head->first == NULL) {
        head->first = element;
        head->last = element;
    }
    else{
        element->next = head->first;
        head->first->prev = element;
        head->first = element;
    }
    head->length++;
}

void push_back (int x, struct DList *head){
    struct DNode* element = (struct DNode*) malloc(sizeof(struct DNode));
    element->next = NULL;
    element->prev = NULL;
    element->x = x;
    if (head->last == NULL){
        head->last = element;
        head->first = element;
    } else{
        element->prev = head->last;
        head->last->next = element;
        head->last = element;
    }
    head->length++;
}

void print_front (struct DList* head){
    struct DNode* tmp;
    tmp = head->first;
    while (tmp != NULL){
        printf(" -> %d", tmp->x);
        tmp = tmp->next;
    }
    printf("\n");
}

void print_back (struct DList* head){
    struct DNode* tmp;
    tmp = head->last;
    while (tmp != NULL){
        printf(" -> %d", tmp->x);
        tmp = tmp->prev;
    }
    printf("\n");
}

void empty(struct DList* head){
    if (head->length)
        printf("Lista nie jest pusta.\n");
    else
        printf("Lista jest pusta.\n");
}

int size(struct DList* head){
    return head->length;
}

int front (struct DList* head){
    return head->first->x;
}

int back (struct DList* head){
    return head->last->x;
}

void pop_front (struct DList* head){
    struct DNode* tmp;
    tmp = head->first;
    head->first = head->first->next;
    head->first->prev = NULL;
    free(tmp);
    head->length--;
}

void pop_back (struct DList* head){
    struct DNode* tmp;
    tmp = head->last;
    head->last = head->last->prev;
    head->last->next = NULL;
    free(tmp);
    head->length--;
}

void remover (int x, struct DList* head){
    struct DNode *tmp1, *tmp2;
    tmp1 = head->first;
    while(tmp1 != NULL){
        if (tmp1->x == x){
            tmp2 = tmp1;
            if(tmp2->prev) tmp2->prev->next = tmp2->next;
            else head->first = tmp2;
            if (tmp2->next) tmp2->next->prev = tmp2->prev;
            else head->last = tmp2->prev;
            tmp1 = tmp1->next;
            free(tmp2);
            head->length--;
        } else
            tmp1 = tmp1->next;
    }
}

void clear(struct DList* head){
    struct DNode* tmp;
    tmp = head->first;
    while(tmp->next != NULL){
        head->first = head->first->next;
        head->first->prev = NULL;
        free(tmp);
        tmp = head->first;
        head->length--;
    }
    head->first = head->first->next;
    free(tmp);
    head->length--;
    head->last = NULL;
}

int main() {

    struct DList* l1;
    l1 = createDList();
    empty(l1);
    printf("Rozmiar Twojej listy to %d.\n", size(l1));

    for(int i=0; i<10; i++){
        push_front(rand()%31, l1);
    }

    print_front(l1);
    printf("Rozmiar Twojej listy to %d.\n", size(l1));

    for(int i=0; i<10; i++){
        push_back(rand()%31, l1);
    }

    print_front(l1);
    printf("Rozmiar Twojej listy to %d.\n", size(l1));

    printf("Twoja lista wypisana od tylu.\n");
    print_back(l1);

    printf("Twoja lista po usunieciu wszystkich elementow o wartosci 26.\n");
    remover(26,l1);
    print_front(l1);

    empty(l1);
    pop_front(l1);
    pop_back(l1);
    printf("Twoja lista po usunieciu pierwszego i ostatniego elementu.\n");
    print_front(l1);

    printf("Rozmiar Twojej listy to %d.\n", size(l1));
    printf("Wartosc pierwszego elemetu to %d.\n", front(l1));
    printf("Wartosc ostatniego elementu to %d.\n", back(l1));
    clear (l1);
    printf("Rozmiar Twojej listy to %d.\n", size(l1));

    return 0;
}