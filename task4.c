#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n = 3;
    char **arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (char *)malloc(50 * sizeof(char));
    }

    printf("Enter 3 strings: ");
    for (int i = 0; i < 3; i++) {
        scanf("%s", arr[i]);
    }

    arr = (char **)realloc(arr, 5 * sizeof(char *));
    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }

    for (int i = 3; i < 5; i++) {
        arr[i] = (char *)malloc(50 * sizeof(char));
    }

    printf("Enter 2 more strings: ");
    for (int i = 3; i < 5; i++) {
        scanf("%s", arr[i]);
    }

    printf("All strings: ");
    for (int i = 0; i < 5; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < 5; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

