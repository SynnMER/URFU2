#pragma once
#include <conio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
template<typename T>
class Rectangle {
private:
    T x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    double masX[4] = {}, masY[4] = {};
public:
    // ����������� � 4 �����������
    Rectangle(T a, T b, T c, T d) : x1(a), x2(b), y1(c), y2(d) {}
    Rectangle() {}
    // ����������� �� ��������� 
    ~Rectangle() { } // ����������

    Rectangle operator + (const Rectangle& counter) const
    {
        return Rectangle{x1 + counter.x1,x2 + counter.x2 ,y1 + counter.y1 ,y2 + counter.y2 };
    }

    Rectangle operator * (const Rectangle& counter) const
    {
        return Rectangle{ x1 * counter.x1,x2 * counter.x2 ,y1 * counter.y1 ,y2 * counter.y2 };
    }

    void Input() ; // ����� ����� � ����������
    virtual void Peremes(); // �����������
    virtual void Size(); // ��������� �������
    void Min() const; // ���������� ������������
    void �ross() const; // ����������� 2 ���������������
    friend std::ostream& operator<<(std::ostream& stream, const Rectangle& counter);
};

std::ostream& operator<<(std::ostream& stream, const Rectangle<double>& counter)
{
    std::cout << "�� ����� ��������� ���������� ��������������:" << std::endl;
    std::cout << " A:" << "(" << counter.x1 << "," << counter.y1 << ")" << std::endl;
    std::cout << " B:" << "(" << counter.x2 << "," << counter.y1 << ")" << std::endl;
    std::cout << " C:" << "(" << counter.x2 << "," << counter.y2 << ")" << std::endl;
    std::cout << " D:" << "(" << counter.x1 << "," << counter.y2 << ")" << std::endl;
    return stream;
}
class Rec: public Rectangle<double> {
public:
    Rec(double a, double b, double c, double d,double valueDx, double valueDy,double valueR) {
        Rectangle ObjectA(a, b, c, d);
        dx = valueDx;
        dy = valueDy;
        r = valueR;
    }
    Rec(){}
    static double dx, dy, r;

    void Peremes()
    {
        Rectangle::Peremes();
    }
    void Size() {
        Rectangle::Size();
    }

};
double Rec::dx = 0;
double Rec::dy = 0;
double Rec::r = 0;


