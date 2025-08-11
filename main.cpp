#include <iostream>
#include <string>
#include <cctype>  //for isalpha
#include <windows.h>  // For Sleep
#include <vector>
using namespace std;

class Validation {
public:
	static bool isname(string name){
		if (name.length() < 5 || name.length() > 20) {
			cout << "Please enter name between 5 to 20 characters \n";
			return false;
	  }
		for (char ch : name) {
			if (!isalpha(ch)) {
				cout << "Please enter only alphabetic characters \n";
				return false;
			}
		}
		return true;
	}
	static bool ispassword(string password) {
		if (password.length() < 8 || password.length() > 20) {
			cout << "Please enter password between 8 to 20 characters \n";
			return false;
		}
		return true;
	}
	static bool isbalance(double balance) {
		if (balance < 1500) {
			cout << "Minimum balance allowed is 1500 $ \n";
			return false;
		}
		return true;
	}
	static bool issalary(double salary) {
		if (salary < 5000) {
			cout << "Minimum salary allowed is 5000 $ \n";
			return false;
		}
		return true;
	}
};
// Person
class Person {
protected:
	//Attributes:
	int id ;
	string name;
	string password;

public:
	//Constructor:
	Person() {
		this->id = 0;
		this->name = name;
		this->password = password;
	}

	Person(int id, string name , string password){
		this-> id = id;
		this->name = name;
		this->password = password;
	}
	//setters:
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		if (Validation::isname(name)) {
			this->name = name;
		}
		else
			cout << "Invalid name , name must be alphabetic between 5 and 20 characters \n";
	}
	void setPassword(string password) {
		if (Validation::ispassword(password)) {
			this->password = password;
		}
		else
			cout << "Invalid password , password must be alphabetic between 8 and 20 characters \n";
	}

	// Getters:
	int getId() const {
		return id;
	}
	string getName() const {
		return name;
	}
	string getPassword() const {
		return password;
	}
	// Methodes

	virtual void display() {

	}

//Destructor:
~Person() {

	}
};
 //Client
class Client :public Person {
private:
	//Attributes:
	double balance;
public:
	//Constractor:
	Client() {
		this->balance = 0;
	}

	Client(int id,string name , string password , double balance ) :Person{ id, name , password } {
		this->balance = balance;
	}
	//Setters:

	void setBalance(double balance) {
		if (Validation::isbalance(balance)) {
			this->balance = balance;
		}
		else
		cout << "Your balance must be 1500 $ minimum \n";
	}

	//Getters:
	double getBalance() {
		return balance;
	}

	// Methodes
	bool login(int inputId, const string& inputPassword) {
		return (id== inputId && password == inputPassword);
	}
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
			cout << "Deposited successfully ; your balance is " << balance << endl;
		}
		else
			cout << "Invalide amount \n";
	}
	void withdraw(double amount) {
		if (amount > 0 && balance - amount >= 1500) {
			balance -= amount;
			cout << "Withdraw successfully ; your balance is " << balance << endl;
		}
		else
			cout << "Invalide amount \n";
	}
	void transferTo(double amount, Client& recipient) {
		if (amount > 0 && balance - amount >= 1500) {
			balance -= amount;
			recipient.deposit(amount);
			cout << "Transferred successfully ; your balance is " << balance << endl;
		}
		else
			cout << "Transfer falied;check your balance please \n";
	}
	void checkBalance() {
		cout << "Your balanec is " << balance << endl;
	}
	void display() {
		cout << "Client ID " << id << "\nname " << name << "\nbalance " << balance << endl;
	}
	
};

//Employee
class Employee :public Person {
protected:
	//Attributes:
	double salary;
	vector<Client>& clients;
public:
	//Constractor:
	Employee() {
		double salary = 0;
	}

	Employee(int id, string name, string password, double salary, vector<Client>& clients) :Person{ id, name , password } {
		this->salary = salary;
		bool login(int inputId, const string & inputPassword) {
			return (id == inputId && password == inputPassword);
		}
	
	}
	// Setters
	void setName(const string& newName) {
		if (Validation::isname(newName)) {
			Person::setName(newName);
		}
		else {
			cout << "Invalid name! Name must be alphabetic, 5-20 characters.\n";
		}
	}

