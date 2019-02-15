// Tyler Benson
// Tyler Mooney
// Benjamin Goldstein
// Homework 2
// CSCI 4448

import java.util.*;



class Square extends Shape {
  public void Display() {
    System.out.println("I'm a SQUARE!");
  }
}

class Circle extends Shape {
  public void Display() {
    System.out.println("I'm a CIRCLE!");
  }
}

class Triangle extends Shape {
  public void Display() {
    System.out.println("I'm a TRIANGLE!");
  }
}


class hw2 {
  public static void main(String args[]) {
    System.out.println("Homework 2: In Java!");

    Vector<Shape> collection = new Vector<>();
    int c_size;
    Shape square_1 = new Square();
    Shape square_2 = new Square();
    Shape square_3 = new Square();
    Shape circle_1 = new Circle();
    Shape circle_2 = new Circle();
    Shape circle_3 = new Circle();
    Shape triangle_1 = new Triangle();
    Shape triangle_2 = new Triangle();
    Shape triangle_3 = new Triangle();
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

    Collections.sort(collection);
    System.out.println("Size of Collection: " + c_size);
    for (int i=0; i<c_size; i++) {
      collection.get(i).Display();
    }
  }
}
