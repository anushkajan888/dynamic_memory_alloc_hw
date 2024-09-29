#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_realloc(void *ptr, size_t current_size, size_t new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(new_size);
    }

    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }

    size_t copy_size = current_size < new_size ? current_size : new_size;
    memcpy(new_ptr, ptr, copy_size);
    
    free(ptr);
    return new_ptr;
}

int main() {
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Initial array of 5 integers: ");
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr = (int *)my_realloc(arr, 5 * sizeof(int), 8 * sizeof(int));
    if (arr == NULL) {
        printf("Reallocation failed\n");
        return 1;
    }

    printf("Array after reallocation to 8 integers: ");
    for (int i = 0; i < 8; i++) {
        if (i >= 5) arr[i] = i + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

