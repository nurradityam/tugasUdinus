#include <conio.h>
#include <iostream.h>
#include <stdio.h>

// soroso njelaske aku, kodene wes tk acak ben gk podo wekku

// deklarasi struct
struct sPegawai{
	int nip, anak;
	char pendidikan[10];
};

// deklarasi variabel global
sPegawai pegawai[11];

int	brs = 1,
	klm = 15,
	klmMx = klm + 12,
	posisi = 0;

// deklarasi fungsi
void isiNip();
void isiAnak();
void isiPendidikan();
void tampilan();
void laporan();

// blok utama
main(){
	char lagi;

	do{
		if(posisi == 9) break;
		posisi++;
		
		tampilan();
		isiNip();
		isiAnak();
		isiPendidikan();

		cout << "Isi lagi [y/t]: "; cin >> lagi;

	} while (lagi == 'y');
	
	laporan();
	
	getch();
}

void isiNip(){
	gotoxy(klmMx, brs+2); cin >> pegawai[posisi].nip;
}

void isiAnak(){
	gotoxy(klmMx, brs+3); cin >> pegawai[posisi].anak;
}

void isiPendidikan(){
	int pilihan;

	// tampilan pembantu
	gotoxy(45,5); cout << "|1 = SD  |";
	gotoxy(45,6); cout << "|2 = SMP |";
	gotoxy(45,7); cout << "|3 = SMA |";
	gotoxy(45,8); cout << "|4 = S1  |";
	gotoxy(45,9); cout << "|5 = S2  |";
	gotoxy(45,10); cout << "";

	gotoxy(klmMx, brs+4); cin >> pilihan;

	switch(pilihan){
		case 1: strcpy(pegawai[posisi].pendidikan, "SD"); break;
		case 2: strcpy(pegawai[posisi].pendidikan, "SMP"); break;
		case 3: strcpy(pegawai[posisi].pendidikan, "SMA"); break;
		case 4: strcpy(pegawai[posisi].pendidikan, "S1"); break;
		case 5: strcpy(pegawai[posisi].pendidikan, "S2"); break;
	}
}

void tampilan(){
	clrscr();

	cout << "Data Pegawai pada posisi : " << posisi << endl;
	cout << "=================================" << endl;
	cout << "1. NIP \t\t\t: " << endl;
	cout << "2. Jumlah Anak \t\t: " << endl;
	cout << "3. Pendidikan \t\t: " << endl;
}

void laporan(){
	clrscr();
	
	// output header
	gotoxy(11,3); cout << "Laporan";
	gotoxy(11,4); cout << "+------+---------------+---------------+---------------+";
	gotoxy(11,5); cout << "| No \t | NIP \t\t | Anak \t | Pendidikan \t |";
	gotoxy(11,6); cout << "+------+---------------+---------------+---------------+";

	// perulangan output isi data
	for(int a =1; a <= posisi; a++){
		gotoxy(11,6+a); cout << "| " << a << "\t | " ;
		gotoxy(20,6+a); cout << pegawai[a].nip << "\t\t |";
		gotoxy(36,6+a); cout << pegawai[a].anak  << "\t\t |";
		gotoxy(52,6+a); cout << pegawai[a].pendidikan  << "\t\t |";
		
		if(a == posisi){
			gotoxy(11,7+a); cout << "+------+---------------+---------------+---------------+";
		}
	}
	
	getch();
}
