# 🔐 Console User Authentication System

A lightweight, persistent command-line application built in C++ that manages user authentication. The system enables users to safely register new accounts and securely log into existing profiles by writing and reading data from a flat-file database local storage system.

---

## 🚀 Features

* **Account Registration:** Checks for existing user records dynamically to enforce unique usernames across the platform.
* **Secure Login Verification:** Validates matching combinations of stored credentials before granting profile access.
* **Persistent File Database:** Stores registration data long-term inside a localized plain-text file (`users.txt`).
* **Interactive Menu Loop:** Simple, persistent user CLI selection dashboard allowing continuous operational requests until exit.
* **Automatic Resource Cleanup:** Proactively opens and closes input/output file streams (`std::ifstream` and `std::ofstream`) to keep system memory clear and avoid file locks.

---

## ⚙️ How It Works

The system operates directly on local file tracking logic:

* **File Appending (`std::ios::app`):** When writing new users, the application jumps to the end of the file database without overwriting previous profiles.
* **Token Stream Parsing:** User accounts are written as spaced values (`username password\n`). The system leverages line-by-line reading to safely parse and validate records individual string pairs at a time.

---

## 🛠️ Installation & Compilation

To run this application, make sure you have a standard C++ compiler toolchain (like `g++` or `clang`) set up.

### 1. Save the Source Code
Save the provided code to your machine in a file named `auth_system.cpp`.

### 2. Compile via Command Line
Open your workspace terminal and build the binary program using:
```bash
g++ -std=c++11 auth_system.cpp -o auth_system
