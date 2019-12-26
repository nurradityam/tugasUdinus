//////////////////////////////////////////////////////////////////////
/// Nama 	: Nur Raditya Mahardika
/// NIM		: A12.2018.06015
/// Matkul	: Algoritma dan Pemprograman 2
//////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

// deklarasi struct
struct node
{
    int id;
    int golongan;
    int pemakaian;
    char nama[30];

    node *next;
    node *prev;
};

// deklarasi pointer global
node *head = NULL;
node *tail = NULL;

// deklarasi fungsi
void    depanTambah(),
        depanHapus(),
        belakangTambah(),
        belakangHapus(),
        laporanDataNodeSpesifik(char argHeader[], int argId, char argNama[], int argGolongan, int argPemakaian),
        laporanDataNodeUrut(int argMode),
        laporanDataNodeUrut_loop(int x, int y, int i, node *temp),
        notif(int tipeNotif, char pesan[]),
        menu();

int     cari();

long    hitungBayar(int argGolongan, int argPemakaian);

void depanTambah()
{
    node *temp;
    temp = new node;

    temp->next = NULL;
    temp->prev = NULL;

    cout << "ID          : "; cin >> temp->id;
    cout << "Nama        : "; cin >> temp->nama;
    cout << "Pemakaian   : "; cin >> temp->pemakaian;
    cout << "Golongan    : "; cin >> temp->golongan;

    if (head == NULL)
    {
        head = temp;
        tail = head;
        head->next = NULL;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = NULL;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void depanHapus()
{
    node *temp;
    
    if (head->next != NULL)
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
}

void belakangTambah()
{
    node *temp;
    temp = new node;

    temp->next = NULL;
    temp->prev = NULL;

    cout << "ID          : "; cin >> temp->id;
    cout << "Nama        : "; cin >> temp->nama;
    cout << "Pemakaian   : "; cin >> temp->pemakaian;
    cout << "Golongan    : "; cin >> temp->golongan;

    if (head == NULL)
    {
        head = temp;
        tail = head;
        head->next = NULL;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = NULL;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
        tail->next = NULL;
    }
}

void belakangHapus()
{
    node *temp;

    if (head->next != NULL)
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
    }
    else
    {
        head = NULL;
        tail = NULL;
    }
}

/*  RETURN CODE: 0 : data ditemukan
                 1 : data tidak ditemukan
*/
int cari()
{
    node *temp;
    temp = head;
    long idPelangganDicari = 0;
    int orderNumber = 1;

    cout << "Nomer Pelanggan Yang Dicari : "; cin >> idPelangganDicari;

    while (temp != NULL)
    {
        if (idPelangganDicari == temp->id)
        {
            // kuno tenan revisi c++ borland kui, concat karo tostring ribet
            // jane tk passing ke parameter wae
            laporanDataNodeSpesifik("Isi Node", 
                                    temp->id, 
                                    temp->nama, 
                                    temp->golongan, 
                                    temp->pemakaian);

            cout << endl << "Data ditemukan pada urutan ke " << orderNumber;
            getch();
            
            return 0;
        }
        
        orderNumber++;
        temp = temp->next;
    }

    return 1;
}

/*	Fungsi: template untuk menampilkan isi data node
	PARAMETER: 	argHeader[]     : tulisan utama
				argId	        : nilai No pelanggan
                argNama[]       : nilai nama pelanggan
                argGolongan     : nilai golongan pelanggan
                argPemakaian    : nilai pemakaian pelanggan
*/
void laporanDataNodeSpesifik(char argHeader[], int argId, char argNama[], int argGolongan, int argPemakaian)
{
    clrscr();
    cout << argHeader << endl;
    cout << "====================================" << endl;
    cout << "No.Pel     : " << argId << endl;
    cout << "Nama       : " << argNama << endl;
    cout << "Golongan   : " << argGolongan << endl;
    cout << "Pemakaian  : " << argPemakaian << endl;
    cout << "Bayar      : " << hitungBayar(argGolongan, argPemakaian) << endl;
    getch();
}

/*	Fungsi: template untuk menampilkan semua isi data node
	PARAMETER: 	argMode : 0 = tampilkan data urut dari HEAD
                          1 = tampilkan data urut dari TAIL 
*/
void laporanDataNodeUrut(int argMode)
{
    node *temp;
    int x = -10; // untuk mengatur X dari kiri layar
    int y = -2;  // untuk mengatur Y dari atas layar
    int i = 1; // variabel pembantu iterasi

    clrscr();
	gotoxy(11+x,3+y); cout << "++++++++++++++++++++++++++++++++++++++LAPORAN+++++++++++++++++++++++++++++++++++++++++++";
	gotoxy(11+x,4+y); cout << "+------+---------------+---------------+---------------+---------------+---------------+";
	gotoxy(11+x,5+y); cout << "| No   | No. Pelanggan | Nama          | Golongan      | Pemakaian     | Bayar         |";
	gotoxy(11+x,6+y); cout << "+------+---------------+---------------+---------------+---------------+---------------+";
    
    if (argMode == 0) // urut dari HEAD
    {
        temp = head;
        while (temp != tail->next)
        {
            laporanDataNodeUrut_loop(x, y, i, temp);
            i++;
            temp = temp->next;
        }
    }
    else // urut dari TAIL
    {
        temp = tail;
        while (temp != head->prev)
        {
            laporanDataNodeUrut_loop(x, y, i, temp);
            i++;
            temp = temp->prev;
        }
    }

    gotoxy(11+x,6+y+i); cout << "+------+---------------+---------------+---------------+---------------+---------------+";
    gotoxy(43+x,8+y+i); cout << "Tekan ENTER untuk kembali ke menu.";
    getch();
}

void laporanDataNodeUrut_loop(int x, int y, int i, node *temp)
{
        gotoxy(11+x,6+y+i); cout << "| " << i; 					            gotoxy(18+x,6+y+i); cout << "|";
        gotoxy(20+x,6+y+i); cout << 		temp->id;				        gotoxy(34+x,6+y+i); cout << "|";
        gotoxy(36+x,6+y+i); cout << 		temp->nama;				        gotoxy(50+x,6+y+i); cout << "|";
        gotoxy(52+x,6+y+i); cout << 		temp->golongan;  		        gotoxy(66+x,6+y+i); cout << "|";
        gotoxy(68+x,6+y+i); cout << 		temp->pemakaian;  		        gotoxy(82+x,6+y+i);	cout << "|";
        gotoxy(84+x,6+y+i); cout << 		hitungBayar(temp->golongan, 
                                                        temp->pemakaian);   gotoxy(98+x,6+y+i); cout << "|";
}

// pas neng lab terakhir, jare pak suharnawi engko kemungkinan 
// penambahanne kyk ngitung bayar sesuai golongan
/*	Fungsi: menghitung nilai bayar sesuai kriteria
	PARAMETER: 	argGolongan: 
                argPemakaian:
*/
long hitungBayar(int argGolongan, int argPemakaian)
{
    switch(argGolongan)
        case 1 :
        case 2 :
        case 3 :
        default :
            return argPemakaian * 500;
}

/*	Fungsi: menampilkan tulisan berdasarkan tipe yang diinginkan
	PARAMETER: 	tipeNotif:	0 = menampilkan tulisan+ header sukses
                            1 = menampilkan tulisan+ header error
							2 = menampilkan pesan saja tanpa header
				
				pesan[]: tulisan yang akan ditampilkan		
*/
void notif(int tipeNotif, char pesan[])
{
	clrscr();

	switch(tipeNotif){	
		case 0 : 
			gotoxy(3,2);cout << "SUKSES!";
			break;

		case 1 : 
			gotoxy(3,2);cout << "ERROR!";
			break;
			
		case 2 :
			// tampilkan pesan tanpa header
			break;
	}

	gotoxy(3,3); cout << pesan << endl;
    gotoxy(3,4); cout << "Tekan ENTER untuk melanjutkan.";
	getch();
}

void menu()
{
    int pilihan = 0;
    int x = 3; // untuk mengatur X dari kiri layar
    int y = 1; // untuk mengatur Y dari atas layar

    clrscr();
	gotoxy(x,y++); cout << "+----------------Menu----------------+";
	gotoxy(x,y++); cout << "| [1] Tambah Depan                   |";
	gotoxy(x,y++); cout << "| [2] Hapus Depan                    |";
    gotoxy(x,y++); cout << "| [3] Tampilkan Isi Data Depan       |";
	gotoxy(x,y++); cout << "| [4] Tambah Belakang                |";
	gotoxy(x,y++); cout << "| [5] Hapus Belakang                 |";
	gotoxy(x,y++); cout << "| [6] Tampilkan Isi Data Belakang    |";
	gotoxy(x,y++); cout << "| [7] Tampilkan Data Dari Depan      |";
    gotoxy(x,y++); cout << "| [8] Tampilkan Data Dari Belakang   |";
    gotoxy(x,y++); cout << "| [9] Cari Data                      |";
	gotoxy(x,y++); cout << "| [0] Keluar Program                 |";
	gotoxy(x,y++); cout << "+------------------------------------+";
	gotoxy(x,y++); cout << "| Masukkan nomor menu:               |";
	gotoxy(x,y++); cout << "+------------------------------------+";
	gotoxy(x+23,y-2); cin >> pilihan;
    clrscr();

    switch(pilihan)
    {
        // TAMBAH DEPAN
        case 1 :
            depanTambah();
            notif(0, "Data Berhasil Ditambahkan di Node HEAD");
            break;

        // HAPUS DEPAN
        case 2 :
            if (head == NULL)
                notif(1, "Data Masih Kosong!");
            else
            {
                depanHapus();
                notif(0, "Node HEAD Berhasil Dihapus!");
            }
            break;

        // TAMPILKAN DATA DEPAN
        case 3 :
            if (head == NULL)
                notif(1, "Data Masih Kosong!");
            else
                laporanDataNodeSpesifik("Isi Data Pada HEAD", 
                            head->id, 
                            head->nama, 
                            head->golongan, 
                            head->pemakaian);
            break;

        // TAMBAH BELAKANG
        case 4 :
            belakangTambah(); 
            notif(0, "Data Berhasil Ditambahkan di Node TAIL!");
            break;

        // HAPUS BELAKANG
        case 5 :
            if (head == NULL)
                notif(1, "Data Masih Kosong!");
            else
            {
                belakangHapus();
                notif(0, "Node TAIL Berhasil Dihapus!");
            }
            break;

        // TAMPILKAN DATA BELAKANG
        case 6 :
            if (head == NULL)
                notif(1, "Data Masih Kosong!");
            else
                laporanDataNodeSpesifik("Isi Data Pada TAIL", 
                            tail->id, 
                            tail->nama, 
                            tail->golongan, 
                            tail->pemakaian);
            break;

        // TAMPILKAN DATA DARI DEPAN
        case 7 :
            if (head == NULL)
                notif(1, "Data Masih Kosong!");
            else
                laporanDataNodeUrut(0);
            break;

        // TAMPILKAN DATA DARI BELAKANG
        case 8 :
            if (head == NULL)
                notif(1, "Data Masih Kosong!");
            else
                laporanDataNodeUrut(1);
            break;

        // CARI DATA
        case 9 :
            if (head == NULL)
                notif(1, "Data Masih Kosong!");
            else
                if (cari())
                    notif(1, "Data Tidak Ditemukan!");
            break;

        // EXIT
        case 0 :
            return; 

        // HANDLER INPUT ANOMALI
        default :
            notif(1, "Input Tidak Dikenali!");
            break;
    }
    menu(); // untuk loop ke menu
}

void main()
{
    menu();
}
