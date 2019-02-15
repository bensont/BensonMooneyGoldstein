// Tyler Benson
// Tyler Mooney
// Benjamin Goldstein
// Homework 2
// CSCI 4448

import java.util.*;

public abstract class Shape implements Comparable<Shape>{
  public int x_;
  public int y_;

  public Shape() {
    Random rand = new Random();
    x_ = rand.nextInt(50) + 1;
    y_ = rand.nextInt(50) + 1;
  }

  public void Display() {System.out.println();}

  public int get_x() {return x_;}

  public int get_y() {return y_;}

  //Does comparisons on x
  public int compareTo(Shape compareShape){
    return this.x_ - compareShape.get_x();
  }

}
