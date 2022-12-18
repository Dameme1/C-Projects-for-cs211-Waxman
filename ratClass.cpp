//Tameem ahmed
//Rat Class

#include <iostream> 
using namespace std;

class Rat{
    private:
    int n; 
    int d;

    public:
// Constructors
    Rat(){
        n = 0;
        d = 1; 
    }

    Rat(int x, int y){
        n = x; 
        d = y;
    }

    Rat(int x){
        n = x; 
        d = 1; 
    }

//Member functions

    int getN(){return n;} // returns numerator
    int getD(){return d;} // returns denominator 

    void setN(int x){n = x;}  //changes numerator
    void setD(int x){d = x;}  //changes denominator 

//Friend functions
    friend ostream &operator<<(ostream &os, Rat r);

    friend istream &operator>>(istream &is, Rat& r);
};

    ostream& operator<<(ostream& os, Rat r){
        os << r.n << "/" << r.d;
        return os;
    }

    istream& operator>>(istream& is, Rat& r){

        is >> r.n >> r.d;
        return is; 
    }

    Rat operator+(Rat x, Rat y){
        Rat t; 
        t.setN(x.getN() * y.getD() + x.getD() * y.getN());
        t.setD(x.getD() * y.getD());
        
        return t;
    }

    Rat operator-(Rat x, Rat y){
        Rat t; 
        t.setN(x.getN() * y.getD() - x.getD() * y.getN());
        t.setD(x.getD() * y.getD());
        
        return t;
    }

    Rat operator*(Rat x, Rat y){
        Rat t; 
        t.setN(x.getN() * y.getN());
        t.setD(x.getD() * y.getD());
        return t;
    }

    Rat operator/(Rat x, Rat y){
        Rat t;
        t.setN(x.getN() * y.getD());
        t.setD(x.getD() * y.getN());
        return t;
    }


int main(){

    Rat x, y(2,5), z(5);

    cout << x << " " << y << " " << z << endl;

    cout << 5 + z << endl;
    cout << 5 * z << endl;
    cout << 5 / z << endl;
    cout << 5 - z << endl;

    cout << "Enter two numbers for the numerator and denominator, with space in the middle: ";
    cin >> x >> y; 
    cout << x << endl << y << endl;
    
    return 0;
}
