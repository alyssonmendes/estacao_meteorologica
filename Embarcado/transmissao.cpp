#include <iostream>
#include <ctime>
#include<fstream>
#include <string>
#include "../Computador/Fila.cpp"
#include "mySerial.cpp"
#include "temperatura.cpp"
#include <wiringPi.h>

using namespace std;

mySerial serial("/dev/ttyAMA0", 115200);

class Menu
{
    void sendSerial();
    Fila<float> tempCerto, tempErrado;
    string dados;

public:
    void sendSerial(int);
    void readTemp();
    void dentroEsperado(float temperatura, int id);
    float temp;
    Menu();
    ~Menu();
};



Menu::Menu()
    {
    int select;
    cout << "\n\t\tEstacao Meteorologica\n\n";
    cout << "\n1. Iniciar leitura do sensor\n";
    cout << "2. Exibir lista de acertos\n";
    cout << "3. Exibir lista de erros\n";
    cout << "4. Enviar dados pela serial\n";
    cout << "9. Encerrar programa\n\n";
    cout << "Selecione uma opcao: ";
    cin >> select;

    while(select != 9)
    {
        switch(select)
        {
        case 1:
        for(int i = 0; i<10; i++){
            cout << "Lendo temperatura...\n";
            Menu::readTemp();
            delay(1000);
            
        }



        break;

        case 2:
            Menu::tempCerto.listAll();               

            break;
        case 3:
            Menu::tempErrado.listAll(); 
            break;
        case 4:
            Menu::sendSerial();
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
}

void Menu::sendSerial()  //Envia um nodo da fila
{
    ofstream saida("dados.txt");
    int tam = tempCerto.tamanhoFila();


for(int i = 0; i < tam; i++ )
{
    saida << tempCerto.readFirst();
    dados = tempCerto.readFirst();
    tempCerto.removeFirst();

    }
    saida.close();
    serial.Send(dados);
}

void Menu::readTemp()
{

    float temperatura;
    int qtde, id = 1;
    temperatura = leituraTemperatura();
    dentroEsperado(temperatura, id);


    //Para testes sem o sensor
    /*
    cout <<"Qtde de medidas: ";
    cin >> qtde;

    for(int i = 0; i < qtde; i++)
    {
    cout<<"Insira a temperatura: ";
    cin >> temperatura;
    id++;
    temp.insertAfterLast(temperatura,id);
    }

    */
}

void Menu::dentroEsperado(float temperatura, int id){
    
    if(temperatura >= 30 && temperatura <= 45)
        tempCerto.insertAfterLast(temperatura,id);
    else
        tempErrado.insertAfterLast(temperatura,id);
}

int main()
{
    wiringPiSetupSys();
    Menu m1;




return 0;
}
