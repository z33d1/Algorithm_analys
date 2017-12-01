#include "sorts.h"
#include <iostream>
#include <stdio.h>

template <typename T>
void RandFiller<T>::fill(vector<T> &arr, T cnt)
{
    int Cnt = int(cnt);

    if (arr.empty() || (arr.size() != Cnt))
    {
        arr.resize(Cnt, 0);
    }

    for (int i = 0; i < Cnt; i++)
    {
        arr[i] = rand();
    }
}

template <typename T>
void UpFiller<T>::fill(vector<T> &arr, T cnt)
{
    T st = 0;
    int d = 1;
    if (cnt < 0)
    {
        cnt *= -1;
        st = cnt;
        d = -1;
    }
    int Cnt = int(cnt);

    if (arr.empty() || (arr.size() != Cnt))
    {
        arr.resize(Cnt, 0);
    }

    for (int i = 0; i < Cnt; i++)
    {
        arr[i] = st+i*d;
    }
}

template <typename T>
BaseSorter<T>::BaseSorter(Filler<T> *in)
{
    fl = in;
}


template <typename T>
long double GnomeSorter<T>::sort(vector<T> &arr)
{
    int i = 0;
    long double start = clock();

    while (i < arr.size())
    {
        if (i == 0 || arr[i - 1] <= arr[i])
        {
            ++i;
        }
        else
        {
            std::swap(arr[i - 1], arr[i]);
            --i;
        }
    }

    return clock() - start;
}

template <typename T>
long double BubbleSorter<T>::sort(vector<T> &arr)
{
    long double start = clock();

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
            }
        }
    }

    return clock() - start;
}

template <typename T>
long double ShakerSorter<T>::sort(vector<T> &arr)
{
    long double start = clock();

    int left = 0;
    int right = arr.size() - 1;
    int flag = 1;
    while ((left < right) && flag)
    {
        flag = 0;
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i+1])
            {
              std::swap(arr[i], arr[i+1]);
              flag = 1;
            }
        }

        right--;

        for (int i = right; i > left; i--)
        {
            if (arr[i-1] > arr[i])
            {
                std::swap(arr[i], arr[i-1]);
                flag = 1;
            }
        }

        left++;
    }

    return clock() - start;
}
