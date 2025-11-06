#include<bits/stdc++.h>
using namespace std;

// Structure for a node in the linked list
struct node {
    int info;
    struct node *next;
};

// Function to create a new node
node* getnode() {
    node* p;
    p = (node*)malloc(sizeof(struct node));
    return p;
}

// Function to traverse and print the linked list
void traverse(node* start) {
    node* p = start;
    while (p != NULL) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}

// Function to insert a new node at the beginning of the list
void insbeg(node*& start, int x) {
    node* p = getnode();
    p->info = x;
    p->next = start;
    start = p;
}

// Function to insert a new node at the end of the list
void insend(node*& start, int x) {
    node* p = getnode();
    p->info = x;
    p->next = NULL;

    if (start == NULL) {
        start = p;
    } else {
        node* q = start;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

// Function to insert a new node after a specific node 'q'
int insafter(node* q, int x) {
    if (q == NULL) {
        return -1; // Cannot insert after a NULL node
    }
    node* p = getnode();
    p->info = x;
    p->next = q->next;
    q->next = p;
    return 1;
}

// Function to merge two sorted linked lists into a third one
void mergell(node* start1, node* start2, node*& start3) {
    node* p = start1;
    node* q = start2;
    start3 = NULL;

    while (p != NULL && q != NULL) {
        if (p->info < q->info) {
            insbeg(start3, p->info);
            p = p->next;
        } else {
            insbeg(start3, q->info);
            q = q->next;
        }
    }

    // Append remaining nodes of the first list, if any
    while (p != NULL) {
        insbeg(start3, p->info);
        p = p->next;
    }

    // Append remaining nodes of the second list, if any
    while (q != NULL) {
        insbeg(start3, q->info);
        q = q->next;
    }
}

int main() {
    node* start1 = NULL;
    node* start2 = NULL;
    node* start3 = NULL;

    // Populate the first list using insbeg (in reverse order for sorted)
    insbeg(start1, 50);
    insbeg(start1, 30);
    insbeg(start1, 10);
    cout << "List 1: ";
    traverse(start1);

    // Populate the second list using insbeg (in reverse order for sorted)
    insbeg(start2, 60);
    insbeg(start2, 40);
    insbeg(start2, 20);
    cout << "List 2: ";
    traverse(start2);

    // Demonstrate insend
    insend(start1, 70);
    cout << "List 1 after inserting 70 at the end: ";
    traverse(start1);

    // Demonstrate insafter (inserting 35 after the node with value 30)
    // Find the node with value 30
    node* temp = start1;
    while(temp != NULL && temp->info != 30) {
        temp = temp->next;
    }
    if (temp != NULL) {
        insafter(temp, 35);
    }
    cout << "List 1 after inserting 35 after 30: ";
    traverse(start1);

    // Merge the two lists
    mergell(start1, start2, start3);
    cout << "Merged List (Note: built in reverse order): ";
    traverse(start3);

    return 0;
}