	void setPassword(const string& newPassword) {
		if (Validation::ispassword(newPassword)) {
			Person::setPassword(newPassword);
		}
		else {
			cout << "Invalid password! Password must be 8-20 characters.\n";
		}
	}

	void setSalary(double newSalary) {
		if (newSalary >= 5000) {
			Person::setSalary(newSalary);
		}
		else {
			cout << "Salary must be at least 5000.\n";
		}
	// Getters
	int getId() const {
		return id;
	}
	
	string getName() const {
		return name; 
	}
	string getPassword() const {
		return password;
	}
	double getSalary() const {
		return salary;
	}

	// Methodes
	void addClient() {
		int newId;
		string newName, newPassword;
		double newBalance;
	cout << "Enter Client ID: ";
	cin >> newId;
	cout << "Enter Client Name: ";
	cin >> newName;
	cout << "Enter Client Password: ";
	cin >> newPassword;
	cout << "Enter Initial Balance: ";
	cin >> newBalance;

	clients.emplace_back(newId, newName, newPassword, newBalance);
	cout << "Client added successfully!\n";
}
	void searchClient() {
		int searchId;
		cout << "Enter Client ID to search: ";
		cin >> searchId;

		for (const auto& client : clients) {
			if (client.getId() == searchId) {
				client.display();
				return;
			}
		}
		cout << "Client not found.\n";
	}

	void listClients() {
		cout << "\nAll Clients:\n";
		for (const auto& client : clients) {
			client.display();
		}
	}
	void editClient() {
		int clientId;
		cout << "Enter Client ID to edit: ";
		cin >> clientId;

		for (auto& client : clients) {
			if (client.getId() == clientId) {
				string newName, newPassword;
				double newBalance;

				cout << "Enter new name: ";
				cin >> newName;
				cout << "Enter new password: ";
				cin >> newPassword;
				cout << "Enter new balance: ";
				cin >> newBalance;

				client.setName(newName);
				client.setPassword(newPassword);
				client.setBalance(newBalance);

				cout << "Client updated successfully.\n";
				return;
			}
		}

		cout << "Client not found.\n";
	}
	
	void display() {
		cout << "Employee ID " << id << "\nname " << name << "\nsalary " << salary << endl;
	}
	
};

//Admin
class Admin :public Employee {
	vector<Employee>employees;

public:
	//Constractor:
	Admin() {

	}

	Admin(int id, string name, string password, double salary,vector<Client>&clients, vector<Employee>employees) :Employee{ id, name , password , salary } {

	}
	

	// Methodes
	void addEmployee() {
		int newId;
		string newName, newPassword;
		double newSalary;

		cout << "Enter Employee ID: ";
		cin >> newId;
		cout << "Enter Employee Name: ";
		cin >> newName;
		cout << "Enter Employee Password: ";
		cin >> newPassword;
		cout << "Enter Employee Salary: ";
		cin >> newSalary;

		employees.emplace_back(newId, newName, newPassword, newSalary, clients);
		cout << "Employee added successfully!\n";
	}

	void searchEmployee() {
		int searchId;
		cout << "Enter Employee ID to search: ";
		cin >> searchId;

		for (const auto& emp : employees) {
			if (emp.getId() == searchId) {
				emp.displayInfo();
				return;
			}
		}
		cout << "Employee not found.\n";
	}

	void editEmployee() {
		int empId;
		cout << "Enter Employee ID to edit: ";
		cin >> empId;

		for (auto& emp : employees) {
			if (emp.getId() == empId) {
				string newName, newPassword;
				double newSalary;

				cout << "Enter new name: ";
				cin >> newName;
				cout << "Enter new password: ";
				cin >> newPassword;
				cout << "Enter new salary: ";
				cin >> newSalary;

				emp.setName(newName);
				emp.setPassword(newPassword);
				emp.salary = newSalary;

				cout << "Employee updated successfully.\n";
				return;
			}
		}

		cout << "Employee not found.\n";
	}

	void listEmployees() {
		cout << "\nAll Employees:\n";
		for (const auto& emp : employees) {
			emp.displayInfo();
		}
	}

	void display() {
		cout << "ِAdmin ID " << id << "\nname " << name << "\nsalary " << salary << endl;
	}
	//Destructor:
	~Admin() {

	}
};

