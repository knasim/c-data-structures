/**
 * @brief Dynamic array structure and methods
 * @file vector.h
 */

typedef struct Vector
{
    unsigned short size;
    int* array;
} Vector;

/**
 * @brief Initializes the array in heap memory
 *
 * @param size The initial size of the array
 *
 * @return Vector
 */
Vector create(const unsigned short size);
