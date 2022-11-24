#include <iostream>
#include "fila.cpp"
#include <string>
#include <fstream>
//#include "myserial.cpp"
using namespace std;

//mySerial serial("/dev/ttyS1",115200);

class Menu
{
    int select;
    Fila<float>* log =0;
    char* buffer;
    int r;
public:
    Menu();
    ~Menu();
};

Menu::Menu()
{

    cout << "\n\t\tEstacao Meteorologica\n\n";
    cout << "Selecione uma opcao:\n";
    cout << "1. Receber dados\n";
    cout << "2. Filtrar dados por data\n";
    cout << "9. Encerrar programa\n";
    cin >> select;

    while(select != 9)
    {
        switch(select)
        {
        case 1:
            log = new Fila<float>;
            cout << "Recebendo da Serial...\n";
            //ifstream file("shopping_list.txt");

           // if (file.is_open()){
             //   file >> buffer;
               // cout << buffer;
            //}
           // r = serial.Receive(buffer, 16);
            //cout << r << endl;
            //cout << buffer << endl;
            break;
        case 2:
            int d1, m1, a1, d2, m2, a2;
            if(log != 0){
            cout << "Digite o dia 'De': ";
            cin >> d1;
            cout << "Digite o mes 'De': ";
            cin >> m1;
            cout << "Digite o ano 'De': ";
            cin >> a1;
            cout << "Digite o dia 'Ate': ";
            cin >> d2;
            cout << "Digite o mes 'Ate': ";
            cin >> m2;
            cout << "Digite o ano 'Ate': ";
            cin >> a2;
            log->listIntervalo(d1,m1,a1,d2,m2,a2);}
            else{
                cout << "Dados nao recebidos...\n";
            }
            break;
        }
        cout << "Selecione uma opcao:\n ";
        cin >> select;

    }
}

Menu::~Menu(){
    cout << "\nEncerrando o programa...\n";
    cout << log;
    if(log != 0)
        delete log;
}


void readSerial()  //ler a serial e armazenar os valores
{
    int id, d, m, y, h,min,s;
    float temp;
}



void getData(int d1, int m1, int a1, int d2, int m2, int a2)
{
//    log.readSerial();
    /*    if (a.dia >= d1 && a.dia <= d2 && a.mes >= m1 &&  a.mes <= m2 && a.ano <= a1 && a.ano <= a2)
        {
            cout << "Data: " << a.dia <<"/"<< a.mes << "/" << a.ano << "\t Temperatura: " << a.temp << "\t Umidade: " << a.umid <<endl;

        }
    }
    */
}

int main()
{

    Menu m1;

//readSerial();
    return 0;
}
