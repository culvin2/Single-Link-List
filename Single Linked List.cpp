#include<bits/stdc++.h>

typedef struct node{
    int data;
    struct node *next;
}a;   // a itu buat di ganti tulisan struct node di atas , dan bisa di ganti dengan variabel apa sajah

a *head;

a *create(a *head){
    a *baru, *temp;
    int num;
    printf("Masukan angka (-1 untuk berhenti): ");
    scanf("%d",&num);
    while(num != -1){
        baru = (a *)malloc(sizeof(a));
        baru->data = num;
        if(head == NULL){
            head = baru;
            head->next = NULL;
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = baru;
            baru->next = NULL;
        }
        printf("Masukan angka (-1 untuk berhenti): ");
        scanf("%d",&num);
    }
    return head;
}

a *display(a *head){
    a *temp;
    temp = head;
    while(temp != NULL){
        printf("\t%d",temp->data);
        temp = temp->next;
    }
    return head;
}

a *deletenode(a *head){
    a *temp,*pretemp;
    int num;
    printf("\nMasukan angka yang ingin dihapus: ");
    scanf("%d",&num);
    temp = head;
    pretemp = temp;
    while (temp->data != num){
        pretemp = temp;
        temp = temp->next;
    }
    pretemp->next = temp->next;
    free(temp);
    return head;
}

a *addafter (a *head) {
    int value, after;
    a *nodebaru, *temp;
    nodebaru = (a *) malloc (sizeof (a));
    printf ("\n Masukkan angka: ");
    scanf ("%d", &value);
    nodebaru -> data = value;
    printf ("\n Setelah angka: ");
    scanf ("%d", &after);
    temp = head;
    while (temp -> data != after) {
        temp = temp -> next;
    }
    nodebaru -> next = temp -> next;
    temp -> next = nodebaru;
    return head;
}

int main(){
    head = create(head);
    head = display(head);
    head = deletenode(head);
    head = display(head);
    head = addafter (head);
    head = display (head);
    return 0;
}
