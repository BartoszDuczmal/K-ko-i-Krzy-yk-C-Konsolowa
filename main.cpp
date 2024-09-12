#include <iostream>
#include <cstring>

using namespace std;

//Deklaracje

void commands();
void menu();
void game();
void rules();
bool check(char[], char);
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
    commands();
}

//Funkcja obsługi komend

void commands()
{
    char temp[15];
    cout << "Komendy: /start, /zasady " << endl;
    cin >> temp;
    if(strcmp(temp, "/start") == 0) 
    {
        game();
    }
    else if(strcmp(temp, "/zasady") == 0) 
    {
        rules();
    }
    else
    {
        cout << "Nieprawidłowa komenda!" << endl;
        commands();
    }
}

//Funkcja startu gry

void game() 
{
    //Zmienna tury
    char tura = 'O';
    int temp;
    
    cout << "\n " << pola[0] << " | " << pola[1] << " | " << pola[2] << endl;
    cout << "---+---+---" << endl;
    cout << " " << pola[3] << " | " << pola[4] << " | " << pola[5] << endl;
    cout << "---+---+---" << endl;
    cout << " " << pola[6] << " | " << pola[7] << " | " << pola[8] << endl;
    cout << "Zaczyna kółko! \"O\"" << endl;
    
    for(int i =0;i<9;i++) 
    {
        powrot:
        cin >> temp;
        if(temp < 10 && temp > 0)
        {
            if(pola[temp-1] != 'X' && pola[temp-1] != 'O')
            {
                pola[temp-1] = tura;
            }
            else
            {
                cout << "To pole jest już zajęte!" << endl;
                goto powrot;
            }   
        }
        else
        {
            cout << "Nieprawidłowy numer pola!" << endl;
            goto powrot;
        }
        cout << "\n " << pola[0] << " | " << pola[1] << " | " << pola[2] << endl;
        cout << "---+---+---" << endl;
        cout << " " << pola[3] << " | " << pola[4] << " | " << pola[5] << endl;
        cout << "---+---+---" << endl;
        cout << " " << pola[6] << " | " << pola[7] << " | " << pola[8] << endl;
        if(check(pola,tura)) {
            commands();
            break;
        }
        if(tura == 'O')
        {
            tura = 'X';
        }
        else
        {
            tura = 'O';
        }
        if(i!=8) 
        {
            cout << "Następna tura! \"" << tura << "\"" << endl;
        } 
        else 
        {
            cout << "Koniec gry!" << endl;
        }
    }
}

//Funkcja wyświetlająca zasady

void rules() 
{
    cout << "\n--+ ZASADY +--" << endl;
    cout << "Aby zrobić ruch wpisz numer wolnego pola.\nPola numerowane są od lewej do prawej, z góry na dół." << endl;
    commands();
}

bool check(char temp[], char tura)
{
    if(((temp[0] == temp[1]) && (temp[1] == temp[2]) && (temp[0] != ' ')) || ((temp[0] == temp[3]) && (temp[3] == temp[6]) && (temp[0] != ' ')) || ((temp[1] == temp[4]) && (temp[4] == temp[7]) && (temp[1] != ' ')) || ((temp[2] == temp[5]) && (temp[5] == temp[8]) && (temp[2] != ' ')) || ((temp[3] == temp[4]) && (temp[4] == temp[5]) && (temp[3] != ' ')) || ((temp[6] == temp[7]) && (temp[7] == temp[8]) && (temp[6] != ' ')) || ((temp[0] == temp[4]) && (temp[4] == temp[8]) && (temp[0] != ' ')) || ((temp[2] == temp[4]) && (temp[4] == temp[6]) && (temp[2] != ' ')))
    {
        cout << "Wygrał gracz \"" << tura << "\"!" << endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

//Funkcja main

int main() 
{
    menu();
}