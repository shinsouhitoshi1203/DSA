# Singly Linked List

This document describes the implementation of a singly linked list in the file `linked_list.cpp`.

## Overview

A singly linked list is a linear data structure where each element (node) points to the next node in the sequence. It consists of:

- **Node**: Contains data and a pointer to the next node.
- **Head**: Points to the first node in the list.

## Code Structure

The implementation in `linked_list.cpp` includes the following:

1. **Node Structure**: Defines the structure of a node.
2. **Linked List Class**: Contains methods to manipulate the list, such as insertion, deletion, and traversal.

## Features

- **Insertion**: Adds a new node at the end of the list.
- **Deletion**: Removes a node by its value.
- **Traversal**: Displays all elements in the list.

## How to Run

1. Save the code in `linked_list.cpp`.
2. Compile using a C++ compiler:
    ```shell
    g++ linked_list.cpp -o linked_list.exe
    ```
3. Run the executable:
    ```shell
    ./linked_list.exe
    ```

## Output Example

```
Linked List: 10 -> 20 -> 30 -> NULL
After Deletion: 10 -> 30 -> NULL
```
