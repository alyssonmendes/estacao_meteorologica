#include <iostream>
#include "fila.cpp"
#include <ctime>
#include "ClockCalendar.cpp"

using namespace std;


class Log: public ClockCalendar
{
    ClockCalendar data;
    float temperatura;
    float umidade;
    fila<float> tempCertos;

public:
    Log();
    ~Log();
    void setTemp();
    void setUmid();
    void setTime();
    void setData(int, int, int);
    fila<float> getTempCertos();


};

void Log::setData(int d, int m, int a)
{
    data.setCalendar(d, m, a);
}

Log readSerial()
{
    Log dados;
    int d, m, a;
    float t, u;

    cout << "Insira o dia: " ;
    cin >> d;
    cout << "Mes: ";
    cin >> m;
    cout << "Ano: ";
    cin >> a;
    dados.setData(d, m, a);
    cout<< "Temperatura: ";
    cin >> t;
    cout<< "Umidade: ";
    cin >> u;

    return dados;
}

void listEvents(int d1, int m1, int a1, int d2, int m2, int a2)
{
    Log a = readSerial();

    if (a.dia >= d1 && a.dia <= d2 && a.mes >= m1 &&  a.mes <= m2 && a.ano <= a1 && a.ano <= a2)
    {
        cout << a;
    }
}

void getData(int d1, int m1, int a1, int d2, int m2, int a2)
{
    Log a = readSerial();
    if (a.dia >= d1 && a.dia <= d2 && a.mes >= m1 &&  a.mes <= m2 && a.ano <= a1 && a.ano <= a2)
    {
        cout << "Data: " << a.dia <<"/"<< a.mes << "/" << a.ano << "\t Temperatura: " << a.temp << "\t Umidade: " << a.umid <<endl;

    }
}

int main()
{

    time_t timetoday;
    time(&timetoday);
    cout << asctime(localtime(&timetoday));

    int hr, min, seg, pm, dia, mes, ano;
    ClockCalendar cc(1,26,1998,8,35,55,0);
    cc.advance(); // no caso de advance() não ser sobrecarregado,
    // em ClockCalendar, sera' preciso especificar
    // cc.Clock::advance() ou cc.Calendar::advance()
    cc.readClock(hr, min, seg, pm);
    cc.readCalendar(dia, mes, ano);
    cout << hr << ":" << min << ":" << seg << " " << pm << endl;
    cout << dia << "/" << mes << "/" << ano << endl;
    float temperatura;

    queue<float> log;

    cout << "Simulacao da UART\n";

    while(temperatura != -9)
    {
        cin >> temperatura;
        log.push(temperatura);
    }
    cout << log.size() << endl;
    int tam_log = log.size();
    for(int i = 0; i < tam_log; i++)
    {
        cout << log.front() << endl;
        log.pop();
    }
    return 0;
}
