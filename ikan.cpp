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

struct karayawan
{
    int idKarayawan;
    string namaKarayawan;
    int umurKarayawan;
    karayawan *next;
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
int editIkan(ikan *head);
int hapusIkan(ikan **head);
bool compareByHargaDescending(ikan *a, ikan *b);
bool compareByBeratDescending(ikan *a, ikan *b);
bool compareByUmurDescending(ikan *a, ikan *b);
void shellSort(ikan **headRef, bool (*compare)(ikan *, ikan *));
int getLength(ikan *head);
ikan *getNodeAt(ikan *head, int index);
void mergeSort(ikan **headRef, bool (*compare)(ikan *, ikan *));
void mergeSortedLists(ikan *list1, ikan *list2, ikan **headRef, bool (*compare)(ikan *, ikan *));
void splitList(ikan *source, ikan **front, ikan **back);
bool compareByHarga(ikan *a, ikan *b);
bool compareByBerat(ikan *a, ikan *b);
bool compareByUmur(ikan *a, ikan *b);
void fibonacciSearchExact(ikan *head, float keyHarga);
void jumpSearchByUmur(ikan *head, int keyUmur);
void boyerMooreSearch(ikan *head, string pattern);
void preprocessBadChar(string pattern, vector<int> &badChar);

int main()
{
    system("cls || clear");
    ikan *linkedListIkan = nullptr;
    int status;
    int pilihan;
    float keyHarga;
    int keyUmur;
    string pattern;

    const int menuCount = 13;
    int Set[menuCount] = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
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
                status = editIkan(linkedListIkan);
                if (status == -1)
                {
                    cout << "Ikan tidak ditemukan" << endl;
                    system("pause");
                    system("cls || clear");
                }
                else if (status == -2)
                    system("cls || clear");
                else
                {
                    cout << "Ikan berhasil diubah" << endl;
                    system("pause");
                    system("cls || clear");
                }
                system("cls || clear");
                break;
            case 3:
                system("cls || clear");
                status = hapusIkan(&linkedListIkan);
                if (status == 1)
                {
                    cout << "Ikan berhasil dihapus (Mode Stack - Pop)." << endl;
                }
                system("pause");
                break;
            case 4:
                system("cls || clear");
                cout << "Tambah Karyawan";
                break;
            case 5:
                system("cls || clear");
                cout << "Lihat Karyawan";
                break;
            case 6:
                system("cls || clear");
                cout << "Pecat Karyawan";
                break;
            case 7:
                system("cls || clear");
                mergeSort(&linkedListIkan, compareByHarga);
                cout << "Data ikan berhasil diurutkan secara Ascending menggunakan Merge Sort" << endl
                     << endl;
                tampilkanIkan(linkedListIkan);
                break;
            case 8:
                system("cls || clear");
                cout << "Data ikan berhasil diurutkan secara Descending menggunakan Shell Sort" << endl
                     << endl;
                shellSort(&linkedListIkan, compareByHargaDescending);
                tampilkanIkan(linkedListIkan);
                break;
            case 9:
                system("cls || clear");
                cout << " == PROGRAM SEARCH FIBONACCI HARGA IKAN ==" << endl;
                cout << "=========================================" << endl;
                if (linkedListIkan == NULL)
                {
                    cout << "Data ikan masih kosong" << endl;
                    system("pause");
                    system("cls || clear");
                    break;
                }
                else
                {
                    mergeSort(&linkedListIkan, compareByHarga);
                    keyHarga = getFloatInput("Masukkan harga ikan yang ingin dicari : ");
                    fibonacciSearchExact(linkedListIkan, keyHarga);
                    system("pause");
                    break;
                }
            case 10:
                system("cls || clear");
                cout << " == PROGRAM SEARCH JUMP UMUR IKAN ==" << endl;
                cout << "=========================================" << endl;
                if (linkedListIkan == NULL)
                {
                    cout << "Data ikan masih kosong" << endl;
                    system("pause");
                    system("cls || clear");
                    break;
                }
                else
                {
                    mergeSort(&linkedListIkan, compareByUmur);
                    keyUmur = getIntInput("Masukkan umur ikan yang ingin dicari : ");
                    jumpSearchByUmur(linkedListIkan, keyUmur);
                    system("pause");
                    break;
                }
            case 11:
                system("cls || clear");
                cout << " == PROGRAM SEARCH BOYER-MOORE NAMA IKAN ==" << endl;
                cout << "=========================================" << endl;
                if (linkedListIkan == NULL)
                {
                    cout << "Data ikan masih kosong" << endl;
                    system("pause");
                    system("cls || clear");
                    break;
                }
                else
                {
                    pattern = getStringInput("Masukkan nama ikan yang ingin dicari : ");
                    boyerMooreSearch(linkedListIkan, pattern);
                    system("pause");
                    break;
                }
            }
            if (counter == menuCount - 1)
            {
                break;
            }
        }

        Set[counter] = 12;

        system("cls || clear");
        displayGambarIkan();
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
        "3. Edit Ikan",
        "4. Hapus Ikan (Pop)",
        "5. Tambah Karyawan (Queue)",
        "6. Lihat Karayawan",
        "7. Pecat Karyawan (Dequeue)",
        "8. Merge Sort Harga Ikan (ASC)",
        "9. Shell Sort Harga Ikan (DSC)",
        "10. Search Fibonacci (Harga Ikan)",
        "11. Search Jump (Umur Ikan)",
        "12. Search Boyer-Moore (Nama Ikan)",
        "13. Keluar Program"};

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

