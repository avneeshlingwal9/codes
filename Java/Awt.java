import java.awt.*;

public class Awt extends Frame {
    Awt() {
        Button b = new Button("Submit");
        TextField t = new TextField();
        Label l = new Label("Employee id");
        b.setBounds(100, 100, 80, 30);
        t.setBounds(20, 100, 80, 30);
        l.setBounds(20, 70, 80, 30);
        setLayout(null);
        setVisible(true);
        setSize(400, 400);
        add(b);
        add(t);
        add(l);

    }

    public static void main(String args[]) {
        Awt a = new Awt();

    }
}
