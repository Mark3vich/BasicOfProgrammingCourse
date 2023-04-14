#include "vector.h"

void outputVector(vector v) { 
    for(size_t i = 0; i < v.size; i++) { 
        printf("%d ", v.data[i]);
    }
}

void test_pushBack_emptyVector(vector *v) { 
    for(size_t i = 1; i < 6; i++) { 
        pushBack(v, i);
    }
}   

void test_pushBack_fullVector(vector *v) { 
    for(size_t i = 6; i < 11; i++) { 
        pushBack(v, i);
    }
}

void test_popBack_notEmptyVector(vector *v) { 
    for(size_t i = 0; i < 5; i++) { 
        popBack(v);
    }
}

void test_atVector_notEmptyVector(vector *v) { 
    printf("%d ", atVector(v, 6));   
}

void test_atVector_requestToLastElement(vector *v) { 
    printf("%d ", atVector(v, 5));
}

void test_back_oneElementInVector(vector *v) { 
    printf("%d ", back(v));
}

void test_front_oneElementInVector(vector *v) { 
    printf("%d ", front(v));
}

void test(vector *v) { 
    test_pushBack_emptyVector(v);
    test_pushBack_fullVector(v);
    test_popBack_notEmptyVector(v);
    test_atVector_requestToLastElement(v);
    test_back_oneElementInVector(v);
    test_front_oneElementInVector(v);
    test_atVector_notEmptyVector(v);
}

int main() { 
    vector v = createVector(2);

    test(&v);

    outputVector(v);

    deleteVector(&v);

    return 0; 
}