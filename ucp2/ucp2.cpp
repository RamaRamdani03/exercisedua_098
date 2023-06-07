#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x; // variabel untuk menyimpan input dari lingkaran maupun bujursangkar
public:
    bidangDatar() { // constructor
        x = 0;
    }
    virtual void input() = 0; // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
    virtual float Luas(int a) = 0; // fungsi untuk menghitung luas
    virtual float Keliling(int a) = 0; // fungsi untuk menghitung keliling
    void setX(int a) { // fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }
    int getX() { // fungsi untuk membaca/mengambil nilai dalam x
        return x;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        cout << "Masukkan jejari: ";
        int r;
        cin >> r;
        setX(r);
    }

    float Luas(int r) {
        return 3.14 * r * r;
    }

    float Keliling(int r) {
        return 2 * 3.14 * r;
    }
};

class Bujursangkar : public bidangDatar {
public:
    void input() {
        cout << "Masukkan sisi: ";
        int s;
        cin >> s;
        setX(s);
    }

    float Luas(int s) {
        return s * s;
    }

    float Keliling(int s) {
        return 4 * s;
    }
};

int main() {
    bidangDatar* b;

    cout << "Lingkaran dibuat" << endl;
    b = new Lingkaran();
    b->input();
    int r = b->getX();
    cout << "Luas Lingkaran = " << b->Luas(r) << endl;
    cout << "Keliling Lingkaran = " << b->Keliling(r) << endl;

    cout << "Bujursangkar dibuat\n" << endl;
    b = new Bujursangkar();
    b->input();
    int s = b->getX();
    cout << "Luas Bujursangkar = " << b->Luas(s) << endl;
    cout << "Keliling Bujursangkar = " << b->Keliling(s) << endl;

    delete b;
    return 0;
}