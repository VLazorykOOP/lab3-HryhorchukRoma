#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#include <math.h>
#if !defined(CODING_VS_CODE)
	#include <clocale>
#endif
using namespace std;

class Time {
private:
	int hour;
	int min;
	int sec;

public:
	Time() {
		hour = 0;
		min = 0;
		sec = 0;
	}

	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}
	int getHour() const { return hour; }

	void setHour(int newHour) {
		if (newHour >= 0 && newHour <= 23)
			hour = newHour;
	}

	int getMin() const { return min; }

	void setMin(int newMin) {
		if (newMin >= 0 && newMin <= 59)
			min = newMin;
	}

	int getSec() const { return sec; }

	void setSec(int newSec) {
		if (newSec >= 0 && newSec <= 59)
			sec = newSec;
	}

	void print24() {
		std::cout << hour << " годин " << min << " хвилин " << sec << " секунд"
			<< std::endl;
	}

	void print12() {
		if (hour >= 0 && hour <= 12)
			std::cout << hour << " a.m. ";
		else
			std::cout << hour - 12 << " p.m ";
		std::cout << min << " хвилин " << sec << " секунд" << std::endl;
	}
};
class Vector {
    float* arr;
    unsigned int N;
    short int stan;

public:
    Vector() {
        arr = new float[1];
        arr[0] = 0;
        stan = 0;
        N = 1;
    }

    ~Vector() {
        if (arr)
            delete[] arr;
    }

    Vector(int N_) {
        if (N_ <= 0) {
            arr = NULL;
            N = 0;
            stan = -1;
            std::cout << "Error. N <=0. Stan is -1." << std::endl;
        }
        else {
            arr = new float[N_];
            for (int i = 0; i < N_; i++) {
                arr[i] = 0;
            }
            stan = 0;
            N = N_;
        }
    }

    Vector(int N_, float znach) {
        if (N_ <= 0) {
            arr = NULL;
            N = 0;
            stan = -1;
            std::cout << "Error. N <=0. Stan is -1." << std::endl;
        }
        else {
            arr = new float[N_];
            for (int i = 0; i < N_; i++) {
                arr[i] = znach;
            }
            stan = 0;
            N = N_;
        }
    }

    Vector(const Vector& input) {
        if (this != &input) {
            N = input.N;
            arr = new float[N];
            stan = 0;
            for (unsigned int i = 0; i < N; i++)
                arr[i] = input.arr[i];
        }
    }

    Vector& operator=(const Vector& vect) {
        if (N != vect.N) {
            if (arr)
                delete[] arr;
            N = vect.N;
            arr = new float[N];
            stan = 0;
        }
        for (unsigned int i = 0; i < N; i++)
            arr[i] = vect.arr[i];
        return *this;
    }

    void changeElemInPos(unsigned int position, float number) {
        if (arr) {
            if (position <= N) {
                arr[position] = number;
            }
            else
                std::cout << "Error: N > positions in array." << std::endl;
        }
    }

    void printElemInPos(unsigned int pos) { std::cout << arr[pos]; }

    std::ostream& operator<<(std::ostream& os, const Vector& inp) {
        for (unsigned int i = 0; i < inp.N; i++) {
            os << inp.arr[i] << " ";
        }
        return os;
    }

    Vector operator+(const Vector& b) const {
        int resN;
        resN = N < b.N ? N : b.N;
        if (resN >= 0) {
            Vector result(resN);
            for (int i = 0; i < resN; i++) {
                result.arr[i] = arr[i] + b.arr[i];
            }
            return result;
        }
        return Vector(0);
    }

    Vector operator-(const Vector& b) const {
        int resN;
        resN = N < b.N ? N : b.N;
        if (resN >= 0) {
            Vector result(resN);
            for (int i = 0; i < resN; i++) {
                if (arr[i] - b.arr[i] <= 0)
                    result.arr[i] = 0;
                else
                    result.arr[i] = arr[i] - b.arr[i];
            }
            return result;
        }
        return Vector(0);
    }

    Vector operator*(unsigned int num) const {
        Vector result(N);
        for (unsigned int i = 0; i < N; i++) {
            result.arr[i] = arr[i] * num;
        }
        return result;
    }

    bool operator>(const Vector& b) const {
        for (unsigned int i = 0; i < N; i++) {
            if (arr[i] <= b.arr[i])
                return false;
        }
        return true;
    }

    bool operator<(const Vector& b) const {
        for (unsigned int i = 0; i < N; i++) {
            if (arr[i] >= b.arr[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Vector& b) const {
        for (unsigned int i = 0; i < N; i++) {
            if (arr[i] == b.arr[i])
                return false;
        }
        return true;
    }

    bool operator==(const Vector& b) const {
        for (unsigned int i = 0; i < N; i++) {
            if (arr[i] != b.arr[i])
                return false;
        }
        return true;
    }
};

mainExample() {
    // 1
    Time time;
    Time time2(16, 18, 3);
    Time time1(16, 18, 3);
    time1.print24();
    time2.print12();
    std::cout << "min time2: " << time2.getMin() << std::endl;
    // 2
    Vector A(5, 2);                       // arr[5] = {2,2,2,2,2}
    std::cout << "A: " << A << std::endl; // printing A (2,2,2,2,2)
    Vector B(A);                          // copy of A
    Vector C(4, 3);                       // arr[4] = {3,3,3,3}
    std::cout << "B: " << B << std::endl;
    std::cout << "C: " << C << std::endl;
    std::cout << "sum A + C: " << A + C << std::endl;
    std::cout << "is A==B: " << (A == B) << std::endl;
    std::cout << "is A > C: " << (A > C) << std::endl;
    std::cout << "is C < B: " << (C < B) << std::endl;
    std::cout << "is A != C: " << (A != C) << std::endl;
    std::cout << "C - B: " << C - B << std::endl;
    std::cout << "B*3: " << B * 3 << std::endl;
    std::cout << "A.changeElemInPos(2,10)" << std::endl;
    A.changeElemInPos(2, 10);
    std::cout << "Changed A: " << A << std::endl;
    std::cout << "A at pos 2: ";
    A.printElemInPos(2);
    std::cout << std::endl;
    // 3
    matrix Amat(2, 2, 5);
    std::cout << "A:\n" << A << std::endl;
    matrix Bmat(Amat);
    std::cout << "B:\n" << B << std::endl;
    Amat.setElem(1, 1, 2);
    std::cout << "changed A:\n" << A << std::endl;
    matrix Cmat = Amat;
    std::cout << "C:\n" << Cmat << std::endl;
    std::cout << "Objects: " << Cmat.count << std::endl;
    std::cout << "A+B:\n" << Amat + Bmat << std::endl;
    std::cout << "A-B:\n" << Amat - Bmat << std::endl;
    std::cout << "B/5:\n" << Bmat / 5 << std::endl;
    std::cout << "A/0:\n" << Amat / 0 << std::endl;
    std::cout << "A*B:\n" << Amat * Bmat << std::endl;
    std::cout << "A!=B: " << (Amat != Bmat) << std::endl;
    std::cout << "A==C: " << (Amat == Cmat) << std::endl;
    std::cout << "A>B: " << (Amat > Bmat) << std::endl;
    std::cout << "A<B: " << (Amat < Bmat) << std::endl;
}