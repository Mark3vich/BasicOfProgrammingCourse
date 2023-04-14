#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h> 

typedef struct vector { 
    int *data; 
    size_t size; 
    size_t capacity;
} vector;

vector createVector(size_t n) {     
    if(n < __SIZE_MAX__) { 
        vector *v;
        v->data = (size_t *)malloc(n * sizeof(size_t));
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
        v->data = (size_t *) realloc(v->data, sizeof(size_t) * newCapacity);
        v->size = newCapacity;
        v->capacity = newCapacity;
    } else if (newCapacity == 0) { 
        v->data = NULL;
        v->size = 0; 
        v->capacity = 0;
    } else { 
        v->data = (size_t *) realloc(v->data, sizeof(size_t) * newCapacity);
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

bool isEmpty(vector *v) { 
    return v->size == 0 ? true : false;
}

bool isFull(vector *v) { 
    return v->size == v->capacity ? true : false;
}

int getVectorValue(vector *v, size_t i) { 
    return v->data[i];
}

void pushBack(vector *v, size_t x) { 
    if(v->capacity == v->size) { 
        reserve(v, v->capacity * 2); 
    }
    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) { 
    if(v->size == 0) { 
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->size--;
}

int* atVector(vector *v, size_t index) { 
    if(index <= v->size && index >= 0) { 
        return &v->data[index];
    } else {
        printf("IndexError: vector[%d] is not exists", index);
        exit(1);
    }
}

int* back(vector *v) { 
    return &v->data[v->size];
}

int* front(vector *v) { 
    return &v->data[0];
}