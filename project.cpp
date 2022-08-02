#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class bookshope {
private:
	string username = "Farhaan", password = "0613";
public:
	void control_panel();
	void control_panel(bool customer);
	void add_book();
	void show_book();
	int check_book(string);
	void update_book();
	void del_book();
	void buy_book();
	friend void login();
};

void bookShopRecord();
void bookShopRecord(bool);

// Function to display the admin menu
void bookshope::control_panel()
{
	system("cls");
	cout << "\n\n\t\t\t\tCONTROL PANEL ADMIN";
	cout << "\n\n1. ADD BOOK";
	cout << "\n2. DISPLAY BOOKS";
	cout << "\n3. UPDATE BOOK";
	cout << "\n4. DELETE BOOK";
	cout << "\n5. EXIT";
}

// Function to display the customer menu
void bookshope::control_panel(bool customer)
{
	system("cls");
	cout << "\n\n\t\tCONTROL PANEL CUSTOMER";
	cout << "\n1. DISPLAY BOOKS";
	cout << "\n2. BUY BOOK";
	cout << "\n3. EXIT";
}

// Function to add book
void bookshope::add_book()
{
	system("cls");
	fstream file;
	int no_copy;
	double b_cost;
	string b_name, a_name, b_id;
	cout << "\n\n\t\t\t\tADD BOOKS";
	cout << "\n\nBook ID : ";
	cin >> b_id;
	cout << "\nBook Name : ";
	cin >> b_name;
	cout << "\nAuthor Name : ";
	cin >> a_name;
	cout << "\nNo. of Books : ";
	cin >> no_copy;
	cout << "\nCost of Book : ";
	cin >> b_cost;
	

	// Open file in append or
	// output mode
	file.open("D:// book.txt",
			ios::out | ios::app);
	file << " " << b_id << " "
		<< b_name << " " << a_name
		<< " " << no_copy << " " << b_cost << "\n";
	file.close();
}

// Function to display book
void bookshope::show_book()
{
	system("cls");
	fstream file;
	int no_copy;
	double b_cost;
	string b_name, b_id, a_name;
	cout << "\n\n\t\t\t\t\tAll BOOKS";

	// Open the file in input mode
	file.open("D:// book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\n\nBook ID\t\tBook"
			<< "\t\tAuthor\t\tNo. of "
				"Books\t\tCost\n\n";
		file >> b_id >> b_name;
		file >> a_name >> no_copy;
		file >> b_cost;

		// Till end of file is reached
		while (!file.eof()) {

			cout << " " << b_id
				<< "\t\t" << b_name
				<< "\t\t" << a_name
				<< "\t\t" << no_copy
				<< "\t\t\t" << b_cost
				<< "\n\n";
			file >> b_id >> b_name;
			file >> a_name >> no_copy >> b_cost;
		}

		// Close the file
		file.close();
	}
}

// Function to check the book
int bookshope::check_book(string b_idd)
{
	fstream file;
	int no_copy, count = 0, n_cp;
	double b_cost;
	string b_id, b_name, a_name;


	// Open the file in input mode
	file.open("D:// book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		file >> b_id >> b_name;
		file >> a_name >> no_copy >> b_cost;

		while (!file.eof()) {

			if (b_idd == b_id) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Book available ";
				cout << "\n\nBook ID : "
					<< b_id;
				cout << "\nName : "
					<< b_name;
				cout << "\nAuthor : "
					<< a_name;
				cout << "\nNo. of Books : "
					<< no_copy;
				cout << "\nCost of book : "
					<< b_cost;
				cout << endl
					<< endl;
				cout << "\nEnter no. of books ";
				cin >> n_cp;
				if(n_cp > no_copy){
					cout << "\nNot enough stock ";
					system("pause");
					return -1;
				}
				else {
					cout <<"\nYour total amount will be " <<(n_cp*b_cost);
				}
				count++;
				break;
			}
			file >> b_id >> b_name;
			file >> a_name >> no_copy >> b_cost;
		}
		file.close();
		if (count == 0)	{
			cout << "\n\nBook ID Not"
				<< " Found...";
				
			return	-1;
		}
		else
			return n_cp;
			
	}
}

// Function to update the book
void bookshope::update_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, no_co, count = 0;
	double b_cost,b_co;
	string b_name, b_na, a_name;
	string a_na, b_idd, b_id;

	cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("D:// book1.txt",
			ios::app | ios::out);
	file.open("D:// book.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy >> b_cost;

		// Till end of file is reached
		while (!file.eof()) {
			if (b_id == b_idd) {
				system("cls");
				cout << "\t\t\t\t"
					<< "Update Book Record";
				cout << "\n\nNew Book Name : ";
				cin >> b_na;
				cout << "\nAuthor Name : ";
				cin >> a_na;
				cout << "\nNo. of Books : ";
				cin >> no_co;
				if(no_co == 0){
					count++;
					file >> b_idd >> b_name;
					file >> a_name >> no_copy >> b_cost;
					continue;
				}
				cout << "\nCost of book : ";
				cin >> b_co;
				file1 << " " << b_id << " "
					<< b_na << " "
					<< a_na << " " << no_co << " " << b_co
					<< "\n\n";
				count++;
			}
			else
				file1 << " " << b_idd
					<< " " << b_name
					<< " " << a_name
					<< " " << no_copy
					<< " " << b_cost
					<< "\n\n";
			file >> b_idd >> b_name;
			file >> a_name >> no_copy >> b_cost;
		}
		if (count == 0)
			cout << "\n\nBook ID"
				<< " Not Found...";
	}
	cout << endl;
	system("pause");

	// Close the files
	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt",
		"D:// book.txt");
}

