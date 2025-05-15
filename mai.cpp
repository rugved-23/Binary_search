#include <iostream>
#include <vector>
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid potential overflow
        // Check if target is present at mid
        if (arr[mid] == target)
            return mid;
        // If target is greater, ignore left half
        if (arr[mid] < target)
            left = mid + 1;
        // If target is smaller, ignore right half
        else
            right = mid - 1;
    }
    // Element not present in array
    return -1;
}
int main() {
    // Example usage
    std::vector<int> sortedArray = {2, 3, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    int result = binarySearch(sortedArray, target);
    if (result != -1)
        std::cout << "Element " << target << " found at index " << result << std::endl;
    else
        std::cout << "Element " << target << " not found in the array" << std::endl;
    return 0;
}
