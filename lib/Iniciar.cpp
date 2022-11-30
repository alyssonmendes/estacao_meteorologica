#include "Iniciar.h"

void Iniciar::readTemp() //lê temperatura e insere na fila
{

    float temperatura;
    int id = 1;
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

void Iniciar::dentroEsperado(float temperatura, int id){ //insere na fila correta
    
    if(temperatura >= 40 && temperatura <= 50)
        tempCerto.insertAfterLast(temperatura,id);
    else
        tempErrado.insertAfterLast(temperatura,id);
}
