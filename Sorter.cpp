#include <iostream>

class Sorter {

public:
    // Member function to sort the array
    void sort(int* arr, int size, bool ascending = true) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (ascending) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                } else {
                    if (arr[j] < arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    }
    
    // Function to display the array
    void display(const int* arr, int size) const {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    // Helper function to swap two elements
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    Sorter sorter;

    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[3]);

    std::cout << "Original array: ";
    sorter.display(arr, size);

    // Sort in ascending order (default)
    sorter.sort(arr, size);
    std::cout << "Sorted array (ascending): ";
    sorter.display(arr, size);

    // Sort in descending order
    sorter.sort(arr, size, false);
    std::cout << "Sorted array (descending): ";
    sorter.display(arr, size);

    return 0;
}

