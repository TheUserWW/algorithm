# Algorithm 

A comprehensive C library implementing fundamental data structures and algorithms with clean, efficient, and well-documented code.

## Overview

This library provides robust implementations of essential data structures commonly used in computer science and software development. Built with performance and reliability in mind, it serves as both a practical utility library and an educational resource for understanding data structure implementations.

## Features

### 🏗️ Implemented Data Structures

- **Deque (Double-Ended Queue)**: Flexible linear collection supporting insertion and removal at both ends
- **Queue**: First-In-First-Out (FIFO) data structure
- **Stack**: Last-In-First-Out (LIFO) data structure

### ✨ Key Features

- **Type Safety**: Generic implementation using `void*` pointers for data flexibility
- **Memory Management**: Comprehensive memory allocation and deallocation handling
- **Error Handling**: Robust error checking and validation
- **Performance**: Optimized for time and space complexity
- **Thread Safety**: Designed with potential thread-safe extensions in mind

## Project Structure
```
algorithm/
├── include/              # Header files
│   ├── deque.h          # Deque interface and type definitions
│   ├── queue.h          # Queue interface and type definitions
│   └── stack.h          # Stack interface and type definitions
├── src/                 # Implementation source files
│   ├── deque.c          # Deque implementation
│   ├── queue.c          # Queue implementation
│   └── stack.c          # Stack implementation
├── algorithm.c          # Main program and usage examples
├── algorithm.slnx       # Visual Studio solution file
└── algorithm.vcxproj    # Visual Studio project file
```


## Installation

### Prerequisites

- Visual Studio 2022 or later
- C compiler supporting C99 standard
- Windows development environment

### Building from Source

1. Clone the repository:
```bash
git clone <repository-url>
cd algorithm
```

2. Open the solution file in Visual Studio:
   - Open `algorithm.slnx` in Visual Studio
   - Build the solution (Ctrl+Shift+B)

3. Alternatively, compile using command line:
```bash
cl /Fe:algorithm.exe algorithm.c src/*.c /Iinclude
```

## Usage

### Basic Example

```c
#include "include/stack.h"
#include <stdio.h>

int main() {
    // Create a new stack
    stack* st = new_stack();
    
    // Push elements
    int a = 10, b = 20, c = 30;
    stack_push(st, &a);
    stack_push(st, &b);
    stack_push(st, &c);
    
    // Pop and process elements
    while (!is_stack_empty(st)) {
        int* value = (int*)stack_pop(st);
        printf("Popped: %d\n", *value);
    }
    
    // Cleanup
    stack_destroy(st);
    return 0;
}
```

### Deque Usage

```c
#include "include/deque.h"

// Create deque and add elements
deque* dq = new_deque();
int values[] = {1, 2, 3, 4, 5};

// Add to both ends
deque_push_front(dq, &values[0]);
deque_push_back(dq, &values[1]);

// Access elements
int* front = (int*)deque_front(dq);
int* back = (int*)deque_back(dq);

// Cleanup
deque_clear(dq);
```

## API Reference

### Stack Operations

- `new_stack()`: Create a new stack
- `is_stack_empty(st)`: Check if stack is empty
- `stack_push(st, element)`: Push element onto stack
- `stack_pop(st)`: Pop element from stack
- `stack_top(st)`: Peek at top element
- `stack_size(st)`: Get current stack size
- `stack_destroy(st)`: Destroy stack and free memory

### Deque Operations

- `new_deque()`: Create a new deque
- `is_deque_empty(dq)`: Check if deque is empty
- `deque_push_front(dq, element)`: Add element to front
- `deque_push_back(dq, element)`: Add element to back
- `deque_pop_front(dq)`: Remove element from front
- `deque_pop_back(dq)`: Remove element from back
- `deque_size(dq)`: Get current deque size
- `deque_clear(dq)`: Clear all elements

### Queue Operations

- `new_queue()`: Create a new queue
- `is_queue_empty(q)`: Check if queue is empty
- `enqueue(q, element)`: Add element to queue
- `dequeue(q)`: Remove element from queue
- `queue_front(q)`: Get front element
- `queue_size(q)`: Get current queue size

## Performance Characteristics

| Operation | Stack | Queue | Deque |
|-----------|-------|-------|-------|
| Push/Enqueue | O(1) | O(1) | O(1) |
| Pop/Dequeue | O(1) | O(1) | O(1) |
| Access Front | O(1) | O(1) | O(1) |
| Access Back | O(1) | O(n) | O(1) |
| Memory | O(n) | O(n) | O(n) |


## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Inspired by classic data structure implementations
- Built with educational purposes in mind
- Designed for both learning and practical use
---

**Happy Coding!** 🚀
