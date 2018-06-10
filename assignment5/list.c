#include "list.h"

int length(struct node* n) {
    int length = 1;
    struct node* current = n;
    while (current != 0) {
        length++;
        current = current->next;
    }
    return length;
}

void print(struct node* n, int length) {
    if (length > length(n)) return;
    
    int i;
    struct node* current = n;
    for (i = 0; i < length; i++) {
        printf("%d ", current->val);
        current = current->next;
    }
}

struct node* push(struct node* head, int value) {
    struct node* new = malloc(sizeof(struct node));
    new->val = value;
    new->next = head;
    return new;
}

struct node* append(struct node* head, int value) {
    struct node* new = malloc(sizeof(struct node));
    new->val = value;
    new->next = NULL;

    struct node* current = head;
    while (current->next != NULL) current = current->next;
    current->next = new;

    return head;
}

struct node* clear(struct node* head) {
    struct node* current;
    while (head != NULL) {
        current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
    }
    free(head);
    return NULL;
}

struct node* remove_node(struct node* head, int index) {
    struct node* current = head;
    int i
    for (i = 0; i < index - 1; i++) current = current->next;
    struct node* next = current->next->next;
    free(current->next);
    current->next = next;
}

int is_sorted_a(struct node* head) {
    struct node* current = head;
    while (current->next != NULL) {
	if (current->val > current->next->val) return 0;
    }
    return 1;
}

int is_sorted_d(struct node* head) {
    struct node* current = head;
    while (current->next != NULL) {
	if (current->val < current->next->val) return 0;
    }
    return 1;
}

struct node* swap_nodes(struct node* head, struct node** left, struct node** right) {
    if (head == left) {
	left->next = right->next;
	
    }
}

struct node* sort_ascending(struct node* head) {
    while (!is_sorted_a()) {
    }
}

struct node* sort_descending(struct node*) {

}

struct node* insert_middle(struct node*, int, int) {

}
