#include <stdlib.h>
#include <string.h>

#include "sortedVector.h"

void sortedVectorCreate(sortedVector *vector)
{
	vector->size = 0;
	vector->capacity = SORTED_VECTOR_INITIAL_CAPACITY;
	vector->elements = malloc(sizeof(sortedVectorType)*vector->capacity);
}

void sortedVectorFree(sortedVector *vector)
{
	free(vector->elements);
}

void sortedVectorAddUnique(sortedVector *vector, sortedVectorType element)
{
	unsigned int index = sortedVectorIndex(vector, element);

	if(vector->elements[index - 1] == element) return;
	
	vector->size++;
	if(vector->size == vector->capacity) {
		vector->capacity <<= 1;
		vector->elements = realloc(vector->elements, sizeof(sortedVectorType)*vector->capacity);
	}

	if(index != vector->size - 1) {
		memmove(&vector->elements[index + 1], &vector->elements[index], (vector->size - index - 1) * sizeof(sortedVectorType));
	}

	vector->elements[index] = element;
}

void sortedVectorRemove(sortedVector *vector, sortedVectorType element)
{
	unsigned int index = sortedVectorIndex(vector, element) - 1;

	if(vector->elements[index] == element) {
		memmove(&vector->elements[index], &vector->elements[index + 1], (vector->size - index - 1) * sizeof(sortedVectorType));
		vector->size--;
	}
}

unsigned int sortedVectorIndex(sortedVector *vector, sortedVectorType element)
{
	int first, last, middle;

	if(vector->size == 0) return 0;

	first = 0;
	last = vector->size - 1;
	middle = last >> 1;

	while(first <= last) {
		if(vector->elements[middle] < element) {
			first = middle + 1;
		}
		else if(vector->elements[middle] == element) {
			break;
		}
		else {
			last = middle - 1;
		}

		middle = (first + last) >> 1;
	}

	return middle + 1;
}