// Function to delete book
void bookshope::del_book()
{
	system("cls");
	fstream file, file1;
	int no_copy, count = 0;
	double b_cost;
	string b_id, b_idd, b_name, a_name;
	cout << "\n\n\t\t\t\tDelete a Book";

	// Append file in output mode
	file1.open("D:// book1.txt",
			ios::app | ios::out);
	file.open("D:// book.txt",
			ios::in);

	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name;
		file >> a_name >> no_copy >> b_cost;
		while (!file.eof()) {

			if (b_id == b_idd) {

				system("cls");
				cout << "\n\n\t\t\t\t"
					<< "Delete a Book";
				cout << "\n\nBook is Deleted "
						"Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << b_idd
					<< " " << b_name
					<< " " << a_name
					<< " " << no_copy
					<< " " << b_cost
					<< "\n\n";
			file >> b_idd >> b_name;
			file >> a_name >> no_copy;
		}
		if (count == 0)
			cout << "\n\nBook ID "
				<< "Not Found...";
	}
	system("pause");

	// Close the file
	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt",
		"D:// book.txt");
}

//Function to buy books
void bookshope::buy_book()
{
	int no_copy,n_cp;
	long ph_no;
	double b_cost;
	char x;
	string b_id,name,b_idd,b_name,a_name;
	cout << "\nAvailable books";
	show_book();
	cout << "\nEnter Book ID to purcahse ";
	cin >> b_id;
	n_cp = check_book(b_id);
	
	if(n_cp != -1){
		cout << "\n\nEnter your Name ";
		cin >> name;
		cout << "\nEnter phone number ";
		cin >> ph_no;
		cout << "Confirm purchase? (y/n) ";
		cin >> x;
		cout << "value of x is " << x;
		if(x == 'y'){
			cout << "okay here123";
			system("pause");
			fstream file, file1;
			file1.open("D:// book1.txt",ios::app | ios::out);
			file.open("D:// book.txt", ios::in);
			
			if (!file)
				cout << "\n\nFile Opening Error!";
			else {
				file >> b_idd >> b_name;
				file >> a_name >> no_copy >> b_cost;

				// Till end of file is reached
				while (!file.eof()) {
					if (b_id == b_idd) {
						cout << "okay here";
						if((no_copy - n_cp) == 0){
							file >> b_idd >> b_name;
							file >> a_name >> no_copy >> b_cost;
							continue;
						}
						file1 << " " << b_idd << " "
							<< b_name << " "
							<< a_name << " " << (no_copy - n_cp) << " " << b_cost
							<< "\n\n";
					}
					else
						file1 << " " << b_idd
							<< " " << b_name
							<< " " << a_name
							<< " " << no_copy
							<< " " << b_cost
							<< "\n\n";
					file >> b_idd >> b_name;
					file >> a_name >> no_copy >> b_cost;
				}
				cout << endl;
				system("pause");

				// Close the files
				file.close();
				file1.close();
				remove("D:// book.txt");
				rename("D:// book1.txt",
				"D:// book.txt");
			
			}
			
		
		}
	}
	cout<<"Sab hogaya hai, koi receipt print kar do bhai,I need to go yo teach until 10 pm";
	cout << "Preferably use a random function to generate a 8 digit receipt number according to project guidlines";
	system("pause");
}

// Function to login
void login()
{
	string u_name,pwd;
	int choice;
	char x;
	bookshope b;
	
	while (1) {
		system("cls");
		cout << "\n\n\tLOGIN AS";
		cout << "\n\n1. USER";
		cout << "\n\n2. ADMIN ";
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			bookShopRecord(false);
			break;

		case 2:
			cout << "Enter username ";
			cin >> u_name;
			cout << "Enter password ";
			cin >> pwd;
			if(u_name == b.username && pwd == b.password)
			{
				cout << "\nLogged in";
				bookShopRecord();
			}
			else {
				cout <<"Wrong username/password\n\n";
				system("pause");
			break;
			}

		default:
			cout << "\n\nINVALID CHOICE\n";
			
		}
	}
}

// Function for admin book shop record
void bookShopRecord()
{
	int choice;
	char x;
	bookshope b;

	while (1) {

		b.control_panel();
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			do {

				b.add_book();
				cout << "\n\nWant to add"
					<< " another book? "
						"(y/n) : ";
				cin >> x;
			} while (x == 'y');
			break;

		case 2:
			b.show_book();
			system("pause");
			break;

		case 3:
			b.update_book();
			break;

		case 4:
			b.del_book();
			break;

		case 5:
			exit(0);
			break;

		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
}

// Function for customer book shop record
void bookShopRecord(bool customer)
{
	int choice;
	bookshope b;
	
	while (1) {

		b.control_panel(customer);
		cout << "\n\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			b.show_book();
			system("pause");
			break;

		case 2:
			b.buy_book();
			break;

		case 3:
			exit(0);
			break;

		default:
			cout << "\n\nINVALID CHOICE\n";
		}
	}
}

int main()
{
	login();

	return 0;
}

