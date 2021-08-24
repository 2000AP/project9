
//********************************************* Bank Management System **********************************************************


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int mainExit;
int d = 500, s = 2000;
void menu();
void close();
struct date
{
    int day, month, year;
};
struct
{

    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

} add, upd, check, rem, transaction;


//used for calculation of Interest
float interest(float t, float amount, int rate)
{
    float SI;
    SI = (rate * t * amount) / 100.00;
    return (SI);
}


//Used to create new account
void newAccount(void)
{
    int choice;
    FILE *fp;
    fp = fopen("record.dat", "a+");
account_no:
    system("cls");
    printf("\n\n\t\t\t\t * Create Account * \t\t\t\t");
    printf("\n\n\t\t>> Enters Todays Date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &add.deposit.day, &add.deposit.month, &add.deposit.year);
    printf("\n\t\t>> Enter Account Number: ");
    scanf("%d", &check.acc_no);
    while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account no. already in use!");
            Sleep(d);
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\n\t\t>> Enter Name: ");
    scanf(" %s", add.name);
    printf("\n\t\t>> Enter Date of Birth: ");
    scanf("%d/%d/%d", &add.dob.day, &add.dob.month, &add.dob.year);
    printf("\n\t\t>> Enter Age: ");
    scanf("%d", &add.age);
    printf("\n\t\t>> Enter Address: ");
    scanf("%s", &add.address);
    printf("\n\t\t>> Enter Citizenship: ");
    scanf("%s", &add.citizenship);
    printf("\n\t\t>> Enter Mobile No.: ");
    scanf("%lf", &add.phone);
    printf("\n\t\t>> Enter the Amount want to Deposite: $");
    scanf("%f", &add.amt);
    printf("\n\t\t>> Enter type of Account:    \n\t\t\t#Saving Account.    \n\t\t\t#Current Account.    \n\t\t\t#Fixed1 (For 1 Year) Account.    \n\t\t\t#Fixed2 (For 2 Year) Account.    \n\t\t\t#Fixed3 (For 3 Year) Account.     \n\t\tEnter your choice: ");
    scanf("%s", add.acc_type);

    fprintf(fp, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);

    fclose(fp);
add_invalid:
    printf("\nAccount Created Succesfully.");
    printf("\n\n\n\t\tPress 1 to go to Main Menu or 0 to Exit: ");
    scanf("%d", &mainExit);
    system("cls");
    Sleep(d);
    if (mainExit == 1)
    {
        menu();
    }
    else if (mainExit == 0)
    {
        close();
    }
    else
    {
        printf("\n\nEntered an Invalid Choice!!!!");
        goto add_invalid;
    }
}



//Used to make any update in Account Details
void update(void)
{
    int choice, test = 0;
    FILE *oldRec, *newRec;
    oldRec = fopen("record.dat", "r");
    newRec = fopen("new.dat", "w");
    printf("\nEnter the Account Number of customer whose info you want to change: ");
    scanf("%d", &upd.acc_no);

    while (fscanf(oldRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;
            printf("\nWhich information do you want to change?    \n\t1. Address    \n\t2. Phone No.    \n\nEnter your Choice (from 1 and 2): ");
            scanf("%d", &choice);
            system("cls");
            if (choice == 1)
            {
                printf("Enter new Address: ");
                scanf("%s", upd.address);
                fprintf(newRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                system("cls");
                Sleep(d);
                printf("\nAddress Updated!");
            }
            else if (choice == 2)
            {
                printf("Enter new Phone Number: ");
                scanf("%lf", &upd.phone);
                fprintf(newRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                system("cls");
                Sleep(d);
                printf("\nPhone No. Updated!");
            }
            else
            {
                fprintf(newRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
            }
        update2_invalid:
            printf("\n\n\nEnter 1 to go to main Menu and 0 to Exit: ");
            scanf("%d", &mainExit);
            system("cls");
            if (mainExit == 1)
            {
                menu();
            }
            else if (mainExit == 0)
            {
                close();
            }
            else
            {
                printf("Invalid! choice");
                goto update2_invalid;
            }
        }
    }
    fclose(oldRec);
    fclose(newRec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1)
    {
        system("cls");
        printf("Record not Found.");
    update_invalid:
        printf("\n\nEnter 0 to Try Again, 1 to Return to Main Menu and 2 to Exit: ");
        scanf("%d", &mainExit);
        system("cls");
        if (mainExit == 0)
        {
            update();
        }
        else if (mainExit == 1)
        {
            menu();
        }
        else if (mainExit == 2)
        {
            close();
        }
        else
        {
            printf("Invalid! Choice");
            goto update_invalid;
        }
    }
    else
    {
    update1_invalid:
        printf("\n\n\nEnter 1 to go to main Menu and 0 to Exit: ");
        scanf("%d", &mainExit);
        system("cls");
        if (mainExit == 1)
        {
            menu();
        }
        else if (mainExit == 0)
        {
            close();
        }
        else
        {
            printf("Invalid! choice");
            goto update1_invalid;
        }
    }
}




//Used for purpose of Transaction
void transact(void)
{
    int choice, test = 0;
    FILE *oldRec, *newRec;
    oldRec = fopen("record.dat", "r");
    newRec = fopen("new.dat", "w");
    printf("Enter the Account Number of the Customer: ");
    scanf("%d", &transaction.acc_no);

    while (fscanf(oldRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            if (strcmpi(add.acc_type, "fixed1") == 0 || strcmpi(add.acc_type, "fixed2") == 0 || strcmpi(add.acc_type, "fixed3") == 0)
            {
                printf("\a\a\a\nYou cannot Deposite or Withdraw cash from Fixed Account.");
                Sleep(s);
                system("cls");
                menu();
            }
            printf("\n\nDo You want to:-            \n\t1. Deposite.            \n\t2. Withdraw.            \nEnter your choice: ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("\nEnter the Amount you want to deposite: $");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(newRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                printf("\n\n\tAmount Deposited Successfully!");
            }
            else
            {
                printf("\nEnter the Amount you want to Withdraw: $");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                printf("\n\n\tAmount Withdrawn Successfully!");
            }
        }
        else
        {
            fprintf(newRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
        }
    transact1_invalid:
        printf("\n\n\nEnter 1 to go to main Menu and 0 to Exit: ");
        scanf("%d", &mainExit);
        system("cls");
        if (mainExit == 1)
        {
            menu();
        }
        else if (mainExit == 0)
        {
            close();
        }
        else
        {
            printf("Invalid! choice");
            goto transact1_invalid;
        }
    }
    fclose(oldRec);
    fclose(newRec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {
        printf("\n\nRecord not found!");
    transact_invalid:
        printf("\n\nEnter 0 to try again, 1 to retrun to Main Menu and 2 to Exit: ");
        scanf("%d", &mainExit);
        system("cls");
        if (mainExit == 0)
        {
            transact();
        }
        else if (mainExit == 1)
        {
            menu();
        }
        else if (mainExit == 2)
        {
            close();
        }
        else
        {
            printf("Invalid! Choice");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\n\nEnter 1 to go to Main Menu or 0 to Exit: ");
        scanf("%d", &mainExit);
        if (mainExit == 1)
        {
            menu();
        }
        else
        {
            close();
        }
    }
}





//To check details of existing account
void see(void)
{
    FILE *fp;
    int rate, test = 0;
    int choice;
    float time;
    float intrst;
    fp = fopen("record.dat", "r");
    printf("\n\nDo you want to check by:    \n\t1. Account No.    \n\t2. Name.    \nEnter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("\n\nEnter Account No.: ");
        scanf("%d", &check.acc_no);
        while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
        {
            if (add.acc_no == check.acc_no)
            {
                system("cls");
                test = 1;
                printf("\n\nAccount No.: %d        \nName: %s        \nDate of Birth: %d/%d/%d        \nAge: %d        \nAddress: %s        \nCitizenship: %s        \nPhone No.: %.0lf        \nAccount Type: %s        \nAmount Deposited: $%.2f        \nDate of Deposite: %d/%d/%d", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                if (strcmpi(add.acc_type, "Fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%0.2f as interest on %d/%d/%d", intrst, add.deposit.day, add.deposit.month, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "Fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%0.2f as interest on %d/%d/%d", intrst, add.deposit.day, add.deposit.month, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "Fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%0.2f as interest on %d/%d/%d", intrst, add.deposit.day, add.deposit.month, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "Saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%0.2f as interest on %d of every month.", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "Current") == 0)
                {
                    printf("\n\nYou will get no interest!");
                }
            }
        }
    }
    else if (choice == 2)
    {
        printf("\n\nEnter Name: ");
        scanf("%s", &check.name);
        while (fscanf(fp, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
        {
            if (strcmpi(add.name, check.name) == 0)
            {
                system("cls");
                test = 1;
                printf("\n\nAccount No.: %d        \nName: %s        \nDate of Birth: %d/%d/%d        \nAge: %d        \nAddress: %s        \nCitizenship: %s        \nPhone No.: %.0lf        \nAccount Type: %s        \nAmount Deposited: $%.2f        \nDate of Deposite: %d/%d/%d", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
                if (strcmpi(add.acc_type, "Fixed1") == 0)
                {
                    time = 1.0;
                    rate = 9;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%0.2f as interest on %d/%d/%d", intrst, add.deposit.day, add.deposit.month, add.deposit.year + 1);
                }
                else if (strcmpi(add.acc_type, "Fixed2") == 0)
                {
                    time = 2.0;
                    rate = 11;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%0.2f as interest on %d/%d/%d", intrst, add.deposit.day, add.deposit.month, add.deposit.year + 2);
                }
                else if (strcmpi(add.acc_type, "Fixed3") == 0)
                {
                    time = 3.0;
                    rate = 13;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%0.2f as interest on %d/%d/%d", intrst, add.deposit.day, add.deposit.month, add.deposit.year + 3);
                }
                else if (strcmpi(add.acc_type, "Saving") == 0)
                {
                    time = (1.0 / 12.0);
                    rate = 8;
                    intrst = interest(time, add.amt, rate);
                    printf("\n\nYou will get $%0.2f as interest on %d of every month.", intrst, add.deposit.day);
                }
                else if (strcmpi(add.acc_type, "Current") == 0)
                {
                    printf("\n\nYou will get no interest!");
                }
            }
        }
    }
    fclose(fp);

    if (test != 1)
    {
        system("cls");
        printf("\n\nRecord not Found!\a\a\a");
    see_invalid:
        printf("\n\nEnter 0 to Try Again, 1 to return to Main Menu and 2 to Exit: ");
        scanf("%d", &mainExit);
        if (mainExit == 0)
        {
            see();
        }
        else if (mainExit == 1)
        {
            menu();
        }
        else if (mainExit = 2)
        {
            close();
        }
        else
        {
            system("cls");
            printf("\nInvalid choice!");
            goto see_invalid;
        }
    }
    else
    {
        printf("\n\nEnter 1 to go to Main Menu and 0 to Exit: ");
        scanf("%d", &mainExit);
        if (mainExit == 1)
        {
            system("cls");
            menu();
        }
        else
        {
            system("cls");
            close();
        }
    }
}




//to delete previous account
void erase(void)
{
    int test = 0;
    FILE *oldRec, *newRec;
    oldRec = fopen("record.dat", "r");
    newRec = fopen("new.dat", "w");
    printf("\n\nEnter the Account No. you want to Erase: ");
    scanf("%d", &rem.acc_no);
    while (fscanf(oldRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        if (add.acc_no != rem.acc_no)
        {
            fprintf(newRec, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d\n", add.acc_no, add.name, add.dob.day, add.dob.month, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.day, add.deposit.month, add.deposit.year);
        }
        else
        {
            test++;
            printf("\n\nRecord Deleted Successfully!");
        }
    }
    fclose(oldRec);
    fclose(newRec);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 0)
    {
        printf("\nRecord not found!\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d", &mainExit);
        if (mainExit == 0)
        {
            erase();
        }
        else if (mainExit == 1)
        {
            menu();
        }
        else if (mainExit == 2)
        {
            close();
        }
        else
        {
            printf("\nInvalid Choice!\a\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &mainExit);
        system("cls");
        if (mainExit == 1)
        {
            menu();
        }
        else
        {
            close();
        }
    }
}




//use to see the list of account
void viewList(void)
{
    FILE *list;
    list = fopen("record.dat", "r");
    int test = 0;
    system("cls");
    printf("\nAccount No.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    while (fscanf(list, "%d %s %d/%d/%d %d %s %s %.0lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.day, &add.dob.month, &add.dob.year, &add.age, &add.address, &add.citizenship, &add.phone, &add.acc_type, &add.amt, &add.deposit.day, &add.deposit.month, &add.deposit.year) != EOF)
    {
        printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }
    fclose(list);
    if (test == 0)
    {
        system("cls");
        printf("\nNo Record!!\n");
    }
viewList_invalid:
    printf("\nEnter 0 to Try Again, 1 to return to Main Menu and 2 to Exit: ");
    scanf("%d", &mainExit);
    system("cls");
    if (mainExit == 0)
    {
        viewList();
    }
    else if (mainExit == 1)
    {
        menu();
    }
    else if (mainExit == 2)
    {
        close();
    }
    else
    {
        printf("\nInvalid Choice!!\a\a");
    }
}



//used to exit
void close(void)
{
    printf("\n\n\tThanks! for Using Patil Bank Management System");
}



//Used to show menu bar
void menu(void)
{
    int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\t\t* Account Bank Management Sytem *");
    printf("\n\n\n\t\t\t\tWelcome to Main Menu: ");
    printf("\n\n\tEnter the key you want to do: ");
    Sleep(d);
    printf("\n\n\t\t>> 1. Creat new Account: ");
    Sleep(d);
    printf("\n\t\t>> 2. Update Information of Existing Account: ");
    Sleep(d);
    printf("\n\t\t>> 3. For Transactions: ");
    Sleep(d);
    printf("\n\t\t>> 4. Check the details of Existing Account: ");
    Sleep(d);
    printf("\n\t\t>> 5. Removing Existing Account: ");
    Sleep(d);
    printf("\n\t\t>> 6. View Customer's list: ");
    Sleep(d);
    printf("\n\t\t>> 7. Exit: ");
    Sleep(d);
    printf("\nEnter your Choice: ");
    scanf("%d", &choice);

    system("cls");
    switch (choice)
    {
    case 1:
        newAccount();
        break;

    case 2:
        update();
        break;
    case 3:
        transact();
        break;
    case 4:
        see();
        break;
    case 5:
        erase();
        break;
    case 6:
        viewList();
        break;
    case 7:
        close();
        break;

    default:
        break;
    }
}


//Main Function
int main()
{
    char Pass[10], Password[10] = "Pass@2000";
    printf("\n\n\t\t\t\t~ ~ ~ Welcome! to PATIL BANK MANAAGEMENT SYSTEM ~ ~ ~");
    printf("\n\n\t\t Enter the Password: ");
    scanf("%s", &Pass);
    if (strcmp(Pass, Password) == 0)
    {
        printf("\n\nEntered Right Password.\n");
        printf("Loading.......");
        Sleep(s);
        system("cls");
        menu();
    }
    else
    {
        printf("\n\nEntered a wrong Password.\n");
    login_try:
        printf("Loading........");
        Sleep(s);
        printf("\nPress 1 to Try Again or 0 to Exit: ");
        scanf("%d", &mainExit);
        if (mainExit == 1)
        {
            system("cls");
            main();
        }
        else if (mainExit == 0)
        {
            system("cls");
            close();
        }
        else
        {
            printf("\nInvalid Choice!!");
            system("cls");
            goto login_try;
        }
    }

    return 0;
}