int editIkan(ikan *head)
{
    cout << "   == Pilih Ikan untuk Di-Edit ==" << endl;
    cout << "====================================" << endl;
    if (head == NULL)
    {
        cout << "Data ikan masih kosong" << endl;
        system("pause");
        return -2;
    }
    else
    {
        ikan *temp = head;
        int selectedIndex = 0;
        char key;

        while (true)
        {
            system("cls || clear");
            cout << "   == Pilih Ikan untuk Di-Edit ==" << endl;
            cout << "====================================" << endl;
            gotoxy(0, 2);

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

                temp->jenisIkan = getStringInput("Nama ikan \t\t: ");
                temp->umurIkan = getIntInput("Umur ikan (Bulan)\t: ");
                temp->hargaIkan = getIntInput("Harga ikan \t\t: Rp. ");
                return 1;
                system("pause");
                break;
            }
            else if (key == 27)
            {
                return -2;
                break;
            }
        }
    }
};

int hapusIkan(ikan **head)
{
    ikan *temp = *head;
    ikan *prev = NULL;

    if (*head == NULL)
    {
        cout << "Data ikan masih kosong cuy" << endl;
        return -1;
    }

    *head = (*head)->next;
    delete temp;
    return 1;
}

int getLength(ikan *head)
{
    int length = 0;
    while (head != nullptr)
    {
        length++;
        head = head->next;
    }
    return length;
}

ikan *getNodeAt(ikan *head, int index)
{
    int counter = 0;
    ikan *current = head;
    while (current != nullptr && counter < index)
    {
        current = current->next;
        counter++;
    }
    return current;
}

void shellSort(ikan **headRef, bool (*compare)(ikan *, ikan *))
{
    int n = getLength(*headRef);

    for (int gap = n / 2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i++)
        {

            ikan *temp = getNodeAt(*headRef, i);
            ikan *current = getNodeAt(*headRef, i - gap);

            int j = i;
            while (j >= gap && compare(current, temp))
            {
                ikan *nextCurrent = getNodeAt(*headRef, j - gap);

                swap(getNodeAt(*headRef, j)->idIkan, current->idIkan);
                swap(getNodeAt(*headRef, j)->jenisIkan, current->jenisIkan);
                swap(getNodeAt(*headRef, j)->umurIkan, current->umurIkan);
                swap(getNodeAt(*headRef, j)->hargaIkan, current->hargaIkan);

                j -= gap;
                if (j >= gap)
                    current = nextCurrent;
            }
        }
    }
}

bool compareByHargaDescending(ikan *a, ikan *b)
{
    return a->hargaIkan < b->hargaIkan;
}

bool compareByUmurDescending(ikan *a, ikan *b)
{
    return a->umurIkan < b->umurIkan;
}

