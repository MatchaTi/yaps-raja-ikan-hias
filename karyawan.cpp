#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

struct karyawan
{
    int idKaryawan;
    string namaKaryawan;
    int umurKaryawan;
    karyawan *next;
};

karyawan *head = nullptr;
karyawan *tail = nullptr;

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

void enqueueKaryawan(karyawan **head, karyawan **tail)
{
    karyawan *nodeKaryawan = new karyawan;
    cout << "           == Tambah Karyawan ==" << endl;
    cout << "=========================================" << endl;
    while (true)
    {
        nodeKaryawan->idKaryawan = getIntInput("ID Karyawan \t\t: ");
        bool isUnique = true;
        karyawan *current = *head;
        while (current != NULL)
        {
            if (current->idKaryawan == nodeKaryawan->idKaryawan)
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
            cout << "ID karyawan sudah ada. Silakan masukkan ID yang berbeda." << endl;
        }
    }
    nodeKaryawan->namaKaryawan = getStringInput("Nama Karyawan \t: ");
    nodeKaryawan->umurKaryawan = getIntInput("Umur Karyawan \t: ");
    if (*head == nullptr)
    {
        *head = nodeKaryawan;
        *tail = nodeKaryawan;
    }
    else
    {
        (*tail)->next = nodeKaryawan;
        *tail = nodeKaryawan;
    }
}

void displayKaryawan(karyawan *head)
{
    karyawan *current = head;
    while (current != NULL)
    {
        cout << "ID Karyawan \t: " << current->idKaryawan << endl;
        cout << "Nama Karyawan \t: " << current->namaKaryawan << endl;
        cout << "Umur Karyawan \t: " << current->umurKaryawan << " Tahun" << endl;
        cout << "====================================" << endl;
        current = current->next;
    }
}

int main(int argc, char const *argv[])
{
    int pilihanTambah;
    do
    {
        cout << "           == Menu Utama ==" << endl;
        cout << "====================================" << endl;
        cout << "1. Tambah Karyawan" << endl;
        cout << "2. Tampilkan Karyawan" << endl;
        cout << "3. Keluar" << endl;
        cout << "====================================" << endl;
        pilihanTambah = getIntInput("Masukkan pilihan : ");
        switch (pilihanTambah)
        {
        case 1:
            enqueueKaryawan(&head, &tail);
            break;
        case 2:
            displayKaryawan(head);
            break;
        case 3:
            cout << "Program selesai. Sampai jumpa!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }
    } while (pilihanTambah != 3);

    return 0;
}
