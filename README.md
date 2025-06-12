# 📚 Library Management System

This is a **Qt-based C++ project** for managing a digital library system that supports two main roles: **Students** and **Library Administrators (Admins)**. The system uses **object-oriented programming** with polymorphism and integrates a **MySQL database** to store user and book data persistently.

---

## 🔧 Project Structure

- Two main classes:
  - `User` (Base class) → `Student`, `Admin` (Derived classes)
  - `Book` (Base class) → `Magazine`, `Newspaper`, `OrdinaryBook` (Derived classes)
- Users and books are stored as **vectors of pointers** to allow **polymorphic behavior**.
- Each session dynamically loads/stores objects from/to the database (`mylibrary.db`).

---

## 📜 Getting Started

When launching the system, click the **"Read Caption"** button to review the library rules.

---

## 👤 1. Sign In as Admin

1. Click on **"Sign as Admin"** and fill in the form:
   - First and Last Name
   - Date of Birth
   - Student ID: Must be exactly 8 digits (digits only)
   - Unique Username
   - Strong Password:
     - At least 8 characters
     - One uppercase letter
     - One digit
     - One special character
   - **Root Password**: Required for admin access → `viva l'algerie`

2. Upon successful registration:
   - A new `Admin` object is dynamically created and stored in the user vector.
   - Data is stored in the database for persistence.
   - A new window opens with full access to admin operations.

3. Admin Options:
   - View tables for **Books**, **Magazines**, and **Newspapers**
   - View **Registered Students** and their borrowed books
   - View **Signed-in Admins**
   - View detailed borrow/return data (overdue books highlighted in red)

4. Admin Privileges:
   - Add/Remove books, magazines, newspapers
   - Remove users
   - Cannot remove books with active borrowers
   - Cannot remove users with unreturned books

---

## 🎓 2. Sign In as Student

1. Click on **"Sign In"**:
   - Provide Name, Date of Birth (between 2003–2007)
   - Choose a unique username
   - Create a strong password (same rules as above)
   - Select your **Study Year** (1st–4th Year)

2. Upon submission:
   - A new `Student` object is created and stored in the users vector.
   - User data is saved to the database.

3. Student Options:
   - View available **Books**, **Magazines**, and **Newspapers**
   - View own borrow/return history (overdue books highlighted in red)

4. Student Actions:
   - Borrow/Return books, magazines, newspapers
   - Rate returned books (0–10 scale)
   - Cannot borrow multiple copies of the same book
   - Cannot borrow if all previously borrowed books are not returned
   - Can only return books they personally borrowed

---

## 📚 Book Management

### ➕ Add Book
- Admins click **"Add Book"**, fill in the form, and submit.
- The new item appears in the table.
- Applies to magazines and newspapers as well.

### ➖ Remove Book
- Select the row of the item and click **"Remove"**.
- Book must have no active borrowers.

### 📥 Borrow Book
- Students select a book row and click **"Borrow"**.
- A dialog appears with:
  - Title, Author
  - Borrow Date (current date)
  - Return Date (max 2 months ahead)
- Click **"Confirm"** to proceed.

### 📤 Return Book
- Students select the book row and click **"Return"**.
- A dialog appears for rating the book (0–10).
- The system updates the average rating.

### 🔍 Search Function
- Use the **search bar** to quickly find books or users.

---

## 📺 Demo Video

▶️ [Watch the YouTube video tutorial](https://www.youtube.com/watch?v=oh1aYQt3Zg4)

---

## ✅ Features Summary

- Role-based access: Admins and Students
- Polymorphic behavior via pointer vectors
- MySQL database persistence
- Real-time validation of inputs (ID, username, password)
- Visual UI built with Qt
- Red alerts for overdue books
- Book rating system
- Robust error handling and smooth user experience

---

## 🧠 Behind the Scenes

> _"The library management system ensures robust error handling, validation of user inputs, and reliable insertion, removal, and retrieval of data from the database. Backend processes are optimized to provide a seamless experience for both users and administrators."_  

---

## 👨‍💻 Author

**Saliha HAMMOUTENE**  
National Higher School of Artificial Intelligence, Algeria  
Academic Year: 2024–2025

---

