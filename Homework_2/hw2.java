// Tyler Benson
// Tyler Mooney
// Benjamin Goldstein
// Homework 2
// CSCI 4448

// Needed imports
import java.util.*;

// Extending Shape to allow for different shapes
// Square with display override
class Square extends Shape {
  public void Display() {
    System.out.println("I'm a SQUARE!");
  }
}
// Circle with display override
class Circle extends Shape {
  public void Display() {
    System.out.println("I'm a CIRCLE!");
  }
}
// Triange with display override
class Triangle extends Shape {
  public void Display() {
    System.out.println("I'm a TRIANGLE!");
  }
}

// Main class: Creates shapes (3 each circle, square, triangle)
// Adds shapes to a vector (collection) in place of a database
// Sorts collection on x. The custom sort is implemented in shape.java
// Display is called on the sorted "database" and the shapes are printed
class hw2 {
  public static void main(String args[]) {
    System.out.println("Homework 2: In Java!");
    // Create "database
    Vector<Shape> collection = new Vector<>();
    int c_size;
    // Create shapes (3 each)
    Shape square_1 = new Square();
    Shape square_2 = new Square();
    Shape square_3 = new Square();
    Shape circle_1 = new Circle();
    Shape circle_2 = new Circle();
    Shape circle_3 = new Circle();
    Shape triangle_1 = new Triangle();
    Shape triangle_2 = new Triangle();
    Shape triangle_3 = new Triangle();
    // Add objects to collection
    collection.add(square_1);
    collection.add(square_2);
    collection.add(square_3);
    collection.add(circle_1);
    collection.add(circle_2);
    collection.add(circle_3);
    collection.add(triangle_1);
    collection.add(triangle_2);
    collection.add(triangle_3);
    c_size = collection.size();
    // Sort
    Collections.sort(collection);
    // Print size of collection and display for all objects
    System.out.println("Size of Collection: " + c_size);
    for (int i=0; i<c_size; i++) {
      collection.get(i).Display();
    }
  }
}
