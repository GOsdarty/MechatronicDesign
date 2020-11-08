long liczba1;//definicja zmiennych globalnych
long liczba2;
char dzialanie;
long wynik;

void setup() {
  Serial.begin(9600); // okreslamy predkosc transmisji
  Serial.println("Podaj dzialanie np. 5+4");
  Serial.println();
}

void loop() {
  while(Serial.available() > 0) {    // petla dziala gdy mamy mozliwosc odczytu danych z portu szeregowego
    
    liczba1 = Serial.parseInt(); //umożliwia odczytanie kolejnej prawidłowej wartości całkowitej
    dzialanie = Serial.read(); // pobranie operatora dzialania
    liczba2 = Serial.parseInt(); // odczyt wartosci drugiej zmiennej
    obliczanie(); // wywolanie funkcji obliczeniowej
    Serial.print("wynik = ");
    Serial.println(wynik); // wyswietlanie wyniku dzialania
    Serial.println();
    Serial.println("Podaj dzialanie np. 5+4");
  Serial.println();
  }
}

void obliczanie() { // funkcja obliczeniowa
  if (dzialanie == '+') {
    wynik = liczba1 + liczba2;
  }
  else if (dzialanie == '-')  {
    wynik = liczba1 - liczba2; 
  }
  else if (dzialanie == '*')  {
    wynik = liczba1 * liczba2; 
  }
  else if (dzialanie == '/')  {
    wynik = liczba1 / liczba2; 
  }
  else  {
    Serial.println("Zly operator"); 
    Serial.println();
    wynik = 0;
  }
}