	int main() {
		vector<Client> clients;
		vector<Employee> employees;
		cout << "Welcome to Bank Misr.\n";

		// Sleep for 3 seconds (3000 milliseconds)
		Sleep(3000);


		// Clear screen
		system("cls");  // Windows

		int choice;
		int id;
		string password;
		int userType;
		cout << "Select : 1. Client 2. Employee 3. Admin\n";
		cin >> userType;

		if (userType == 1) { /* Client logic */ }
		else if (userType == 2) { /* Employee logic */ }
		else if (userType == 3) { /* Admin logic */ }
		else {
			cout << "Invalid choice.\n";
		}

		//Client
		cout << "Client Login\nEnter ID: ";
		cin >> id;
		cout << "Enter Password: ";
		cin >> password;

		Client* loggedInClient = nullptr;

		// Find and authenticate client
		for (auto& client : clients) {
			if (client.login(id, password)) {
				loggedInClient = &client;
				break;
			}
		}

		if (!loggedInClient) {
			cout << "Invalid ID or password.\n";
			return 0;
		}

		cout << "Welcome " << loggedInClient->getName() << "!\n";

		do {
			// Display menu
			cout << "\n-----Client MENU -----\n";
			cout << "1. Deposit\n";
			cout << "2. Withdraw\n";
			cout << "3. Check Balance\n";
			cout << "4.transfer\n";
			cout << "5. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;
		}
			
			switch (choice) {
			case 1:
				double amount;
				cout << "Enter amount to deposit: ";
				cin >> amount;
				loggedInClient->deposit(amount);
				break;
			case 2:
				double withdraw;
				cout << "Enter amount to withdraw: ";
				cin >> withdraw;
				loggedInClient->withdraw(withdraw);
				break;
			case 3:
				loggedInClient->checkBalance();
				break;
			case 4:
				int recipientId;
				double transferAmount;
				cout << "Enter recipient ID: ";
				cin >> recipientId;
				cout << "Enter amount to transfer: ";
				cin >> transferAmount;
				for (auto& c : clients) {
					if (c.getId() == recipientId) {
						loggedInClient->transferTo(transferAmount, c);
						break;
					}
				}
				break;
			case 5:
				exitProgram();
				break;
			default:
				cout << "Invalid choice, please try again.\n";
			}

			//Employee
			
			cout << "Employee Login:\n";
			cout << "Enter ID: ";
			cin >> id;
			cout << "Enter Password: ";
			cin >> password;

			Employee emp(id, name, password, salary, clients); 
			
				int choice;
				do {
					cout << "\n--- Employee Menu ---\n";
					cout << "1. Add Client\n2. Search Client\n3. List Clients\n4. Edit Client\n5. Display My Info\n0. Exit\n";
					cout << "Enter choice: ";
					cin >> choice;
				}
					switch (choice) {
					case 1: emp.addClient(); break;
					case 2: emp.searchClient(); break;
					case 3: emp.listClients(); break;
					case 4: emp.editClient(); break;
					case 5: void display(); break;
					case 0: cout << "Logging out...\n"; break;
					default: cout << "Invalid choice.\n";
					}

				 while (choice != 0);
		
			else {
				cout << "Invalid login.\n";
			}
      // Admin
			
			cout << "Admin Login:\n";
			cout << "Enter ID: ";
			cin >> id;
			cout << "Enter Password: ";
			cin >> pass;

			Admin admin(id, name, password, salary, clients, employees);
				int choice;
				do {
					cout << "\n--- Admin Menu ---\n";
					cout << "1. Add Employee\n2. Search Employee\n3. Edit Employee\n4. List Employees\n";
					cout << "5. Add Client\n6. Search Client\n7. Edit Client\n8. List Clients\n";
					cout << "9. Display My Info\n0. Logout\n";
					cout << "Enter choice: ";
					cin >> choice;

					switch (choice) {
					case 1: admin.addEmployee(); break;
					case 2: admin.searchEmployee(); break;
					case 3: admin.editEmployee(); break;
					case 4: admin.listEmployees(); break;
					case 5: admin.addClient(); break;
					case 6: admin.searchClient(); break;
					case 7: admin.editClient(); break;
					case 8: admin.listClients(); break;
					case 9: void display(); break;
					case 0: cout << "Logging out...\n"; break;
					default: cout << "Invalid choice.\n";
					}

				} while (choice != 0);
			}
			else {
				cout << "Invalid login.\n";
			}

	}
