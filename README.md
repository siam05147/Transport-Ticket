# Transport-Ticket
🚌 Bus Booking System (C – Console Edition)
A lightweight, file-based bus reservation system written in pure C with no external dependencies.
Compile once, run anywhere (Windows / Linux / macOS).




What we Get

1.User & Admin roles

2.Sign-up / Login / Password-change

3.Seat reservation (1-35) with conflict check

4.Ticket printing (console)

5.Dummy payment gateway (bkash / nagad)

6.Daily report for admin

7.All data stored in simple .txt files – easy to inspect or backup


FOLDER/FILE MAP

.
├─ auth.c          – login, signup, password change  
├─ manage.c        – seat booking & availability  
├─ booking.c       – ticket printing  
├─ payment.c       – payment UI (dummy)  
├─ report.c        – daily report generator  
├─ main.c          – menus & dashboard router  
├─ users.txt       – auto-created (CSV)  
├─ bookings.txt    – auto-created (CSV)  
└─ README.md       – this file


COMPILE & RUN

# GCC (Linux / macOS / MinGW-W64 on Windows)
gcc -std=c99 -Wall -o bus main.c

# Run
./bus
No libraries needed – uses only stdio, stdlib, string, time.


DEFAULT ADMIN


| Username | Password |
| -------- | -------- |
| admin    | admin123 |
(Created automatically on first run if users.txt is missing)

CSV Formats


users.txt
username,password,phone,role
Example:
admin,admin123,0000000000,admin
bookings.txt
name,seat,source,destination
Example:
Rakib,5,Dhaka,Chittagong


MAIN MENU


 1 Admin Login  → Admin Dashboard (view-all / report / password)
 2 User Login   → User Dashboard (book / view / print / password)
 3 Create Account
 0 Exit

 FEATURES THAT WORK

 
 | Feature                    | Status |
| -------------------------- | ------ |
| Sign-Up                    | ✅      |
| Login / Logout             | ✅      |
| Role-based menus           | ✅      |
| Seat booking (1-35)        | ✅      |
| Duplicate seat guard       | ✅      |
| Ticket printing            | ✅      |
| Password change            | ✅      |
| Daily report (date filter) | ✅      |
| Dummy payment              | ✅      |


 Known Limitations (Happy-Hacking List)

 
1.No encryption – passwords stored plain-text
2.No input validation – phone/format unchecked
3.No race-condition guard – concurrent booking may overlap
4.Hard-coded fare – always 150 tk
5.Stub functions – cancel, edit, search routes print “coming soon”
6.Case-sensitive passwords – no trim/lower
7.No 3-try lockout – wrong password exits program
8.No backup / audit log – delete a txt = lose history


 Suggested Next Steps

 
1.Add flock() or Windows file-locking to prevent double booking
2.Replace scanf() with fgets() + sscanf() for safer parsing
3.Hash passwords (SHA-256 or bcrypt)
4.Validate phone & email regex
5.Add fare table per route
6.Implement real payment SDK hooks
7.Convert to SQLite for concurrency & ACID


ONE LINE BUILD & RUN
gcc -std=c99 -Wall -o bus main.c && ./bus


