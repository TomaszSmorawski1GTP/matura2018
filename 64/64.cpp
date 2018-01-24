#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Bit parzysto�ci ci�gu z�o�onego z zer i jedynek jest r�wny 0, gdy w ci�gu tym wyst�puje parzysta
liczba jedynek, w przeciwnym razie bit parzysto�ci jest r�wny 1.
Czarno-bia�y obrazek rozmiaru n � n sk�ada si� z n wierszy po n pikseli. Ka�dy wiersz pikseli
reprezentujemy jako ci�g zer i jedynek, ka�dy bia�y piksel reprezentujemy przez 0, czarny �
przez 1. Na ko�cu ka�dego wiersza dodany jest bit parzysto�ci, podobnie pod ostatnim wierszem
obrazka do��czony jest wiersz bit�w parzysto�ci ka�dej z n kolumn. Bit�w parzysto�ci
nie traktujemy jako cz�ci obrazka.
Plik dane_obrazki.txt sk�ada si� z opisu 200 czarno-bia�ych obrazk�w o rozmiarze
20 � 20 pikseli. S�siednie obrazki oddzielone s� w pliku pustym wierszem.
*/

/* Wyniki
64.1: 13, 381
*/

const int SIZE = 200;
ifstream in("dane_obrazki.txt");
char tab[21][21];

void readPicture() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 20 && j == 20) return;
      in >> tab[i][j];
    }
  }
}

void displayPicture() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

/*
Obrazek nazywamy rewersem, je�li liczba wyst�puj�cych w nim pikseli czarnych jest wi�ksza
od liczby pikseli bia�ych.
Przyk�ad: W obrazku z powy�szego przyk�adu wyst�puje 18 pikseli czarnych i 7 pikseli
bia�ych. Zatem jest on rewersem.
Podaj, ile jest w pliku obrazk�w, kt�re s� rewersami. Podaj te� najwi�ksz� liczb� pikseli czarnych
wyst�puj�cych w jednym obrazku. 
*/

bool isRewers() {
  int black = 0, white = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (tab[i][j] == '0') white++;
      if (tab[i][j] == '1') black++;
    }
  }
  return black > white;
}

int countBlacks() {
  int counter = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (tab[i][j] == '1') counter++;
    }
  }
  return counter;
}

int main() {
  int rewersCounter = 0, maxBlacks = 0;
  
  for (int i = 0; i < SIZE; i++) {
    readPicture();
    if (isRewers()) rewersCounter++;
    if (countBlacks() > maxBlacks) maxBlacks = countBlacks();
  }
  
  cout << "Zadanie 1:" << endl;
  cout << "Rewersow: " << rewersCounter << endl;
  cout << "Najwieksza ilosc czarnych: " << maxBlacks;
}




