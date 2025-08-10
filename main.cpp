#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Validation {
public:
	static bool isname(string name){
		if (name.length() < 5 || name.length() > 20) {
			cout << "Please enter name from 5 to 20 characters \n";
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
			cout << "Please enter password from 8 to 20 characters \n";
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
		if (salary < 1500) {
			cout << "Minimum salary allowed is 5000 $ \n";
			return false;
		}
		return true;
	}
};

class Person {
protected:
	//Attributes:
	int id ;
	string name;
	string password;

public:
	//Constructor:
	Person() {
		int id = 0;
		string name;
		string password;
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
		if (Validation::isname) {
			this->name = name;
		}
		else
			cout << "Invalid name , name must be alphabetic between 5 and 20 characters \n";
	}
	void setPassword(string password) {
		if (Validation::ispassword) {
			this->password = password;
		}
		else
			cout << "Invalid password , password must be alphabetic between 8 and 20 characters \n";
	}

	// Getters:
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	// Methodes

	void printInfo() {

	}

//Destructor:
~Person() {

	}
};

class Client :public Person {
private:
	//Attributes:
	double balance = 0;

public:
	//Constractor:
	Client() {
		double balance = 0;
	}

	Client(int id,string name , string password , double balance ) :Person{ id, name , password } {
		this->balance = balance;
	}
	//Setters:

	void setBalance(double balance) {
		if (Validation::isbalance) {
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
		cout << "client id " << id << "\nname " << name << "\nbalance " << balance << endl;
	}
	//Destructor:
	~Client() {

	}
};
class Employee :public Person {
protected:
	//Attributes:
	double salary;

public:
	//Constractor:
	Employee() {
		double salary = 0;
	}

	Employee(int id, string name, string password, double salary) :Person{ id, name , password } {
		this->salary = salary;
	}
	//Setters:

	void setSalary(double salary) {
		if (Validation::issalary) {
			this->salary = salary;
		}
		else
			cout << "Invalid salary; minimum salary is 5000$ \n";
	}

	//Getters:
	double getSalary() {
		return salary;
	}


	// Methodes


	void display() {
		cout << "Employee id " << id << "\nname " << name << "\nsalary " << salary << endl;
	}
	//Destructor:
	~Employee() {

	}
};
class Admin :public Employee {
	//Attributes:

public:
	//Constractor:
	Admin() {

	}

	Admin(int id, string name, string password, double salary) :Employee{ id, name , password , salary } {

	}
	//Setters:

	//Getters:

	// Methodes
	void display() {
		cout << "ِAdmin id " << id << "\nname " << name << "\nsalary " << salary << endl;
	}
	//Destructor:
	~Admin() {

	}
};


	int main() {


	}
