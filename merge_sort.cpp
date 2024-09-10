#include <iostream>
using namespace std;

// Size of the array to be sorted
const int n = 10;

// Function to merge two halves of the array
void merge(int a[], int temp[], int left, int right, int right_end) 
{
    int left_end = right - 1; // End of the left subarray
    int temp_pos = left;      // Starting position in temp array
    int num_elements = right_end - left + 1; // Total elements to be merged

    // Merge the two halves into temp array
    while (left <= left_end && right <= right_end) 
	{
        if (a[left] <= a[right]) 
		{
            // If element in left subarray is smaller or equal, copy it to temp
            temp[temp_pos++] = a[left++];
        }
		else 
		{
            // If element in right subarray is smaller, copy it to temp
            temp[temp_pos++] = a[right++];
        }
    }

    // Copy any remaining elements from the left subarray
    while (left <= left_end) 
	{
        temp[temp_pos++] = a[left++];
    }

    // Copy any remaining elements from the right subarray
    while (right <= right_end) 
	{
        temp[temp_pos++] = a[right++];
    }

    // Copy the merged elements back into the original array
    for (int i = 0; i < num_elements; ++i, --right_end)
	{
        a[right_end] = temp[right_end];
    }
}

// Recursive function to perform merge sort
void m_sort(int a[], int temp[], int left, int right) 
{
    if (left < right) 
	{
        int center = (left + right) / 2; // Find the midpoint

        // Recursively sort the left half
        m_sort(a, temp, left, center);
        // Recursively sort the right half
        m_sort(a, temp, center + 1, right);
        // Merge the two halves
        merge(a, temp, left, center + 1, right);
    }
}

// Function to initiate merge sort
void merge_sort(int a[], unsigned int n) 
{
    int* temp = new int[n]; // Allocate temporary array
    if (temp != NULL) 
	{  // Check for successful allocation
        m_sort(a, temp, 0, n - 1); // Call the sorting function
        delete[] temp; // Free the allocated memory
    } 
	else 
	{
        // Handle memory allocation failure
        cerr << "Memory allocation failed" << endl;
    }
}

int main() 
{
    int arr[n] = {12, 34, 9, 8, 45, 67, 78, 3, 1, 6}; // Initialize array

    // Print the original array
    cout << "Original array: ";
    for (int i = 0; i < n; ++i) 
	{
        cout << arr[i] << ",";
    }
    cout << endl << endl;

    // Sort the array using merge sort
    merge_sort(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) 
	{
        cout << arr[i] << ",";
    }
    cout << endl;

    return 0;
}
