// Tyler Benson
// Tyler Mooney
// Benjamin Goldstein
// Homework 2
// CSCI 4448

// Needed imports
import java.util.*;

// Shape class
public abstract class Shape implements Comparable<Shape>{
  // point values
  public int x_;
  public int y_;
  // Constuctor
  public Shape() {
    // Generate random values from 1 to 50
    Random rand = new Random();
    x_ = rand.nextInt(50) + 1;
    y_ = rand.nextInt(50) + 1;
  }
  // Display function
  public void Display() {System.out.println();}
  // Returns the x value of the shape
  public int get_x() {return x_;}
  // Returns the y value of the shape
  public int get_y() {return y_;}
  //Does comparisons on x
  public int compareTo(Shape compareShape){
    return this.x_ - compareShape.get_x();
  }
}
