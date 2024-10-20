import java.util.Scanner;

interface Rectangle{
    int area(int l , int b);
}
interface Triangle{
    double areat(double x ,double y,double z);
}


public class g1 implements Rectangle,Triangle {
    @Override
    public int area(int l , int b){
        return l*b;
    }
    @Override
    public double areat(double x, double y,double z){
        double s = (x+y+z)/3.0;
        return Math.sqrt(s*(s-x)*(s-y)*(s-z));
    }
    public static void main(String args[]){
        g1 g = new g1();
        int l , b ;
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the dimensions of the rectangle: ");
        l = s.nextInt();
        b = s.nextInt();
        double x, y ,z ;
        System.out.println("Enter the dimensions of the triangle: ");
        x = s.nextDouble();
        y = s.nextDouble();
        z = s.nextDouble();
        System.out.println("The area of the rectangle is: "+ g.area(l,b));
        System.out.println("The area of the triangle is: "+g.areat(x,y,z));



    }
}
