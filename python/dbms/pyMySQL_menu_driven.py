import pymysql as pms

host = 'localhost'
user = 'root'
database = 'company'
password = ''

try:
    conn = pms.connect(host=host, user=user, passwd=password, database=database, autocommit=True)
    print("Connection successful!")
except:
    print("An error occurred")

while True:
    try:
        print("\n1. Insert a row")
        print("2. Get information about all employees")
        print("3. Get information about single employee")
        print("4. Update department number for an employee")
        print("5. Delete information about an employee")
        print("6. Exit")
        choice = int(input("\n\nEnter your choice: "))

        match(choice):
            case 1:
                aadhar = -1
                while(aadhar < 100000000000):
                    try:
                        aadhar = int(input("Enter aadhar number of employee (12 digit): "))
                        if(aadhar < 100000000000):
                            print("Enter a valid aadhar number!")
                    except ValueError:
                        aadhar = -1
                        print("Enter a valid aadhar number!")

                name = input("Enter employee name: ")
                gender = input("Enter employee gender (M, F or O): ").upper()

                salary = -1
                while(salary < 8000 or salary > 100000):
                    try:
                        salary = int(input("Enter employee salary (8K - 100K): "))
                        if(salary < 8000 or salary > 100000):
                            print("Enter a valid salary!")
                    except ValueError:
                        salary = -1
                        print("Enter a valid salary!")
                
                dept = -1
                while(dept < 0):
                    try:
                        dept = int(input("Enter department number for employee: "))
                        if(dept < 0):
                            print("Enter a valid department number!")
                    except ValueError:
                        dept = -1
                        print("Enter a valid department number!")

                cur = conn.cursor()
                sql = f"INSERT INTO employee VALUES ('{aadhar}', '{name}', '{gender}', '{salary}', '{dept}')"
                cur.execute(sql)
                cur.close()

            case 2:
                cur = conn.cursor()
                cur.execute("SELECT * FROM employee")
                rows = cur.fetchall()
                if(rows is None):
                    print("No records!")
                else:
                    for row in rows:
                        print(row)
                cur.close()

            case 3:
                aadhar = -1
                while(aadhar < 100000000000):
                    try:
                        aadhar = int(input("Enter aadhar number of employee (12 digit): "))
                        if(aadhar < 100000000000):
                            print("Enter a valid aadhar number!")
                    except ValueError:
                        aadhar = -1
                        print("Enter a valid aadhar number!")

                cur = conn.cursor()
                
                cur.execute(f"SELECT * FROM employee WHERE aadhar = '{aadhar}'")
                row = cur.fetchone()
                if(row is None):
                    print("Employee does NOT exist!")
                else:
                    print(row)
                cur.close()

            case 4:
                aadhar = -1
                while(aadhar < 100000000000):
                    try:
                        aadhar = int(input("Enter aadhar number of employee (12 digit): "))
                        if(aadhar < 100000000000):
                            print("Enter a valid aadhar number!")
                    except ValueError:
                        aadhar = -1
                        print("Enter a valid aadhar number!")
                dept = -1
                while(dept < 0):
                    try:
                        dept = int(input("Enter department number for employee to update: "))
                        if(dept < 0):
                            print("Enter a valid department number!")
                    except ValueError:
                        dept = -1
                        print("Enter a valid department number!")

                cur = conn.cursor()
                cur.execute(f"UPDATE employee SET deptno = '{dept}' WHERE aadhar = '{aadhar}'")
                if(cur.rowcount == 0):
                    print("Employee does NOT exist! Department number not updated")
                else:
                    print("Updated successsfully")
                cur.close()

            case 5:
                aadhar = -1
                while(aadhar < 100000000000):
                    try:
                        aadhar = int(input("Enter aadhar number of employee (12 digit): "))
                        if(aadhar < 100000000000):
                            print("Enter a valid aadhar number!")
                    except ValueError:
                        aadhar = -1
                        print("Enter a valid aadhar number!")

                cur = conn.cursor()
                cur.execute(f"DELETE FROM employee WHERE aadhar = '{aadhar}'")
                if(cur.rowcount == 0):
                    print("Employee does NOT exist! Employee details not deleted")
                else:
                    print("Employee record deleted successfully")
                cur.close()

            case 6:
                conn.close()
                print("Exiting program...")
                exit(0)

            case _:
                print("Enter a valid choice!")

    except ValueError:
        choice = -1
        print("Enter a valid choice!")
