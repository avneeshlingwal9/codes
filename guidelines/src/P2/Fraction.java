package P2;

import javax.lang.model.type.ArrayType;
import java.util.Scanner;

public class Fraction {
    private
    int a , b ,gcd;
    double val ;
    public Fraction(int num , int den){

        if(den==0){
            throw new ArithmeticException();}
        gcd= findgcd(num,den);
        a = num/gcd;
        b = den/gcd;


        val =(double) a/b ;


    }
    public Fraction(){
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the value of the denominator: " );
        b = s.nextInt();
        if(b == 0){
            throw new ArithmeticException();}
        System.out.println("Enter the value of the numerator: ");
        a = s.nextInt();
        gcd = findgcd(a,b);
        a = a/gcd;
        b = b/gcd;
        val = (double) a/b ;
    }


    public double getVal() {
        return val;
    }

    public void mul(Fraction f){
        a *= f.a ;
        b*=f.b;
        val = (double) a/b;
        this.optimize();
    }
    public void getFraction(){
        System.out.println("The value of the fraction is: " + a + "/" + b);
        }
    private int findgcd(int a , int b){
        while(b!=0){
            int temp = b ;
            b = a%b;
            a = temp;
        }
        return a ;
    }
    public void optimize(){
        a = a/gcd ;
        b = b/gcd;
    }





    public void sm(Fraction f){
        int g = findgcd(b,f.b);
        int l = (b*f.b)/g;
        System.out.println(g/b);
        System.out.println(g);
        a = a*(l/b) + f.a*(l/f.b);
        b = l;


    }
    public void subtract(Fraction f){
        a = a*f.b - f.a*b ;
        b = b*f.b;
        val = (double) a/b ;
        this.optimize();


        }

    public static void main(String args[]){
        try{
        Fraction f = new Fraction(1,2);
        Fraction f2 = new Fraction(1,4);
        f.getFraction();
        f2.getFraction();
        f.sm(f2);
        f.getFraction();





        }

        catch (ArithmeticException a ){
            System.out.println("Please enter a valid value for denominator ");

        }

    }



}
