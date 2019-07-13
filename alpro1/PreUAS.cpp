//////////////////////////////////////////////////////////////////////
///Nama 	: Nur Raditya Mahardika
///NIM		: A12.2018.06015
///Repo		: github.com/nurradityam/tugasUdinus/tree/master/alpro1
//////////////////////////////////////////////////////////////////////
#include <conio.h>
#include <iostream.h>
#include <stdlib.h> // untuk menggunakan fungsi exit()

// deklarasi konstanta
#define maxEntryData 9 // menentukan batas maksimal input data pegawai

// deklarasi struct
struct structPegawai{
	int 	nip, anak;
	long	tunjanganAnak, gajiPokok, gajiKotor;
	char 	pendidikan[5];
};

// deklarasi variabel global
structPegawai pegawai[maxEntryData+1], pegawaiSorted[maxEntryData+1]; // +1 karena array yg diisi tidak dari 0. REVIEW: model karo view ojo samakan, start ko 0?
	
int		baris 		= 1,
		kolom 		= 15,
		kolomMax 	= kolom + 12,
		index 		= 0; // penanda jumlah index yang terisi

char	lagi;

// deklarasi fungsi
void 	input_header(int index),
		input_isiLagi(int index),
		input_isiNip(int index),
		input_isiAnak(int index),
		input_isiPendidikan(int index),
		input_isiGajiPokok(int index, long gajiPokok),
		input_isiTunjanganAnak(int index),
		input_isiGajiKotor(int index),
		input_koreksiData(),
		edit(int index),
		sorting(),
		hapus(int index),
		laporan(int mode),
		keluar(),
		menu(),
		notif(int tipeNotif, char string[]),
		debug();
		
int		search_formulir(),
		cekArrayKosong();

bool	search_cekHasil(int returnCode);

/// FUNGSI
void input_header(int index){
	clrscr();

	cout << "Data Pegawai pada posisi : " << index << endl;
	cout << "=================================" << endl;
}

void input_isiNip(int index){
	cout << "1. NIP \t\t\t: "; cin >> pegawai[index].nip;
	//cout << "1. NIP \t\t\t: " << endl;
	//gotoxy(kolomMax, baris+2); cin >> pegawai[index].nip;
}

void input_isiAnak(int index){
	cout << "2. Jumlah Anak \t\t: "; cin >> pegawai[index].anak;
/* 	cout << "2. Jumlah Anak \t\t: " << endl;
	gotoxy(kolomMax, baris+3); cin >> pegawai[index].anak; */
}

void input_isiPendidikan(int index){
	int pilihan;
	
	cout << "3. Pendidikan \t\t: " << endl;
	
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
		// nyambi ngisi gaji pokok
		case 1: 
			strcpy(pegawai[index].pendidikan, "SD");	
			input_isiGajiPokok(index, 1500000);
			
			break;
			
		case 2: 
			strcpy(pegawai[index].pendidikan, "SMP");
			input_isiGajiPokok(index, 2000000);
			
			break;
		
		case 3: 
			strcpy(pegawai[index].pendidikan, "SMA");
			input_isiGajiPokok(index, 3000000);
			
			break;
			
		case 4: 
			strcpy(pegawai[index].pendidikan, "S1");
			input_isiGajiPokok(index, 5000000);
			
			break;
			
		case 5: 
			strcpy(pegawai[index].pendidikan, "S2");
			input_isiGajiPokok(index, 5000000);
			
			break;
		
		// handler salah input
		default:
			gotoxy(29,5); cout << "[INPUT SALAH!, MASUKKAN LAGI!]";
			input_isiPendidikan(index); // akan mengulangi form isi pendidikan
			
			break;
	}
	clrscr();
}

// habis input pendidikan ada menu koreksi, user dikasih opsi input apa yg ingin direvisi. nanti hanya yg diinput user yg ak
void input_koreksiData(){
	int koreksi;
	
	do{
		clrscr();
		gotoxy(3,2);	cout << "+------Menu Koreksi------+";
		gotoxy(3,3); 	cout << "| [0] Skip Koreksi Data  |";
		gotoxy(3,4);	cout << "| [1] Koreksi NIP        |";
		gotoxy(3,5);	cout << "| [2] Koreksi Anak       |";
		gotoxy(3,6); 	cout << "| [3] Koreksi Pendidikan |";
		gotoxy(3,7); 	cout << "+------------------------+";
		gotoxy(3,8); 	cout << "| Masukkan nomor menu:   |";
		gotoxy(3,9); 	cout << "+------------------------+";
		gotoxy(26,8);	cin >> koreksi;

		switch(koreksi){
			// skip 
			case 0:
				break;
			
			// koreksi nip
			case 1:
				clrscr();
				input_isiNip(index);
				
				break;
			
			// koreksi anak
			case 2:
				clrscr();
				input_isiAnak(index);
				break;
			
			// koreksi pendidikan
			case 3: 
				clrscr();
				input_isiPendidikan(index);
				break;
			
			// handler salah input
			default:
				notif(1, "Input tidak dikenali! Tekan ENTER untuk kembali ke menu koreksi.");
				
				break;
		}
	} while (koreksi != 0); // jika user sudah menginput 0 maka keluar loop
}

