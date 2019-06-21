//////////////////////////////////////////////////////////////////////
///Nama 	: Nur Raditya Mahardika
///NIM		: A12.2018.06015
///Repo		: github.com/nurradityam/tugasUdinus/tree/master/alpro1
//////////////////////////////////////////////////////////////////////
#include <conio.h>
#include <iostream.h>

// deklarasi konstanta
#define maxEntryData 9 // menentukan batas maksimal input data pegawai

// deklarasi struct
struct structPegawai{
	int 	nip, anak;
	long	tunjanganAnak, gajiPokok, gajiKotor;
	char 	pendidikan[5];
};

// deklarasi variabel global
structPegawai pegawai[maxEntryData+1], pegawaiSorted[maxEntryData+1]; // +1 karena array yg diisi tidak dari 0
	
int		baris 		= 1,
		kolom 		= 15,
		kolomMax 	= kolom + 12,
		index 		= 0;

char	lagi;

// deklarasi fungsi
void 	input_formulir(),
		input_isiLagi(),
		input_isiNip(),
		input_isiAnak(),
		input_isiPendidikan(),
		input_isiGajiPokok(long gajiPokok),
		input_isiTunjanganAnak(),
		input_isiGajiKotor(),
		sorting(),
		hapus(int indexDihapus),
		laporan(),
		exit(),
		menu(),
		search_noticeNotFound();

int		search_formulir();

/// FUNGSI
void input_formulir(){
	clrscr();

	cout << "Data Pegawai pada posisi : " << index << endl;
	cout << "=================================" << endl;
	cout << "1. NIP \t\t\t: " << endl;
	cout << "2. Jumlah Anak \t\t: " << endl;
	cout << "3. Pendidikan \t\t: " << endl;
}

void input_isiLagi(){
	// jika kali isian sudah mencapai limit, akan menolak entry lagi
	if(index == maxEntryData){
		lagi = 'n';
		return;
	} 
	
	gotoxy(5,2); 	cout << "+------------------+";
	gotoxy(5,3); 	cout << "|Isi Lagi [Y/T]:   |";
	gotoxy(5,4); 	cout << "+------------------+";
	gotoxy(22,3); 	cin >> lagi;
}

void input_isiNip(){
	gotoxy(kolomMax, baris+2); cin >> pegawai[index].nip;
}

void input_isiAnak(){
	gotoxy(kolomMax, baris+3); cin >> pegawai[index].anak;
}

void input_isiPendidikan(){
	int pilihan;

	// tampilan pembantu
	gotoxy(27,6); 	cout << "+-Pilihan-+";
	gotoxy(27,7); 	cout << "| 1 = SD  |";
	gotoxy(27,8);	cout << "| 2 = SMP |";
	gotoxy(27,9); 	cout << "| 3 = SMA |";
	gotoxy(27,10); 	cout << "| 4 = S1  |";
	gotoxy(27,11); 	cout << "| 5 = S2  |";
	gotoxy(27,12);	cout << "+---------+";

	gotoxy(kolomMax, baris+4); cin >> pilihan;
	switch(pilihan){
		// nyambi hitung gaji pokok
		case 1: 
			strcpy(pegawai[index].pendidikan, "SD");	
			input_isiGajiPokok(1500000);
			break;
			
		case 2: 
			strcpy(pegawai[index].pendidikan, "SMP");
			input_isiGajiPokok(2000000);
			break;
		
		case 3: strcpy(pegawai[index].pendidikan, "SMA");
			input_isiGajiPokok(3000000);
			break;
			
		case 4: 
			strcpy(pegawai[index].pendidikan, "S1");
			input_isiGajiPokok(5000000);
			break;
			
		case 5: 
			strcpy(pegawai[index].pendidikan, "S2");
			input_isiGajiPokok(5000000);
			break;
		
		// handler salah input
		default:
			gotoxy(29,5); cout << "[INPUT SALAH!, MASUKKAN LAGI!]";
			input_isiPendidikan();
			break;
	}
	clrscr();
}

void input_isiGajiPokok(long gajiPokok){
	pegawai[index].gajiPokok = gajiPokok;
}

void input_isiTunjanganAnak(){
	// menghitung tunjangan anak, (1% dari gaji pokok) x jumlah anak
	pegawai[index].tunjanganAnak = (0.01 * pegawai[index].gajiPokok) * pegawai[index].anak;
}

void input_isiGajiKotor(){
	// menghitung gaji kotor
	pegawai[index].gajiKotor = pegawai[index].tunjanganAnak + pegawai[index].gajiPokok;
}

