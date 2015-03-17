#pragma once

#define SORTED_VECTOR_INITIAL_CAPACITY 1

typedef unsigned int sortedVectorType;

typedef struct {
	sortedVectorType *elements;
	unsigned int size, capacity;
} sortedVector;

void sortedVectorCreate(sortedVector *vector);
void sortedVectorFree(sortedVector *vector);
void sortedVectorAddUnique(sortedVector *vector, sortedVectorType element);
void sortedVectorRemove(sortedVector *vector, sortedVectorType element);
unsigned int sortedVectorIndex(sortedVector *vector, sortedVectorType element);