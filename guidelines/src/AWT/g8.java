package AWT;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class g8 extends  Frame implements ActionListener {
    Button b1 ;
    Button b2 ;
    g8(){
         b1 = new Button("Red");
        b2 = new Button("Blue");
        b1.setBounds(100,100,40,20);
        b2.setBounds(100, 150,40,20);
        setSize(400,400);
        setTitle("Guideline 8");
        setVisible(true);
        setLayout(null);
        b1.addActionListener(this);
        b2.addActionListener(this);
        add(b1);
        add(b2);


    }
    @Override
    public void actionPerformed(ActionEvent e ){
        if(e.getSource() == b1){
            setBackground(Color.RED);

        }
        else if(e.getSource() == b2){
            setBackground(Color.BLUE);
        }


    }
    public static void main(String args[]){
        new g8();
    }

}
