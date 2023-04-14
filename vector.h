#include <stdio.h> 
#include <stdlib.h>

typedef struct vector { 
    int *data; 
    size_t size; 
    size_t capacity;
} vector;

vector createVector(size_t n) {     
    if(n < __SIZE_MAX__) { 
        vector *v;
        v->data = (size_t * )malloc(n * sizeof(size_t));
        v->size = 0;
        v->capacity = n;
        return *v; 
    } else {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
}

void reserve(vector *v, size_t newCapacity) { 
    if(newCapacity >= __SIZE_MAX__) { 
        fprintf(stderr, "bad alloc");
        exit(1);
    } else if (newCapacity < v->size)  {
        v->data = (size_t *) realloc(v, newCapacity);
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else if (newCapacity == 0) { 
        v->data = NULL;
        v->size = 0; 
        v->capacity = 0;
    } else { 
        v->data = (size_t *) realloc(v, newCapacity);
        v->capacity = newCapacity;
    }
}

void clear(vector *v) { 
    v->size = 0; 
}

void shrinkToFit(vector *v) { 
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v);
}