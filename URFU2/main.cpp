#include "Rectangle.h"
#include <iostream>
using namespace std;
//шаблон класс , все методы шаб
int main() {
    setlocale(LC_ALL, "");
    std::cout << "Прямоугольники \n Справка: \n 1 - Ввод данных \n 2 - Вывод \n 3 - Перемещение \n 4 - изменение размера\n 5 - Минимальный прямоугольник содержащий 2 заданных\n 6 - Прямоугольник получившийся на пересечении 2 заданных\n 0 - выход\n" << std::endl;
    Rec r;
    Rectangle<double> &ObjectA = r; // Создаем объект без параметров, то есть будет использован конструктор по умолчанию
    char Control;
    std::cout << ">";
    std::cin >> Control;

    do
    {
        switch (Control)
        {

        case '1':
            ObjectA.Input();
            std::cout << ">";
            std::cin >> Control;
            break;
        case '2':
            std::cout << ObjectA;
            std::cout << ">";
            std::cin >> Control;
            break;
        case '3':
            ObjectA.Peremes();
            std::cout << ">";
            std::cin >> Control;
            break;
        case '4':
            ObjectA.Size();
            std::cout << ">";
            std::cin >> Control;
            break;
        case '5':
            ObjectA.Min();
            std::cout << ">";
            std::cin >> Control;
            break;
        case '6':
            ObjectA.Сross();
            std::cout << ">";
            std::cin >> Control;
            break;
        case '0': return 0;
        }
    } while (true);

    return 0;
}
template<typename T>
void Rectangle<T>::Input()
{
    std::cout << "Введите координату х левых точек" << std::endl;
    std::cin >> x1;
    std::cout << "Введите координату y верхних точек" << std::endl;
    std::cin >> y1;
    std::cout << "Введите координату х правых точек" << std::endl;
    std::cin >> x2;
    while (x1 > x2) {
        std::cout << "Ошибка.Левая координата больше правой";
        std::cin >> x2;
    }
    std::cout << "Введите координату y нижних точек" << std::endl;
    std::cin >> y2;
    while (y2 > y1)
    {
        std::cout << "Ошибка. Нижняя координата больше верхней";
        std::cin >> y2;
    }
    std::cout << std::endl;

    Rectangle ObjectA(x1, x2, y1, y2);
    masX[0] = ObjectA.x1;
    masX[1] = ObjectA.x2;
    masX[2] = ObjectA.x2;
    masX[3] = ObjectA.x1;
    masY[0] = ObjectA.y1;
    masY[1] = ObjectA.y1;
    masY[2] = ObjectA.y2;
    masY[3] = ObjectA.y2;
}


