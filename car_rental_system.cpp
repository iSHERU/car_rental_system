#include <iostream>
using namespace std;

class Vehicle
{
public:
    string name;
    int model;
    string colour;
    int capacity;
    bool available;
    int slot[30];

    Vehicle() {}

    Vehicle(string name, int model, string colour, int capacity, bool available)
        : name(name), model(model), colour(colour), capacity(capacity), available(available) {}
};

class car : public Vehicle
{
public:
    int price;

    car() {}

    car(string name, int price, int model, string colour, int capacity, bool available)
        : Vehicle(name, model, colour, capacity, available), price(price) {}
};

class User : public Vehicle
{
public:
    string password;
    int phone_num;
    string address;
    int total_amount;
    string booking[5];
    string BookingDates[5];

    User() {}

    User(string name, string password, int phone_num, string address)
        : Vehicle(name, 0, "None", 0, true), password(password), phone_num(phone_num), address(address), total_amount(0) {}
};

class Rental_system
{
public:
    car cars[10];
    User users[10];

    Rental_system()
    {
        for (int i = 0; i < 10; i++)
        {
            cars[i].name = "Nill";
            cars[i].price = 0;
            cars[i].model = 0;
            cars[i].colour = "None";
            cars[i].capacity = 0;
            cars[i].available = true;
            users[i].name = "None";
            users[i].password = "None";
            users[i].phone_num = 0;
            for (int j = 0; j < 5; j++)
            {
                users[i].booking[j] = "Nill";
                users[i].BookingDates[j] = "0";
            }
            users[i].total_amount = 0;
            users[i].address = "None";
            for (int j = 0; j < 30; j++)
            {
                cars[i].slot[j] = 0;
            }
        }
    }

    void add_car(string name, int price, int model, string colour, int capacity, bool available)
    {
        int count = 0;
        for (int i = 0; i < 10; i++)
        {
            if (cars[i].name == "Nill" && cars[i].price == 0 && cars[i].model == 0 && cars[i].colour == "None" && cars[i].capacity == 0)
            {
                cars[i].name = name;
                cars[i].price = price;
                cars[i].model = model;
                cars[i].colour = colour;
                cars[i].capacity = capacity;
                count++;
                break;
            }
        }
        if (count > 9)
        {
            cout << endl
                 << "No slot available for Cars";
        }
    }

    void add_User(string name, string password, int phone_num, string address)
    {
        int count = 0;
        for (int i = 0; i < 10; i++)
        {
            if (users[i].name == "None" && users[i].password == "None" && users[i].phone_num == 0 && users[i].address == "None")
            {
                users[i].name = name;
                users[i].password = password;
                users[i].phone_num = phone_num;
                users[i].address = address;
                cout << endl
                     << "CONGRATULATIONS Account successfully created....." << endl;
                count++;
                break;
            }
        }
    }

    void login_check(string name, string password)
    {
        int count = 0;
        for (int i = 0; i < 10; i++)
        {
            if (name == users[i].name && password == users[i].password)
            {
                cout << "LOGIN SUCCESSFUL....." << endl;
                cout << endl
                     << "Note: YOU CAN ONLY BOOK MAXIMUM 5 CARS AND BOOKING DATE WILL BE FOR THIS MONTH ONLY....." << endl;
                cout << "DON'T FORGET TO VISIT VIEW MENU TO CHECK THE AVAILABLE VEHICLES..." << endl;
                cout << endl
                     << "-------BOOKING MENU-------";
                int option;
                do
                {
                    cout << endl
                         << "press 1 to view vehicle details";
                    cout << endl
                         << "press 2 to book vehicle ";
                    cout << endl
                         << "press 3 to view account details";
                    cout << endl
                         << "press 4 to logout";
                    cout << endl
                         << "press 5 to remove booking";
                    cout << endl
                         << "your option : ";
                    cin >> option;

                    if (option == 1)
                    {
                        view_vehicle();
                    }
                    if (option == 2)
                    {
                        booking(i);
                    }
                    if (option == 3)
                    {
                        account_details(i);
                    }
                    if (option == 5)
                    {
                        remove_car(i);
                    }
                } while (option != 4);
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << endl
                 << "Incorrect Username or Password";
        }
    }

    void view_vehicle()
    {
        cout << endl
             << "--------------------VEHICLE DETAILS-----------------------------";
        for (int i = 0; i < 10; i++)
        {
            cout << endl
                 << i + 1 << ". NAME: " << cars[i].name << ", PRICE: " << cars[i].price << ", MODEL: " << cars[i].model << ", COLOUR: " << cars[i].colour << ", CAPACITY: " << cars[i].capacity << endl;
        }
    }

    void booking(int p)
    {
        string name;
        int date;
        int counter1 = 0;
        int counter3 = 0;
        do
        {
            cout << endl
                 << "Enter the name of the vehicle you want to book : ";
            cin >> name;
            for (int i = 0; i < 10; i++)
            {
                if (cars[i].name == name)
                {
                    int counter = 0;
                    do
                    {
                        cout << "enter the booking date : ";
                        cin >> date;
                        for (int j = 0; j < 30; j++)
                        {
                            if (date == cars[i].slot[j])
                            {
                                break;
                            }
                            if (date != cars[i].slot[j] && date != 0)
                            {
                                for (int m = 0; m < 5; m++)
                                {
                                    if (users[p].booking[m] == "Nill")
                                    {
                                        users[p].booking[m] = cars[i].name;
                                        cars[i].slot[j] = date;
                                        users[p].total_amount = users[p].total_amount + cars[i].price;
                                        users[p].BookingDates[m] = to_string(date);
                                        counter3++;
                                        break;
                                    }
                                }
                                counter++;
                                break;
                            }
                        }
                        if (counter > 0)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Sorry, the car is already booked for this date" << endl;
                        }
                    } while (counter == 0);
                    counter1++;
                }
                if (counter1 > 0)
                {
                    break;
                }
            }
            if (counter1 == 0)
            {
                cout << "Invalid vehicle name";
            }
            if (counter3 == 0)
            {
                cout << endl
                     << "You have already booked 5 cars";
                break;
            }
            if (counter1 > 0)
            {
                cout << "Vehicle booked" << endl;
                cout << "Visit Account details to view your Bookings" << endl;
                break;
            }
        } while (counter1 == 0);
    }

