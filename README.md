# 🎓 Student Record Management System

A command-line based C application that allows users to manage student records with full CRUD (Create, Read, Update, Delete) functionality.

## 📂 Project Structure

.
├── data/
│ └── students.txt # File to store student records
├── include/
│ ├── student.h # Student data structure and function declarations
│ ├── file_handler.h # File saving/loading declarations
│ └── menu.h # Menu functions
├── src/
│ ├── main.c # Entry point
│ ├── student.c # Student logic and validation
│ ├── file_handler.c # File reading/writing
│ └── menu.c # User interface
├── Makefile # Build and run automation
└── .gitignore # Ignores students.txt and build files


---

## ✅ Features

- Add a new student with:
  - ID, first name, last name, date of birth, semester, topic
- View all students
- Search student by ID
- Update any student field
- Delete a student record
- Input validation for all fields
- Data stored persistently in a text file
- Clean terminal interface (cross-platform `clear_screen`)

---

## 💻 Technologies

- **Language:** C
- **Compiler:** GCC
- **Build Tool:** Make
- **OS Compatibility:** Windows / Linux

---

## 🚀 How to Run

1. **Clone the repository**
   ```bash
   git clone https://github.com/Abderrahmanehocine/student-record-management-system.git
   cd student-record-management-system

2. **Build the project**
    ```bash
    make

3. **Run the program**
    ```bash
    make run

4. **Clean compiled files**
    ```bash
    make clean

📁 Sample Output

========== Student Record Management ==========
1. Add Student
2. Display Students
3. Search Student by ID
4. Update Student
5. Delete Student
0. Exit
===============================================
Enter your choice:

🔐 Data File

    Records are saved in data/students.txt


👨‍💻 Author

Hocine Abderrahmane
Portfolio • LinkedIn • GitHub
📜 License

This project is licensed under the MIT License.
Feel free to use or improve it for educational or personal purposes!


---

### ✅ Next Step:
You can save this content to a file called `README.md` in the root of your project directory, then commit and push it:

```bash
git add README.md
git commit -m "Add project README with features and usage"
git push origin main