#include <iostream>
#include <string.h>
using namespace std;
void cube(int& a){
    a = a * a * a;
}
void count_letters(char str[], int& n_letters, int& n_digits, int& n_other)
{
    n_letters = 0;
    n_digits = 0;
    n_other = 0;
    int length = 0;
    for(int i = 0; str[i] != '\0';i++)
    {
        length++;
        if((str[i] >=65 && str[i] <=90) ||(str[i] >=97 && str[i] <=122))
                n_letters++;
        if(str[i] >=48 && str[i] <=57)
                n_digits++;
    }
    n_other = length - n_letters - n_digits;
}
int main()
{
    int k;
    cout << "Number is ..";
    cin >> k;
    cout <<"Cube is "<< cube(k)<<endl;
    char str[1000];
    cout << "Write some words..";
    cin >> str;
    int n_letters ,n_digits, n_other;
    count_letters(str, n_letters, n_digits, n_other);
    cout <<"n_letters=" << n_letters<<" " << "n_digits=" << n_digits<<" " << "n_other=" << n_other;
}