import java.util.Scanner;

interface Rectangle {
    int area(int l, int b);
}

interface Triangle {
    double areat(double x, double y, double z);
}

class G1 implements Rectangle, Triangle {
    @Override
    int area(int l, int b) {
        return l * b;
    }

    @Override
    double areat(double x, double y, double z) {
        double s = (x + y + z) / 3;
        return Math.sqrt(s * (s - x) * (s - y) * (s - z));

    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the dimensions of the rectangle : ");
        int l, b;
        l = s.nextInt();
        b = s.nextInt();
        double x, y, z;
        System.out.println("Enter the dimensions of the triangle: ");
        x = s.nextDouble();
        y = s.nextDouble();
        z = s.nextDouble();
        G1 g = new G1();
        System.out.println("The area of the rectangle is : " + g.area(l, b));
        System.out.println("The area of the triangle is: " + g.areat(x, y, z));

    }
}