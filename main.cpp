#include <iostream>
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
    ikan *next;
};

void tambahIkan(ikan **head);
void tampilkanIkan(ikan *head);
int editIkan(ikan *head);
int hapusIkan(ikan **head);
bool isEmpty(ikan *head);
void peek(ikan *head);
void front(ikan *head);
void rear(ikan *head);
float getFloatInput(const string &prompt);
string getStringInput(const string &prompt);
int getIntInput(const string &prompt);
void display(ikan *head);
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
    ikan *linkedListIkan = NULL;
    int status;
    int pilihan;
    float keyHarga;
    int keyUmur;
    string pattern;
    do
    {
        cout << "=========================================" << endl;
           std::cout << "               __," << std::endl;
    std::cout << "               .-'_-'`" << std::endl;
    std::cout << "             .' {`" << std::endl;
    std::cout << "         .-'````'-.    .-'``'." << std::endl;
    std::cout << "       .'(0)       '._/ _.-.  `\\" << std::endl;
    std::cout << "      }     '. ))    _<`    )`  |" << std::endl;
    std::cout << "       `-.,\\'.\\_,.-\\` \\`---; .' /" << std::endl;
    std::cout << "            )  )       '-.  '--:" << std::endl;
    std::cout << "           ( ' (          ) '.  \\" << std::endl;
    std::cout << "            '.  )      .'(   /   )" << std::endl;
    std::cout << "              )/      (   '.    /" << std::endl;
    std::cout << "                       '._( ) .'" << std::endl;
    std::cout << "                           ( (" << std::endl;
    std::cout << "                            `-." << std::endl;
        cout << "=========================================" << endl;
        cout << "           MENU YAPS RAJA IKAN HIAS" << endl;
        cout << "\t1. Tambah Ikan (Stack / Queue)" << endl;
        cout << "\t2. Tampilkan Ikan" << endl;
        cout << "\t3. Edit Ikan" << endl;
        cout << "\t4. Hapus Ikan  (Stack / Queue)" << endl;
        cout << "\t5. Merge Sort Harga Ikan (ASC)" << endl;
        cout << "\t6. Shell Sort Harga Ikan (DSC)" << endl;
        cout << "\t7. Search Fibonacci (Harga Ikan)" << endl;
        cout << "\t8. Search Jump (Umur Ikan)" << endl;
        cout << "\t9. Search Boyer-Moore (Nama Ikan)" << endl;
        cout << "\t10. Keluar" << endl;
        cout << "==========================================" << endl;
        pilihan = getIntInput("Pilihan : ");
        system("cls || clear");

        switch (pilihan)
        {
        case 1:
            tambahIkan(&linkedListIkan);
            break;
        case 2:
            tampilkanIkan(linkedListIkan);
            break;
        case 3:
            status = editIkan(linkedListIkan);
            if (status == -1)
            {
                cout << "Ikan tidak ditemukan" << endl;
                cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
                cin.get();
                system("cls || clear");
            }
            else if (status == -2)
                system("cls || clear");
            else
            {
                cout << "Ikan berhasil diubah" << endl;
                cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
                cin.get();
                system("cls || clear");
            }
            break;
        case 4:
            status = hapusIkan(&linkedListIkan);
            if (status == -1)
            {
                cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
                cin.get();
                system("cls || clear");
            }
            else if (status == -2)
                system("cls || clear");
            else
            {
                cout << "Ikan berhasil dihapus" << endl;
                cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
                cin.get();
                system("cls || clear");
            }
            break;
        case 5:
            mergeSort(&linkedListIkan, compareByHarga);
            display(linkedListIkan);
            cout << "Data ikan berhasil diurutkan secara Ascending menggunakan Merge Sort" << endl;
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 6:
            shellSort(&linkedListIkan, compareByHargaDescending);
            display(linkedListIkan);
            cout << "Data ikan berhasil diurutkan secara Descending menggunakan Shell Sort" << endl;
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 7:
            cout << " == PROGRAM SEARCH FIBONACCI HARGA IKAN ==" << endl;
            cout << "=========================================" << endl;
            mergeSort(&linkedListIkan, compareByHarga);
            keyHarga = getFloatInput("Masukkan harga ikan yang ingin dicari : ");
            fibonacciSearchExact(linkedListIkan, keyHarga);
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 8:
            cout << " == PROGRAM SEARCH JUMP UMUR IKAN ==" << endl;
            cout << "=========================================" << endl;
            mergeSort(&linkedListIkan, compareByUmur);
            keyUmur = getIntInput("Masukkan umur ikan yang ingin dicari : ");
            jumpSearchByUmur(linkedListIkan, keyUmur);
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 9:
            cout << " == PROGRAM SEARCH BOYER-MOORE NAMA IKAN ==" << endl;
            cout << "=========================================" << endl;
            pattern = getStringInput("Masukkan nama ikan yang ingin dicari : ");
            boyerMooreSearch(linkedListIkan, pattern);
            cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
            cin.get();
            system("cls || clear");
            break;
        case 10:
            cout << " == PROGRAM MANAGEMENT YAPS RAJA IKAN HIAS BERAKHIR == " << endl;
            return 0;
        default:
            cout << "Menu tidak tersedia" << endl;
            break;
        }
    } while (pilihan != 10);
    return 0;
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
    int pilihanTambah;

    while (true)
    {
        cout << "          OPSI TAMBAH DATA :" << endl;
        cout << "=========================================" << endl;
        cout << "1. Menambahkan di Awal  (Push)    <Stack>" << endl;
        cout << "2. Menambahkan di Akhir (Enqueue) <Queue>" << endl;
        cout << "3. Kembali ke Menu Utama" << endl;
        cout << "=========================================" << endl;
        pilihanTambah = getIntInput("OPSI ANDA : ");

        if (pilihanTambah == 1 || pilihanTambah == 2)
            break;
        else if (pilihanTambah == 3)
        {
            system("cls || clear");
            return;
        }
        else
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }

    ikan *nodeIkan = new ikan;
    cout << "           == Tambah Ikan ==" << endl;
    cout << "=========================================" << endl;
    while (true)
    {
        nodeIkan->idIkan = getIntInput("ID Ikan \t\t\t: ");
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

    if (pilihanTambah == 1)
    {
        nodeIkan->next = *head;
        *head = nodeIkan;
    }
    else if (pilihanTambah == 2)
    {
        if (*head == NULL) // jika data null maka itu adalah data awal
        {
            *head = nodeIkan;
            nodeIkan->next = NULL;
        }
        else
        {
            ikan *temp = *head;
            while (temp->next != NULL) // Karena saya tidak menggunakan tail maka saya perlu mencari data paling akhir untuk ditambahkan
                temp = temp->next;
            temp->next = nodeIkan;
            nodeIkan->next = NULL;
        }
    }

    system("cls || clear");
    cout << "Ikan berhasil ditambahkan." << endl;
}

