#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head1=NULL; 
struct node *head2=NULL;

struct node* createnode(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;

}

void insertatend(struct node** head, int value){
    struct node* newnode = createnode(value);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void reverse(struct node** head) {
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;
    
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;     
    }
    *head = prev; 
}

void concatenate(struct node** head1, struct node** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
    } else {
        struct node* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = *head2;
    }
    *head2 = NULL; 
}

void sortlist(struct node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; 
    }
    
    struct node* i ,*j;
    int temp;

    for(i=*head;i!=NULL;i=i->next) {
        for(j=i->next;j!=NULL;j=j->next) {
            if(i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main() {
    int n1, n2, value;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);
    printf("Enter elements of first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insertatend(&head1, value);
    }

    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);
    printf("Enter elements of second list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insertatend(&head2, value);
    }

    printf("First List: ");
    display(head1);
    
    printf("Second List: ");
    display(head2);

    reverse(&head1);
    printf("Reversed First List: ");
    display(head1);

    reverse(&head2);
    printf("Reversed Second List: ");
    display(head2);

    concatenate(&head1, &head2);
    printf("Concatenated List: ");
    display(head1);

    sortlist(&head1);
    printf("Sorted List: ");
    display(head1);


    return 0;
}
