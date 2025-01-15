#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (getBalance() > 500) { 
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: $" << getBalance() << std::endl; 
        }
        else {
            std::cout << "Insufficient funds for withdrawal." << std::endl;
        }
       
    }
};
class HeatingSystem {
public:
    void turnOn() {
        std::cout << "Heating system turned on." << std::endl;
    }

    void turnOff() {
        std::cout << "Heating system turned off." << std::endl;
    }
};

class Thermostat {
private:
    double currentTemperature;

public:
    Thermostat(double temperature) : currentTemperature(temperature) {}

    double getCurrentTemperature() const {
        return currentTemperature;
    }


    void regulate(HeatingSystem& hs, int targetTemp) {
        if (getCurrentTemperature() < targetTemp) {
            hs.turnOn();
        }
        else {
            hs.turnOff();
        }


    }
};
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    bool isAvailable;

public:
    Book(const std::string& title) : title(title), isAvailable(true) {}

    bool checkAvailability() const {
        return isAvailable;
    }

    void borrowBook() {
        isAvailable = false;
    }

    void returnBook() {
        isAvailable = true;
    }

    void tryBorrowBook() {
        if (checkAvailability()) {
            borrowBook();
            std::cout << "Book borrowed successfully." << std::endl;
        }
        else {
            std::cout << "Book is not available for borrowing." << std::endl;
        }
    }
};

class Library {
public:
    void processBookBorrowing(Book& book) {
        book.tryBorrowBook();
    }
};

class Player {
private:
    int health;
    int ammo;

public:
    Player() : health(100), ammo(10) {}

    int getHealth() const {
        return health;
    }

    int getAmmo() const {
        return ammo;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void useAmmo() {
        ammo--;
    }

    void canAttack() {
        if (getHealth() > 0 && getAmmo() > 0) {
            takeDamage(10);
            useAmmo();
            std::cout << "Player attacked and used ammo." << std::endl;
        }
        else {
            std::cout << "Player can't respond to attack." << std::endl;
        }
    }
};

class Game {
public:
    void enemyAttack(Player& player) {
        player.canAttack();
    }
};


int main() {
    //////////////////////////////////////////////////////////////////
    // Exercise 1
    //////////////////////////////////////////////////////////////////
 
    BankAccount account(1000.0);

    // Violation of Tell, Don't Ask
        account.withdraw(500);
   
    //////////////////////////////////////////////////////////////////
    // Exercise 2
    //////////////////////////////////////////////////////////////////

    Thermostat thermostat(18.5);
    HeatingSystem heating;

    thermostat.regulate(heating, 20); 
    
    //////////////////////////////////////////////////////////////////
    // Exercise 3
    //////////////////////////////////////////////////////////////////

    Book myBook("1984");
    Library library;

    library.processBookBorrowing(myBook);  // First borrow should succeed
    library.processBookBorrowing(myBook);  // Second attempt should show not available

    //////////////////////////////////////////////////////////////////
    // Exercise 4
    //////////////////////////////////////////////////////////////////
    Player player;
    Game game;

    game.enemyAttack(player); // Player can respond to attack

    return 0;
}
