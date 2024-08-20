#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void display(int arr[], int size);
void insertAtBeginning(int arr[], int *size, int element);
void insertAtEnd(int arr[], int *size, int element);
void insertAtLocation(int arr[], int *size, int element, int location);
void deleteFromBeginning(int arr[], int *size);
void deleteFromEnd(int arr[], int *size);
void deleteFromLocation(int arr[], int *size, int location);
void bubbleSort(int arr[], int size);
int linearSearch(int arr[], int size, int key);
void mergeArrays(int arr1[], int *size1, int arr2[], int size2);

int main(int argc, char *argv[]) {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, location, key;
    int arr2[MAX_SIZE];
    int size2 = 0;

    if (argc > 1) {
        printf("Command-line arguments are provided. Ignoring user input.\n");
        for (int i = 1; i < argc; i++) {
            arr[size++] = atoi(argv[i]);
        }
    } else {
        printf("No command-line arguments provided. You can input the array elements manually.\n");
        printf("\nEnter the size of array");
        scanf("%d",&size);
        printf("\nEnter the elements of array : ");
        for(int i=0;i<size;i++){
            scanf("%d",&arr[i]);
        }
    }

    do {
        printf("\nMenu:\n");
        printf("1. Display Array\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Location\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Location\n");
        printf("8. Bubble Sort\n");
        printf("9. Linear Search\n");
        printf("10. Merge Another Array\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array elements: ");
                display(arr, size);
                break;
            case 2:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &element);
                insertAtBeginning(arr, &size, element);
                display(arr,size);
                break;
            case 3:
                printf("Enter element to insert at end: ");
                scanf("%d", &element);
                insertAtEnd(arr, &size, element);
                display(arr,size);
                break;
            case 4:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter location to insert: ");
                scanf("%d", &location);
                insertAtLocation(arr, &size, element, location);
                display(arr,size);
                break;
            case 5:
                deleteFromBeginning(arr, &size);
                display(arr,size);
                break;
            case 6:
                deleteFromEnd(arr, &size);
                display(arr,size);
                break;
            case 7:
                printf("Enter location to delete: ");
                scanf("%d", &location);
                deleteFromLocation(arr, &size, location);
                display(arr,size);
                break;
            case 8:
                bubbleSort(arr, size);
                printf("Array sorted successfully.\n");
                display(arr,size);
                break;
            case 9:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int index = linearSearch(arr, size, key);
                if (index != -1) {
                    printf("Element found at index %d.\n", index);
                } else {
                    printf("Element not found.\n");
                }
                break;
            case 10:
                printf("Enter size of the second array: ");
                scanf("%d", &size2);
                printf("Enter elements of the second array:\n");
                for (int i = 0; i < size2; i++) {
                    scanf("%d", &arr2[i]);
                }
                mergeArrays(arr, &size, arr2, size2);
                display(arr,size);
                break;
            case 11:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 11.\n");
        }
    } while (choice != 11);

    return 0;
}

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtBeginning(int arr[], int *size, int element) {
    for (int i = *size - 1; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = element;
    (*size)++;
}

void insertAtEnd(int arr[], int *size, int element) {
    arr[*size] = element;
    (*size)++;
}

void insertAtLocation(int arr[], int *size, int element, int location) {
    if (location < 0 || location > *size) {
        printf("Invalid location.\n");
        return;
    }
    for (int i = *size - 1; i >= location; i--) {
        arr[i + 1] = arr[i];
    }
    arr[location] = element;
    (*size)++;
}

void deleteFromBeginning(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete from beginning.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteFromEnd(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete from end.\n");
        return;
    }
    (*size)--;
}

void deleteFromLocation(int arr[], int *size, int location) {
    if (*size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (location < 0 || location >= *size) {
        printf("Invalid location.\n");
        return;
    }
    for (int i = location; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void mergeArrays(int arr1[], int *size1, int arr2[], int size2) {
    for (int i = 0; i < size2; i++) {
        arr1[*size1 + i] = arr2[i];
    }
    *size1 += size2;
}