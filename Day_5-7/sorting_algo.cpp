#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j + 1], arr[j]);
        }
    }
}
void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (curr <= arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

void selection_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp;
    int l = start, r = mid + 1;
    while (l <= mid && r <= end)
    {
        if (arr[l] < arr[r])
            temp.push_back(arr[l++]);
        else
            temp.push_back(arr[r++]);
    }
    while (l <= mid)
        temp.push_back(arr[l++]);
    while (r <= end)
        temp.push_back(arr[r++]);

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}

void merge_sort(vector<int> &arr, int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    merge_sort(arr, mid + 1, end);
    merge_sort(arr, start, mid);
    merge(arr, start, mid, end);
}

int partition(vector<int> &arr, int start, int end)
{
    int l = start;
    int r = end;
    int pivot = arr[start];
    int p = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] < pivot)
            p++;
    }
    swap(arr[p], arr[start]);
    while (l < r)
    {
        if (arr[l] > pivot && arr[r] < pivot)
        {
            swap(arr[l++], arr[r--]);
        }
        else if (arr[l] > pivot)
            r--;
        else
        {
            l++;
        }
    }

    return p;
}

void quick_sort(vector<int> &arr, int start, int end)
{
    // basic Idea, find a patition Index and the sort partition+1 to end / start to partition.
    if (start >= end)
        return;
    int partitionIndex = partition(arr, start, end);
    quick_sort(arr, partitionIndex + 1, end);
    quick_sort(arr, start, partitionIndex - 1);
}

// 4 1 6 3 2 6 9    -> 4 1 6 3 2 6 9 -> 4 1 3 6 2 6 9 -> 4 1 3 2 6 6 9

void merge_sort_ite(vector<int> &arr, int start, int end)
{
}

void print_vector(vector<int> &v)
{
    for (auto &a : v)
    {
        cout << a << " ";
    }
    cout << '\n';
}

int main()
{
    // Implement all sorting algorithms.
    // 1. Bubble sort , Counting Sort , Selection sort, Inserting Sort , Merge Sort and Quick Sort.

    vector<int> v = {4, 5, 32, 6, 2, 52, 8, 4, 9, 4, 3};
    quick_sort(v, 0, v.size() - 1);
    print_vector(v);
}