void input_isiLagi(){
	// jika kali isian sudah mencapai limit, akan menolak entry lagi
	if(index == maxEntryData){
		lagi = 'n';
		notif(3, "Data yang dimasukkan sudah mencapai batas entri! Tekan ENTER untuk kembali ke menu.");
		
		return;
	} 
	
	clrscr();
	gotoxy(5,2); 	cout << "+------------------+";
	gotoxy(5,3); 	cout << "|Isi Lagi [Y/T]:   |";
	gotoxy(5,4); 	cout << "+------------------+";
	gotoxy(22,3); 	cin >> lagi;
}

/* 	Fungsi: melakukan pengisian nilai ke elemen index  
	PARAMETER:	index: nomor index yang akan diisi
				gajiPokok: nilai yang akan diisi ke index
*/
void input_isiGajiPokok(int index, long gajiPokok){
	pegawai[index].gajiPokok = gajiPokok;
}

/* 	Fungsi: menghitung tunjangan anak, (1% dari gaji pokok) x jumlah anak
	PARAMETER:	index: nomor index yang akan dihitung
*/
void input_isiTunjanganAnak(int index){
	
	pegawai[index].tunjanganAnak = (0.01 * pegawai[index].gajiPokok) * pegawai[index].anak;
}
/* 	Fungsi: menghitung gaji kotor
	PARAMETER:	index: nomor index yang akan dihitung
*/
void input_isiGajiKotor(int index){
	pegawai[index].gajiKotor = pegawai[index].tunjanganAnak + pegawai[index].gajiPokok;
}

/* 	Fungsi: menampilkan semua elemen yg berada di index yg dimasukkan
	PARAMETER:	index: nomor index yang akan ditampilkan isinya
*/
void search_cariData(int index){
	if(search_cekHasil(index)) return; // melakukan cek terhadap nilai parameter index. jika return true, maka langsung keluar
	
	clrscr();
	cout << "Data Pegawai pada posisi : " << index << endl;
	cout << "=================================" << endl;
	cout << "1. NIP \t\t\t: " << pegawai[index].nip <<endl;
	cout << "2. Jumlah Anak \t\t: " << pegawai[index].anak << endl;
	cout << "3. Pendidikan \t\t: " << pegawai[index].pendidikan << endl;
	
	getch();
}

/* 	Fungsi: melakukan input ulang pada nomor index yang dimasukkan
	PARAMETER:	index: nomor index yang akan diedit
*/
void edit(int index){
	if(search_cekHasil(index)) return; // melakukan cek terhadap nilai parameter index. jika return true, maka langsung keluar
	
	// melakukan input ulang
	input_header(index);
	input_isiNip(index);
	input_isiAnak(index);
	input_isiPendidikan(index);
	input_isiTunjanganAnak(index);
	input_isiGajiKotor(index);
	
	notif(2, "Data berhasil diubah! Tekan ENTER untuk kembali ke menu.");
}

/* 	Fungsi: Menghapus element dengan metode memindahkan element yang lain
	PARAMETER:	index: nomor index yang akan dihapus
*/
void hapus(int index){
	if(search_cekHasil(index)) return; // melakukan cek terhadap nilai parameter index. jika return true, maka langsung keluar
		
	// mengganti value index yg dihapus dgn value index diatasnya, dan looping sampe index terakhir 
	for(int i = index; i <= ::index; i++){
		pegawai[i]=pegawai[i+1];
	}
	
	::index--; // mengurangi var global index. karena index ada yg kosong 1 dibagian akhir, tak kurangi wae. harus e di deallocation memori ne
	notif(2, "Data berhasil dihapus! Tekan ENTER untuk kembali ke menu.");
}

