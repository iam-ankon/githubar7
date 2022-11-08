from tkinter import *
import tkinter.messagebox as MessageBox
import mysql.connector as mysql

G_userid = ""
G_amount = ""
G_address = ""
G_phone = ""
G_name = ""


def insert():
    id = pg2_e_id.get()
    name = pg2_e_name.get()
    phone = pg2_e_phone.get()
    password = pg2_e_pass.get()
    amount = pg2_e_amount.get()
    address = pg2_e_address.get()

    if (id == "" or name == "" or phone == "" or password == "" or amount == "" or address == ""):
        MessageBox.showinfo("Insert Status", "All fields are required")
    else:
        con = mysql.connect(host="localhost", user="root", password="ankon20158", database="test")
        cursor = con.cursor()
        cursor.execute("insert into bankdata values('"+id+"','" +
                       name+"','"+phone+"','"+password+"','"+amount+"','"+address+"')")
        cursor.execute("commit")

        pg2_e_id.delete(0, 'end')
        pg2_e_name.delete(0, 'end')
        pg2_e_phone.delete(0, 'end')
        pg2_e_pass.delete(0, 'end')
        pg2_e_amount.delete(0, 'end')
        pg2_e_address.delete(0, 'end')
        pg2_show()
        MessageBox.showinfo("Insert Status", "Inserted Successfully")
        con.close()

def delete():
    id = pg2_e_id.get()
    if (id == ""):
        MessageBox.showinfo("Delete Status", "ID is compolsary for delete")
    else:
        con = mysql.connect(host="localhost", user="root",
                            password="ankon20158", database="test")
        cursor = con.cursor()
        cursor.execute("delete from bankdata where id='"+id+"'")
        cursor.execute("commit")

        pg2_e_id.delete(0, 'end')
        pg2_e_name.delete(0, 'end')
        pg2_e_phone.delete(0, 'end')
        pg2_e_pass.delete(0, 'end')
        pg2_e_amount.delete(0, 'end')
        pg2_e_address.delete(0, 'end')
        pg2_show()
        MessageBox.showinfo("Delete Status", "Deleted Successfully")
        con.close()

def update():
    id = pg2_e_id.get()
    name = pg2_e_name.get()
    phone = pg2_e_phone.get()
    amount = pg2_e_amount.get()
    address = pg2_e_address.get()

    if (id == "" or name == "" or phone == "" or amount == ""):
        MessageBox.showinfo(
            "Update Status", "All fields are required except Password")
    else:
        con = mysql.connect(host="localhost", user="root",
                            password="ankon20158", database="test")
        cursor = con.cursor()
        cursor.execute("update bankdata set name='"+name+"',phone='" +
                       phone + "',amount='"+amount + "',address='"+address + "' where id='"+id+"'")
        cursor.execute("commit")

        pg2_e_id.delete(0, 'end')
        pg2_e_name.delete(0, 'end')
        pg2_e_phone.delete(0, 'end')
        pg2_e_pass.delete(0, 'end')
        pg2_e_amount.delete(0, 'end')
        pg2_e_address.delete(0, 'end')
        pg2_show()
        MessageBox.showinfo("Update Status", "Updated Successfully")
        con.close()

def get():
    id = pg2_e_id.get()
    if (id == ""):
        MessageBox.showinfo("Fetch Status", "ID is compolsary to get data")
    else:
        con = mysql.connect(host="localhost", user="root",
                            password="ankon20158", database="test")
        cursor = con.cursor()
        cursor.execute("select * from bankdata where id='"+id+"'")
        rows = cursor.fetchall()

        for row in rows:
            pg2_e_name.insert(0, row[1])
            pg2_e_phone.insert(0, row[2])
            pg2_e_amount.insert(0, row[4])
            pg2_e_address.insert(0, row[5])

        con.close()

def pg2_show():
    con = mysql.connect(host="localhost", user="root",
                        password="ankon20158", database="test")
    cursor = con.cursor()
    cursor.execute("select * from bankdata")
    rows = cursor.fetchall()
    pg2_list.delete(0, pg2_list.size())

    for row in rows:
        insertData = '  ID:' + str(row[0]) + '  Name:' + row[1] + \
            '  Phone:' + row[2] + '  Amount:' + \
            str(row[4]) + '  Address:' + str(row[5])
        pg2_list.insert(pg2_list.size()+1, insertData)

    con.close()

