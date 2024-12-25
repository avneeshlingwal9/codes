import pymysql as pq
import pandas as pd

conn = pq.connect(
    host='localhost',
    user= 'root',
    db = 'Company'
)
cur = conn.cursor()

def choice_1():
    
    aadhar = int(input("Enter your aadhar number: "))
    name = input("Enter your name: ")
    gender = input("Enter your gender: ").upper()
    salary = float(input("Enter your salary: "))
    deptnum = int(input("Enter your department number: "))

    data = [aadhar,name,gender,salary,deptnum]
    query = "INSERT INTO `employee`(Aadhar,Name,Gender,Salary,Deptno)  VALUES (%s,%s,%s,%s,%s)"
    cur.execute(query,data)
    conn.commit()


def choice_2():
    query = "SELECT * FROM employee"
    cur.execute(query)
    outp = cur.fetchall()
    for i in range(len(outp)):
        for j in range(len(outp[i])):
            print(outp[i][j])
"""     columns = ["Aadhar", "Name", "Gender","Salary" , "Deptno"]
    df = pd.DataFrame(outp,columns=columns)
    print(df) """

def choice_3():
    aadhar = int(input("Enter aadhar number of the employee: "))
    query = "SELECT * FROM employee WHERE Aadhar = %s"
    cur.execute(query,(aadhar))
    result = cur.fetchone()
    columns = ["Aadhar", "Name", "Gender","Salary" , "Deptno"]
    
    if result is None:
        print("No employee found")
    else:
       print(result)
        

def choice_4():
    aadhar = int(input("Enter aadhar number of the employee: "))
    deptno = int(input("Enter new department number of employee: "))
    data = [deptno,aadhar]
    query = "UPDATE employee SET Deptno = %s WHERE Aadhar = %s "
    cur.execute(query,data)
    if(cur.rowcount == 0):
        print("Employee does not exist")
    else:
        print("Department number Updated successfully")
    conn.commit()

def choice_5():
    aadhar = int(input("Enter aadhar number of the employee: "))
    query = "DELETE FROM employee WHERE Aadhar = %s"

    cur.execute(query,(aadhar))
    if(cur.rowcount == 0):
        print("Employee does not exist")
    else:
        print("Data deletion successful")
    conn.commit()



print("1. To insert a row")
print("2. To get information about all employees")
print("3. Get information based on some specific condition")
print("4. Update department number for employee")
print("5. Delete information about an employee")
print("6. To exit")
flag = True
while(flag ):
    choice = int(input("Enter your choice:"))
    if(choice == 1):
        choice_1()
    elif(choice == 2):
        choice_2()
    elif(choice == 3):
        choice_3()
    elif(choice == 4):
        choice_4()
    elif(choice == 5):
        choice_5()
    elif(choice == 6):
        flag = False
    else:
        print("Invalid choice")
    
conn.close()