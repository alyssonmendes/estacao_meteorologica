void readSerial()  //ler a serial e armazenar os valores
{
    int id, d, m, y, h,min,s;
    float temp;
    string buffer, idt, dia, mes, ano, hora, minuto, segundo, temperatura;
    buffer = "1,22,11,2022,17,26,25,0";
    int pos;
    int length = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
        length++;

    pos = buffer.find(',');
    idt = buffer.substr(0,pos+1);
    dia = buffer.substr(pos, 2);
    pos = buffer.find(',', pos);
    mes = buffer.substr(pos, 2);
    pos = buffer.find(',', pos);
    ano = buffer.substr(pos, 2);
    pos = buffer.find(',', pos);
    hora = buffer.substr(pos, 2);
    pos = buffer.find(',', pos);
    minuto = buffer.substr(pos, 2);
    pos = buffer.find(',', pos);
    segundo = buffer.substr(pos, 2);
    pos = buffer.find(',', pos);
    temperatura = buffer.substr(pos, length - pos);
string::size_type sz;


    id = stoi(idt, &sz);
    d= stoi(dia, &sz);
    m = stoi(mes, &sz);
    y = stoi(ano, &sz);
    h = stoi(hora, &sz);
    min = stoi(minuto, &sz);
    s = stoi(segundo, &sz);
    temp = stof(temperatura, &sz);

    cout << d<<"/"<<m<<"/"<<y<<endl;



}