void splitList(ikan *source, ikan **front, ikan **back)
{
    ikan *slow;
    ikan *fast;

    slow = source;
    fast = source->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

ikan *mergeSortedLists(ikan *list1, ikan *list2, bool (*compare)(ikan *, ikan *))
{
    ikan *result = nullptr;

    if (list1 == nullptr)
        return list2;
    else if (list2 == nullptr)
        return list1;

    if (compare(list1, list2))
    {
        result = list1;
        result->next = mergeSortedLists(list1->next, list2, compare);
    }
    else
    {
        result = list2;
        result->next = mergeSortedLists(list1, list2->next, compare);
    }

    return result;
}

void mergeSort(ikan **headRef, bool (*compare)(ikan *, ikan *))
{
    ikan *head = *headRef;
    ikan *list1;
    ikan *list2;

    if ((head == nullptr) || (head->next == nullptr))
    {
        return;
    }

    splitList(head, &list1, &list2);

    mergeSort(&list1, compare);
    mergeSort(&list2, compare);

    *headRef = mergeSortedLists(list1, list2, compare);
}

bool compareByHarga(ikan *a, ikan *b)
{
    return a->hargaIkan <= b->hargaIkan;
}

bool compareByUmur(ikan *a, ikan *b)
{
    return a->umurIkan <= b->umurIkan;
}

void fibonacciSearchExact(ikan *head, float keyHarga)
{
    int n = getLength(head);

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);
        ikan *current = getNodeAt(head, i);

        if (current->hargaIkan < keyHarga)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (current->hargaIkan > keyHarga)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            cout << "\nIkan dengan harga " << keyHarga << " ditemukan:" << endl;

            ikan *foundIkan = current;
            cout << "ID: " << foundIkan->idIkan
                 << ", Nama: " << foundIkan->jenisIkan
                 << ", Umur: " << foundIkan->umurIkan
                 << ", Harga: " << foundIkan->hargaIkan << endl;

            int backwardIndex = i - 1;
            while (backwardIndex >= 0)
            {
                ikan *previousIkan = getNodeAt(head, backwardIndex);
                if (previousIkan->hargaIkan == keyHarga)
                {
                    cout << "\nDetail Ikan yang ditemukan:" << endl;
                    cout << "=========================================" << endl;
                    cout << "ID Ikan \t: " << previousIkan->idIkan << endl;
                    cout << "Nama Ikan \t: " << previousIkan->jenisIkan << endl;
                    cout << "Umur Ikan \t: " << previousIkan->umurIkan << " Bulan" << endl;
                    cout << "Harga Ikan \t: Rp. " << fixed << setprecision(2) << previousIkan->hargaIkan << endl;
                    cout << "====================================" << endl;
                }
                else
                {
                    break;
                }
                backwardIndex--;
            }

            int forwardIndex = i + 1;
            while (forwardIndex < n)
            {
                ikan *nextIkan = getNodeAt(head, forwardIndex);
                if (nextIkan->hargaIkan == keyHarga)
                {
                    cout << "Detail Ikan yang ditemukan:" << endl;
                    cout << "=========================================" << endl;
                    cout << "ID Ikan \t: " << nextIkan->idIkan << endl;
                    cout << "Nama Ikan \t: " << nextIkan->jenisIkan << endl;
                    cout << "Umur Ikan \t: " << nextIkan->umurIkan << " Bulan" << endl;
                    cout << "Harga Ikan \t: Rp. " << fixed << setprecision(2) << nextIkan->hargaIkan << endl;
                    cout << "====================================" << endl;
                }
                else
                {
                    break;
                }
                forwardIndex++;
            }

            return;
        }
    }

    if (fibMMm1 && getNodeAt(head, offset + 1)->hargaIkan == keyHarga)
    {
        ikan *lastIkan = getNodeAt(head, offset + 1);
        cout << "\nIkan dengan harga " << keyHarga << " ditemukan:" << endl;
        cout << "Detail Ikan yang ditemukan:" << endl;
        cout << "=========================================" << endl;
        cout << "ID Ikan \t: " << lastIkan->idIkan << endl;
        cout << "Nama Ikan \t: " << lastIkan->jenisIkan << endl;
        cout << "Umur Ikan \t: " << lastIkan->umurIkan << " Bulan" << endl;
        cout << "Harga Ikan \t: Rp. " << fixed << setprecision(2) << lastIkan->hargaIkan << endl;
        cout << "====================================" << endl;
    }
    else
    {
        cout << "\nIkan dengan harga " << keyHarga << " tidak ditemukan." << endl;
    }
}

