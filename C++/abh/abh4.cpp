#include <iostream>
class ScopeExample {
private:
    int nonStaticVar;

public:
    static int staticVar;
    ScopeExample(int value) {
        nonStaticVar = value;
    }

    void displayValues() const {
        std::cout << "Static variable (inside class method): " << staticVar << std::endl;
        std::cout << "Non-static variable (inside class method): " << nonStaticVar << std::endl;
    }
  static void staticMethod() {
        std::cout << "Static variable (inside static method): " << staticVar << std::endl;
    }
};

int ScopeExample::staticVar = 50;

int main() {
    int localVar = 20;

    {
        int nestedVar = 30;
        std::cout << "Local variable (inside main): " << localVar << std::endl;
        std::cout << "Nested variable (inside nested block): " << nestedVar << std::endl;
    }

    std::cout << "Static variable (outside main): " << ScopeExample::staticVar << std::endl;

    ScopeExample obj(42);
    obj.displayValues();
    ScopeExample::staticMethod();
  return 0;
}