template<typename T>
void Rectangle<T>::Peremes() {
    Rec rec;
    std::cout << " На сколько единиц вы хотите переместить прямоугольник по оси X ?" << std::endl;
    std::cin >> rec.dx;
    std::cout << " На сколько единиц вы хотите переместить прямоугольник по оси Y ?" << std::endl;
    std::cin >> rec.dy;
    std::cout << std::endl;
    masX[0] = x1+rec.dx;
    masX[1] = x2+rec.dx;
    masX[2] = x2+rec.dx;
    masX[3] = x1+rec.dx;
    masY[0] = y1+rec.dy;
    masY[1] = y1+rec.dy;
    masY[2] = y2+rec.dy;
    masY[3] = y2+rec.dy;
    std::cout << "Получились следующие координаты прямоугольника:" << std::endl;
    std::cout << " A:" << "(" << masX[0] << "," << masY[0] << ")" << std::endl;
    std::cout << " B:" << "(" << masX[1] << "," << masY[1] << ")" << std::endl;
    std::cout << " C:" << "(" << masX[2] << "," << masY[2] << ")" << std::endl;
    std::cout << " D:" << "(" << masX[3] << "," << masY[3] << ")" << std::endl;
}
template<typename T>
void Rectangle<T>::Size() {
    Rec rec;
    std::cout << " Во сколько раз изменяем размер прямоугольника ?" << std::endl;
    std::cin >> rec.r;
    masX[1] = masX[1]+rec.r;
    masX[2] = masX[2]+rec.r;

    masY[0] = masY[0]+rec.r;
    masY[1] = masY[1]+rec.r;
    masY[2] = masY[2]+rec.r;
    masY[3] = masY[3]+rec.r;
    while (masY[0] <= y2 || rec.r == 0 || rec.r < 0 || masY[1] <= y2) {
        std::cout << "Измените r, иначе будет изменение представления прямоугольника (значение r !=0 )";
        std::cin >> rec.r;
    }
    while (masX[2] <= masX[0] || rec.r < 0 || rec.r == 0 || masX[1] <= masX[0]) {
        std::cout << "Измените r, иначе будет изменение представления прямоугольника";
        std::cin >> rec.r;
    }
    std::cout << std::endl;
    std::cout << "Получились следующие координаты прямоугольника:" << std::endl;
    std::cout << " A:" << "(" << masX[0] << "," << masY[0] << ")" << std::endl;
    std::cout << " B:" << "(" << masX[1] << "," << masY[1] << ")" << std::endl;
    std::cout << " C:" << "(" << masX[2] << "," << masY[2] << ")" << std::endl;
    std::cout << " D:" << "(" << masX[3] << "," << masY[3] << ")" << std::endl;

}
template<typename T>
void Rectangle<T>::Min() const{
    double x_min = masX[0], x_max = masX[0], y_min = masY[0], y_max = masY[0],x3,x4,y3,y4;
    std::cout << " 2 прямоугольник:" << std::endl;
    std::cout << "Введите координату х левых точек" << std::endl;
    std::cin >> x3;
    std::cout << "Введите координату y верхних точек" << std::endl;
    std::cin >> y3;
    std::cout << "Введите координату х правых точек" << std::endl;
    std::cin >> x4;

    while (x3 == x4 || x3 > x4) {
        std::cout << "Ошибка. Точки не могут иметь одинаковые координаты";
        std::cin >> x4;
    }
    std::cout << "Введите координату y нижних точек" << std::endl;
    std::cin >> y4;
    while (y4 == y3 || y4 > y3)
    {
        std::cout << "Ошибка. Точки не могут иметь одинаковые координаты";
        std::cin >> y4;
    }
    std::cout << std::endl;
    std::cout << "Вы ввели следующие координаты 1 прямоугольника:" << std::endl;
    std::cout << " A:" << "(" << masX[0] << "," << masY[0] << ")" << std::endl;
    std::cout << " B:" << "(" << masX[1] << "," << masY[1] << ")" << std::endl;
    std::cout << " C:" << "(" << masX[2] << "," << masY[2] << ")" << std::endl;
    std::cout << " D:" << "(" << masX[3] << "," << masY[3] << ")" << std::endl;
    std::cout << std::endl;
    std::cout << "Вы ввели следующие координаты 2 прямоугольника:" << std::endl;
    std::cout << " A:" << "(" << x3 << "," << y3 << ")" << std::endl;
    std::cout << " B:" << "(" << x4 << "," << y3 << ")" << std::endl;
    std::cout << " C:" << "(" << x4 << "," << y4 << ")" << std::endl;
    std::cout << " D:" << "(" << x3 << "," << y4 << ")" << std::endl;
    std::cout << std::endl;
    double A[4] = { masX[0],masX[2],x3,x4 }, B[4] = { masY[0],masY[2],y3,y4 };
    for (int i = 0; i < 4; i++)
    {
        if (x_max < A[i])
        {
            x_max = A[i];
        }
        if (y_max < B[i])
        {
            y_max = B[i];
        }
        if (x_min > A[i])
        {
            x_min = A[i];
        }
        if (y_min > B[i])
        {
            y_min = B[i];
        }
    }
    std::cout << " Наименьший прямоугольник содержащий оба предыдущих имеет следующие координаты: " << std::endl;
    std::cout << " A:" << "(" << x_min << "," << y_max << ")" << std::endl;
    std::cout << " B:" << "(" << x_max << "," << y_max << ")" << std::endl;
    std::cout << " C:" << "(" << x_max << "," << y_min << ")" << std::endl;
    std::cout << " D:" << "(" << x_min << "," << y_min << ")" << std::endl;
}
template<typename T>
void Rectangle<T>::Сross() const {
    double x3, x4, y3, y4, x_min = masX[0], x_max = masX[1], y_min = masY[2], y_max = masY[1], x1_sred, x2_sred, y1_sred, y2_sred;
    
    int k = 0;
    std::cout << " 2 прямоугольник:" << std::endl;
    std::cout << "Введите координату х левых точек" << std::endl;
    std::cin >> x3;
    std::cout << "Введите координату y верхних точек" << std::endl;
    std::cin >> y3;
    std::cout << "Введите координату х правых точек" << std::endl;
    std::cin >> x4;

    while (x3 > x4) {
        std::cout << "Ошибка. ";
        std::cin >> x4;
    }
    std::cout << "Введите координату y нижних точек" << std::endl;
    std::cin >> y4;
    while (y4 > y3)
    {
        std::cout << "Ошибка. ";
        std::cin >> y4;
    }
    /*if (x2 < x3 || x4 < x1 || y2 < y3 || y4 < y1) {
        std::cout << "Прямоугольники не пересекаются\n";
        return;
    }*/
    std::cout << std::endl;
    std::cout << "Вы ввели следующие координаты 1 прямоугольника:" << std::endl;
    std::cout << " A:" << "(" << masX[0] << "," << masY[0] << ")" << std::endl;
    std::cout << " B:" << "(" << masX[1] << "," << masY[1] << ")" << std::endl;
    std::cout << " C:" << "(" << masX[2] << "," << masY[2] << ")" << std::endl;
    std::cout << " D:" << "(" << masX[3] << "," << masY[3] << ")" << std::endl;
    std::cout << std::endl;
    std::cout << "Вы ввели следующие координаты 2 прямоугольника:" << std::endl;
    std::cout << " A:" << "(" << x3 << "," << y3 << ")" << std::endl;
    std::cout << " B:" << "(" << x4 << "," << y3 << ")" << std::endl;
    std::cout << " C:" << "(" << x4 << "," << y4 << ")" << std::endl;
    std::cout << " D:" << "(" << x3 << "," << y4 << ")" << std::endl;
    std::cout << std::endl;
    double A[4] = { masX[0],masX[1],x3,x4 }, B[4] = { masY[1],masY[2],y3,y4 };
    
    if (A[0]<A[2] && A[1]>A[3] && B[0]>B[2] && B[1] <B[3])
    {
        std::cout << " Прямоугольник на пересечении двух предыдущих имеет следующие координаты: " << std::endl;
        std::cout << " A:" << "(" << x3 << "," << y3 << ")" << std::endl;
        std::cout << " B:" << "(" << x4 << "," << y3 << ")" << std::endl;
        std::cout << " C:" << "(" << x4 << "," << y4 << ")" << std::endl;
        std::cout << " D:" << "(" << x3 << "," << y4 << ")" << std::endl;
    }
    else if (A[0] > A[2] && A[1]<A[3] && B[0]<B[2] && B[1] > B[3]) {
        std::cout << " Прямоугольник на пересечении двух предыдущих имеет следующие координаты: " << std::endl;
        std::cout << " A:" << "(" << masX[0] << "," << masY[0] << ")" << std::endl;
        std::cout << " B:" << "(" << masX[1] << "," << masY[1] << ")" << std::endl;
        std::cout << " C:" << "(" << masX[2] << "," << masY[2] << ")" << std::endl;
        std::cout << " D:" << "(" << masX[3] << "," << masY[3] << ")" << std::endl;
    }
    else {
        if ((x_min < x3 < x_max) && (masY[2] < y4 < masY[1]))
            k += 1;
        if ((x_min < x4 < x_max) && (masY[2] < y4 < masY[1]))
            k += 1;
        if ((x_min < x3 < x_max) && (masY[1] > y3 > masY[2]))
            k += 1;
        if ((x_min < x4 < x_max) && (masY[1] > y3 > masY[2]))
            k += 1;

        for (int i = 0; i < 4; i++)
        {
            if (x_max < A[i])
            {
                x_max = A[i];
            }
            if (y_max < B[i])
            {
                y_max = B[i];
            }
            if (x_min > A[i])
            {
                x_min = A[i];
            }
            if (y_min > B[i])
            {
                y_min = B[i];
            }
        }


        for (int i = 0; i < 4; i++)
        {
            if ((A[i] != x_max) && (A[i] != x_min))
            {
                x1_sred = A[i];
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (((A[i] != x_max) && (A[i] != x_min) && (A[i] != x1_sred)))
            {
                x2_sred = A[i];
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if ((B[i] != y_max) && (B[i] != y_min))
            {
                y1_sred = B[i];
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if ((B[i] != y_max) && (B[i] != y_min) && (B[i] != y1_sred))
            {
                y2_sred = B[i];
                break;
            }
        }
        std::cout << " Прямоугольник на пересечении двух предыдущих имеет следующие координаты: " << std::endl;
        std::cout << " A:" << "(" << x2_sred << "," << y1_sred << ")" << std::endl;
        std::cout << " B:" << "(" << x1_sred << "," << y1_sred << ")" << std::endl;
        std::cout << " C:" << "(" << x1_sred << "," << y2_sred << ")" << std::endl;
        std::cout << " D:" << "(" << x2_sred << "," << y2_sred << ")" << std::endl;
    }
    

    

}