void jumpSearchByUmur(ikan *head, int keyUmur)
{
    if (head == nullptr)
    {
        cout << "Linked List kosong." << endl;
        return;
    }

    // Hitung panjang linked list
    int n = getLength(head);
    int jump = sqrt(n); // Ukuran langkah
    int prev = 0;

    ikan *current = head;
    int i = 0;
    unordered_set<int> foundIDs; // Set untuk menyimpan ID yang sudah ditemukan

    while (current != nullptr && current->umurIkan < keyUmur)
    {
        prev = i;
        for (int j = 0; j < jump && current != nullptr; j++)
        {
            current = current->next;
            i++;
        }
    }

    if (prev < n && getNodeAt(head, prev)->umurIkan == keyUmur)
    {
        ikan *foundIkan = getNodeAt(head, prev);
        if (foundIDs.find(foundIkan->idIkan) == foundIDs.end())
        {
            foundIDs.insert(foundIkan->idIkan);
            cout << "\nDetail Ikan yang ditemukan:" << endl;
            cout << "=========================================" << endl;
            cout << "ID Ikan \t: " << foundIkan->idIkan << endl;
            cout << "Nama Ikan \t: " << foundIkan->jenisIkan << endl;
            cout << "Umur Ikan \t: " << foundIkan->umurIkan << " Bulan" << endl;
            cout << "Harga Ikan \t: Rp. " << fixed << setprecision(2) << foundIkan->hargaIkan << endl;
            cout << "====================================" << endl;
        }
    }

    if (current != nullptr && current->umurIkan == keyUmur)
    {
        while (current != nullptr && current->umurIkan == keyUmur)
        {
            if (foundIDs.find(current->idIkan) == foundIDs.end())
            {
                cout << "Ikan dengan umur " << keyUmur << " ditemukan:" << endl;
                foundIDs.insert(current->idIkan);
                cout << "ID: " << current->idIkan
                     << ", Nama: " << current->jenisIkan
                     << ", Umur: " << current->umurIkan
                     << ", Harga: " << current->hargaIkan << endl;
                cout << "====================================" << endl;
            }
            current = current->next;
        }
    }
    else
    {
        cout << "Ikan dengan umur " << keyUmur << " tidak ditemukan." << endl;
    }
}

void preprocessBadChar(string pattern, vector<int> &badChar)
{
    int m = pattern.size();
    for (int i = 0; i < 256; i++)
    {
        badChar[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        badChar[(int)pattern[i]] = i;
    }
}

void boyerMooreSearch(ikan *head, string pattern)
{
    vector<int> badChar(256);
    preprocessBadChar(pattern, badChar);

    ikan *current = head;
    int id = 0;

    while (current != nullptr)
    {
        string name = current->jenisIkan;
        int n = name.size();
        int m = pattern.size();

        int s = 0;
        while (s <= (n - m))
        {
            int j = m - 1;

            while (j >= 0 && pattern[j] == name[s + j])
            {
                j--;
            }

            if (j < 0)
            {
                cout << "\nIkan dengan nama \"" << pattern << "\" ditemukan:" << endl;
                cout << "=========================================" << endl;
                cout << "ID Ikan \t: " << current->idIkan << endl;
                cout << "Nama Ikan \t: " << current->jenisIkan << endl;
                cout << "Umur Ikan \t: " << current->umurIkan << " Bulan" << endl;
                cout << "Harga Ikan \t: Rp. " << fixed << setprecision(2) << current->hargaIkan << endl;
                cout << "====================================" << endl;
                s += (s + m < n) ? m - badChar[name[s + m]] : 1;
                return;
            }
            else
            {
                s += max(1, j - badChar[name[s + j]]);
            }
        }

        current = current->next;
        id++;
    }

    cout << "Ikan dengan nama \"" << pattern << "\" tidak ditemukan." << endl;
}