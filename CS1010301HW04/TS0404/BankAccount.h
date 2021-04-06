static int total = 0;
class BankAccount {
private:
	int balance;
public:
	BankAccount();
	BankAccount(int input);
	void withdraw(int output);
	void save(int input);
	int getBalance();
	static int getAllMoneyInBank();
};

BankAccount::BankAccount() {
	balance = 0;
	total += balance;
}

BankAccount::BankAccount(int input) {
	balance = input;
	total += balance;
}

void BankAccount::withdraw(int output) {
	balance -= output;
	total -= output;
}

void BankAccount::save(int input) {
	balance += input;
	total += input;
}

int BankAccount::getBalance() {
	return balance;
}

int BankAccount::getAllMoneyInBank() {
	return total;
}