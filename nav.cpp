#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct ikan
{
    int idIkan;
    string jenisIkan;
    int umurIkan;
    int hargaIkan;
    string pakanIkan;
    ikan *next;
};

void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main() {
    int Set[] = {7,7,7};
    int counter = 2;
    char key;

        cout << "=========================================" << endl;
        cout << "               __," << endl;
        cout << "               .-'_-'`" << endl;
        cout << "             .' {`" << endl;
        cout << "         .-'````'-.    .-'``'." << endl;
        cout << "       .'(0)       '._/ _.-.  `\\" << endl;
        cout << "      }     '. ))    _<`    )`  |" << endl;
        cout << "       `-.,\\'.\\_,.-\\` \\`---; .' /" << endl;
        cout << "            )  )       '-.  '--:" << endl;
        cout << "           ( ' (          ) '.  \\" << endl;
        cout << "            '.  )      .'(   /   )" << endl;
        cout << "              )/      (   '.    /" << endl;
        cout << "                       '._( ) .'" << endl;
        cout << "                           ( (" << endl;
        cout << "                            `-." << endl;
        cout << "=========================================" << endl;

    for(int i = 0; ;) {


        gotoxy(0,18);
        color(Set[0]);
        cout << "1. Tambah Ikan";

        gotoxy(0,19);
        color(Set[1]);
        cout << "2. Tampilkan Ikan";

        gotoxy(0,20);
        color(Set[2]);
        cout << "3. Keluar";

        key = _getch();

        if(key == 72 && (counter >= 2 && counter <= 3)) {
            counter--;
        } 
        if(key == 80 && (counter >= 1 && counter <= 2)) {
            counter++;
        } 
        if(key == '\r') {
            if(counter == 1) {
                system("cls");
                cout << "Tambah Ikan";
            } else if(counter == 2) {
                system("cls");
                cout << "Tampilkan Ikan";
            } else if(counter == 3) {
                system("cls");
                cout << "Keluar";
                break;
            }
        }

        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;

        if(counter == 1) {
            Set[0] = 12;
        }
        if(counter == 2) {
            Set[1] = 12;
        }
        if(counter == 3) {
            Set[2] = 12;
        }
    }
    return 0;
}