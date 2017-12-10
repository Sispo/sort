# Sorting algorithms sample code on c++

- length - lenght of an array
- c - number of iterations
- m - number of swaps

1. Insertion sort
```c++
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
```
2. Bubble sort
```c++
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
```
3. Selection sort
```c++
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
```
4. Coctail sort
```c++
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
```
5. Quick sort
```c++
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
```
