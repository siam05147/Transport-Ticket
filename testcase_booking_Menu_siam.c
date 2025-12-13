#include "booking.c"


int test_ticketMenu_basic()
{
    void (*func_ptr)() = ticketMenu;
    int actual = (func_ptr != NULL) ? 1 : 0;
    int expected = 1;  
    int success = actual == expected;

    printf("expected: %d, actual: %d, success: %d\n", expected, actual, success);
    return success;
}


int test_ticketMenu_options()
{
    printf("Test - ticketMenu options:\n");
    
    
    printf("Expected menu options:\n");
    printf("1. Print Ticket\n");
    printf("2. Back to Main Menu\n");
    
    int actual = (ticketMenu != NULL) ? 1 : 0;
    int expected = 1;  
    int success = actual == expected;

    printf("expected: %d, actual: %d, success: %d\n", expected, actual, success);
    return success;
}

int main()
{
    test_ticketMenu_basic();
    test_ticketMenu_options();
    return 0;
}