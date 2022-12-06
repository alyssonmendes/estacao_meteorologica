#include "Fila.cpp"
#include "mySerial.cpp"
#include "temperatura.cpp"

#include <ctime>
#include<fstream>
#include <string>
class Iniciar{
        
    public:
        Fila<float> tempCerto, tempErrado;
        string dados;
        virtual void sendSerial(Fila<float>) = 0;
        virtual void gerarDadosModelo() = 0;
        void readTemp();
        void dentroEsperado(float temperatura, int id);
        virtual ~Iniciar();
};
 
Iniciar::~Iniciar(){}

class Menu: public Iniciar
{
    
public:
    void sendSerial(Fila<float>);
    void readTemp();
    void gerarDadosModelo();
    float temp;
    Menu();
    ~Menu();
};

class Embarcado : public Iniciar{
    public:
    Embarcado();
    void gerarDadosModelo();
    void sendSerial(Fila<float>);
 };
