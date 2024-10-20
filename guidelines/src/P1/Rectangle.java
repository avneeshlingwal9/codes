package P1;

import java.util.Scanner;

public class Rectangle extends Figure {
    @Override


    public int area() {
        return getDim1()*getDim2();
    }
    public Rectangle(){
        super();
        System.out.println("Enter length and breadth of rectangle: ");
        Scanner s = new Scanner(System.in);
        int l,b ;
        l = s.nextInt();
        setDim1(l);
        b = s.nextInt();
        setDim2(b);

    }
}
