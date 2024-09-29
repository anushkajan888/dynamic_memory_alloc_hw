#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(size_t size, size_t alignment) {
    void *ptr = NULL;
    void **aligned_ptr = NULL;
    
    if (alignment && (alignment & (alignment - 1)) == 0) {
        ptr = (void *)malloc(size + alignment + sizeof(void*));
        if (ptr != NULL) {
            aligned_ptr = (void **)(((size_t)ptr + alignment + sizeof(void*)) & ~(alignment - 1));
            aligned_ptr[-1] = ptr;
        }
    }
    
    return aligned_ptr;
}

void aligned_free(void *ptr) {
    free(((void **)ptr)[-1]);
}

int main() {
    size_t alignment = 16;
    size_t size = 64;

    void *ptr = aligned_malloc(size, alignment);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory allocated at address: %p\n", ptr);

    aligned_free(ptr);
    return 0;
}

