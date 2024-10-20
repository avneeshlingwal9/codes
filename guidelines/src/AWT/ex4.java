package AWT;
import java.awt.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class ex4  extends  Frame{
    TextField tn ;
    ex4(){
        tn = new TextField();
        Button b = new Button("Click me");
        tn.setBounds(20,80,80,20);
        b.setBounds(40,60,60,20);
        add(b);
        add(tn);
        setTitle("Second Example");
        setVisible(true);
        setLayout(null);
        setSize(400,400);
        tn.setText("Hello");
        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tn.setText("Heheheh");

            }
        });
    }
    public static void main(String args[]){
        ex4 e = new ex4();
    }

}
