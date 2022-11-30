#include "ClockCalendar.h"


time_t now;
tm* ltm = localtime(&now);


Calendar::Calendar()
{
    yr = 1900 + ltm->tm_year; //Armazena o ano
    mo = 1 + ltm->tm_mon;     //Mês
    day = ltm->tm_mday;       //Dia

}
Clock::Clock()
{
    hr =  ltm->tm_hour;   //Hora
    min = ltm->tm_min;  //Minuto
    sec = ltm->tm_sec;       //Segundo
    if(hr > 12)
        is_pm = 1;
    else
        is_pm = 0;
}
ClockCalendar::ClockCalendar():Clock (), Calendar ()
{
    now = time(0);       //Armazena data e hora atual pela biblioteca ctime

    tm* ltm = localtime(&now);
    yr = 1900 + ltm->tm_year; //Armazena o ano
    mo = 1 + ltm->tm_mon;     //Mês
    day = ltm->tm_mday;       //Dia

    hr = ltm->tm_hour;   //Hora
    min =  ltm->tm_min;  //Minuto
    sec = ltm->tm_sec;       //Segundo
    if(hr > 12)
        is_pm = 1;
    else
        is_pm = 0;

}

Calendar::Calendar(int d, int m, int y){
  mo =m;
  day = d;
  yr = y;
 }
Clock::Clock(int h, int m, int s, bool pm){
  hr=h;
  min=m;
  sec=s;
  is_pm=pm;
}
ClockCalendar::ClockCalendar (int d, int mo, int y, int h, int m, int s, bool pm) : Clock (h, m, s, pm), Calendar (d, mo, y){

}

void ClockCalendar::setCalendar(){
    yr = 1900 + ltm->tm_year; //Armazena o ano
    mo = 1 + ltm->tm_mon;     //Mês
    day = ltm->tm_mday;       //Dia

}

void ClockCalendar::setClock(){
    hr =  ltm->tm_hour;   //Hora
    min = ltm->tm_min;  //Minuto
    sec = ltm->tm_sec;       //Segundo
    if(hr > 12)
        is_pm = 1;
    else
        is_pm = 0;
}

void ClockCalendar:: readClock(int& h, int& m,  int& s, bool& pm)
{
    h = hr;
    m = min;
    s = sec;
    pm = is_pm;
    //
}


void ClockCalendar :: readCalendar(int& d, int& m,  int& a)
{
    m = mo;
    d = day;
    a = yr;
    //
}
