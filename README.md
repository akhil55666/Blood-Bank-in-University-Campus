# Blood Donor Management System (BST)

## Overview
This project is a **Blood Donor Management System** implemented using a **Binary Search Tree (BST)** in C. It allows users to:

- Insert donor details categorized by blood type.
- Search for donors with a specific blood type.
- Find compatible blood donors based on blood compatibility rules.
- Display donor information.

## Features
- Efficient storage and retrieval using a **Binary Search Tree (BST)**.
- **Blood compatibility logic** to find suitable donors.
- **Dynamic memory allocation** for storing donor details.
- **Automatic memory cleanup** to prevent memory leaks.

## Blood Type Compatibility Rules
The program finds compatible donors based on the following rules:

- **O-** can donate to all blood types.
- **O+** can donate to O+, A+, B+, and AB+.
- **A-** can donate to A- and A+.
- **A+** can donate to A+.
- **B-** can donate to B- and B+.
- **B+** can donate to B+.
- **AB-** can donate to AB- and AB+.
- **AB+** can donate only to AB+.

## Installation & Usage

### Prerequisites
- A C compiler (e.g., GCC)

### Compilation
To compile the program, use:
```bash
gcc blood_donor_bst.c -o blood_donor_bst
```

### Running the Program
```bash
./blood_donor_bst
```

### Sample Input/Output
#### Input:
```
Enter the blood type to search for: A-
```

#### Output:
```
Found donor with blood type A-: Akhil - ak7099@srnist.edu.in

Compatible Donors:
1. Akhil - ak7099@srnist.edu.in - Blood Type: A-
2. Darahas - pd0099@srnist.edu.in - Blood Type: A+
```

## File Structure
```
├── blood_donor_bst.c   # Main source code file
├── README.md           # Documentation
```

## Memory Management
- Uses **`malloc`** for dynamic memory allocation.
- Uses **`strdup`** to store donor details securely.
- Implements **`freeTree`** function to release memory before exit.

## Future Enhancements
- Implement a GUI for better user interaction.
- Store donor details in a file for persistent storage.
- Improve blood compatibility logic with additional checks.

## Contributing
Contributions are welcome! Feel free to fork the repository and submit a pull request.



## Author
Developed by **[Udaya Harsha, Akhil Kanvarsh]**.

