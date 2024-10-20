package P1;

import java.util.Scanner;

public class rightAngledTriangle  extends Figure{
    public rightAngledTriangle(){
        super();
        System.out.println("Enter the base and the perpendicular of the triangle: ");
        Scanner s = new Scanner(System.in);
        int b , p ;
        b = s.nextInt();
        setDim1(b);
        p = s.nextInt();
        setDim2(p);

        }
    public int area(){
        return (getDim1()*getDim2())/2;
    }
}
