//////////////////////////////////////////////////////////////////////
///Nama 	: Nur Raditya Mahardika
///NIM		: A12.2018.06015
///Repo		: github.com/nurradityam/tugasUdinus/tree/master/alpro2
//////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

const maxInput = 5; // menentukan jumlah maksimal entri barang
struct structBarang{
	char 	kode[20]; 	// XXXXXXXX, 8 char
	char 	nama[20];	// XXXXXXXXXXXXXXX, 15 char
	long 	harga;
	int 	kuantitas;
	long 	total;
};
structBarang barang[maxInput];
int index = 0;

void inputBarang(){
	char ulangiInput;
	
	for(int i = index; i < maxInput; i++){
		clrscr();
		
		cout << "Masukkan kode barang : "; 		gets(barang[i].kode);
		cout << "\nMasukkan nama barang : "; 	gets(barang[i].nama);
		cout << "\nMasukkan harga barang : "; 	cin >> barang[i].harga;
		cout << "\nMasukkan jumlah barang : "; 	cin >> barang[i].kuantitas;
	
		barang[i].total = barang[i].harga * barang[i].kuantitas;
	
		cout << "\nInput Lagi?(Y/N)"; cin >> ulangiInput;
	
		switch(ulangiInput){
			case 'y':
			case 'Y':
				index++; // iterasi array
				break; // looping lagi
			
			default:
				return;	// keluar dari fungsi input barang
		}
	}
}

void laporan(){
	long grandTotal = 0;
	
	clrscr();
	
	cout << "LAPORAN BARANG" << endl;
	cout << "=====================================================================================";
	gotoxy(02,3); cout << "NO.";
    gotoxy(07,3); cout << "KODE BARANG";
    gotoxy(25,3); cout << "NAMA BARANG";
    gotoxy(50,3); cout << "HARGA";
    gotoxy(65,3); cout << "JUMLAH";
    gotoxy(75,3); cout << "TOTAL";
	
	for(int i = 0; i <= index; i++){
		grandTotal += barang[i].total; // looping untuk menjumlah total harga pada setiap index
		
		gotoxy(02,4+i); cout << (i+1);
		gotoxy(07,4+i); cout << barang[i].kode;
		gotoxy(25,4+i); cout << barang[i].nama;
		gotoxy(50,4+i); cout << barang[i].harga;
		gotoxy(65,4+i); cout << barang[i].kuantitas;
		gotoxy(75,4+i); cout << barang[i].total << endl;
	}
	
	cout << "=====================================================================================\n";
	cout << "TOTAL KESELURUHAN"; gotoxy(75,6+index); cout << grandTotal;
}

void main(){
	inputBarang();
	laporan();
	getch();
}
