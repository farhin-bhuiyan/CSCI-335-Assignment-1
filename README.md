# Points2D Class Implementation

## Overview
This project involves the creation of a `Points2D` class to represent a sequence of 2D points, where each point is an array of two elements of type `Object` (can be `int`, `double`, etc.). The class supports basic operations such as copying, moving, adding sequences, and reading/writing from/to streams.

## Implementation Details

### The "Big Five"
The `Points2D` class includes implementations for the "big five" functions:
1. **Default Constructor**: Initializes an empty sequence.
2. **Copy Constructor**: Creates a deep copy of another `Points2D` object.
3. **Copy Assignment Operator**: Uses the copy-and-swap idiom for exception safety and self-assignment protection.
4. **Move Constructor**: Transfers ownership of the sequence from another `Points2D` object.
5. **Move Assignment Operator**: Uses `std::swap` to transfer ownership of the sequence.
6. **Destructor**: Releases dynamically allocated memory.

### Other Member Functions
- **One Parameter Constructor**: Initializes the sequence with a single point.
- **size() Method**: Returns the size of the sequence.
- **Overloaded `[]` Operator**: Provides access to points in the sequence with bounds checking.
- **Overloaded `+` Operator**: Combines two `Points2D` sequences.
- **Overloaded `<<` Operator**: Outputs the sequence of points to an output stream.
- **Overloaded `>>` Operator**: Reads a sequence of points from an input stream.

## Approach
1. **Understanding Requirements**: Carefully read the problem statement to understand the requirements and constraints.
2. **Class Design**: Design the `Points2D` class with appropriate private data members and public member functions.
3. **Implement the "Big Five"**: Implement the default constructor, copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor.
4. **Operator Overloading**: Overload the `[]`, `+`, `<<`, and `>>` operators to provide the necessary functionality.
5. **Testing**: Test the class thoroughly using the provided `test_points2d.cc` file to ensure all functions work correctly.

## Difficulties Encountered
- **Pointer Management**: Handling dynamic memory allocation and ensuring proper memory management using the destructor and the "big five" functions was a bit challenging. Ensuring no memory leaks or dangling pointers was crucial.
- **Operator Overloading**: Implementing the `+` operator to correctly combine sequences of different sizes required careful handling of array indices and memory allocation.
- **Stream Operators**: Writing and reading sequences from streams required understanding the format of input and output and ensuring the data was correctly processed.

## Simple Parts
- **Default Constructor**: Implementing the default constructor was straightforward as it simply initializes the sequence to be empty.
- **size() Method**: Implementing the size method was simple since it just returns the size of the sequence.

## Testing
The project includes a `test_points2d.cc` file that tests various functionalities of the `Points2D` class:
1. Creating empty and non-empty sequences.
2. Reading and writing sequences from/to streams.
3. Copying and moving sequences.
4. Combining sequences using the `+` operator.
5. Accessing points using the `[]` operator.

## Conclusion
The implementation of the `Points2D` class provides a comprehensive exercise in managing dynamic memory, implementing the "big five" functions, and overloading operators. The project reinforces key concepts in C++ such as pointers, dynamic memory management, and operator overloading. Despite some challenges, the final implementation meets the requirements and passes all provided tests.
