// MatrixMalloc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int count = 1;

void initMatrix(int** arr, int size)
{
    
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            arr[i][j] = rand() % 10 + 0;
}

void printMatrix(int** arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            std::cout << arr[i][j] << " ";
        std::cout << std::endl;
    }
}

void* operator new[](std::size_t size)
{

    void* ptr = (int*)malloc(size);

    if (ptr == NULL)
    {
        throw (std::bad_alloc());
    }
    std::cout << "The " << count << " row of the matrix was created" << std::endl;
    count++;

    return ptr;
}

void operator delete[](void* ptr)
{
    std::free(ptr);

    std::cout << "The " << count << " row of the matrix was deleted" << std::endl;
    count++;

}

int sumMatrix(int** arr, int size)
{
    int sum = 0;
    for (int i = 1; i < size; i++)
        for (int j = 0; j < i; j++)
            sum = sum + arr[i][j];

    return sum;
}

int main()
{
    int size;

    std::cout << "Please enter size of the matrix:  ";
    std::cin >> size;
    int** arr = new int*[size];
    for (int i = 0; i < size; i++)
        arr[i] = new int[size];

    initMatrix(arr, size);
    count = 1;
    printMatrix(arr, size);

    int sum = sumMatrix(arr, size);
    std::cout << "The sum is:  " << sum << std::endl;

    for (int i = 0; i < size; i++)
    {
        delete[] arr[i];
        arr[i] = nullptr;
    }
    ::delete[] arr;
    arr = nullptr;

}
