#include "myheader.h"
using namespace std;

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
	int no_copy;
	double b_cost;
	string b_name, a_name, b_id;
	fstream file;
	system("cls");
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
	
	// Open file in append or output mode
	file.open("D:// book.txt", ios::out | ios::app);
	file << " " << b_id << " " << b_name << " " << a_name << " " << no_copy << " " << b_cost << "\n";
	file.close();
}

// Function to display book
void bookshope::show_book()
{
	int no_copy;
	double b_cost;
	string b_name, b_id, a_name;
	fstream file;
	system("cls");
	
	// Open the file in input mode
	file.open("D:// book.txt", ios::in);
	cout << "\n\n\t\t\t\t\tAll BOOKS";
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {
		cout << "\n\n\nBook ID\t\tBook\t\tAuthor\t\tNo. of Books\t\tCost\n\n";
		file >> b_id >> b_name >> a_name >> no_copy >> b_cost;
		// Till end of file is reached
		while (!file.eof()) {

			cout << " " << b_id << "\t\t" << b_name << "\t\t" << a_name << "\t\t" << no_copy << "\t\t\t" << b_cost << "\n\n";
			file >> b_id >> b_name >> a_name >> no_copy >> b_cost;
		}
		// Close the file
		file.close();
	}
}

// Function to check the book
int bookshope::check_book(string b_idd)
{
	int no_copy, count = 0, n_cp;
	double b_cost;
	char x;
	string b_id, b_name, a_name;
	fstream file;
	
	// Open the file in input mode
	file.open("D:// book.txt", ios::in);
	if (!file)
		cout << "\n\nFile Opening Error!";
	else {
		file >> b_id >> b_name >> a_name >> no_copy >> b_cost;
		while (!file.eof()) {
			if (b_idd == b_id) {
				system("cls");
				cout << "\n\n\t\t\t\tBook available ";
				cout << "\n\nBook ID : " << b_id;
				cout << "\nName : " << b_name;
				cout << "\nAuthor : " << a_name;
				cout << "\nNo. of Books : " << no_copy;
				cout << "\nCost of book : " << b_cost;
					
				cout << "\n\nEnter no. of books to purchase ";
				cin >> n_cp;
				if(n_cp > no_copy) {
					cout << "\nNot enough stock\n";
					system("pause");
					return -1;
				}
				else
					cout <<"Your total amount will be " << (n_cp*b_cost);
				count++;
				break;
			}
			file >> b_id >> b_name >> a_name >> no_copy >> b_cost;
		}
		file.close();
		if (count == 0)	{
			cout << "\nBook ID Not Found...\n";
			return	-1;
		}
		else {
			cout << "\nConfirm purchase? (y/n) ";
			cin >> x;
			if (x == 'y')
				return n_cp;
			else
				return -1;
		}	
	}
}

// Function to update the book
void bookshope::update_book()
{
	
	
	int no_copy, no_co, count = 0;
	double b_cost,b_co;
	string b_name, b_na, a_name, a_na, b_idd, b_id;
	fstream file, file1;
	system("cls");

	cout << "\n\n\t\t\t\tUpdate Book Record";
	file1.open("D:// book1.txt", ios::app | ios::out);
	file.open("D:// book.txt", ios::in);

	if (!file)
		cout << "\n\nFile Opening Error!";
	else {
		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name >> a_name >> no_copy >> b_cost;

		// Till end of file is reached
		while (!file.eof()) {
			if (b_id == b_idd) {
				system("cls");
				cout << "\t\t\t\tUpdate Book Record";
				cout << "\n\nNew Book Name : ";
				cin >> b_na;
				cout << "\nAuthor Name : ";
				cin >> a_na;
				cout << "\nNo. of Books : ";
				cin >> no_co;
				if(no_co == 0){
					count++;
					file >> b_idd >> b_name >> a_name >> no_copy >> b_cost;
					continue;
				}
				cout << "\nCost of book : ";
				cin >> b_co;
				file1 << " " << b_id << " " << b_na << " " << a_na << " " << no_co << " " << b_co << "\n\n";
				count++;
			}
			else
				file1 << " " << b_idd << " " << b_name << " " << a_name << " " << no_copy << " " << b_cost << "\n\n";
				
			file >> b_idd >> b_name >> a_name >> no_copy >> b_cost;
		}
		if (count == 0)
			cout << "\n\nBook ID Not Found...";
	}
	cout << endl;
	system("pause");

	// Close the files
	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt", "D:// book.txt");
}

