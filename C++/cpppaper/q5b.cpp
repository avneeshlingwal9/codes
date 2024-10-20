#include <iostream>
#include <string>
using namespace std;

class PathDemo {
private:
    string str;

public:
    PathDemo(string s) : str(s) {}

    string get() {
        return str;
    }

    virtual void extractFile() = 0;      // Pure virtual function
    virtual void extractDirectory() = 0; // Pure virtual function
};

class Result : public PathDemo {
public:
    Result(string s) : PathDemo(s) {}

    void extractFile() override {
        size_t k = get().find_last_of("/");
        cout << "File name is " << get().substr(k + 1) << endl;
    }

    void extractDirectory() override {
        size_t k = get().find_last_of("/");
        cout << "Directory is " << get().substr(0, k) << endl;
    }
};

int main() {
    Result r("C:/g.txt");
    r.extractFile();
    r.extractDirectory();

    return 0;
}
