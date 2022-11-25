#include <iostream>
#include <ctime>
#include<fstream>
#include <string>
#include "fila.cpp"
#include "mySerial.cpp"

using namespace std;

void readTemp();

void sendSerial();
Fila<float> temp;
mySerial serial("/dev/ttyAMA0", 115200);
string dados;

void sendSerial()  //Envia um nodo da fila
{
    ofstream saida("dados.txt");
    int tam = temp.tamanhoFila();


    for(int i = 0; i < tam; i++ )
    {
        saida << temp.readFirst();
        dados = temp.readFirst();
        temp.removeFirst();

    }
    saida.close();
    serial.Send(dados);
}

void readTemp()
{

    float temperatura;
    int qtde, id = 0;
    //temperatura = leitura_do_sensor;

    //Para testes sem o sensor
    cout <<"Qtde de medidas: ";
    cin >> qtde;

    for(int i = 0; i < qtde; i++)
    {
        cout<<"Insira a temperatura: ";
        cin >> temperatura;
        id++;
        ClockCalendar* novaLeitura;
        temp.insertAfterLast(temperatura, novaLeitura, id);
    }


}

int main()
{

    readTemp();
    temp.listAll();
    sendSerial();


    return 0;
}
