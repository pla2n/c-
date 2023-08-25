#include <iostream>
using std::cout;
using std::endl;

class Car
{
private:
    int gasolineGauge;
public:
    Car(int n) : gasolineGauge(n)
    {

    }
    int GetGasGauge()
    {
        return gasolineGauge;
    }
};

class HybridCar : public Car
{
private:
    int electricGauge;
public:
    HybridCar(int a, int b) : Car(a), electricGauge(b)
    {

    }
    int GetElecGauge()
    {
        return electricGauge;
    }
};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;
public:
    HybridWaterCar(int a, int b, int c) : HybridCar(a, b), waterGauge(c)
    {

    }
    void ShowCurrentGauge()
    {
        cout << "잔여 가솔린: " << GetGasGauge() << endl;
        cout << "잔여 전기량: " << GetElecGauge() << endl;
        cout << "잔여 워터량: " << waterGauge << endl;
    }
};
int main()
{
    HybridWaterCar a(10, 20, 30);
    a.ShowCurrentGauge();
    return 0;
}