def admin_check():
    pw = pg1_entry2.get()
    usr = pg1_entry.get()
    pg1_entry.delete(0, 'end')
    pg1_entry2.delete(0, 'end')
    con = mysql.connect(host="localhost", user="root",
                        password="ankon20158", database="test")
    cursor = con.cursor()
    cursor.execute("select * from admin")
    rows = cursor.fetchall()
    idfound = False
    password_admin = ""
    local_amount = ""

    for row in rows:
        if (usr == str(row[0])):
            idfound = True
            password_user = row[1]

    if (idfound != True):
        MessageBox.showinfo("Login Status", "Invalid ID!")
    else:
        if (pw != password_user):
            MessageBox.showinfo("Login Status", "Invalid Password!")
        else:
            show_frame(admin_page_2)

    con.close()

def admin_insert():
    name = apg1_entry.get()
    password = apg1_entry2.get()

    if (name == "" or password == ""):
        MessageBox.showinfo("Insert Status", "All fields are required")
    else:
        con = mysql.connect(host="localhost", user="root",
                            password="ankon20158", database="test")
        cursor = con.cursor()
        cursor.execute("insert into admin values('" +
                       name+"','"+password+"')")
        cursor.execute("commit")

        apg1_entry.delete(0, 'end')
        apg1_entry2.delete(0, 'end')

        apg2_show()
        MessageBox.showinfo("Insert Status", "Inserted Successfully")
        con.close()

def apg2_show():
    con = mysql.connect(host="localhost", user="root",
                        password="ankon20158", database="test")
    cursor = con.cursor()
    cursor.execute("select * from admin")
    rows = cursor.fetchall()
    apg2_list.delete(0, apg2_list.size())
    cnt = 1

    for row in rows:
        insertData = str(cnt) + ': ' + row[0]
        apg2_list.insert(apg2_list.size()+1, insertData)
        cnt = cnt+1

    con.close()

def user_check():
    pw = upg1_entry2.get()
    userid = upg1_entry.get()
    con = mysql.connect(host="localhost", user="root",
                        password="ankon20158", database="test")
    cursor = con.cursor()
    cursor.execute("select * from bankdata")
    rows = cursor.fetchall()
    idfound = False
    password_user = ""
    local_amount = ""
    upg1_entry.delete(0, 'end')
    upg1_entry2.delete(0, 'end')

    for row in rows:
        if (userid == str(row[0])):
            idfound = True
            password_user = row[3]
            global G_userid
            G_userid = str(row[0])
            global G_amount
            G_amount = str(row[4])
            global G_name
            G_name = row[1]

        insertName = "Welcome, " + G_name + "       "
    upg2_welcome = Label(user_page_2, text=insertName, font=('bold', 15))
    upg2_welcome.place(x=20, y=20)
    upg2_amount1 = Label(user_page_2, text="Your Current Amount:", font=('bold', 15))
    upg2_amount1.place(x=600, y=90)
    upg2_amount2 = Label(user_page_2, text=G_amount + "   ", font=('bold', 20))
    upg2_amount2.place(x=650, y=120)
    if (idfound != True):
        MessageBox.showinfo("Login Status", "Invalid ID!")
    else:
        if (pw != password_user):
            MessageBox.showinfo("Login Status", "Invalid Password!")
        else:
            show_frame(user_page_2)

    con.close()

def user_update():
    phone = upg2_e_phone.get()
    password = upg2_e_pass.get()
    address = upg2_e_address.get()

    if (phone == "" or password == "" or address == ""):
        MessageBox.showinfo("Update Status", "All fields are required")
    else:
        con = mysql.connect(host="localhost", user="root",
                            password="ankon20158", database="test")
        cursor = con.cursor()
        cursor.execute("update bankdata set password='"+password +
                       "',phone='"+phone + "',address='"+address + "' where id='"+G_userid+"'")
        cursor.execute("commit")

        upg2_e_pass.delete(0, 'end')
        upg2_e_phone.delete(0, 'end')
        upg2_e_address.delete(0, 'end')
        upg2_show()
        MessageBox.showinfo("Update Status", "Updated Successfully")
        con.close()

def user_withdraw():
    wd = upg2_e_trans.get()
    dpo = "0"

    if (wd == ""):
        MessageBox.showinfo("Update Status", "No amount written to withdraw")
    else:
        con = mysql.connect(host="localhost", user="root",
                            password="ankon20158", database="test")
        cursor = con.cursor()
        cursor.execute("insert into transactions values('" +
                       G_userid+"','"+wd+"','"+dpo+"')")
        cursor.execute("commit")

        upg2_e_trans.delete(0, 'end')
        global G_amount
        tmp = int(G_amount) - int(wd)
        G_amount = str(tmp)
        cursor.execute("update bankdata set amount='" +
                       G_amount + "' where id='"+G_userid+"'")
        cursor.execute("commit")

        upg2_show()
        MessageBox.showinfo("Update Status", "Withdrawn Successfully")
        con.close()

