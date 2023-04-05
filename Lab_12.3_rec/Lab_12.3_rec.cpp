#include <iostream>

using namespace std;

typedef int Info;

struct Elem
{

    Elem* prev,
        * next;
    Info info;
};

Elem* first = NULL;
Elem* last = NULL;

void Print(Elem* first);

void enqueue_recursive(Elem*& first, Elem*& last, Info value, Elem* prev = NULL)
{
    if (last == NULL)
    {
        last = new Elem;
        last->prev = prev;
        last->next = NULL;
        last->info = value;
        if (first == NULL)
        {
            first = last;
        }
    }
    else
    {
        enqueue_recursive(first, last->next, value, last);
    }
}

int odd_numbers(Elem* first);
Info dequeue(Elem*& first, Elem*& last);
void Print(Elem* first);

int main()
{
    int amount;
    cout << "\n Enter the number of the list elements: "; cin >> amount;

    int num;
    for (int i = 0; i < amount; i++)
    {
        cout << "Enter the number to include to list: ";
        cin >> num;
        enqueue_recursive(first, last, num, NULL);
    }
    cout << "\n List: ";
    Print(first);
    int rezult = odd_numbers(first);
    cout << "\n The list contains " << rezult << " odd numbers.\n";
    dequeue(first, last);

}


int odd_numbers(Elem* current)
{
    if (current == NULL) {
        return 0;
    }
    else {
        int count = odd_numbers(current->next);
        if (current->info % 2 != 0) {
            count++;
        }
        return count;
    }
}

Info dequeue(Elem*& first, Elem*& last)
{
    if (first == NULL) {
        throw "Queue is empty";
    }

    Info value = first->info;

    Elem* tmp = first;

    if (first == last) {
        first = NULL;
        last = NULL;
    }
    else {
        first = first->next;
        first->prev = NULL;
    }

    delete tmp;

    if (first != NULL) {
        dequeue(first, last);
    }

    return value;
}
void Print(Elem* first)
{
    if (first == NULL) {
        cout << endl;
        return;
    }
    cout << first->info << " ";
    Print(first->next); 
}

