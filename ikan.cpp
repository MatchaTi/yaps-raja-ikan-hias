#include <iostream>
#include <conio.h>
#include <windows.h>
#include <limits>
#include <iomanip>
#include <cmath>
#include <vector>
#include <unordered_set>

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

void color(int color);
void gotoxy(int x, int y);
void displayMenu(int Set[], int menuCount);
void displayGambarIkan();
float getFloatInput(const string &prompt);
string getStringInput(const string &prompt);
int getIntInput(const string &prompt);
void tambahIkan(ikan **head);
void tampilkanIkan(ikan *head);
void display(ikan *head, int *counter);
bool isEmpty(ikan *head);

int main()
{
    system("cls || clear");
    ikan *linkedListIkan = NULL;
    int status;
    int pilihan;
    float keyHarga;
    int keyUmur;
    string pattern;

    const int menuCount = 12;
    int Set[menuCount] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
    int counter = 0;
    char key;

    displayGambarIkan();
    displayMenu(Set, menuCount);

    while (true)
    {
        key = _getch();

        if (key == 72 && counter > 0)
        {
            Set[counter] = 7;
            counter--;
        }
        if (key == 80 && counter < menuCount - 1)
        {
            Set[counter] = 7;
            counter++;
        }

        if (key == '\r')
        {
            gotoxy(0, 28);
            cout << "You selected option " << counter + 1 << "                    ";
            switch (counter)
            {
            case 0:
                system("cls || clear");
                tambahIkan(&linkedListIkan);
                system("pause");
                system("cls || clear");
                break;
            case 1:
                system("cls || clear");
                tampilkanIkan(linkedListIkan);
                break;
            case 2:
                system("cls || clear");
                cout << "Edit Ikan";
                break;
            case 3:
                system("cls || clear");
                cout << "Hapus Ikan";
                break;
            case 4:
                system("cls || clear");
                cout << "Tambah Karyawan";
                break;
            case 5:
                system("cls || clear");
                cout << "Pecat Karyawan";
                break;
            case 6:
                system("cls || clear");
                cout << "Merge Sort Harga Ikan (ASC)";
                break;
            case 7:
                system("cls || clear");
                cout << "Shell Sort Harga Ikan (DSC)";
                break;
            case 8:
                system("cls || clear");
                cout << "Search Fibonacci (Harga Ikan)";
                break;
            case 9:
                system("cls || clear");
                cout << "Search Jump (Umur Ikan)";
                break;
            case 10:
                system("cls || clear");
                cout << "Search Boyer-Moore (Nama Ikan)";
                break;
            }
            if (counter == menuCount - 1)
            {
                break;
            }
        }

        Set[counter] = 12;

        displayMenu(Set, menuCount);
    }

    return 0;
}

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void displayMenu(int Set[], int menuCount)
{

    string menu[] = {
        "1. Tambah Ikan (Stack)",
        "2. Tampilkan Ikan",
        "3. Edit Ikan (Stack)",
        "4. Hapus Ikan (Pop)",
        "5. Tambah Karyawan (Queue)",
        "6. Pecat Karyawan (Dequeue)",
        "7. Merge Sort Harga Ikan (ASC)",
        "8. Shell Sort Harga Ikan (DSC)",
        "9. Search Fibonacci (Harga Ikan)",
        "10. Search Jump (Umur Ikan)",
        "11. Search Boyer-Moore (Nama Ikan)",
        "12. Keluar Program"};

    for (int i = 0; i < menuCount; i++)
    {
        gotoxy(0, 16 + i);
        color(Set[i]);
        cout << menu[i] << endl;
    }
}

void displayGambarIkan()
{
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
}

