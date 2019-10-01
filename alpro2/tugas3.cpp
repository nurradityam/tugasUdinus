//////////////////////////////////////////////////////////////////////
///Nama 	: Nur Raditya Mahardika
///NIM		: A12.2018.06015
///Repo		: github.com/nurradityam/tugasUdinus/tree/master/alpro2
//////////////////////////////////////////////////////////////////////

// environment: window size 120
// hasil modifikasi kode https://github.com/nurradityam/tugasUdinus/blob/master/alpro1/PreUAS.cpp

#include <conio.h>
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h> // exit()
#include <string.h> // strcmp()

// deklarasi konstanta
#define maxEntryData 9 // menentukan batas maksimal input data

// deklarasi struct objek
struct structBarang{
	int 	kode; 
	char 	nama[20];
	long 	harga;
	int 	kuantitas;
	long 	total;
};

// deklarasi variabel global
structBarang 	barang[maxEntryData+1],
				barangSorted[maxEntryData+1]; // +1 karena array yg diisi tidak dari 0. REVIEW: model karo view ojo samakan, start ko 0?

int		baris 		= 1,
		kolom 		= 15,
		kolomMax 	= kolom + 12,
		index 		= 0; // penanda jumlah index yang terisi

char	lagi;

// deklarasi class fungsi
void 	input_header(int index),
		input_isiKode(int index),
		input_isiNama(int index),
		input_isiHarga(int index),
		input_isiKuantitas(int index),
		input_isiTotal(int index),
		edit(int index),
		sorting(),
		hapus(int index),
		laporan(int mode),
		keluar(),
		menu(),
		notif(int tipeNotif, char string[]),
		debug();
		
int		search_barang(),
		cekArrayKosong();

bool	search_cekHasil(int returnCode);

// fungsi
void input_header(int index){
	clrscr();

	cout << "Data Barang pada posisi : " << index << endl;
	cout << "=================================" << endl;
}

void input_isiKode(int index){
	cout << "1. Kode \t\t: "; cin >> barang[index].kode;
}

void input_isiNama(int index){
	cout << "2. Nama Barang \t\t: "; gets(barang[index].nama);
}

void input_isiHarga(int index){
	cout << "2. Harga \t\t: "; cin >> barang[index].harga;
}

void input_isiKuantitas(int index){
	cout << "2. Kuantitas \t\t: "; cin >> barang[index].kuantitas;
}

