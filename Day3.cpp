#include <iostream>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    Student* next;
};


void insertAtPosition(Student*& head, int position, int rollNumber, string name) {
    Student* newStudent = new Student{rollNumber, name, nullptr};

    if (position == 1) {
        newStudent->next = head;
        head = newStudent;
        return;
    }

    Student* current = head;
    for (int i = 1; current != nullptr && i < position - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds." << endl;
        delete newStudent;
        return;
    }

    newStudent->next = current->next;
    current->next = newStudent;
}


void deleteByRollNumber(Student*& head, int rollNumber) {
    Student* current = head;
    Student* prev = nullptr;

    if (current != nullptr && current->rollNumber == rollNumber) {
        head = current->next;
        delete current;
        return;
    }

    while (current != nullptr && current->rollNumber != rollNumber) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Roll number not found." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}

void reverseList(Student*& head) {
    Student* prev = nullptr;
    Student* current = head;
    Student* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// Function to print the list
void printList(Student* head) {
    Student* current = head;
    while (current != nullptr) {
        cout << "Roll Number: " << current->rollNumber << ", Name: " << current->name << endl;
        current = current->next;
    }
}



int main() {
    Student* head = nullptr;

    insertAtPosition(head, 1, 20, "Amulya");
    insertAtPosition(head, 2, 22, "Avinash");

    cout << "Original List:" << endl;
    printList(head);
    cout<<endl;
    
    cout<<"Enter data to insert : "<<endl;
    int a,b;
    cin >> a >> b;
    string n;
    cin >> n;
    
    cout<<endl;
    cout << "After inserting a new node at specified position : "<<endl;
    insertAtPosition(head,a,b,n);
    printList(head);
    
    cout<<endl;
    cout << "After deletion of roll number 22:" << endl;
    deleteByRollNumber(head, 22);
    printList(head);

    cout<<endl;
    cout << "After reversing the list:" << endl;
    reverseList(head);
    printList(head);
    return 0;
}