    void account_details(int k)
    {
        cout << endl
             << "--------Account Details--------" << endl;
        cout << endl
             << "Name : " << users[k].name;
        cout << endl
             << "Password : " << users[k].password;
        cout << endl
             << "Phone Number : " << users[k].phone_num;
        cout << endl
             << "Address : " << users[k].address << endl;
        cout << endl
             << "-------Your Bookings-------";
        for (int i = 0; i < 5; i++)
        {
            if (users[k].booking[i] != "Nill")
            {
                cout << endl
                     << i + 1 << ". " << users[k].booking[i] << " on " << users[k].BookingDates[i] << "This Month";
            }
        }
        cout << endl
             << endl
             << "Total Amount = " << users[k].total_amount << endl;
    }

    void remove_car(int b)
    {
        for (int i = 0; i < 5; i++)
        {
            if (users[b].booking[i] != "Nill")
            {
                cout << endl
                     << i + 1 << ". " << users[b].booking[i] << " on " << users[b].BookingDates[i] << " MAY 2023";
            }
        }
        string option;
        cout << endl
             << endl
             << "Enter the name of the car you want to remove : ";
        cin >> option;
        for (int i = 0; i < 5; i++)
        {
            if (option == users[b].booking[i])
            {
                users[b].booking[i] = "Nill";
                users[b].BookingDates[i] = "-";
                cout << endl
                     << "Booking Removed" << endl;
            }
        }
    }
};

int main()
{
    cout << "____WELCOME TO ONLINE CAR BOOKING PORTAL____" << endl;
    Rental_system system;
    system.add_car("civic", 15000, 2022, "black", 5, true);
    system.add_car("corolla", 10000, 2018, "White", 5, true);
    system.add_car("yaris", 10500, 2020, "Grey", 5, true);
    system.add_car("city", 9000, 2017, "White", 5, true);
    system.add_car("alto", 6000, 2018, "White", 5, true);
    system.add_car("bolan", 6000, 2015, "Grey", 10, true);
    system.add_car("brv", 12000, 2017, "black", 7, true);
    system.add_car("vigo", 10000, 2013, "black", 5, true);
    system.add_car("noah", 9000, 2017, "White", 12, true);
    system.add_car("haice", 10000, 2015, "black", 15, true);

    int option;
    do
    {
        cout << endl
             << "-------MAIN MENU-------";
        cout << endl
             << "press 1 to create account";
        cout << endl
             << "press 2 to login";
        cout << endl
             << "press 3 to Exit";
        cout << endl
             << "Your option : ";
        cin >> option;

        if (option == 1)
        {
            cout << endl
                 << "-------SIGNUP MENU-------";
            string name; // name for creating account
            string pass; // pass for creating account
            int num;
            string address;
            cout << "\nEnter your name : ";
            cin >> name;
            cout << "set password for your account : ";
            cin >> pass;
            cout << "Enter your phone num : ";
            cin >> num;
            cout << "Enter your address : ";
            cin >> address;
            system.add_User(name, pass, num, address);
        }
        if (option == 2)
        {
            cout << endl
                 << "-------LOGIN MENU-------";
            string na; // name for login
            string pa; // pass for login
            cout << "\nEnter your name : ";
            cin >> na;
            cout << "enter password : ";
            cin >> pa;
            system.login_check(na, pa);
        }
    } while (option != 3);

    for (int i = 0; i < 10; i++)
    {
        cout << endl
             << system.users[i].name;
        cout << endl
             << system.users[i].password;
    }
    for (int i = 0; i < 30; i++)
    {
        cout << system.cars[0].slot[i];
    }
}