float getFloatInput(const string &prompt)
{
    float value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus berupa angka desimal. Silakan coba lagi." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

string getStringInput(const string &prompt)
{
    string value;
    while (true)
    {
        cout << prompt;
        getline(cin, value);

        if (value.empty() || value.find(' ') != string::npos)
        {
            cout << "Input tidak boleh kosong atau mengandung spasi. Silakan coba lagi." << endl;
        }
        else
        {
            return value;
        }
    }
}

int getIntInput(const string &prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus berupa angka. Silakan coba lagi." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void tambahIkan(ikan **head)
{
    ikan *nodeIkan = new ikan;
    cout << "           == Tambah Ikan ==" << endl;
    cout << "=========================================" << endl;
    while (true)
    {
        nodeIkan->idIkan = getIntInput("ID Ikan \t\t: ");
        bool isUnique = true;
        ikan *current = *head;
        while (current != NULL)
        {
            if (current->idIkan == nodeIkan->idIkan)
            {
                isUnique = false;
                break;
            }
            current = current->next;
        }

        if (isUnique)
        {
            break;
        }
        else
        {
            cout << "ID ikan sudah ada. Silakan masukkan ID yang berbeda." << endl;
        }
    }
    nodeIkan->jenisIkan = getStringInput("Nama Ikan \t\t: ");
    nodeIkan->umurIkan = getIntInput("Umur Ikan (Bulan)\t: ");
    nodeIkan->hargaIkan = getIntInput("Harga Ikan\t\t: Rp. ");

    nodeIkan->next = *head;
    *head = nodeIkan;

    system("cls || clear");
    cout << "Ikan berhasil ditambahkan." << endl;
}

void tampilkanIkan(ikan *head)
{
    int selectedIndex = 0;
    char key;

    cout << "           == Tampilkan Ikan ==" << endl;
    cout << "=========================================\n"
         << endl;

    if (head == NULL)
    {
        cout << "Data ikan masih kosong" << endl;
        system("pause");
        system("cls || clear");
        return;
    }

    while (true)
    {
        gotoxy(0, 4);
        color(selectedIndex == 0 ? 12 : 7);
        cout << "1. Semua Ikan" << endl;

        gotoxy(0, 5);
        color(selectedIndex == 1 ? 12 : 7);
        cout << "2. Peek Ikan" << endl;

        gotoxy(0, 6);
        color(selectedIndex == 2 ? 12 : 7);
        cout << "3. Kembali ke Menu Utama" << endl;

        key = _getch();

        if (key == 72 && selectedIndex > 0)
        {
            selectedIndex--;
        }
        else if (key == 80 && selectedIndex < 2)
        {
            selectedIndex++;
        }
        else if (key == '\r')
        {
            system("cls || clear");
            if (selectedIndex == 0)
            {
                ikan *temp = head;
                selectedIndex = 0;

                while (true)
                {
                    system("cls || clear");
                    gotoxy(0, 0);

                    cout << "ID\tJenis\tUmur\tHarga\tPakan\n";
                    cout << "-------------------------------------\n";

                    temp = head;
                    int index = 0;

                    while (temp != nullptr)
                    {
                        if (index == selectedIndex)
                        {
                            color(12);
                        }
                        else
                        {
                            color(7);
                        }
                        cout << temp->idIkan << "\t" << temp->jenisIkan << "\t" << temp->umurIkan
                             << "\t" << temp->hargaIkan << "\t" << "\n";
                        temp = temp->next;
                        index++;
                    }

                    color(7);
                    key = _getch();
                    if (key == 72 && selectedIndex > 0)
                    {
                        selectedIndex--;
                    }
                    else if (key == 80 && selectedIndex < index - 1)
                    {
                        selectedIndex++;
                    }
                    else if (key == '\r')
                    {
                        temp = head;
                        for (int i = 0; i < selectedIndex; i++)
                        {
                            temp = temp->next;
                        }
                        system("cls || clear");
                        cout << "Detail Ikan yang Dipilih:" << endl;
                        cout << "=========================================" << endl;
                        cout << "ID Ikan \t: " << temp->idIkan << endl;
                        cout << "Nama Ikan \t: " << temp->jenisIkan << endl;
                        cout << "Umur Ikan \t: " << temp->umurIkan << " Bulan" << endl;
                        cout << "Harga Ikan \t: Rp. " << fixed << setprecision(2) << temp->hargaIkan << endl;
                        cout << "====================================" << endl;
                        system("pause");
                        break;
                    }
                    else if (key == 27)
                    {
                        break;
                    }
                }
            }
            else if (selectedIndex == 1)
            {
                if (head != NULL)
                {
                    cout << "ID Ikan \t: " << head->idIkan << endl;
                    cout << "Nama Ikan \t: " << head->jenisIkan << endl;
                    cout << "Umur Ikan \t: " << head->umurIkan << " Bulan" << endl;
                    cout << "Harga Ikan \t: Rp. " << fixed << setprecision(2) << head->hargaIkan << endl;
                    cout << "====================================" << endl;
                }
                else
                {
                    cout << "Data ikan masih kosong" << endl;
                }
                system("pause");
            }
            else if (selectedIndex == 2)
            {
                break;
            }
            system("cls || clear");
        }

        gotoxy(0, 4);
        color(selectedIndex == 0 ? 12 : 7);
        cout << "1. Semua Ikan" << endl;
        color(selectedIndex == 1 ? 12 : 7);
        cout << "2. Peek Ikan" << endl;
        color(selectedIndex == 2 ? 12 : 7);
        cout << "3. Kembali ke Menu Utama" << endl;
    }

    system("cls || clear");
}

void display(ikan *head, int *counter)
{
    ikan *current = head;
    while (current != NULL)
    {
        cout << "ID Ikan \t: " << current->idIkan << endl;
        cout << "Nama Ikan \t: " << current->jenisIkan << endl;
        cout << "Umur Ikan \t: " << current->umurIkan << " Bulan" << endl;
        cout << "Harga Ikan \t: Rp. " << fixed << setprecision(2) << current->hargaIkan << endl;
        cout << "====================================" << endl;
        current = current->next;
        counter++;
    }
}

bool isEmpty(ikan *head)
{
    return head == NULL;
}