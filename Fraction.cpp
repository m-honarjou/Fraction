#include<iostream>

using namespace std;

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

class Fraction{
public:
    Fraction(int init_numerator, int init_denominator) : numerator(init_numerator), denominator(init_denominator){}
    Fraction(int init_numerator) : numerator(init_numerator), denominator(1){}
    void set_numerator(int init_numerator){ numerator = init_numerator; }
    void set_denominator(int init_denominator){ denominator= init_denominator; }
    int get_numerator(){ return numerator; }
    int get_denominator(){ return denominator; }
    void reduce(){     
        int GCD = gcd(numerator, denominator);
        numerator /= GCD;
        denominator /= GCD;
    }
    Fraction operator+(const Fraction& f){
        return Fraction( numerator * f.denominator  + f.numerator * denominator , denominator * f.denominator );
    }
    Fraction operator*(const Fraction& f){
        return Fraction( numerator * f.numerator , denominator * f.denominator );
    }
    Fraction operator-(const Fraction& f){
        return Fraction( numerator * f.denominator  - f.numerator * denominator , denominator * f.denominator );
    }
    Fraction operator/(const Fraction& f){
        return Fraction( numerator * f.denominator , denominator * f.numerator );
    }
    bool operator==(const Fraction& f){
        int GCD = gcd(numerator, denominator);
        int GCD1 = gcd(f.numerator, f.denominator);
        if( numerator/GCD == f.numerator/GCD1 && denominator/GCD == f.denominator/GCD1)
            return true;
        return false;
    }
    bool operator!=(const Fraction& f){
        int GCD = gcd(numerator, denominator);
        int GCD1 = gcd(f.numerator, f.denominator);
        if( numerator/GCD == f.numerator/GCD1 && denominator/GCD == f.denominator/GCD1)
            return false;
        return true;
    }
    bool operator>(const Fraction& f){
        if( numerator/denominator > f.numerator/f.denominator )
            return true;
        return false;
    }
    bool operator<(const Fraction& f){
        if( numerator/denominator < f.numerator/f.denominator)
            return true;
        return false;
    }
    bool operator>=(const Fraction& f){
        if( numerator/denominator > f.numerator/f.denominator )
            return true;
        int GCD = gcd(numerator, denominator);
        int GCD1 = gcd(f.numerator, f.denominator);
        if( numerator/GCD == f.numerator/GCD1 && denominator/GCD == f.denominator/GCD1)
            return true;
        return false;
    }
    bool operator<=(const Fraction& f){
        if( numerator/denominator < f.numerator/f.denominator )
            return true;
        int GCD = gcd(numerator, denominator);
        int GCD1 = gcd(f.numerator, f.denominator);
        if( numerator/GCD == f.numerator/GCD1 && denominator/GCD == f.denominator/GCD1)
            return true;
        return false;
    }
    friend ostream& operator<<(ostream& out, const Fraction& f){
        out << f.numerator << "/" << f.denominator;
        return out;
    }
    friend istream& operator>>(istream& in, Fraction& f){
        string input;
        cin >> input;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '/'){
                f.set_numerator( stoi(input.substr(0,i)) );
                f.set_denominator( stoi(input.substr(i + 1, input.size() - 1 )) );
            }
        }
        return cin;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    Fraction a(1, 10);
    Fraction b(10, 100);
    Fraction c(1, 1000);
    Fraction d(1005, 1000);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    Fraction sum = a + b;
    cout << "Sum: " << sum << endl;
    sum.reduce();
    cout << "Reduced sum: " << sum << endl;
    Fraction sub = a - b;
    cout << "Sub: " << sub << endl;
    sub.reduce();
    cout << "Reduced sub: " << sub << endl;
    Fraction mult = a * b;
    cout << "Multipication: " << mult << endl;
    mult.reduce();
    cout << "Reduced multipication: " << mult << endl;
    Fraction divide = a / b;
    cout << "Division: "<< divide << endl;
    divide.reduce();
    cout << "Reduced division: " << divide << endl;

    if ( a == b ){
        cout << a << " == " << b << endl;
    }
    if ( a != c ){
        cout << a << " != " << c << endl;
    }
    if ( d > c ){
        cout << d << " > " << c << endl;
    }
    if ( a >= b ){
        cout << a << " >= " << b << endl;
    }
    if ( a < d ){
        cout << a << " < "  << d << endl;
    }
    if ( a <= d ){
        cout << a << " <= " << d << endl;
    }

    cin >> b;
    cout << b << endl;
}