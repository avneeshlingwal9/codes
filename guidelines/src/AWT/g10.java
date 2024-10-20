package AWT;
import java.util.Scanner;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
class Student{
    private
    String name ;
    String course ;
    int rollNo ;
    String college ;
    double cgpa ;
    Student(){
        Scanner s  = new Scanner(System.in);
        System.out.println("Enter your name: ");
        s.nextLine();
        System.out.println("Enter your course");
        s.nextLine();
        System.out.println("Enter your Roll No. ");
        s.nextInt();
        System.out.println("Enter your college");
        s.next();
        System.out.println("Enter your cgpa: ") ;
        s.nextDouble();
    }
    Student(String name , String college, String course ,int roll , double cgpa){
        this.name = name ;
        this.college = college;
        this.course = course ;
        this.rollNo = roll;
        this.cgpa = cgpa;
    }
    public String getName(){
    String l = "The name of the student is: " + this.name ;
    return l;}

    public String getCollege() {
        String l = "The name of the college is " + this.college ;
        return l;
    }

    public String getCourse() {
        String l = "The name of the course is " + this.course;
        return l;
    }

    public String  getRollNo() {
        String l = "The roll no. is " +  this.rollNo ;
        return l ;
    }

    public String getCgpa() {
        String l = "The cgpa is " + this.cgpa;
        return l ;
    }
}

public class g10  extends Frame implements ActionListener{
    Button b1 , b2 ;
    Label l1,l2,l3,l4,l5;
    g10(){
        b1 = new Button("A");
        b2 = new Button("B");
        l1 = new Label();
        l2 = new Label();
        l3 = new Label();
        l4 = new Label();
        l5 = new Label();
        b1.setBounds(200,200,40,20);
        b2.setBounds(200,250,40,20);
        b1.addActionListener(this);
        b2.addActionListener(this);
        setTitle("Guideline 8");
        setLayout(null);
        setSize(1000,1000);
        setVisible(true);
        add(b1);
        add(b2);

        }


    @Override
    public void actionPerformed(ActionEvent e) {
        Student s = new Student("A","B","C",4,4.5) ;


        if(e.getSource()==b1){
            l1.setBounds(100,300,400,20);
            l1.setText(s.getName());
            l2.setBounds(100,400,400,20);
            l2.setText(s.getCollege());
            l3.setBounds(100,500,400,20);
            l3.setText(s.getCourse());
            l4.setBounds(100,600,400,20);
            l4.setText( s.getRollNo());
            add(l1);
            add(l2);
            add(l3);
            add(l4);
            remove(l5);

        }
        else if(e.getSource()==b2){
            remove(l1);
            remove(l2);
            remove(l3);
            remove(l4);
            l5.setBounds(100,300,100,20);
            l5.setText( s.getCgpa());
            add(l5);
        }

    }
    public static void main(String args[]){
        new g10();

    }

}


