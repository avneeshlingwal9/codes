package P2;
import P1.*;

public class Car {
    private
    Engine e ;
    int regi ;
    String model;
    public
    Car(int n , int r , String s , String m){
        e = new Engine(n,s);
        regi = r ;
        model = m ;
    }
    public String toString() {

        System.out.println("The car has engine of  brand " + e.getmake() + " and chasis number is " +e.getCnum() +
                " and registartation number of car is "+ regi + "and model is " + model);
        return  "NULL";
    }

public static void main(String args[]){
        Car c = new Car(45,45,"Yes","x");
        c.toString();

}}
