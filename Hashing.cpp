#include <iostream>
using namespace std;

void linearInsert(int arr[], int size)
{
    int elem ;
    cout << "Enter the element: ";
    cin >> elem ;
    int index = elem % size ;
    if (arr[index] == -1)
    {
        arr[index] = elem;
        return;
    }
    int in = (index + 1) % size;
    while (in != index)
    {
    if (arr[in] == -1)
    {
        arr[in] = elem;
        return;
    }
    in = (in + 1) % size;
    }
    cout << "No more space" << endl;
}

void quadraticInsert(int arr[], int size)
{
    int elem ;
    cout << "Enter the element: ";
    cin >> elem ;
    int index = elem % size ;
    int i = 1;
    if (arr[index] == -1)
    {
        arr[index] = elem;
        return;
    }
    int in = (index + (i*i)) % size;
    while (in != index)
    {
        int temp = in;
        if (arr[in] == -1)
        {
            arr[in] = elem;
            return;
        }
        else
        {
            i++ ;
            in = (in + (i*i)) % size;
        }
    }
}

void linearSearch(int arr[], int size)
{
    int key;
    cout << "Enter element you want to search: ";
    cin >> key;
    if (arr[0] == key)
    {
        cout << "Element found at Index 0 "<< endl;
        return;
    }
    else
    {
        int ind = key % size;
        if (arr[ind] == key)
        {
            cout << "Element found at Index " << ind << endl;
            return;
        }
        int i = (ind + 1) % size;
        while ( i != ind)
        {
            if (arr[i] == key)
            {
                cout << "Element found at Index " << i << endl;
                return;
            }
            i = (ind + 1) % size;
        }
    }
}

void print (int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "" << endl;
}

int main() 
{
    int size;
    cout << "Enter the size of Array: ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = -1;
    }
    print(arr, size);
    int select = 1;
    // cout << "Do you want to insert the element? " << endl;
    while (select != 0)
    {
        if (select == 1)
        {
            linearInsert(arr, size);
        }
        if (select == 2)
        {
            linearSearch(arr, size);
        }
        if (select == 3)
        {
            quadraticInsert(arr, size);
        }
    print(arr, size);
    cout << "Press 1 to Linear Insert, 2 to Linear Search, 3 to Quadratic Insert ";
    cin >> select;
    }
}
