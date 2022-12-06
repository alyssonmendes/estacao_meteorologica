#include <iostream>
#include "lib/Fila.cpp"
#include <string>
#include <fstream>
#include "lib/mySerial.cpp"
using namespace std;

mySerial serial("/dev/ttyS1",115200);

class Menu
{
    int select;
    Fila<float>* log = 0;
    string buffer;
    int r;
public:
    int id, d, m, y, h,min,s;
    float temp;
    Menu();
    ~Menu();
    void readLine(string buffer, int &id, int &d, int &m, int &y,int  &h, int &min, int &s, float &temp);
};

Menu::Menu()
{

    cout << "\n\t\tEstacao Meteorologica\n\n";
    cout << "\n1. Receber dados\n";
    cout << "2. Filtrar dados por data\n";
    cout << "9. Encerrar programa\n\n";
    cout << "Selecione uma opcao: ";
    cin >> select;
    ifstream file("output_files/dados.txt");
    while(select != 9)
    {
        switch(select)
        {
        case 1:
            log = new Fila<float>;


            if (file.is_open())
            {
                cout << "Lendo o arquivo...\n";
                while (getline(file, buffer))
                {
                    istringstream iss(buffer);
                    readLine(buffer, id, d, m, y, h,min,s, temp);
                    
                    log->insertAfterLast(id,d,m,y,h,min,s,temp);
                }
                cout << "Arquivo lido...\n";
                log->listAll();
                
                
            /*cout << "Recebendo da Serial...\n";
              r = serial.Receive(buffer, 16);
              cout << r << endl;
              while (getline(file, buffer))
                {
                    istringstream iss(buffer);
                    readLine(buffer, id, d, m, y, h,min,s, temp);
                    log->insertAfterLast(id,d,m,y,h,min,s,temp);
                }*/
                
            }
            else
                cout<< "Arquivo nao encontrado!\n";

            


            

            break;

        case 2:
            int d1, m1, a1, d2, m2, a2;
            if(log != 0)
            {
                cout << "Digite o dia 'De': ";
                cin >> d1;
                while (d1 <=0 || d1 > 31)
                {
                    cout <<"Data invalida!\n";
                    cout << "Digite o dia 'De': ";
                    cin >> d1;

                }
                cout << "Digite o mes 'De': ";
                cin >> m1;
                while (m1 <=0 || m1 > 12)
                {
                    cout <<"Data invalida!\n";
                    cout << "Digite o mes 'De': ";
                    cin >> m1;

                }
                cout << "Digite o ano 'De': ";
                cin >> a1;
                while (a1 <=0 || a1 > 3000)
                {
                    cout <<"Data invalida!\n";
                    cout << "Digite o ano 'De': ";
                    cin >> a1;

                }
                cout << "Digite o dia 'Ate': ";
                cin >> d2;
                while (d2 <=0 || d2 > 31)
                {
                    cout <<"Data invalida!\n";
                    cout << "Digite o dia 'Ate': ";
                    cin >> d2;

                }
                cout << "Digite o mes 'Ate': ";
                cin >> m2;
                while (m2 <=0 || m2 > 12)
                {
                    cout <<"Data invalida!\n";
                    cout << "Digite o mes 'Ate': ";
                    cin >> m2;

                }
                cout << "Digite o ano 'Ate': ";
                cin >> a2;
                while (a2 <=0 || a2 > 3000)
                {
                    cout <<"Data invalida!\n";
                    cout << "Digite o ano 'Ate': ";
                    cin >> a2;

                }
                log->listIntervalo(d1,m1,a1,d2,m2,a2);
            }
            else
                cout << "Dados nao recebidos...\n";

            break;

        default:
            cout << "\nOpcao invalida!\n";
        }
        cout << "\nSelecione uma opcao: ";
        cin >> select;

    }
}

Menu::~Menu()
{
    cout << "\nEncerrando o programa...\n";
    if(log != 0)
        delete log;
}


void Menu::readLine(string buffer, int &id, int &d, int &m, int &y,int  &h, int &min, int &s, float &temp)  //ler a serial e armazenar os valores
{

    string idt, dia, mes, ano, hora, minuto, segundo, temperatura;
    int pos;
    int i =0;
    string delimiter = ",";
    string token;
    while ((pos = buffer.find(delimiter)) != string::npos)
    {
        token = buffer.substr(0, pos);
        //cout << token <<endl;
        switch(i)
        {
        case 0:
            idt = token;
            break;
        case 1:
            dia =token;
            break;
        case 2:
            mes = token;
            break;
        case 3:
            ano = token;
            break;
        case 4:
            hora = token;
            break;
        case 5:
            minuto = token;
            break;
        case 6:
            segundo = token;
            break;
        case 7:

            break;
        }

        buffer.erase(0, pos + delimiter.length());
        i++;
        temperatura = buffer;
    }

    istringstream(idt) >> id;
    istringstream(dia) >> d;
    istringstream(mes) >> m;
    istringstream(ano) >> y;
    istringstream(hora) >> h;
    istringstream(minuto) >> min;
    istringstream(segundo) >> s;
    istringstream(temperatura) >> temp;

}




int main()
{

    Menu m1;

    return 0;
}
