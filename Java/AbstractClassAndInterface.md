### **Abstract Class and Interface in Java**

#### **Abstract Class**
An **abstract class** in Java is a class that cannot be instantiated on its own. It can have both abstract methods (without a body) and concrete methods (with a body). It serves as a base class for other classes to extend.

- **Key Features**:
  1. Can have both abstract and concrete methods.
  2. Can declare and initialize instance variables.
  3. Supports constructors.
  4. A class can extend only one abstract class (single inheritance).

- **Example**:
```java
abstract class Animal {
    String name;

    Animal(String name) {
        this.name = name;
    }

    // Abstract method
    abstract void sound();

    // Concrete method
    void sleep() {
        System.out.println(name + " is sleeping.");
    }
}

class Dog extends Animal {
    Dog(String name) {
        super(name);
    }

    @Override
    void sound() {
        System.out.println(name + " barks.");
    }
}
```

### **Interface**

An **interface** is a blueprint for a class in Java. It specifies what a class must do but not how to do it. All methods in an interface are implicitly public and abstract (until Java 7).

- **Key Features**:
  1. Cannot have concrete methods (before Java 8).
  2. All variables are implicitly `public`, `static`, and `final`.
  3. A class can implement multiple interfaces (multiple inheritance).
  4. Starting with Java 8:
     - Supports default methods (concrete methods with `default` keyword).
     - Supports static methods.
  5. Starting with Java 9:
     - Supports private methods.

- **Example**:

```java
interface AnimalBehavior {
    void sound(); // Abstract method

    default void sleep() {
        System.out.println("Animal is sleeping.");
    }
}

class Cat implements AnimalBehavior {
    @Override
    public void sound() {
        System.out.println("Cat meows.");
    }
}
```

### **Similarities Between Abstract Class and Interface**

1. Both can define methods that subclasses or implementing classes must implement.
2. Both are used to achieve abstraction.
3. Both cannot be instantiated directly.

---

### **Differences Between Abstract Class and Interface**

| Feature                     | Abstract Class                                | Interface                              |
|-----------------------------|-----------------------------------------------|----------------------------------------|
| **Nature**                  | Can have both abstract and concrete methods. | All methods are abstract (until Java 8). |
| **Inheritance**             | A class can extend only one abstract class.  | A class can implement multiple interfaces. |
| **Constructors**            | Can have constructors.                       | Cannot have constructors.              |
| **Variables**               | Can have instance variables.                 | Only public, static, and final variables. |
| **Default Implementation**  | Methods can have a body (concrete methods).  | Supports default and static methods (Java 8+). |
| **Access Modifiers for Methods** | Can be public, protected, or private.        | All methods are public by default.     |

---

### **When to Use Abstract Class or Interface**

- Use an **abstract class** when:
  1. You need to share code among several closely related classes.
  2. You want to define instance variables.

- Use an **interface** when:
  1. You need to define a contract that multiple classes can implement.
  2. You want to enable multiple inheritance.

---

### **Example Comparing Abstract Class and Interface**

```java
abstract class Vehicle {
    abstract void start();

    void fuel() {
        System.out.println("Filling fuel...");
    }
}

interface Electric {
    void charge();
}

class Tesla extends Vehicle implements Electric {
    @Override
    void start() {
        System.out.println("Tesla starts silently.");
    }

    @Override
    public void charge() {
        System.out.println("Charging Tesla...");
    }
}

public class Main {
    public static void main(String[] args) {
        Tesla myTesla = new Tesla();
        myTesla.start();
        myTesla.fuel();
        myTesla.charge();
    }
}
```

**Output**:

```bash
Tesla starts silently.
Filling fuel...
Charging Tesla...
```