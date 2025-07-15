# 🎓 Student Record Management System

A command-line based C application that allows users to manage student records with full CRUD (Create, Read, Update, Delete) functionality.

## 📂 Project Structure

```
.
├── data/
│   └── students.txt        # File to store student records
├── include/
│   ├── student.h          # Student data structure and function declarations
│   ├── file_handler.h     # File saving/loading declarations
│   └── menu.h             # Menu functions
├── src/
│   ├── main.c             # Entry point
│   ├── student.c          # Student logic and validation
│   ├── file_handler.c     # File reading/writing
│   └── menu.c             # User interface
├── Makefile               # Build and run automation
└── .gitignore             # Ignores students.txt and build files
```

## ✅ Features

- **Add a new student** with:
  - ID, first name, last name, date of birth, semester, topic
- **View all students** in a formatted table
- **Search student by ID** for quick lookup
- **Update any student field** with data validation
- **Delete a student record** with confirmation
- **Input validation** for all fields
- **Data persistence** in a text file
- **Clean terminal interface** (cross-platform `clear_screen`)

## 💻 Technologies

- **Language:** C
- **Compiler:** GCC
- **Build Tool:** Make
- **OS Compatibility:** Windows / Linux

## 🚀 How to Run

1. **Clone the repository**
   ```bash
   git clone https://github.com/Abderrahmanehocine/student-record-management-system.git
   cd student-record-management-system
   ```

2. **Build the project**
   ```bash
   make
   ```

3. **Run the program**
   ```bash
   make run
   ```

4. **Clean compiled files**
   ```bash
   make clean
   ```

## 📁 Sample Output

```
========== Student Record Management ==========
1. Add Student
2. Display Students
3. Search Student by ID
4. Update Student
5. Delete Student
0. Exit
===============================================
Enter your choice:
```

## 🔐 Data File

Records are saved in `data/students.txt` with persistent storage between program runs.

## 🛠️ Prerequisites

- GCC compiler installed
- Make utility
- Terminal/Command prompt

## 📖 Usage

1. Launch the application
2. Use the numbered menu to navigate options
3. Follow the prompts for data entry
4. All changes are automatically saved to the data file

## 🤝 Contributing

Feel free to submit issues and enhancement requests. Pull requests are welcome!

## 👨‍💻 Author

**Hocine Abderrahmane**
- [Portfolio](https://abderrahmanehocine.github.io/portfolio/) • [LinkedIn](https://www.linkedin.com/in/hocine-abderrahmane-b14bb1220) • [GitHub](https://github.com/Abderrahmanehocine)

## 📜 License

This project is licensed under the MIT License.

Feel free to use or improve it for educational or personal purposes!