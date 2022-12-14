#include "Iniciar.cpp"
Menu::Menu()
    {
    int select;
    cout << "\n\t\tEstacao Meteorologica\n\n";
    cout << "\n1. Iniciar leitura do sensor\n";
    cout << "2. Exibir lista de acertos\n";
    cout << "3. Exibir lista de erros\n";
    cout << "4. Enviar dados pela serial\n";
    cout << "5. Gerar arquivo para o modelo\n";
    cout << "6. Apagar dados das leituras\n";
    cout << "9. Encerrar programa\n\n";
    cout << "Selecione uma opcao: ";
    cin >> select;

    while(select != 9)
    {
        switch(select)
        {
        case 1:
        for(int i = 0; i<1000; i++){
              Iniciar::readTemp();
            //delay(1000);
        }
        cout << "1000 leituras realizadas\n";
        cout << tempCerto.tamanhoFila() << " leituras dentro do previsto.\n";
        cout << tempErrado.tamanhoFila() << " leituras fora do previsto.\n";
        break;

        case 2:
            Menu::tempCerto.listAll();               

            break;
        case 3:
            Menu::tempErrado.listAll(); 
            break;
        case 4:
            if(tempCerto.tamanhoFila()>=1){
                Menu::sendSerial(tempCerto);
                cout<<"Enviando leituras CORRETAS para serial\n";
            }
            else
                cout << "Fila vazia!\n";
            break;
        case 5:
            Menu::gerarDadosModelo();
            break;
        case 6:
            if(tempCerto.tamanhoFila()>=1)
                tempCerto.removeAll();
            else
                cout << "Fila de certos vazia!\n";

            if(tempErrado.tamanhoFila()>=1)
                tempErrado.removeAll();
            else
                cout << "Fila de errados vazia!\n";
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

void Menu::sendSerial(Fila<float> fila)  //Envia um nodo da fila
{
    ofstream saida("output_files/dados.txt");
    int tam = fila.tamanhoFila();


for(int i = 0; i < tam; i++ )
{
    saida << fila.enviaFirst();
    dados = fila.enviaFirst();
    fila.removeFirst();

    }
    saida.close();
    
}

void Menu::gerarDadosModelo()  //Faz 1000 leituras e grava arquivo
{
    ofstream modelo("output_files/leituras.txt");
    Fila<float> dadosMod;
    float media =0;    
for(int i = 0; i < 1000; i++ )
{
    for(int j = 0; j < 100; j++){
        media += leituraTemperatura();
    }
    media = media/100;

    dadosMod.insertAfterLast(media, i+1);
    modelo << dadosMod.readFirst() << ",";
    dadosMod.removeFirst();
    media = 0;
    }
    modelo.close();
}