// Function to delete book
void bookshope::del_book()
{
	int no_copy, count = 0;
	double b_cost;
	string b_id, b_idd, b_name, a_name;
	fstream file, file1;
	system("cls");
	
	// Append file in output mode
	file1.open("D:// book1.txt",
			ios::app | ios::out);
	file.open("D:// book.txt",
			ios::in);
	cout << "\n\n\t\t\t\tDelete a Book";
	if (!file)
		cout << "\n\nFile Opening Error...";
	else {

		cout << "\n\nBook ID : ";
		cin >> b_id;
		file >> b_idd >> b_name >> a_name >> no_copy >> b_cost;
		while (!file.eof()) {
			if (b_id == b_idd) {

				system("cls");
				cout << "\n\n\t\t\t\tDelete a Book";
				cout << "\n\nBook is Deleted Successfully...\n\n";
				count++;
			}
			else
				file1 << " " << b_idd << " " << b_name << " " << a_name << " " << no_copy << " " << b_cost << "\n\n";
				
			file >> b_idd >> b_name >> a_name >> no_copy >> b_cost;
		}
		if (count == 0)
			cout << "\n\nBook ID Not Found...\n";
	}
	system("pause");

	// Close the file
	file.close();
	file1.close();
	remove("D:// book.txt");
	rename("D:// book1.txt", "D:// book.txt");
}

//Function to print receipt
void bookshope::receipt(string nm, long long int ph, string bn, string an, int nc, double bc, string pay)
{
	cout << "\t\t\t\tPURCHASE RECEIPT";
	cout << "\n**********************************************************************************";
	cout << "\nName : " << nm << "\t\t\t\t\t\tPhone : " << ph;
	cout << "\nBook Name\t\tAuthor\t\tCost\t\tPcs\t\tTotal Cost\n";
	cout << bn << "\t\t\t" << an << "\t\t" << bc <<"\t\t" << nc <<"\t\t" << (bc*nc);
	cout <<"\n\n\t\t\t\t\t\t\t\tGST 12% : " << (0.12*bc*nc);
	cout <<"\n\t\t\t\t\t\t\t\tTotal : " << (1.12*bc*nc);
	cout <<"\n\n****************   \t\t\tMode : " << pay << "\t\t   ****************";
	cout << "\n**********************************************************************************";
	cout << "\n\t\t\t\t   THANKS";
  
}
//Function to buy books
void bookshope::buy_book()
{
	int no_copy,n_cp;
	long long int ph_no;
	double b_cost;
	char x;
	string b_id,name,b_idd,b_name,a_name, pay;
	fstream file, file1;
	
	cout << "\nAvailable books";
	show_book();
	cout << "\nEnter Book ID to purcahse ";
	cin >> b_id;
	n_cp = check_book(b_id);
	
	if(n_cp != -1){
		system("cls");
		cout << "\nEnter your Name ";
		cin >> name;
		cout << "Enter phone number ";
		cin >> ph_no;
		cout << "Enter mode of payment ";
		cin >> pay;
		cout << "\n";
		
		file1.open("D:// book1.txt",ios::app | ios::out);
		file.open("D:// book.txt", ios::in);
		
		if (!file)
			cout << "\n\nFile Opening Error!";
		else {
			file >> b_idd >> b_name >> a_name >> no_copy >> b_cost;

			// Till end of file is reached
			while (!file.eof()) {
				if (b_id == b_idd) {
					if((no_copy - n_cp) == 0) {
						file >> b_idd >> b_name >> a_name >> no_copy >> b_cost;
						continue;
					}
					file1 << " " << b_idd << " " << b_name << " " << a_name << " " << (no_copy - n_cp) << " " << b_cost << "\n\n";
						receipt(name, ph_no, b_name, a_name, n_cp, b_cost, pay);
				}
				else
					file1 << " " << b_idd << " " << b_name << " " << a_name << " " << no_copy << " " << b_cost << "\n\n";
					
				file >> b_idd >> b_name >> a_name >> no_copy >> b_cost;
			}
			cout << endl;

			// Close the files
			file.close();
			file1.close();
			remove("D:// book.txt");
			rename("D:// book1.txt", "D:// book.txt");
			
		}
	}
		system("pause");
}

// Function to login
void login()
{
	int choice;
	char x;
	string u_name,pwd;
	bookshope b;
	
	while (1) {
		system("cls");
		cout << "\n\n\tLOGIN AS";
		cout << "\n1. USER";
		cout << "\n2. ADMIN ";
		cout << "\nEnter your choice : ";
		cin >> choice;
		switch (choice) {

		case 1:
			bookShopRecord(false);
			break;

		case 2:
			cout << "\nEnter username ";
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
				cout << "\n\nWant to add another book? (y/n) : ";
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
