#pragma once
#define CAPACITY 10

typedef void* TElement;
typedef void (*DestroyElementFunctionType)(void*);

typedef struct
{
	TElement* elems;
	int length;			// actual length of the array
	int capacity;		// maximum capacity of the array
	DestroyElementFunctionType destroyElemFct; // function pointer to the function responsible with deallocating the elements stored in the array
} DynamicArray;

/// <summary>
/// Creates a dynamic array of generic elements, with a given capacity.
/// </summary>
/// <param name="capacity">Integer, maximum capacity for the dynamic array.</param>
/// <param name="destroyElemFct">Function pointer, of type DestroyElementFunctionType. The function that deals with deallocating the elements of the array.</param>
/// <returns>A pointer the the created dynamic array.</returns>
DynamicArray* createDynamicArray_v(int capacity, DestroyElementFunctionType destroyElemFct);

/// <summary>
/// Destroys the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array to be destoyed.</param>
/// <returns>A pointer the the created dynamic array.</returns>
void destroy_v(DynamicArray* arr);

/// <summary>
/// Adds a generic to the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="p">The planet to be added.</param>
void add_v(DynamicArray* arr, TElement t);

void add_sepcial_v(DynamicArray* arr, TElement t, int poz);

/// <summary>
/// Deletes an element from a given position in the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="pos">The position from which the element must be deleted. The position must be valid.</param>
void delete_v(DynamicArray* arr, int pos);

/// <summary>
/// Returns the length of the dynamic array.
/// </summary>
/// <param name="arr">The dynamic array.</param>
int getLength_v(DynamicArray* arr);

/// <summary>
/// Returns the element on a given position.
/// </summary>
/// <param name="arr">The dynamic array.</param>
/// <param name="pos">The position - must be a valid position.</param>
/// <returns>The element on the given position.</returns>
TElement get_v(DynamicArray* arr, int pos);

void delete_2(DynamicArray* arr, int pos);