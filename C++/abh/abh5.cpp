#include <iostream>

class Fruit {
private:
   int count;

public:

Fruit(int initialCount = 0) : count(initialCount) {}
 int getCount() const {
        return count;
    }

 
void setCount(int newCount) {
        count = newCount;
    }

};


class Apples : public Fruit {

public:
    using Fruit::Fruit; // Inherit base class constructors
};

class Mangoes : public Fruit {
public:
    using Fruit::Fruit; // Inherit base class constructors
};


int main() {
using namespace std;

 Apples appleBasket(10);
Mangoes mangoBasket(5);

cout << "Number of Apples: " << appleBasket.getCount() << endl;
  
 cout << "Number of Mangoes: " << mangoBasket.getCount() << endl;




    int totalFruits = appleBasket.getCount() + mangoBasket.getCount();
    cout << "Total number of Fruits in the basket: " << totalFruits << endl;

 return 0;
}