void tampilkanIkan(ikan *head)
{
    cout << "           == Tampilkan Ikan ==" << endl;
    cout << "=========================================\n"
         << endl;

    if (head == NULL)
    {
        cout << "Data ikan masih kosong" << endl;
    }
    else
    {
        cout << "                PILIH OPSI" << endl;
        cout << "=========================================" << endl;
        cout << "1. Tampilkan Semua Data" << endl;
        cout << "2. Tampilkan Data Teratas  (Peek) <Stack>" << endl;
        cout << "3. Tampilkan Data Pertama  (Front)<Queue>" << endl;
        cout << "4. Tampilkan Data Terakhir (Rear) <Queue>" << endl;
        cout << "5. Cek Data Kosong <isEmpety>" << endl;
        cout << "6. Kembali ke Menu Utama" << endl;
        cout << "=========================================\n"
             << endl;
        int tampilOpsi = getIntInput("OPSI ANDA : ");
        system("cls || clear");
        ikan *current = head;
        switch (tampilOpsi)
        {
        case 1:
            display(head);
            break;
        case 2:
            peek(head);
            break;
        case 3:
            front(head);
            break;
        case 4:
            rear(head);
            break;
        case 5:
            cout << (isEmpty(head) ? "Data kosong" : "Data tidak kosong") << endl;
            break;
        case 6:
            return;
            break;
        default:
            cout << "Opsi tidak tersedia." << endl;
            break;
        }
    }
    cout << "Tekan tombol apapun untuk kembali ke menu utama" << endl;
    cin.get();
    system("cls || clear");
}

void display(ikan *head)
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
    }
}

bool isEmpty(ikan *head)
{
    return head == NULL;
}

void peek(ikan *head)
{
    if (isEmpty(head))
    {
        cout << "Data kosong" << endl;
    }
    else
    {
        cout << "Data teratas (Peek):" << endl;
        cout << "====================================" << endl;
        cout << "ID ikan \t\t: " << head->idIkan << endl;
        cout << "Nama ikan \t: " << head->jenisIkan << endl;
        cout << "Umur ikan \t: " << head->umurIkan << " Bulan" << endl;
        cout << "Harga ikan \t: Rp. " << fixed << setprecision(2) << head->hargaIkan << endl;
        cout << "====================================" << endl;
    }
}

void front(ikan *head)
{
    if (isEmpty(head))
    {
        cout << "Data kosong" << endl;
    }
    else
    {
        cout << "Data pertama (Front):" << endl;
        cout << "====================================" << endl;
        cout << "ID ikan \t\t: " << head->idIkan << endl;
        cout << "Nama ikan \t: " << head->jenisIkan << endl;
        cout << "Umur ikan \t: " << head->umurIkan << " Bulan" << endl;
        cout << "Harga ikan \t: Rp. " << fixed << setprecision(2) << head->hargaIkan << endl;
        cout << "====================================" << endl;
    }
}

