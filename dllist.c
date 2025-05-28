#include <stdio.h>
#include <stdlib.h>
#include "dllist.h"

dllist* dllist_new(void){
    dllist* d = malloc(sizeof(dllist));
    if (d){
        d -> head = NULL;
        d -> tail = NULL; 
    } 
    return d;
};

void dllist_free(dllist *d){
    node *current = d->head;
    while (current) {
        node *next = current->next;
        free(current);
        current = next;
    }
    free(d);
};

void dllist_append(dllist *d, float value){
    node *n=malloc(sizeof(node));
    n->value=value;
    n->next=NULL;
    n->prev=d->tail;
    if(d->tail!=NULL){
        d->tail->next=n;
    } else {
        d->head=n;
    }
    d->tail=n;
};

void dllist_prepend(dllist *d, float value){
    node *n = malloc(sizeof(node));
    n->value = value;
    n->prev = NULL;
    n->next = d->head;

    if (d->head!=NULL)
        d->head->prev = n;
    else
        d->tail = n;

    d->head = n;
};

node* dllist_head(dllist *d){
    return d->head;
};

node* dllist_tail(dllist *d){
    return d->tail;
};

void dllist_remove(dllist *d, node *n) {
    if (!n) return;

    if (n->prev)
        n->prev->next = n->next;
    else
        d->head = n->next;

    if (n->next)
        n->next->prev = n->prev;
    else
        d->tail = n->prev;

    free(n);
};

size_t dllist_len(const dllist *d){
    size_t c = 0;
    node *current = d->head;
    while (current) {
        c++;
        current = current->next;
    }
    return c;
};

void dllist_print(const dllist *d){
    node *current = d->head;
    while (current) {
        printf("%.2F", current->value);
        if (current->next) printf(", ");
        current = current->next;
    }
    printf("/n");
};





