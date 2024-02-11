#include <iostream>

class cashRegister {
private:
	int cashOnHand;
public:
	cashRegister() {
		cashOnHand = 500; //В кассе 500 рублей
	}
	cashRegister(int cash) {
		cashOnHand = cash;
	}
	int getCurrentBalance() { //Возвращает значение cashOnHand
		return cashOnHand;
	}
	void acceptAmount(int amount) { //Получение суммы, внесенной клиентом, и обновления суммы в реестре
		cashOnHand += amount;
	}
};
class dispenserType {
private:
	int numberOfItems;
	int cost;
public:
	dispenserType() {
		numberOfItems = 50; 
		cost = 50;
	}
	dispenserType(int items, int price) {
		numberOfItems = items;
		cost = price;
	}
	int getNoOfItems() {
		return numberOfItems;
	}
	int getCost() {
		return cost;
	}
	void makeSale() {
		if (numberOfItems > 0) {
			numberOfItems--;
		}
	}
};
void showSelection() {
	std::cout << "1. Candy" << std::endl;
	std::cout << "2. Chips" << std::endl;
	std::cout << "3. Gum" << std::endl;
	std::cout << "4. Cookies" << std::endl;
}
void sellProduct(dispenserType& dispenser, cashRegister& cashReg) {
	int choice;
	std::cout << "Your choice: ";
	std::cin >> choice;

	switch (choice) {
	case 1:
		std::cout << "Your candy." << std::endl;
		if (dispenser.getNoOfItems() > 0) {
			std::cout << "Price: $" << dispenser.getCost() << std::endl;
			std::cout << "Your cash: ";
			int money;
			std::cin >> money;
			if (money >= dispenser.getCost()) {
				dispenser.makeSale();
				cashReg.acceptAmount(dispenser.getCost());
				std::cout << "WOW THE BEST CANDY!" << std::endl;
			}
			else {
				std::cout << "Insufficient funds. Money refunded." << std::endl;
			}
		}
		else {
			std::cout << "Out of stock." << std::endl;
		}
		break;
		// Add cases for Chips, Gum, and Cookies here
	default:
		std::cout << "Invalid choice." << std::endl;
	}
}

int main() {
	dispenserType candy(50, 1);
	cashRegister cashReg(500);

	showSelection();
	sellProduct(candy, cashReg);

	return 0;
}