void rear(ikan *head)
{
    if (isEmpty(head))
    {
        cout << "Data kosong" << endl;
    }
    else
    {
        ikan *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        cout << "Data terakhir (Rear):" << endl;
        cout << "====================================" << endl;
        cout << "ID ikan \t\t: " << current->idIkan << endl;
        cout << "Nama ikan \t: " << current->jenisIkan << endl;
        cout << "Umur ikan \t: " << current->umurIkan << " Bulan" << endl;
        cout << "Harga ikan \t: Rp. " << fixed << setprecision(2) << current->hargaIkan << endl;
        cout << "====================================" << endl;
    }
}

int editIkan(ikan *head)
{
    cout << "           == Edit Ikan ==" << endl;
    cout << "====================================" << endl;
    if (head == NULL)
    {
        cout << "Data ikan masih kosong" << endl;
        return -2;
    }
    else
    {
        int idIkan = getIntInput("Masukkan ID ikan yang ingin di edit : ");
        ikan *current = head;
        while (current != NULL)
        {
            if (current->idIkan == idIkan)
            {
                cout << "ID ikan \t\t: " << current->idIkan << endl;
                cout << "Nama ikan \t: " << current->jenisIkan << endl;
                cout << "Umur ikan \t: " << current->umurIkan << " Bulan" << endl;
                cout << "Harga ikan \t: Rp. " << current->hargaIkan << endl;
                cout << "====================================" << endl;

                current->jenisIkan = getStringInput("Nama ikan \t\t: ");
                current->umurIkan = getIntInput("Umur ikan (Bulan)\t: ");
                current->hargaIkan = getFloatInput("Harga ikan \t\t: Rp. ");
                return 1;
            }
            current = current->next;
        }
        return -1;
    }
};

int hapusIkan(ikan **head)
{
    int pilihanHapus;

    while (true)
    {
        cout << "           PILIH OPSI HAPUS DATA : " << endl;
        cout << "===========================================" << endl;
        cout << "1. Menghapus Data Teratas  (Pop)     <Stack>" << endl;
        cout << "2. Menghapus Data Pertama (Dequeue) <Queue>" << endl;
        cout << "3. Hapus Ikan Berdasarkan ID" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "===========================================" << endl;
        pilihanHapus = getIntInput("OPSI ANDA : ");
        system("cls || clear");

        if (pilihanHapus >= 1 && pilihanHapus <= 3)
            break;
        else if (pilihanHapus == 4)
        {
            return -2;
        }
        else
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }

    if (*head == NULL)
    {
        cout << "Data ikan masih kosong" << endl;
        return -1;
    }

    ikan *temp = *head;
    ikan *prev = NULL;

    if (pilihanHapus == 1)
    {
        *head = (*head)->next;
        delete temp;
        cout << "Ikan berhasil dihapus (Mode Stack - Pop)." << endl;
        return 1;
    }
    else if (pilihanHapus == 2)
    {
        *head = (*head)->next; // Disini sama kea pop karean enqueue menambah data di akhir dan dequeue menghapus data di awal (FIFO)
        // Sehingga ini sama dengan pop namun dalam segi konsep implementasi queue ini benar sesuai modul.
        delete temp;
        cout << "Ikan berhasil dihapus (Mode Queue - Dequeue)." << endl;
        return 1;
    }
    else if (pilihanHapus == 3)
    {
        int idIkan = getIntInput("Masukkan ID ikan yang ingin dihapus : ");
        while (temp != NULL && temp->idIkan != idIkan)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "ID ikan tidak ditemukan." << endl;
            return -1;
        }

        if (prev == NULL)
        {
            *head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Ikan berhasil dihapus berdasarkan ID." << endl;
        return 1;
    }

    return -1;
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
                    cout << "ID: " << previousIkan->idIkan
                         << ", Nama: " << previousIkan->jenisIkan
                         << ", Umur: " << previousIkan->umurIkan
                         << ", Harga: " << previousIkan->hargaIkan << endl;
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
                    cout << "ID: " << nextIkan->idIkan
                         << ", Nama: " << nextIkan->jenisIkan
                         << ", Umur: " << nextIkan->umurIkan
                         << ", Harga: " << nextIkan->hargaIkan << endl;
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
        cout << "ID: " << lastIkan->idIkan
             << ", Nama: " << lastIkan->jenisIkan
             << ", Umur: " << lastIkan->umurIkan
             << ", Harga: " << lastIkan->hargaIkan << endl;
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
            cout << "Ikan dengan umur " << keyUmur << " ditemukan:" << endl;
            foundIDs.insert(foundIkan->idIkan);
            cout << "ID: " << foundIkan->idIkan
                 << ", Nama: " << foundIkan->jenisIkan
                 << ", Umur: " << foundIkan->umurIkan
                 << ", Harga: " << foundIkan->hargaIkan << endl;
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
                cout << "Ikan dengan nama \"" << pattern << "\" ditemukan:" << endl;
                cout << "ID: " << current->idIkan
                     << ", Nama: " << current->jenisIkan
                     << ", Umur: " << current->umurIkan
                     << ", Harga: " << current->hargaIkan << endl;

                s += (s + m < n) ? m - badChar[name[s + m]] : 1;
            }
            else
            {
                s += max(1, j - badChar[name[s + j]]);
            }
        }

        current = current->next;
        id++;
    }
}