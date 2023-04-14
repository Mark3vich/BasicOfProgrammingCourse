#include "vector.h"

void outputVector(vector v) { 
    for(size_t i = 0; i < v.size; i++) { 
        printf("%d ", v.data[i]);
    }
}

void test_pushBack_emptyVector(vector *v) { 
    pushBack(v, 1);
    pushBack(v, 2);
    pushBack(v, 3);
    pushBack(v, 4);
    pushBack(v, 5);
}   

void test_pushBack_fullVector(vector *v) { 
    pushBack(v, 6);
    pushBack(v, 7);
    pushBack(v, 8);
    pushBack(v, 9);
    pushBack(v, 10);
}

void test_popBack_notEmptyVector(vector *v) { 
    for(size_t i = 0; i < 5; i++) { 
        popBack(v);
    }
}

void test(vector *v) { 
    test_pushBack_emptyVector(v);
    test_pushBack_fullVector(v);
    test_popBack_notEmptyVector(v);
}

int main() { 
    vector v = createVector(2);

    test(&v);

    outputVector(v);

    deleteVector(&v);

    return 0; 
}