//	Fungsi: melakukan sorting pada array global pegawaiSorted
void sorting(){
	structPegawai temporer;
	
	// copy array untuk versi sorted
	for(int i=1; i<=index; i++){
		pegawaiSorted[i] = pegawai[i];
	}
	
	// sorting metode bubble sort
	for(int i=1; i<index; i++){
		for(int j=1; j<index; j++){
			if(pegawaiSorted[j].nip > pegawaiSorted[j+1].nip){
				temporer = pegawaiSorted[j+1];
				pegawaiSorted[j+1] = pegawaiSorted[j];
				pegawaiSorted[j] = temporer;
			}
		}
	}
}

/*	Fungsi: menampilkan laporan melalui looping array global pegawai dan pegawaiSorted
	PARAMETER:	mode: 	1 = menampilan laporan yg diurutkan (sorted)
						2 = menampilan laporan yg urut sesuai input (unsorted)
*/
void laporan(int mode){ /// REVIEW: butuh refactor
	clrscr();
	sorting(); // diurutkan dulu
	
	int i; // variabel pembantu loop
	// tampilan header
	gotoxy(11,3); cout << "++++++++++++++++++++++++++++++++++++++++++++++++LAPORAN+++++++++++++++++++++++++++++++++++++++++++++++++";
	gotoxy(11,4); cout << "+------+---------------+---------------+---------------+---------------+---------------+---------------+";
	gotoxy(11,5); cout << "| No \t | NIP \t\t | Anak \t | Pendidikan \t | Gaji Pokok \t | Tunj. Anak \t | Gaji Kotor \t |";
	gotoxy(11,6); cout << "+------+---------------+---------------+---------------+---------------+---------------+---------------+";

	// perulangan output isi data
	/// REVIEW: mending dadi siji ae, gawe array lokal khusus view
	// 1 = sorted, 2 = unsorted
	if(mode == 1){
		for(i=1; i <= index; i++){
			gotoxy(11,6+i); 	cout << "| " << i; 								gotoxy(18,6+i); 	cout << "|";
			gotoxy(20,6+i); 	cout << 		pegawaiSorted[i].nip;			gotoxy(34,6+i); 	cout << "|";
			gotoxy(36,6+i); 	cout << 		pegawaiSorted[i].anak;			gotoxy(50,6+i); 	cout << "|";
			gotoxy(52,6+i); 	cout << 		pegawaiSorted[i].pendidikan;  	gotoxy(66,6+i); 	cout << "|"; 
			gotoxy(68,6+i); 	cout << 		pegawaiSorted[i].gajiPokok;  	gotoxy(82,6+i); 	cout << "|";
			gotoxy(84,6+i); 	cout << 		pegawaiSorted[i].tunjanganAnak;	gotoxy(98,6+i); 	cout << "|";
			gotoxy(100,6+i); 	cout << 		pegawaiSorted[i].gajiKotor;  	gotoxy(114,6+i); 	cout << "|";
		}
	} else { // REVIEW: kei kondisi ae drpd else
		for(i=1; i <= index; i++){
			gotoxy(11,6+i); 	cout << "| " << i; 							gotoxy(18,6+i); 	cout << "|";
			gotoxy(20,6+i); 	cout << 		pegawai[i].nip;				gotoxy(34,6+i); 	cout << "|";
			gotoxy(36,6+i); 	cout << 		pegawai[i].anak;			gotoxy(50,6+i); 	cout << "|";
			gotoxy(52,6+i); 	cout << 		pegawai[i].pendidikan;  	gotoxy(66,6+i); 	cout << "|"; 
			gotoxy(68,6+i); 	cout << 		pegawai[i].gajiPokok;  		gotoxy(82,6+i); 	cout << "|";
			gotoxy(84,6+i); 	cout << 		pegawai[i].tunjanganAnak;  	gotoxy(98,6+i); 	cout << "|";
			gotoxy(100,6+i); 	cout << 		pegawai[i].gajiKotor;  		gotoxy(114,6+i); 	cout << "|";
		}
	}
	// penutup tabel
	gotoxy(11,6+i); cout << "+------+---------------+---------------+---------------+---------------+---------------+---------------+";
	
	// pesan footer
	gotoxy(43,8+i); cout << "Tekan ENTER untuk kembali ke menu.";
	
	getch();
}

//	Fungsi: menampilkan tulisan goodbye dan menutup aplikasi 
void keluar(){
	notif(3, "Sampai jumpa :)  Tekan ENTER untuk keluar dari aplikasi.");
	exit(0); // fungsi dari cstlib.h
}

int search_formulir(){
	int nip;
	
	clrscr();
	cout << "Masukkan NIP: "; cin >> nip;
	
	// metode sequential search
	for(int i = 1; i <= maxEntryData; i++){
        if(pegawai[i].nip == nip){
            return i; // array yang pertama kali cocok akan menjadi return code
		}
	}
	
    return -1; // sebagai return code error jika tidak ditemukan
}

