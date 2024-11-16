# `final`, `finally`, and `finalize()` in Java

The terms `final`, `finally`, and `finalize()` in Java may sound similar, but they have distinct purposes and use cases. Here’s a breakdown of when to use each one:

---

### **1. `final` Keyword**

The `final` keyword is used to define constants, prevent method overriding, and prevent inheritance. It can be applied to variables, methods, and classes.

#### **Use Cases**:

- **Final Variables**: A `final` variable can only be initialized once. Once assigned, its value cannot be changed.
    ```java
    final int MAX_VALUE = 100;
    ```

- **Final Methods**: A `final` method cannot be overridden by any subclass.
    ```java
    class Parent {
        public final void show() {
            System.out.println("Final method in Parent");
        }
    }

    class Child extends Parent {
        // This would cause a compile-time error
        // public void show() {}
    }
    ```

- **Final Classes**: A `final` class cannot be subclassed or extended.
    ```java
    public final class MyClass {
        // Class cannot be inherited
    }

    class AnotherClass extends MyClass {  // Compile-time error
    }
    ```

---

### **2. `finally` Block**

The `finally` block is used in exception handling to ensure that a block of code is executed, whether or not an exception occurs. It is typically used for cleanup code (e.g., closing file streams, releasing resources).

#### **Use Cases**:

- **Always executed**: The `finally` block will always be executed after the `try` and `catch` blocks, regardless of whether an exception was thrown or not. Even if the `try` block contains a `return` statement, the `finally` block will still execute.
    ```java
    public void myMethod() {
        try {
            // Some code that may throw an exception
        } catch (Exception e) {
            // Handle exception
        } finally {
            // This block will always be executed
            System.out.println("Cleanup code here");
        }
    }
    ```

- **Resource Cleanup**: `finally` is commonly used to ensure that resources (like file handles, database connections, etc.) are closed, even if an exception occurs in the `try` block.

---

### **3. `finalize()` Method**

The `finalize()` method is a method in the `Object` class that is called by the garbage collector before an object is removed from memory. It gives an object a chance to clean up resources (like closing file handles, releasing memory, etc.) before it is destroyed.

#### **Use Cases**:

- **Resource Cleanup**: `finalize()` can be used to clean up resources, though it's generally considered unreliable and not recommended to use it for critical resource management.
    ```java
    @Override
    protected void finalize() throws Throwable {
        try {
            // Cleanup code, like closing a file
        } finally {
            super.finalize(); // Call the superclass's finalize method
        }
    }
    ```

#### **Caution**:

- **Not reliable**: The `finalize()` method is deprecated in Java 9 and is considered unreliable because the garbage collector may not call it immediately or at all. It is better to use `try-with-resources` or explicit cleanup methods instead.

- **Unpredictable Timing**: You cannot predict when the garbage collector will call `finalize()`, and there’s no guarantee that it will ever be called, so using it for essential resource management is not recommended.

---

### **Summary**:

- **`final`**: Used to make variables immutable, prevent method overriding, and prevent inheritance.
- **`finally`**: Used in exception handling to ensure a block of code executes regardless of whether an exception occurred.
- **`finalize()`**: A method used for resource cleanup before an object is garbage collected, though it is generally discouraged to rely on it due to its unpredictable nature.

### **Recommendation**:

- Prefer **explicit resource management** (like `try-with-resources`) over `finalize()` for cleaning up resources.
- Use **`finally`** when you need to ensure some code is always executed, like cleaning up resources after a `try` block.
