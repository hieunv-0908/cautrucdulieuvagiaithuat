#include "../common.h"
struct NODE {
    int data;
    struct NODE *next;
};

struct NODE* create_node(int data) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append_node(struct NODE** head,int value) {
    struct NODE* new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct NODE* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void search_data_node(struct NODE** head,int search_data) {
    struct NODE *current = *head;
    while (current != NULL) {
        if (current->data == search_data) {
            printf("TRUE");
            return;
        }
        current = current->next;
    }
    printf("FALSE");
    return;
}

void printf_reverse(struct NODE* current) {
    if (current == NULL) return;
    printf_node(current->next);
    printf("%d ",current->data);
    return;
}

void printf_node(struct NODE** head) {
    struct NODE *current = *head;
    printf("head-->");
    while (current != NULL) {
        printf("%d --> ", current->data);
        current = current->next;
    }
    printf("NULL \n");
    return;
}

void count_node(struct NODE** head) {
    int count = 0;
    if (*head == NULL) {
        printf("Danh sach lien ket khong co phan tu nao ton tai\n");
        return;
    }
    struct NODE *current = *head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("danh sach lien ket co %d phan tu\n", count);
    return;
}

void insert_node(struct NODE** head) {
    int index;
    int number;
    struct NODE *current = *head;
    struct NODE *prev = NULL;
    printf("Nhap vi tri chen (index) va gia tri: ");
    scanf("%d %d", &index, &number);
    if (index<0) {
        return;
    }
    struct NODE* new_node = create_node(number);
    int count=1;
    while (current != NULL) {
        if (count == index) {
            if (prev == NULL) {
                new_node->next = *head;
                *head = new_node;
                return;
            }else {
                prev->next = new_node;
                new_node->next = current;
                return;
            }
        }
        count++;
        prev = current;
        current = current->next;
    }
    if (count == index) {
        if (prev != NULL) {
            new_node->next = current;
            prev->next = new_node;
            return;
        }
    }
    return;
}

void delete_node(struct NODE** head) {
    int number_taget;
    scanf("%d",&number_taget);
    printf("Moi nhap vao vi tri muon xoa:");
    struct NODE* current = *head;
    struct NODE* prev = NULL;
    while (current != NULL){
        struct NODE* temp = current->next;
        if (current->data == number_taget) {
            if (prev == NULL) {
                *head = current->next;
            }else {
                prev->next = current->next;
            }
            free(current);
            current = temp;
        }
        prev = current;
        current = current->next;
    }
    return;
}

void swap_nodes(struct NODE** head) {
    int x;
    int y;
    printf("nhap 2 so can doi:");
    scanf("%d %d", &x, &y);
    if (x == y) return;

    struct NODE *prevX = NULL, *currX = *head;
    struct NODE *prevY = NULL, *currY = *head;

    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    if (!currX || !currY) {
        printf("Mot hoac ca hai gia tri khong ton tai.\n");
        return;
    }

    if (prevX != NULL) prevX->next = currY;
    else *head = currY;

    if (prevY != NULL) prevY->next = currX;
    else *head = currX;

    struct NODE* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}

struct NODE* getmiddle(struct NODE** head) {
    struct NODE* fast = *head;
    struct NODE* slow = *head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printf_middle(struct NODE* head) {
    struct NODE* mid = getmiddle(&head);
    printf("gia tri cua phan tu o giua danh sach la:");
    printf("%d",mid->data);
}


int main() {
    struct NODE *head = NULL;
    for (int i = 0; i < 6; i++) {
        printf("Nhap vao gia tri cua phan tu so %d cua danh sach:",i+1);
        int value;
        scanf("%d", &value);
        append_node(&head,value);
    }
    printf_node(&head);
    delete_node(&head);

    return 0;
}
