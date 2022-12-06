#include "Menu.cpp"
#include <wiringPi.h>


mySerial serial("/dev/ttyAMA0", 115200); //inicia a comuncicação serial

void Embarcado::gerarDadosModelo() {    
    Fila<float> dadosMod;
    float media =0;    
    for(int i = 0; i < 1000; i++ )
    {
        for(int j = 0; j < 100; j++){
            media += leituraTemperatura();
        }
        media = media/100;

        dadosMod.insertAfterLast(media, i+1);
        cout  << dadosMod.readFirst() << ",";
        dadosMod.removeFirst();
        media = 0;
        }

    }


Embarcado::Embarcado(){
    
    wiringPiSetup();    // inicia a biblioteca WiringPi
    pinMode(1, INPUT); // configura o pino 1 como ENTRADA

    while(1){           //Lê a temperatura em loop infinito e envia para a serial qual o botao é pressionado
        Iniciar::readTemp();
        
    int tam = tempCerto.tamanhoFila();
        
    if(digitalRead(0)){               //DEFINIR GPIO DE ENTRADA
    for(int i =0; i < tam; i++){
        sendSerial(tempCerto);
        tempCerto.removeFirst();
        }
    }
    
    if(tempErrado.tamanhoFila()>=10){
        tempErrado.listAll();
        delay(10000);
        tempErrado.removeAll();
    }
}

}
void Embarcado::sendSerial(Fila<float> fila)  //Envia um nodo da fila
{
   
    int tam = tempCerto.tamanhoFila();

    for(int i = 0; i < tam; i++ )
        dados = fila.enviaFirst();
        
     serial.Send(dados);
}
