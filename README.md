# Push Swap

## 🌟 Project Overview
**Push Swap** is a project that focuses on sorting data on a stack using a limited set of instructions while achieving the lowest possible number of operations. It helps develop an understanding of sorting algorithms and their complexity, as well as the ability to choose optimized solutions for different scenarios.

## 🚀 How to Use

### 📋 Requirements
- Unix/Linux operating system.
- CC (C compiler).
- Basic understanding of stack data structures.

### 📖 Instructions

1. **Clone the repository:**
   ```bash
   git clone <repository URL>
   cd <repository_name>
   ```

2. **Compile the project:**
   ```bash
   make
   ```

3. **Run the program:**
   Provide a list of integers as arguments. Example:
   ```bash
   ./push_swap 4 3 2 1
   ```
   The program will output the optimal sequence of operations to sort the stack.

4. **Testing with a checker:**
   Use the output of `push_swap` with a checker program to validate the sorting:
   ```bash
   ARG="4 3 2 1"; ./push_swap $ARG | ./checker $ARG
   ```

### 🧹 Cleanup
To remove the files generated during compilation, including the static library from libft:
```bash
make fclean
```

## 🛠 Technologies
- **C Language**: Used to implement the sorting logic and operations.
- **Makefile**: Compilation automation.
- **Norminette**: Compliance with the 42 School coding standard.

---

## 💬 &nbsp;Contacts
<img align="left" src="https://avatars.githubusercontent.com/curtyraissa?size=100">

Made by [Raissa Curty](https://github.com/curtyraissa)!

<a href="https://www.linkedin.com/in/raissa-curty/" target="_blank">
    <img style="border-radius:50%;" src="https://raw.githubusercontent.com/maurodesouza/profile-readme-generator/master/src/assets/icons/social/linkedin/default.svg" width="52" height="40" alt="linkedin logo"  />
</a>&nbsp;