def user_deposit():
    dpo = upg2_e_trans.get()
    wd = "0"

    if (dpo == ""):
        MessageBox.showinfo("Update Status", "No amount written to deposit")
    else:
        con = mysql.connect(host="localhost", user="root",
                            password="ankon20158", database="test")
        cursor = con.cursor()
        cursor.execute("insert into transactions values('" +
                       G_userid+"','"+wd+"','"+dpo+"')")
        cursor.execute("commit")

        upg2_e_trans.delete(0, 'end')
        global G_amount
        tmp = int(G_amount) + int(dpo)
        G_amount = str(tmp)
        cursor.execute("update bankdata set amount='" +
                       G_amount + "' where id='"+G_userid+"'")
        cursor.execute("commit")

        upg2_show()
        MessageBox.showinfo("Update Status", "deposited Successfully")
        con.close()

def upg2_show():
    insertName = "Welcome, " + G_name + "       "
    upg2_welcome = Label(
        user_page_2, text=insertName, font=('bold', 15))
    upg2_welcome.place(x=20, y=20)
    upg2_amount1 = Label(
        user_page_2, text="Your Current Amount:", font=('bold', 15))
    upg2_amount1.place(x=600, y=90)
    upg2_amount2 = Label(
        user_page_2, text=G_amount + "    ", font=('bold', 20))
    upg2_amount2.place(x=650, y=120)

root = Tk()
root.geometry("900x400")
root.title("Bank Management Project")
root.rowconfigure(0, weight=1)
root.columnconfigure(0, weight=1)


page0 = Frame(root)
admin_page_1 = Frame(root)
user_page_1 = Frame(root)
c_admin_page = Frame(root)
admin_page_2 = Frame(root)
user_page_2 = Frame(root)


for frame in (page0, admin_page_1, admin_page_2, user_page_1, user_page_2, c_admin_page):
    frame.grid(row=0, column=0, sticky='nsew')

def show_frame(frame):
    frame.tkraise()

show_frame(page0)

pg0_button = Button(page0, text='USER', font=(
    'Arial', 20, 'bold'), command=lambda: show_frame(user_page_1))
pg0_button.place(x=100, y=90)

pg0_button = Button(page0, text='ADMIN', font=(
    'Arial', 20, 'bold'), command=lambda: show_frame(admin_page_1))
pg0_button.place(x=350, y=90)

# ============= admin login page =========
pg1_label = Label(admin_page_1, text='Username', font=('Arial', 15, 'bold'))
pg1_label.place(x=50, y=100)

pg1_entry = Entry(admin_page_1)
pg1_entry.place(x=170, y=106)

pg1_label2 = Label(admin_page_1, text='Password', font=('Arial', 15, 'bold'))
pg1_label2.place(x=50, y=150)

pg1_entry2 = Entry(admin_page_1)
pg1_entry2.place(x=170, y=155)

pg1_button = Button(admin_page_1, text='LOGIN', font=(
    'Arial', 13, 'bold'), command=admin_check)
pg1_button.place(x=170, y=200)

pg1_button = Button(admin_page_1, text='Back', font=(
    'Arial', 13, 'bold'), command=lambda: show_frame(page0))
pg1_button.place(x=750, y=350)

# -------------- create admin page --------------------------------
apg1_label = Label(c_admin_page, text='Username', font=('Arial', 15, 'bold'))
apg1_label.place(x=50, y=100)

apg1_entry = Entry(c_admin_page)
apg1_entry.place(x=170, y=106)

apg1_label2 = Label(c_admin_page, text='Password', font=('Arial', 15, 'bold'))
apg1_label2.place(x=50, y=150)

apg1_entry2 = Entry(c_admin_page)
apg1_entry2.place(x=170, y=155)

apg2_list = Listbox(c_admin_page, width=70)
apg2_list.place(x=350, y=60)

apg1_button = Button(c_admin_page, text='Create', font=(
    'Arial', 13, 'bold'), command=admin_insert)
apg1_button.place(x=170, y=200)

apg2_button = Button(c_admin_page, text='Back', font=(
    'Arial', 13, 'bold'), command=lambda: show_frame(admin_page_2))
apg2_button.place(x=750, y=350)

apg2_show()

# ============= user login page =========
upg1_label = Label(user_page_1, text='ID', font=('Arial', 15, 'bold'))
upg1_label.place(x=50, y=100)

upg1_entry = Entry(user_page_1)
upg1_entry.place(x=170, y=106)

upg1_label2 = Label(user_page_1, text='Password', font=('Arial', 15, 'bold'))
upg1_label2.place(x=50, y=150)

upg1_entry2 = Entry(user_page_1)
upg1_entry2.place(x=170, y=155)

