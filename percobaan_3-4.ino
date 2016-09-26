#include <LiquidCrystal.h>//library LCD
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);//inisialisasi input
boolean comparatorOutput;// inisialisasi opr boolean

ISR (ANALOG_COMP_vect) { // program interupt
comparatorOutput = true; // inisialisasi nilai true
}
void setup() {
ADCSRB = 0; //nilai ADCSRB=0
ACSR = _BV(ACI)|_BV(ACIE)|_BV(ACIS1);
lcd.begin(16,2);//tampilan LCD kolom dan baris
lcd.clear(); //reset tampilan LCD
lcd.setCursor(0,0);//kursor pada (0,0)
lcd.print("Analog Comparator");//tampilkan Analog
                                   //Comparator
}
void loop() {
if (comparatorOutput==true) { //jika terpenuhi lakukan ..
lcd.setCursor(0,1);//kursor pada 0,1
lcd.print("Comparator High");//tampilkan Comparator High
comparatorOutput = false; //comparator output false
}
else{ //jika tak terpenuhi semua lakukan...
lcd.setCursor(0,1);//letak kursor 0,1
lcd.print("Comparator Low ");//tampilkan Comparator Low
}
delay(1000);//delay 1 detik
}

