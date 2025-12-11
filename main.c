#include <stdio.h>
#include <string.h>

/* bring in all functions */
#include "auth.c"
#include "booking.c"
#include "manage.c"
#include "payment.c"
#include "report.c"

/* stubs for unfinished features */
void searchBooking()
{
    puts("Search booking coming soon.");
}
void editBooking()
{
    puts("Edit booking coming soon.");
}
void cancelBooking()
{
    puts("Cancel booking coming soon.");
}
void addRoute()
{
    puts("Add route coming soon.");
}
void viewPendingPayments()
{
    puts("Pending payments coming soon.");
}

/* ---------- admin dashboard ---------- */
void adminMenu(void)
{
    int choice;
    do {
        puts("\n=== ADMIN DASHBOARD ===");
        puts("1. View all bookings");
        puts("2. Cancel booking");
        puts("3. Daily report");
        puts("4. Add new route");
        puts("5. Change my password");
        puts("0. Logout");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewAllBookings(); break;
            case 2: cancelBooking(); break;
            case 3: generateDailyReport(); break;
            case 4: addRoute(); break;
            case 5: changePassword(); break;
            case 0: puts("Admin logged out."); break;
            default: puts("Invalid choice.");
        }
    } while (choice != 0);
}

/* ---------- user dashboard ---------- */
void userMenu(void)
{
    int choice;
    do {
        puts("\n=== USER DASHBOARD ===");
        puts("1. Book a ticket");
        puts("2. View my reservations");
        puts("3. Edit reservation");
        puts("4. Print ticket");
        puts("5. Check available seats");
        puts("6. Change my password");
        puts("0. Logout");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: bookTicket(); processPayment(); break;
            case 2: viewAllBookings(); break;
            case 3: editBooking(); break;
            case 4: ticketMenu(); break;
            case 5: checkSeatAvailability(); break;
            case 6: changePassword(); break;
            case 0: puts("  User logged out."); break;
            default: puts("  Invalid choice.");
        }
    } while (choice != 0);
}

/* ---------- welcome screen ---------- */
void initialMenu(void)
{
    char role[20];
    int choice;
    do {
        puts("\n=== BUS BOOKING SYSTEM ===");
        puts("1. Admin login");
        puts("2. User login");
        puts("3. Create new account");
        puts("0. Exit");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            if (strcmp(secureLogin(role), "Success") == 0)
                strcmp(role, "admin") == 0 ? adminMenu() : userMenu();
        } else if (choice == 3) {
            userSignup();
        } else if (choice == 0) {
            puts("  Good-bye!");
        } else {
            puts("  Invalid choice.");
        }
    } while (choice != 0);
}

/* ---------- start here ---------- */
int main(void)
{
    initialMenu();
    return 0;
}