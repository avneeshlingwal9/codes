package AWT;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ex5 extends Frame {
    ex5() {
        Button b = new Button("Click me");
        TextField t = new TextField();
        t.setBounds(20, 80, 80, 20);
        b.setBounds(40, 60, 60, 20); // Adjusted button width for better visibility
        add(b);
        add(t);
        setTitle("Second Example");
        setSize(200, 150); // Set frame size
        setVisible(true);
        setLayout(null);

        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                t.setText("Heheheh");
                setBackground(Color.blue);
            }
        });
    }

    public static void main(String args[]) {
        new ex5(); // Corrected class name here
    }
}


