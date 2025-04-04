# 🏦 Bank Management System in C++

A simple console-based Bank Management System built using C++. This program allows users to create an account, deposit money, withdraw cash, and manage their account data using file handling techniques.

---

## 📁 Features

- ✅ Open a new account  
- 💵 Deposit money into an account  
- 💳 Withdraw cash from an account  
- 🧾 File-based data storage using `.txt` files  
- ⏳ Uses Windows API for simple UI enhancements (like screen clear and delay)

---

## 🔧 Technologies Used

- **C++**  
- **File Handling (fstream)**  
- **Windows API** (`windows.h`)  
- **Object-Oriented Programming (OOP)`**

---

## 📌 Prerequisites

To run this project on Windows:

- C++ Compiler (e.g., `g++`, `MinGW`, or any IDE like Code::Blocks, Dev-C++, or Visual Studio)
- Windows OS (for `windows.h` support)

---

## ▶️ How to Run

1. **Clone or Download** the repository.

2. **Compile** the code using a C++ compiler:

    ```bash
    g++ -o BankSystem BankSystem.cpp
    ```

3. **Run** the compiled executable:

    ```bash
    BankSystem.exe
    ```

---

## 📂 File Structure

- `Account.txt`: Stores all account records in the format:
- `Account Temp.txt`: Temporary file used for modifying account data safely.

---

## 🧠 Code Overview

- **Account Class**  
Handles account details like Account Number, Password, and Balance.

- **Functions**  
- `openAccount()` – Creates a new account and writes to file.  
- `addCash()` – Reads the file, updates balance, and rewrites file.  
- `withdraw()` – Deducts money if sufficient balance exists.  
- `main()` – Console UI for navigating features.

---

## ⚠️ Limitations

- ❌ No password encryption (stored in plain text)  
- ❌ No user input validation  
- ❌ Only one user can operate at a time  
- ❌ Platform-dependent (works only on Windows due to `windows.h`)

---

## 🌟 Future Improvements

- 🔒 Add password encryption using hashing (e.g., SHA256)
- 🧠 Implement login system with multiple user support
- 🌐 Use a database (e.g., SQLite) instead of plain text
- ✨ Replace console with GUI (e.g., using Qt or SFML)
- 🛡️ Add input validation and exception handling

---

## 🧑‍💻 Author

**Swapnali Patil**  
Beginner C++ developer and data science enthusiast.

---
