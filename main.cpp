//
//  main.cpp
//  sort
//
//  Created by Tymofii Dolenko on 12/10/17.
//  Copyright © 2017 Tymofii Dolenko. All rights reserved.
//

#include <iostream>
using namespace std;
class ArraySort {
private:
    int*array;
    int length;
public:
    ArraySort() {
        char s;
        cout << "Do you want to use sample data?" << endl;
        cin >> s;
        
        if (s == 'y') {
            length = 32;
            array = new int[length];
            
            for (int i = 0; i < length; i++) {
                array[i] = (rand() % 100) + 1;
                cout << array[i] << " ";
            }
            cout << endl << endl;
        }
        else {
            cout << "Enter length" << endl;
            cin >> length;
            
            array = new int[length];
            
            for (int i = 0; i < length; i++) {
                cin >> array[i];
            }
        }
    }
    ArraySort(const ArraySort&copy) {
        length = copy.length;
        array = new int[length];
        for (int i = 0; i < length; i++) {
            array[i] = copy.array[i];
        }
    }
    ~ArraySort() {
        cout << "Destructor called" << endl;
    }
    
    int getLength() { return length; }
    
    void insertionSort(int&c, int&m) {
        
        for (int i = 1; i < length; i++)
        {
            c++;
            int value = array[i];
            int index = i;
            while ((index > 0) && (array[index - 1] > value))
            {
                m++;
                array[index] = array[index - 1];
                index--;
            }
            array[index] = value;
        }
    }
    
    void bubbleSort(int &c, int&m) {
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = (length - 1); j > i; j--)
            {
                c++;
                if (array[j - 1] > array[j])
                {
                    m++;
                    int temp = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
    
    void selectionSort(int &c, int &m) {
        int min, temp;
        for (int i = 0; i < length - 1; i++)
        {
            min = i;
            
            for (int j = i + 1; j < length; j++)
            {
                c++;
                if (array[j] < array[min])
                    min = j;
            }
            m++;
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
    
    void coctailSort(int &c, int &m) {
        int left = 0, right = length - 1;
        int flag = 1;
        
        while ((left < right) && flag > 0)
        {
            flag = 0;
            for (int i = left; i < right; i++)
            {
                c++;
                if (array[i] > array[i + 1])
                {
                    m++;
                    double t = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = t;
                    flag = 1;
                }
            }
            right--;
            for (int i = right; i > left; i--)
            {
                c++;
                if (array[i - 1] > array[i])
                {
                    m++;
                    double t = array[i];
                    array[i] = array[i - 1];
                    array[i - 1] = t;
                    flag = 1;
                }
                left++;
            }
        }
    }
    
    void quickSort(int &c, int &m, int l, int r) {
        int i = l, j = r, x, w, k;
        x = array[(l + r) / 2];
        do
        {
            while (array[i]<x) {
                c++;
                i++;
            };
            while (x<array[j]) {
                c++;
                j--;
            };
            if (i <= j)
            {
                m++;
                w = array[i];
                array[i] = array[j];
                array[j] = w;
                i++; j--;
            }
        } while (i <= j);
        
        if (l<j) quickSort(c, m, l, j);
        if (i<r) quickSort(c, m, l, j);
        
    }
};

int main() {
    
    ArraySort obj = ArraySort();
    int c = 0, m = 0;
    ArraySort insObj = ArraySort(obj);
    insObj.insertionSort(c, m);
    cout << "Insertion sort score:" << endl;
    cout << "C:" << c << " M:" << m << endl;
    cout << endl;
    c = 0, m = 0;
    ArraySort bubbleObj = ArraySort(obj);
    bubbleObj.bubbleSort(c, m);
    cout << "Bubble sort score:" << endl;
    cout << "C:" << c << " M:" << m << endl;
    cout << endl;
    c = 0, m = 0;
    ArraySort selectionObj = ArraySort(obj);
    selectionObj.selectionSort(c, m);
    cout << "Selection sort score:" << endl;
    cout << "C:" << c << " M:" << m << endl;
    cout << endl;
    c = 0, m = 0;
    ArraySort coctailObj = ArraySort(obj);
    coctailObj.coctailSort(c, m);
    cout << "Coctail sort score:" << endl;
    cout << "C:" << c << " M:" << m << endl;
    cout << endl;
    c = 0, m = 0;
    ArraySort quickObj = ArraySort(obj);
    quickObj.quickSort(c, m,0,quickObj.getLength());
    cout << "Quick sort score:" << endl;
    cout << "C:" << c << " M:" << m << endl;
    
    return 0;
}

