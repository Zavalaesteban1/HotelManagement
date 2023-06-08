#pragma once 

using namespace std;

// class Hotel to run the management system
class Hotel
{
    private:
        struct Node
        {
            int id, date;
            string name, roomType;
            Node* next; 
        };

    public:
        Node* head = NULL;
        void insert();
        void menu();
        void update();
        void search();
        void del();
        void sort();
        void show();

};

void Hotel::menu()
{
    int choice;
    cout << endl;
    // Display the menu that will be displayed 
    cout << setw(45) << "Welcome to Hotel Management System" << endl;
    cout << endl << endl << setw(50) << "___________________Hotel Management System_________________";
    cout << endl << endl << "S.No" << setw(15) << "Functions" << setw(33) << "Decription" << endl;
    cout << endl << endl << "1." << setw(21) << "Allocate Room" << setw(35) << "Insert New Rooom";
    cout << endl << endl << "2." << setw(19) << "Search Room" << setw(44) << "Search Room with RoomID";
    cout << endl << endl << "3." << setw(19) << "Update Room" << setw(39) << "Update Room Record";
    cout << endl << endl << "4." << setw(19) << "Delete Room" << setw(44) << "Delete Room with RoomID";
    cout << endl << endl << "5." << setw(25) << "Show Room Records" << setw(53) << "Show Room Records that have been added";
    cout << endl << endl <<  "6." << setw(12) << "Exit" << endl;
    // prompt the user to enter the following choices
    cout << endl << "Enter your choice: ";
    cin >> choice;
    // switch statements for the different choices that will call each function 
    switch(choice)
    {
        case 1:
            insert();
            menu();
        break;

        case 2:
            search();
            menu();
        break;

        case 3:
            update();
            menu();
        break;

        case 4:
            del();
            menu();
        break;

        case 5:
            sort();
            show();
            menu();
        break;

        case 6:
            exit(0);
            default:
                cout << "Invalid"; 
    }
}

// function that defines the following information of a customor checking in to the hotel 
void Hotel::insert()
{
    cout << endl << endl << setw(50) << "___________________Hotel Management System_________________";
    // decalre node to store the corresponding information 
    Node *new_node = new Node;
    cout << endl << endl << "Enter Room ID: ";
    cin >> new_node -> id;
    cout << endl << "Enter Customer Name: ";
    cin >> new_node -> name;
    cout << endl << "Enter Allocated Date: ";
    cin >> new_node -> date; 
    cout << endl << "Enter Room Tyoe(Single/Double/Twin): ";
    cin >> new_node -> roomType; 

    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node* ptr = head;
        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> next = new_node;
    }
    cout << endl << endl << endl << setw(35) << "New Room Inserted"; 
}

// function that searches for the room information using the room ID
void Hotel::search()
{
     cout << endl << endl << setw(50) << "___________________Hotel Management System_________________";
    int id1;

    if(head == NULL)
    {
        cout << endl << endl << "Linked List is Empty";
    }
    else
    {
        cout << endl << endl << "Room ID: ";
        cin >> id1; 
        Node* ptr = head;
        while(ptr != NULL)
        {
            if(id1 == ptr -> id)
            {
                cout << endl << endl << "Room Found";
                cout << endl << endl << "Room ID: " << ptr -> id;
                cout << endl << endl << "Customer Name: " << ptr -> name;
                cout << endl << endl << "Room Allocated Date: " << ptr -> date;
                cout << endl << endl << "Room Type: " << ptr -> roomType;
            }
        ptr = ptr ->next;
        }
    }

}
// function updates the room that have already been checked in 
void Hotel::update()
{
    cout << endl << endl << setw(50) << "___________________Hotel Management System_________________";
    int id2;

    if(head == NULL)
    {
        cout << endl << endl << "Linked List is Empty";
    }
    else
    {
        cout << endl << endl << "Room ID: ";
        cin >> id2;

        Node *ptr = head;
        while(ptr != NULL)
        {
            if(id2 == ptr -> id)
            {
                cout << endl << endl << "Room ID: ";
                cin >> ptr -> id;

                cout << endl << endl << "Customer Name: ";
                cin >> ptr -> name;

                cout << endl << endl << "Allocated Date: ";
                cin >> ptr -> date;

                cout << endl << endl << "Room Type: ";
                cin >> ptr -> roomType;

                cout << endl << endl << "Update Record Successfully";

            }
            ptr = ptr -> next;
        }
    }
}

//
void Hotel::del()
{
    cout << endl << endl << setw(50) << "___________________Hotel Management System_________________";
    int id3;

    if(head == NULL)
    {
        cout << endl << endl << "Linked List is Empty";
    }
    else
    {
        cout << endl << endl << "Room ID: ";
        cin >> id3; 

        if(id3 == head -> id)
        {
            Node* ptr = head;
            head = head -> next;
            delete ptr;
            cout << "Delete Room Record Successful" << endl; 
        }
    else
    {
        Node* pre = head;
        Node* ptr = head;
        while(ptr != NULL)
        {
            if(id3 == ptr -> id)
            {
                pre -> next = ptr -> next;
                delete ptr;
                cout << "Delete Room Record Successful" << endl;
                break;
            }
            pre = ptr;
            ptr = ptr -> next; 
        }
    }
    }

}

// 
void Hotel::show()
{
    Node* ptr = head;
    while(ptr != NULL)
    {
        cout << endl << endl << "Room ID: " << ptr -> id;
        cout << endl << endl << "Customer Name: " << ptr -> name;
        cout << endl << endl << "Allocated Date: " << ptr -> date;
        cout << endl << endl << "Room Type: " << ptr -> roomType;

        ptr = ptr -> next;
    }

}

//
void Hotel::sort()
{
    if(head == NULL)
    {
        cout << endl << endl << "Linked Lidt is Empty";
        menu();
    }

    int count = 0;
    int date_1, id_1; 
    string name_1, roomtype_1;
    Node* ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> next;
    }

    for(int i = 1; i <= count; i++)
    {
        Node *ptr = head;
        for(int j = 1; j < count; j++)
        {
            if(ptr-> id > ptr -> next -> id)
            {
                id_1 = ptr -> id;
                name_1 = ptr -> name;
                date_1 = ptr -> date;
                roomtype_1 = ptr -> roomType;
                // Save date into current node
                ptr -> id = ptr -> next -> id;
                ptr -> name = ptr -> next -> name;
                ptr -> date = ptr -> next -> date;
                ptr -> roomType = ptr -> next -> roomType;
                // Save Data into next node
                ptr -> next -> id = id_1;
                ptr -> next -> name = name_1;
                ptr -> next -> date = date_1;
                ptr -> next -> roomType = roomtype_1;

              

            }
            ptr = ptr -> next; 
        }
    }
}
