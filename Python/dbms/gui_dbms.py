'''
Program to create an GUI Based interface for mysql queries using python.
Uses Tkinter and Pymysql.




'''

import pymysql as pq 

import tkinter as tki
conn = pq.connect(
    host='localhost',
    user='root',
    db = 'company'
)
cur = conn.cursor()
'''
Function to execute the queries for insertion of data.
'''
def insert_new(data):
    query = "INSERT INTO `employee`(Aadhar,Name,Gender,Salary,Deptno)  VALUES (%s,%s,%s,%s,%s)"
    cur.execute(query,data)
    conn.commit()

'''
Function to execute the queries for deletion of data and returns boolean value based on that.
'''

def delete_one( aadhar):
    query = "DELETE FROM employee WHERE Aadhar = %s"

    cur.execute(query,(aadhar))
    if(cur.rowcount == 0):
        return False
 
    conn.commit()
    return True

'''
Creating an gui. With three buttons.
INSERT : calls insert_data method which opens up another window for the insertion of data, which uses insert_one function and has a button SUBMIT to COMMIT the data.
DISPLAY : calls display_data method which opens up another window to display the current state of the relation employee and contains one button return to go back to previous window.
DELETE : calls delete_entry method which opens up another window to take input for aadhar number of the employee and contains DELETE button to COMMIT , which uses delete_one function and also utilizes wait() function to wait for 2 seconds to display whether the query was executed sucessfully or not.
'''

gui = tki.Tk()
gui.geometry("300x300")
gui.title("Company Database Management")
def insert_data():
    insert_window = tki.Toplevel(gui)
    insert_window.geometry("300x300")
    insert_window.title("Inserting a new employee")
    aadhar = tki.StringVar()
    name = tki.StringVar()
    gender = tki.StringVar()
    salary = tki.StringVar()
    dept = tki.StringVar()
    tki.Label(insert_window, text="Enter aadhar number : " ).grid(row=0,column=0)
    tki.Entry(insert_window,textvariable= aadhar).grid(row = 0, column=1)
    tki.Label(insert_window, text="Enter your name : "  ).grid(row=1,column=0)
    tki.Entry(insert_window,textvariable= name).grid(row=1,column=1)
    tki.Label(insert_window, text="Enter your gender :").grid(row=2,column=0)
    tki.Entry(insert_window,textvariable= gender).grid(row=2,column=1)
    tki.Label(insert_window, text="Enter your department : " ).grid(row=3,column=0)
    tki.Entry(insert_window,textvariable= dept).grid(row=3,column=1)
    tki.Label(insert_window, text="Enter your salary : " ).grid(row=4,column=0)
    tki.Entry(insert_window,textvariable= salary).grid(row=4,column=1)
    def submit():
        data = [int(aadhar.get()),name.get(),gender.get().upper(), float(salary.get()), int(dept.get())]
        insert_new(data)
        insert_window.destroy()
    tki.Button(insert_window, text="Submit", command=submit).grid(row = 5, column=1)



def display_data():
    
    display_window = tki.Toplevel(gui)
    display_window.geometry("300x300")
    display_window.title("Details of employees ")
    query = "SELECT * FROM employee"
    cur.execute(query)
    outp = cur.fetchall()
    header = ["Aadhar", "Name" , "Gender" , "Salary", "Department"]
    
    for i, data in enumerate(header):
        e = tki.Label(display_window,text= data).grid(row = 0 , column= i)
    for i in range(len(outp)):
        for j in range(len(outp[i])):
            e = tki.Label(display_window , text= outp[i][j])
            e.grid(row = i+1 , column=j)
    def return_prev():
        display_window.destroy()
    
    tki.Button(display_window,text="Return", command=return_prev).grid(row = len(outp)+1 , column = 2)
def wait():
    var = tki.IntVar()
    gui.after(2000, var.set,1)
    gui.wait_variable(var)

def delete_entry():
    delete_window = tki.Toplevel(gui)
    delete_window.geometry("300x300")
    delete_window.title("Deletion window")
    aadhar = tki.StringVar()
    tki.Label(delete_window, text="Enter aadhar employee: ").grid(row = 0 , column=0)
    tki.Entry(delete_window,textvariable=aadhar).grid(row = 0 , column=1)
    def deletion():
        flag = delete_one(int(aadhar.get()))
        if(flag):
            tki.Label(delete_window,text="Deletion successful" ).grid(row = 4, column=0)
        else:
            tki.Label(delete_window, text="Entry not found").grid(row = 4, column=-0)
        wait()
        delete_window.destroy()
    tki.Button(delete_window, text= "DELETE", command=deletion).grid(row = 2 , column=1)


    
insert_btn = tki.Button(gui,text="INSERT", command= insert_data)
display_btn = tki.Button(gui,text="DISPLAY", command= display_data)
delete_btn = tki.Button(gui,text="DELETE", command=delete_entry)
insert_btn.pack()
display_btn.pack()
delete_btn.pack()


gui.mainloop()




