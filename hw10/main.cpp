//
//  main.cpp
//  hw10
//
//  Created by Valeria Dudinova on 30.10.2024.
//

#include <iostream>
using namespace std;

// Шаблонний клас для вузла двобічного списку
template <typename T>
class Node
{
public:
    T data;
    Node* next;
    Node* prev;
    
    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
};

// Шаблонний клас "Черга" на основі двобічного списку
template <typename T>
class Queue
{
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    // Метод для додавання елемента в кінець черги
    void enqueue(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    // Метод для видалення елемента з початку черги
    void dequeue()
    {
        if (!head)
        {
            cout << "The queue is empty" << endl;
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        
        if (head)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }

        delete temp;
        size--;
    }

    // Метод для отримання першого елемента черги
    T front() const
    {
        if (!head)
        {
            throw runtime_error("The queue is empty");
        }
        return head->data;
    }

    // Метод для перевірки, чи черга порожня
    bool isEmpty() const
    {
        return size == 0;
    }

    // Метод для отримання розміру черги
    size_t getSize() const
    {
        return size;
    }

    ~Queue()
    {
        while (head)
        {
            dequeue();
        }
    }
};

int main()
{
    Queue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "The first element: " << q.front() << endl;

    q.dequeue();
    cout << "The first item after deletion: " << q.front() << endl;

    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}
