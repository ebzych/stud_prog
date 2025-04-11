#include <iostream>
using namespace std;

char *resize(const char *str, unsigned size, unsigned new_size)
{
    unsigned min_size = size > new_size ?
        new_size : size;
    char *new_str = new char[new_size];
    for (int i = 0; i < min_size; i++) {
        new_str[i] = str[i];
    }
	
    delete [] str;
    
    return new_str;
}

void add_new_char(char *str, unsigned &size, unsigned count, char ch) {
    if (count > size) {
        str = resize(str, size, count * 2);
        size = count * 2;
    }
    
    str[count] = ch;
}

char *getline()
{
    unsigned size = 12, count = 0;
    char ch = '\0', *string = new char[size];
    while (std::cin.get(ch) && ch != '\n' && ch != std::cin.eof() && ch != '0') {
        add_new_char(string, size, count, ch);     
        count++;
    }
    
    add_new_char(string, size, count, '\0');
    return string;
}

int main() {
    int minimum = -1 >> 1;
    cout << minimum << endl;
    getline();
    return 0;
}