#include <iostream>
using namespace std;

struct Cls {
    Cls() {
        cout << "cls constructor" << endl;
    }
    
    Cls(char c, double d, int i) {}
private:
    char c;
    double d;
    int i;
};

struct CloneCls {
public:
    CloneCls() {
        cout << "clonecls constructor" << endl;
    }

    CloneCls(char c, double d, int i) {
        this->c = c;
        this->d = d;
        this->i = i;
    }

    char c;
    double d;
    int i;
};

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
    CloneCls clone('0', 0, 0);
    char *cc = &(clone.c);
    char *c = (char *)((unsigned long)&cls + ((unsigned long)cc - (unsigned long)&clone));
    return *c;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
    CloneCls clone('0', 0, 0);
    double *cc = &(clone.d);
    double *c = (double *)((unsigned long)&cls + ((unsigned long)cc - (unsigned long)&clone));
    return *c;
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
    CloneCls clone('0', 0, 0);
    int *cc = &(clone.i);
    int *c = (int *)((unsigned long)&cls + ((unsigned long)cc - (unsigned long)&clone));
    return *c;
}

int main() {
    Cls cls;
    cout << get_c(cls) << endl;
    cout << get_d(cls) << endl;
    cout << get_i(cls) << endl;
}