void input_isiTotal(int index){
	barang[index].total = barang[index].harga * barang[index].kuantitas;
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

void search_cariData(int index){
	if(search_cekHasil(index)) return; // melakukan cek terhadap nilai parameter index. jika return true, maka langsung keluar
	
	clrscr();
	cout << "Data Barang pada posisi : " << index << endl;
	cout << "=================================" 				<< endl;
	cout << "1. Kode \t\t: " 		<< barang[index].kode 		<< endl;
	cout << "2. Nama \t\t: " 		<< barang[index].nama 		<< endl;
	cout << "3. Harga \t\t: " 		<< barang[index].harga 		<< endl;
	cout << "4. Kuantitas \t\t: " 	<< barang[index].kuantitas 	<< endl;
	cout << "5. Total \t\t: " 		<< barang[index].total 		<< endl;
	
	getch();
}

/* 	Fungsi: melakukan input ulang pada nomor index yang dimasukkan
	PARAMETER:	index: nomor index yang akan diedit
*/
void edit(int index){
	if(search_cekHasil(index)) return; // melakukan cek terhadap nilai parameter index. jika return true, maka langsung keluar
	
	// melakukan input ulang
	input_isiKode(index);
	input_isiNama(index);
	input_isiHarga(index);
	input_isiKuantitas(index);
	input_isiTotal(index);
	
	notif(2, "Data berhasil diubah! Tekan ENTER untuk kembali ke menu.");
}

void hapus(int index){
	if(search_cekHasil(index)) return; // melakukan cek terhadap nilai parameter index. jika return true, maka langsung keluar
		
	// mengganti value index yg dihapus dgn value index diatasnya, dan looping sampe index terakhir 
	for(int i = index; i <= ::index; i++){
		barang[i]=barang[i+1];
	}
	
	::index--; // mengurangi var global index. karena index ada yg kosong 1 dibagian akhir, tak kurangi wae. harus e di deallocation memori ne
	notif(2, "Data berhasil dihapus! Tekan ENTER untuk kembali ke menu.");
}

void sorting(){
	structBarang temporer;
	
	// copy array untuk versi sorted
	for(int i=1; i<=index; i++){
		barangSorted[i] = barang[i];
	}
	
	// sorting metode selection sort
	for(int i=1; i<=index; i++){
		int minIndex = i;
		
		for(int j=i+1; j<=index; j++){
			if(barangSorted[j].kode < barangSorted[minIndex].kode){
				minIndex = j;
			}
		}
		
		temporer = barangSorted[i];
		barangSorted[i] = barangSorted[minIndex];
		barangSorted[minIndex] = temporer;
	}
}

void laporan(int mode){ /// REVIEW: butuh refactor
	clrscr();
	sorting(); // diurutkan dulu
	
	int i; // variabel pembantu loop
	long grandTotal=0;
	// tampilan header
	gotoxy(11,3); cout << "++++++++++++++++++++++++++++++++++++++++LAPORAN+++++++++++++++++++++++++++++++++++++++++";
	gotoxy(11,4); cout << "+------+---------------+---------------+---------------+---------------+---------------+";
	gotoxy(11,5); cout << "| No \t | Kode \t | Nama \t | Harga \t | Kuantitas \t | Total  \t |";
	gotoxy(11,6); cout << "+------+---------------+---------------+---------------+---------------+---------------+";

	// perulangan output isi data
	/// REVIEW: mending dadi siji ae, gawe array lokal khusus view
	// 1 = sorted, 2 = unsorted
	if(mode == 1){
		for(i=1; i <= index; i++){
			gotoxy(11,6+i); 	cout << "| " << i; 								gotoxy(18,6+i); 	cout << "|";
			gotoxy(20,6+i); 	cout << 		barangSorted[i].kode;			gotoxy(34,6+i); 	cout << "|";
			gotoxy(36,6+i); 	cout << 		barangSorted[i].nama;			gotoxy(50,6+i); 	cout << "|";
			gotoxy(52,6+i); 	cout << 		barangSorted[i].harga;  		gotoxy(66,6+i); 	cout << "|";
			gotoxy(68,6+i); 	cout << 		barangSorted[i].kuantitas;  	gotoxy(82,6+i); 	cout << "|";
			gotoxy(84,6+i); 	cout << 		barangSorted[i].total;			gotoxy(98,6+i); 	cout << "|";
			
			grandTotal += barangSorted[i].total;
		}
	} else { // REVIEW: kei kondisi ae drpd else
		for(i=1; i <= index; i++){
			gotoxy(11,6+i); 	cout << "| " << i; 								gotoxy(18,6+i); 	cout << "|";
			gotoxy(20,6+i); 	cout << 		barang[i].kode;					gotoxy(34,6+i); 	cout << "|";
			gotoxy(36,6+i); 	cout << 		barang[i].nama;					gotoxy(50,6+i); 	cout << "|";
			gotoxy(52,6+i); 	cout << 		barang[i].harga;  				gotoxy(66,6+i); 	cout << "|"; 
			gotoxy(68,6+i); 	cout << 		barang[i].kuantitas;  			gotoxy(82,6+i); 	cout << "|";
			gotoxy(84,6+i); 	cout << 		barang[i].total;				gotoxy(98,6+i); 	cout << "|";
			
			grandTotal += barangSorted[i].total;
		}
	}
	// penutup tabel
	gotoxy(11,6+i); cout << "+------+---------------+---------------+---------------+---------------+---------------+";
	gotoxy(11,7+i); cout << "                                                           TOTAL HARGA : " << grandTotal;
	
	// pesan footer
	gotoxy(43,9+i); cout << "Tekan ENTER untuk kembali ke menu.";
	
	getch();
}

//	Fungsi: menampilkan tulisan goodbye dan menutup aplikasi 
void keluar(){
	notif(3, "Sampai jumpa :)  Tekan ENTER untuk keluar dari aplikasi.");
	exit(0); // fungsi dari cstlib.h
}

int search_formulir(){
	int kode;
	
	clrscr();
	cout << "Masukkan kode: "; cin >> kode;
	
	// metode sequential search
	for(int i = 1; i <= maxEntryData; i++){
        if(barang[i].kode == kode){
            return i; // array yang pertama kali cocok akan menjadi return code
		}
	}
	
    return -1; // sebagai return code error jika tidak ditemukan
}

bool search_cekHasil(int returnCode){
	// handler jika return code -1
	if(returnCode == -1){
		notif(1, "kode tidak ditemukan! Tekan ENTER untuk kembali ke menu.");
		
		return true; // index tidak ditemukan
	}
	
	return false; // index ditemukan
}

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
				input_isiKode(index);
				input_isiNama(index);
				input_isiHarga(index);
				input_isiKuantitas(index);
				input_isiTotal(index);
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
		//strcpy(barang[i].kode, "1234567A");
		strcpy(barang[i].nama, "NAMA BARANG123");
		barang[i].harga = 500000;
		barang[i].kuantitas = 3;
		barang[i].total;
		input_isiTotal(i);
		index++;
	}
}

// block utama
main(){
	//debug();
	menu();
}
