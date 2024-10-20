class shape {
    void show(){
        System.out.println("Superclass show ");
    }
    
}
class rectangle extends shape{
    void show(){
        System.out.println("Subclass rectangle");
    }

}
class triangle extends shape{
    void show(){
        System.out.println("Subclass triangle");
    }
}
public class Shape{
    public static void main(String args[]){
        shape s = new shape();
        s.show();
        rectangle r = new rectangle();
        r.show();
        triangle t = new triangle();
        t.show();

    }
}