void sorting(){
	structPegawai temporer;
	
	// copy array untuk versi unsorted
	for(int i=1; i<=index; i++){
		pegawaiSorted[i] = pegawai[i]; /// todo: GAREK GAWE VIEW
	}
	
	// sorting metode bubble sort
	// todo: ganti ben pegawaiSorted[] ae seng di sort
	for(int i=1; i<index; i++){
		for(int j=1; j<index; j++){
			if(pegawai[j].nip > pegawai[j+1].nip){
				temporer = pegawai[j+1];
				pegawai[j+1] = pegawai[j];
				pegawai[j] = temporer;
			}
		}
	}
}

void laporan(){
	clrscr();
	sorting(); // diurutkan dulu
	
	int i; // variabel pembantu loop
	
	// tampilan header
	gotoxy(11,3); cout << "                         Laporan                        ";
	gotoxy(11,4); cout << "+------+---------------+---------------+---------------+---------------+---------------+";
	gotoxy(11,5); cout << "| No \t | NIP \t\t | Anak \t | Pendidikan \t | Gaji Pokok \t | Tunj. Anak \t | Gaji Kotor";
	gotoxy(11,6); cout << "+------+---------------+---------------+---------------+---------------+---------------+";

	// perulangan output isi data
	for(i=1; i <= index; i++){
		gotoxy(11,6+i); cout << "| " << i 						<< "\t | " ;
		gotoxy(20,6+i); cout << 		pegawai[i].nip;			gotoxy(34,6+i); cout << "|";
		gotoxy(36,6+i); cout << 		pegawai[i].anak;		gotoxy(50,6+i); cout << "|";
		gotoxy(52,6+i); cout << 		pegawai[i].pendidikan  	<< "\t\t |" << pegawai[i].gajiPokok << "\t" << pegawai[i].tunjanganAnak << "\t" << pegawai[i].gajiKotor;
	}
	// penutup tabel
	gotoxy(11,6+i); cout << "+------+---------------+---------------+---------------+---------------+---------------+";
	
	getch();
}

void hapus(int indexDihapus){
	// handler jika return code -1	,janjane iso sharing karo menu edit, mungkin iki dadi sub fx search
	if(indexDihapus == -1){
		search_noticeNotFound();
		return;
	}
		
	// mengganti value index yg dihapus dgn value index diatasnya, dan looping sampe index terakhir 
	for(int i=indexDihapus;i<=index;i++){
		pegawai[i]=pegawai[i+1];
	}
	
	index--; // karena index ada yg kosong 1 dibagian akhir, tak kurangi wae. harus e di deallocation memori ne
}

int search_formulir(){
	int nipDicari, i;
	
	clrscr();
	cout << "Masukkan NIP: "; cin >> nipDicari;
	
	for(i = 1; i <= maxEntryData; i++){
        if(pegawai[i].nip == nipDicari){
            return i; // array yang pertama kali cocok akan menjadi return code
		}
	}
    return -1; // sebagai return code error jika tidak ditemukan
}

void search_noticeNotFound(){
	clrscr();
	
	cout << "NIP tidak ditemukan! Tekan ENTER untuk kembali ke menu.";
	getch();
}

void exit(){
	clrscr();
	
	cout << "Selamat Tinggal :(" << endl;
	cout << "Tekan ENTER untuk keluar dari aplikasi.";
	getch();
}

void menu(){
	int pilihanMenu;
	
	clrscr();
	cout << "Menu" << endl << endl;
	cout << "[1] Input" << endl;
	cout << "[2] Edit" << endl;
	cout << "[3] Delete" << endl;
	cout << "[4] Laporan" << endl;
	cout << "[5] Selesai" << endl << endl;
	cout << "Masukkan nomor menu: "; cin >> pilihanMenu;
	
	switch(pilihanMenu){
		// input
		case 1:
			do{
				index++; // index array dimulai dari [1]
				input_formulir(); // menampilkan menu input pegawai
				input_isiNip();
				input_isiAnak();
				input_isiPendidikan();
				input_isiTunjanganAnak();
				input_isiGajiKotor();
				input_isiLagi();
			} while (lagi == 'y' || lagi == 'Y');
			
			break;
		
		// edit		
		case 2:
			break;
		
		// delete
		case 3:
			hapus(search_formulir());
			break;
		
		// laporan	
		case 4:
			laporan();
			break;
		
		// exit		
		case 5:
			exit();
			break;
			
		// handler salah input
		default:
			// kei tulisan nek salah
			break;
	}
	
	menu(); // untuk kembali ke menu
}

/// BLOCK UTAMA
main(){
	menu();
}
