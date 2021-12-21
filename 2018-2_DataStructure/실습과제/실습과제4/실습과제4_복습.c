//
//  main.c
//  ComputerScience
//
//  Created by 임또상 on 2021/12/21.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
    element item;
    struct ListNode* link;
} ListNode;

typedef struct {
    ListNode* head;
    int length;
} ListType;

void init(ListType* list) {
    list->length = 0;
    list->head = NULL;
}

int is_empty(ListType* list) {
    return (list->length == 0);
}

int length(ListType* list) {
    return list->length;
}

void insert_node(ListNode** phead, ListNode* previous, ListNode* new_node) {
    if (*phead == NULL) {
        new_node->link = NULL;
        *phead = new_node;
    } else if (previous == NULL) {
        new_node->link = *phead;
        *phead = new_node;
    } else {
        new_node->link = previous->link;
        previous->link = new_node;
    }
}

ListNode *get_node_at(ListType *list, int pos) {
    ListNode* temp = list->head;
    if(pos < 0) return NULL;
    for(int i = 0; i < pos; i++) {
        temp = temp->link;
    }
    return temp;
}

void add(ListType* list, int position, element item) {
    ListNode* p;
    if ( (0 <= position) && (position <= list->length)) {
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        node->item = item;
        p = get_node_at(&list->head, position-1);
        insert_node(&(list->head), p, node);
        list->length++;
    }
}

void add_last(ListType* list, element item) {
    add(list, list->length, item);
}

void add_first(ListType* list, element item) {
    add(list, 0, item);
}

void delete_node(ListNode** phead, ListNode *p, ListNode *removed) {
    if (p == NULL) {
        *phead = (*phead)->link;
    } else {
        p->link = removed->link;
    }
    free(removed);
}

void delete(ListType* list, int position) {
    if(!is_empty(list) && (0 <= position) && (position <= list->length)) {
        ListNode* previous = get_node_at(list, position-1);
        ListNode* removed = get_node_at(list, position);
        delete_node(&(list->head), previous, removed);
        list->length--;
    }
}


void visit(ListNode *head) {
    ListNode *p = head;
    while(p != NULL) {
        printf("%d ", p->item);
        p = p->link;
    }
    printf("\n");
}

int findIndex(ListType* list, int key) {
    int index = 0;
    if(!is_empty(list)) {
        ListNode* node = list->head;
        while(node != NULL) {
            if (node->item == key) {
                return index;
            }
            index++;
            node = node->link;
        }
    }
    return -1;
}

void deleteAndVisit(ListType *list, int key) {
    int index = findIndex(list, key);
    printf("Key = ");
    printf("%d", key);
    if (index == -1) printf("\"키가 없음\"\n");
    else printf("\n");
    delete(list, index);
    printf("Original data = ");
    visit(list->head);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int arr[10];
    int x1, x2;
    int key1, key2, key3;
    ListType list = (ListType){ .head = NULL, .length = 0};
    
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d %d", &key1, &key2, &key3);
    
    init(&list);
//  리스트에 요소 추가
    for(int i = 0; i< n ;i++) {
        add_last(&list, arr[i]);
    }
    
    printf("n = %d\n", n);
    printf("Original data = ");
    visit(list.head);
    

    deleteAndVisit(&list, key1);
    deleteAndVisit(&list, key2);
    deleteAndVisit(&list, key3);
    
    return 0;
}


