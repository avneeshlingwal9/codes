package AWT;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;

public class g9 extends Frame  {
    TextField t ;
    Label l ;

    g9(){
        t = new TextField();
        t.setBounds(50,100,400,100);
        l = new Label();
        l.setBounds(50,300,200,400);
        add(t);
        add(l);
        setTitle("Guideline 9");
        setSize(1000,1000);
        setVisible(true);
        setLayout(null);
        t.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                String s = t.getText();
                l.setText("Typed key is " + s);
            }
        });

    }
    public static void main(String args[]){
        new g9();
    }
}
