#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task{
    char *name;
    struct Task *next;
};

struct Task *head = NULL;
struct Task *tail = NULL;

struct Task* task_new(const char *name){
    struct Task *task;
    task = (struct Task*)malloc(sizeof(struct Task));
    task -> name = strdup(name);
    task -> next = NULL;
    return task;
};

void task_free(struct Task *task){
    if(task!=NULL){
        free(task->name);
        free(task);
        };
};

void add_task(const char *name){
    struct Task *new_task = task_new(name);

    if(tail==NULL){
        tail=new_task;
        head=new_task;
    }else{
        tail -> next = new_task;
        tail = new_task;
    }

};

void show_tasks(){
    printf("\n");

    if (head == NULL)
    {
        printf("Lista jest pusta.\n");
    };
    

    for(struct Task *now = head; now!=NULL ; now = now -> next){
        printf("%s\n",now->name);
    };
};

void remove_task(){
    if(head!=NULL) {
        Task *next = head->next;
        task_free(head);
        head=next;
        if (head==NULL){
            tail==NULL;
        }
    }
};

int main(){
    int choice;

    do{
        printf("\n");
        printf("1. Wyswietl wszystkie zadania.\n");
        printf("2. Dodaj zadanie na koniec kolejki.\n");
        printf("3. Usun zadanie z poczatku kolejki.\n");
        printf("4.Zakoncz.\n");
        scanf("%d",&choice);
        getchar();
        char add[100];
        switch(choice){
            case 1:
                show_tasks();
                break;
            case 2:
                printf("Podaj zadanie: ");
                scanf("%[^\n]",add);
                add_task(add);
                break;
            case 3:
                remove_task();
                show_tasks();
                break;
        }
        
    }while (choice!=4);
    
    
    return 0;
};