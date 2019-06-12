#include <iostream.h>
#include <conio.h>
#include <string.h>

// deklarasi konstanta
#define maksInput 5

// deklarasi struct
struct mahasiswa{
	int umur;
	char nama[20];
};

// deklarasi variabel global
mahasiswa mhs[maksInput];

// fungsi
void sort(){
	clrscr();
	
	mahasiswa temporer;
	
	// perulangan tahapan
	for(int i=0; i < maksInput-1; i++){
		cout << "\n Tahap : " << (i) << "\n";
		cout << "===========================\n";
	   
		// perulangan penukaran
		for(int j=i+1; j < maksInput; j++){
			// komparasi string
			if(strcmp(mhs[i].nama, mhs[j].nama) > 0){
				temporer = mhs[i];
				mhs[i] = mhs[j];
				mhs[j] = temporer;
			}
		   
			// mencetak urutan data
			for(int x=0; x < maksInput; x++){
				cout<<mhs[x].nama << "\t";
			}
			cout<<"\n";
		}
	}
	
	getch();
}

void header(){
	cout << "===PROGRAM BUBBLE SORT===" << endl;
	cout << "Masukkan " << maksInput << " nama \n";
}

void inputNama(){
	for(int i=0; i < maksInput; i++){
		cout << "Masukkan Nama ke-" 		<< (i+1) << " : "; cin >> mhs[i].nama;
		cout << "Masukkan Umur Nama ke-" 	<< (i+1) << " : "; cin >> mhs[i].umur;
	}
}

void laporan(){
	/*
		bagian iki kurang rapi, tugasmu rapekke ae, mbuh kei garis penutup tah opo
	 */
	clrscr();
	
	gotoxy(11,4); cout << "-------------------------------------------------";
	gotoxy(12,5); cout << "| NAMA	| UMUR";
	gotoxy(11,6); cout << "-------------------------------------------------";

	for(int i=0; i < maksInput; i++){
		gotoxy(12,7+i);cout << "| " << mhs[i].nama;
		gotoxy(25,7+i);cout << "| " << mhs[i].umur;
	}
}

// blok utama
void main(){
	header();
	inputNama();
	sort();
	laporan();
	getch();
}
