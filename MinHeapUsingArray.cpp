#include <iostream>

using namespace std;

int h[50];
int size = -1;

// it will return the index of provided child node
int parent(int i)
{
    return (i - 1) / 2;
}

int rightChild(int i)
{
    return ((2 * i) + 2);
}

int leftChild(int i)
{
    return ((2 * i) + 1);
}

void shiftDown(int x)
{
    int maxIndex = x;

    // left child
    int l = leftChild(x);

    if (l <= size && h[l] < h[maxIndex])
    {
        maxIndex = l;
    }

    // right Child
    int r = rightChild(x);

    if (r <= size && h[r] < h[maxIndex])
    {
        maxIndex = r;
    }

    if (x != maxIndex)
    {
        swap(h[x], h[maxIndex]);
        shiftDown(maxIndex);
    }
}

int dequeue()
{
    if (size == -1)
    {
        return 0;
    }
    else
    {
        int result = h[0];
        h[0] = h[size];
        size--;
        shiftDown(0);
        return result;
    }
}

// shiftUp to maintain heap property when enqueue the element
void shiftUp(int x)
{
    while (x > 0 && h[parent(x)] > h[x])
    {
        swap(h[parent(x)], h[x]);

        x = parent(x);
    }
}

void enqueue(int x)
{
    size++;
    h[size] = x;
    shiftUp(size);
}

void display()
{
    int p = 0;
    while (p != size+1)
    {
        cout << h[p] << endl;
        p++;
    }
}

int main()
{
    enqueue(12);
    enqueue(24);
    enqueue(34);
    enqueue(23);
    enqueue(123);
    enqueue(34);
    enqueue(342);
    enqueue(243);
    enqueue(1);
    enqueue(2);
    enqueue(4);
    enqueue(63);
    cout << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl
         << endl;
    display();
}