bool search_cekHasil(int returnCode){
	// handler jika return code -1
	if(returnCode == -1){
		notif(1, "NIP tidak ditemukan! Tekan ENTER untuk kembali ke menu.");
		
		return true; // index tidak ditemukan
	}
	
	return false; // index ditemukan
}


/*	Fungsi: menampilkan tulisan berdasarkan tipe yang diinginkan
	PARAMETER: 	tipeNotif:	1 = menampilkan tulisan+ header error
							2 = menampilkan tulisan+ header sukses
							3 = menampilkan pesan saja tanpa header
				
				pesan[]: tulisan yang akan ditampilkan		
*/
void notif(int tipeNotif, char pesan[]){ /// REVIEW: refactor, ganti nganggo string
	clrscr();
	
	switch(tipeNotif){
		case 1: 
			gotoxy(3,2);cout << "ERROR!";
			
			break;
			
		case 2: 
			gotoxy(3,2);cout << "SUKSES!";
			
			break;
			
		case 3:
			// langsung skip ke print pesan
			break;
	}
	gotoxy(3,3); cout << pesan;
	
	getch();
}


/* 	Fungsi: melakukan pengecekan terhadap variabel global "index" jika nilai == 0
	RETURN CODE: 1 = kosong, 0 = terisi
*/
int cekArrayKosong(){
	if(index == 0){
		notif(1, "Data belum dimasukkan! Tekan ENTER untuk kembali ke menu");
		
		return 1;
	}
	
	return 0;
}

void menu(){
	int pilihanMenu;
	
	clrscr();
	gotoxy(3,2);	cout << "+----------Menu----------+";
	gotoxy(3,3);	cout << "| [1] Input              |";
	gotoxy(3,4);	cout << "| [2] Cari Data          |";
	gotoxy(3,5); 	cout << "| [3] Edit               |";
	gotoxy(3,6); 	cout << "| [4] Delete             |";
	gotoxy(3,7);	cout << "| [5] Sorting            |";
	gotoxy(3,8); 	cout << "| [6] Laporan            |";
	gotoxy(3,9); 	cout << "| [7] Keluar Program     |";
	gotoxy(3,10); 	cout << "+------------------------+";
	gotoxy(3,11); 	cout << "| Masukkan nomor menu:   |";
	gotoxy(3,12); 	cout << "+------------------------+";
	gotoxy(26,11);	cin >> pilihanMenu;
	
	switch(pilihanMenu){
		// input
		case 1:
			do{
				index++; // index array dimulai dari [1]
				input_header(index); // menampilkan menu input pegawai
				input_isiNip(index);
				input_isiAnak(index);
				input_isiPendidikan(index);
				input_koreksiData();
				input_isiTunjanganAnak(index);
				input_isiGajiKotor(index);
				input_isiLagi();
			} while (lagi == 'y' || lagi == 'Y');
			
			break;
			
		// cari data
		case 2:
			if(cekArrayKosong() != 0) break;
			search_cariData(search_formulir());
			
			break;
		
		// edit		
		case 3:
			if(cekArrayKosong() != 0) break;
			edit(search_formulir());
			
			break;
		
		// delete
		case 4:
			if(cekArrayKosong() != 0) break;
			hapus(search_formulir());
			
			break;
			
		// laporan sorted
		case 5:
			if(cekArrayKosong() != 0) break;
			laporan(1);
			
			break;
		
		// laporan unsorted
		case 6:
			if(cekArrayKosong() != 0) break;
			laporan(2);
			
			break;
		
		// keluar		
		case 7:
			keluar();
			
			break;
			
		// handler salah input
		default:
			notif(1, "Input tidak dikenali! Tekan ENTER untuk kembali ke menu.");
			
			break;
	}
	menu(); // untuk kembali ke menu
}

void debug(){
	// mengisi seluruh array dengan data contoh, berguna pas gacha angka gotoxy di laporan
	for(int i=1; i <= maxEntryData; i++){
		pegawai[i].nip = i+5;
		pegawai[i].anak = i+2;
		strcpy(pegawai[i].pendidikan, "SD");
		input_isiGajiPokok(i, 1500000);
		input_isiTunjanganAnak(i);
		input_isiGajiKotor(i);
		index++;
	}
}

/// BLOCK UTAMA
main(){
	//debug(); // uncomment utk mengisi data pegawai secara otomatis
	menu();
}
