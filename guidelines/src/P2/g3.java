package P2;
import P1.*;

import java.util.Scanner;

public class g3 {
    public static void main(String args[]){
        int s ;
        Scanner inp = new Scanner(System.in);
        System.out.println("Enter a choice for shape from Rectangle and Right Angled Triangle ");
        System.out.println("Enter 1 for Rectangle and 2 for Triangle");
        Figure f ;
        s = inp.nextInt();
        if(s == 1){
            f = new Rectangle();
        System.out.println("The area of the rectangle is " + f.area());
        }
        else if(s == 2){
            f = new rightAngledTriangle();
            System.out.println("The area of the rectangle is " + f.area());
        }



    }
}
