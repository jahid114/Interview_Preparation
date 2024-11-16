
# **SOLID Principles with Examples**

---

## **1. Single Responsibility Principle (SRP)**

**Definition**:  
A class should have only one reason to change. This means it should only have one job or responsibility.

### **Example**  

**Bad Design**:  
The `Invoice` class handles both the business logic and the persistence of data.  

```java
class Invoice {
    public void calculateTotal() {
        // Logic for calculating total
    }

    public void saveToDatabase() {
        // Logic for saving to database
    }
}
```

**Good Design**:  
Separate the responsibilities into different classes.

```java
class Invoice {
    public void calculateTotal() {
        // Logic for calculating total
    }
}

class InvoiceRepository {
    public void saveToDatabase(Invoice invoice) {
        // Logic for saving to database
    }
}
```


## **2. Open/Closed Principle (OCP)**

**Definition**:  
A class should be open for extension but closed for modification. This means you should be able to add new functionality without altering existing code.

### **Example**

**Bad Design**:  
A shape class that requires modification for every new shape type.

```java
class Shape {
    public double calculateArea(String shapeType) {
        if ("Circle".equals(shapeType)) {
            // Area of circle
        } else if ("Rectangle".equals(shapeType)) {
            // Area of rectangle
        }
        return 0;
    }
}
```

**Good Design**:  
Use inheritance or interfaces to allow extension.

```java
abstract class Shape {
    public abstract double calculateArea();
}

class Circle extends Shape {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    private double width, height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double calculateArea() {
        return width * height;
    }
}
```

## **3. Liskov Substitution Principle (LSP)**

**Definition**:  
Derived classes must be substitutable for their base class without altering the correctness of the program.

### **Example**

**Bad Design**:  
A `Bird` base class that breaks substitution when extended.

```java
class Bird {
    public void fly() {
        // Fly logic
    }
}

class Penguin extends Bird {
    @Override
    public void fly() {
        throw new UnsupportedOperationException("Penguins can't fly");
    }
}
```

**Good Design**:  
Use a better hierarchy to avoid breaking substitution.

```java
interface Bird {
    void eat();
}

interface FlyingBird extends Bird {
    void fly();
}

class Sparrow implements FlyingBird {
    public void eat() {
        // Eating logic
    }

    public void fly() {
        // Flying logic
    }
}

class Penguin implements Bird {
    public void eat() {
        // Eating logic
    }
}
```

## **4. Interface Segregation Principle (ISP)**

**Definition**:  
A class should not be forced to implement interfaces it does not use. Split large interfaces into smaller, more specific ones.

### **Example**

**Bad Design**:  
A large interface forces unused methods.

```java
interface Worker {
    void work();
    void manageTeam();
}

class Developer implements Worker {
    public void work() {
        // Coding logic
    }

    public void manageTeam() {
        throw new UnsupportedOperationException("Developers don't manage teams");
    }
}
```

**Good Design**:  
Split the interface into smaller, more specific ones.

```java
interface Worker {
    void work();
}

interface Manager {
    void manageTeam();
}

class Developer implements Worker {
    public void work() {
        // Coding logic
    }
}

class TeamLead implements Worker, Manager {
    public void work() {
        // Coding logic
    }

    public void manageTeam() {
        // Team management logic
    }
}
```

## **5. Dependency Inversion Principle (DIP)**

**Definition**:  
High-level modules should not depend on low-level modules. Both should depend on abstractions.

### **Example**

**Bad Design**:  
High-level classes depend directly on low-level implementations.

```java
class MySQLDatabase {
    public void connect() {
        // MySQL connection logic
    }
}

class Application {
    private MySQLDatabase database;

    public Application() {
        this.database = new MySQLDatabase();
    }

    public void start() {
        database.connect();
    }
}
```

**Good Design**:  
Use abstraction to decouple high-level and low-level modules.

```java
interface Database {
    void connect();
}

class MySQLDatabase implements Database {
    public void connect() {
        // MySQL connection logic
    }
}

class Application {
    private Database database;

    public Application(Database database) {
        this.database = database;
    }

    public void start() {
        database.connect();
    }
}
```

---
## Summary of SOLID Principles

1.  **S**ingle Responsibility: One class, one responsibility.
2.  **O**pen/Closed: Extend, don’t modify.
3.  **L**iskov Substitution: Subtypes should behave like their base types.
4.  **I**nterface Segregation: Small, specific interfaces.
5.  **D**ependency Inversion: Depend on abstractions, not concretions.
