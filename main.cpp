#include <iostream>
#include <cstring>

using namespace std;

//Deklaracje

void commands();
void menu();
void gra();
void zasady();
char pola[9] = "        ";

//Funkcja początkowego menu

void menu()
{
    cout << "Witaj w grze kółko i krzyżyk!" << endl;
    cout << "   |   |   " << endl;
    cout << "---+---+---" << endl;
    cout << "   |   |   " << endl;
    cout << "---+---+---" << endl;
    cout << "   |   |   " << endl << endl;
    cout << "Komendy: /start, /zasady " << endl;
    commands();
}

//Funkcja obsługi komend

void commands()
{
    char temp[15];
    cin >> temp;
    if(strcmp(temp, "/start") == 0) 
    {
        gra();
    }
    else if(strcmp(temp, "/zasady") == 0) 
    {
        zasady();
    }
    else
    {
        cout << "Nieprawidłowa komenda!" << endl;
        commands();
    }
}

//Funkcja startu gry

void gra() 
{
    //Zmienna tury
    char tura = 'O';
    int temp;
    
    cout << "\n " << pola[0] << " | " << pola[1] << " | " << pola[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << pola[3] << " | " << pola[4] << " | " << pola[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << pola[6] << " | " << pola[7] << " | " << pola[8] << endl;
    cout << "Zaczyna kółko! \"O\"";
    
    for(int i =0;i<9;i++) 
    {
        cin >> temp;
        pola[--temp] = tura;
        if(tura == 'O')
        {
            tura = 'X';
        }
        else
        {
            tura = 'O';
        }
        cout << "\n " << pola[0] << " | " << pola[1] << " | " << pola[2] << endl;
        cout << "---+---+---" << endl;
        cout << " " << pola[3] << " | " << pola[4] << " | " << pola[5] << endl;
        cout << "---+---+---" << endl;
        cout << " " << pola[6] << " | " << pola[7] << " | " << pola[8] << endl;
        cout << "Następna tura! \"" << tura << "\"";
    }
}

//Funkcja wyświetlająca zasady

void zasady() 
{
    cout << "\n--+ ZASADY +--" << endl;
    cout << "Aby zrobić ruch wpisz numer wolnego pola.\nPola numerowane są od lewej do prawej, z góry na dół." << endl;
    commands();
}

//Funkcja main

int main() 
{
    menu();
}