upg1_button = Button(user_page_1, text='LOGIN', font=(
    'Arial', 13, 'bold'), command=user_check)
upg1_button.place(x=170, y=200)

upg1_button = Button(user_page_1, text='Back', font=(
    'Arial', 13, 'bold'), command=lambda: show_frame(page0))
upg1_button.place(x=750, y=350)

# ============= admin Page 2 =========
pg2_id = Label(admin_page_2, text='Enter ID', font=('bold', 10))
pg2_id.place(x=20, y=30)

pg2_name = Label(admin_page_2, text='Enter Name', font=('bold', 10))
pg2_name.place(x=20, y=60)

pg2_phone = Label(admin_page_2, text='Enter Phone', font=('bold', 10))
pg2_phone.place(x=20, y=90)

pg2_pass = Label(admin_page_2, text='Enter Password', font=('bold', 10))
pg2_pass.place(x=20, y=150)

pg2_amount = Label(admin_page_2, text='Enter Amount', font=('bold', 10))
pg2_amount.place(x=20, y=180)

pg2_address = Label(admin_page_2, text='Enter Address', font=('bold', 10))
pg2_address.place(x=20, y=120)



pg2_e_id = Entry(admin_page_2)
pg2_e_id.place(x=150, y=30)

pg2_e_name = Entry(admin_page_2)
pg2_e_name.place(x=150, y=60)

pg2_e_phone = Entry(admin_page_2)
pg2_e_phone.place(x=150, y=90)

pg2_e_address = Entry(admin_page_2)
pg2_e_address.place(x=150, y=120)

pg2_e_pass = Entry(admin_page_2)
pg2_e_pass.place(x=150, y=150)

pg2_e_amount = Entry(admin_page_2)
pg2_e_amount.place(x=150, y=180)

pg2_insert = Button(admin_page_2, text='Insert', font=(
    "italic", 10), bg="white", command=insert)
pg2_insert.place(x=20, y=300)

pg2_delete = Button(admin_page_2, text='Delete', font=(
    "italic", 10), bg="white", command=delete)
pg2_delete.place(x=70, y=300)

pg2_update = Button(admin_page_2, text='Update', font=(
    "italic", 10), bg="white", command=update)
pg2_update.place(x=130, y=300)

pg2_get = Button(admin_page_2, text='Get', font=(
    "italic", 10), bg="white", command=get)
pg2_get.place(x=190, y=300)

pg2_get = Button(admin_page_2, text='Create a new admin', font=(
    "italic", 10), bg="white", command=lambda: show_frame(c_admin_page))
pg2_get.place(x=600, y=300)

pg2_logout = Button(admin_page_2, text='Logout', font=(
    "italic", 10), bg="white", command=lambda: show_frame(page0))
pg2_logout.place(x=800, y=10)

pg2_list = Listbox(admin_page_2, width=90)
pg2_list.place(x=290, y=60)
pg2_show()

# ============= user Page 2 =========

upg2_phone = Label(user_page_2, text='Enter Phone', font=('bold', 10))
upg2_phone.place(x=20, y=140)

upg2_pass = Label(user_page_2, text='Enter Password', font=('bold', 10))
upg2_pass.place(x=20, y=170)

upg2_address = Label(user_page_2, text='Enter Address', font=('bold', 10))
upg2_address.place(x=20, y=200)

upg2_witdepo = Label(user_page_2, text='Withdraw/deposit', font=('bold', 10))
upg2_witdepo.place(x=470, y=200)

upg2_toup = Label(
    user_page_2, text='To update your password, address and phone number:', font=('bold', 10))
upg2_toup.place(x=20, y=110)

upg2_e_phone = Entry(user_page_2)
upg2_e_phone.place(x=150, y=140)

upg2_e_pass = Entry(user_page_2)
upg2_e_pass.place(x=150, y=170)

upg2_e_address = Entry(user_page_2)
upg2_e_address.place(x=150, y=200)

upg2_e_trans = Entry(user_page_2)
upg2_e_trans.place(x=600, y=200)

upg2_update = Button(user_page_2, text='Update', font=(
    "italic", 10), bg="white", command=user_update)
upg2_update.place(x=130, y=300)

upg2_withdraw = Button(user_page_2, text='Withdraw', font=(
    "italic", 10), bg="white", command=user_withdraw)
upg2_withdraw.place(x=600, y=230)

upg2_deposit = Button(user_page_2, text='Deposit', font=(
    "italic", 10), bg="white", command=user_deposit)
upg2_deposit.place(x=670, y=230)

upg2_logout = Button(user_page_2, text='Logout', font=(
    "italic", 10), bg="white", command=lambda: show_frame(page0))
upg2_logout.place(x=750, y=10)

upg2_show()

root.mainloop()