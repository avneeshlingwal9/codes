package AWT;
import java.awt.*;

public class ex1 extends Frame {
    ex1(){
        Button b = new Button("Click me");
        b.setBounds(100,100,100,30);
        add(b);
        setSize(300,300);
        setLayout(null);
        setVisible(true);
        setTitle("First example");

    }

public static void main(String args[]){
        ex1 e = new ex1();

}}
