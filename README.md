# Grade Manager CLI

A simple, persistent C++ application for tracking grades and calculating weighted averages.

## Features
* **Persistence:** Saves and loads data from a `.csv` file automatically.
* **Efficient Storage:** Uses `std::unordered_map` for fast grade lookups.
* **Weighted Calculations:** Supports assignment weights for accurate average tracking.
* **Input Validation:** Robust handling of non-numeric input to prevent application crashes.

---

## Project Structure



| File | Description |
| :--- | :--- |
| **GradeManager.h** | Header file containing class declarations and the `Grade` struct. |
| **GradeManager.cpp** | Implementation of core logic (add, remove, average). |
| **Persistence.h** | Logic for reading/writing data to the local file system. |
| **main.cpp** | The command-line interface and main application loop. |
| **Makefile** | Build automation script for easy compilation. |

---

## Installation & Building

1. **Clone or download** the project files into a single directory.
2. Ensure you have a **C++17 compatible compiler** (GCC 7+, Clang 5+, or MSVC 2017+).
3. Build the project using the included Makefile:

```bash
# To compile the project
make

# To run the application
./gradeapp

# To remove compiled files (fresh start)
make clean
```

## Usage
Once the application is running, use the following commands:

- add: Prompts for assignment name, grade (0-100), and weight (e.g., 0.25).

- show: Displays a formatted list of all current assignments and scores.

- delete: Removes a specific assignment by name.

- average: Calculates the total weighted average of all stored data.

- quit: Automatically saves all changes to grades.csv and exits.
