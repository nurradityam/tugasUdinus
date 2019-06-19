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
structPegawai pegawai[maxEntryData+1]; // +1 karena array yg diisi tidak dari 0

int		baris = 1,
		kolom = 15,
		kolomMax = kolom + 12,
		index = 0;

char	lagi;

/// luweh aman nek deklarasi nama fungsi neng duwur sek, ben ra kasus undefined function

/// FUNGSI
void sort(){
	structPegawai temporer;
	
	// metode bubble sort
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

void menu_exit(){
	clrscr();
	
	cout << "goodbye :(";
	getch();
}

void menuInputPegawai(){
	clrscr();

	cout << "Data Pegawai pada posisi : " << index << endl;
	cout << "=================================" << endl;
	cout << "1. NIP \t\t\t: " << endl;
	cout << "2. Jumlah Anak \t\t: " << endl;
	cout << "3. Pendidikan \t\t: " << endl;
}

void isiLagi(){
	if(index == maxEntryData) { lagi = 'n'; return;}
	
	gotoxy(5,2); 	cout << "+------------------+";
	gotoxy(5,3); 	cout << "|Isi Lagi [Y/T]:   |";
	gotoxy(5,4); 	cout << "+------------------+";
	gotoxy(22,3); 	cin >> lagi;
}

void isiNip(){
	gotoxy(kolomMax, baris+2); cin >> pegawai[index].nip;
}

void isiAnak(){
	gotoxy(kolomMax, baris+3); cin >> pegawai[index].anak;
}

void isiPendidikan(){
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
			pegawai[index].gajiPokok = 1500000;
			break;
			
		case 2: 
			strcpy(pegawai[index].pendidikan, "SMP");
			pegawai[index].gajiPokok = 2000000;
			break;
		
		case 3: strcpy(pegawai[index].pendidikan, "SMA");
			pegawai[index].gajiPokok = 3000000;
			break;
			
		case 4: 
			strcpy(pegawai[index].pendidikan, "S1");
			pegawai[index].gajiPokok = 5000000;
			break;
			
		case 5: 
			strcpy(pegawai[index].pendidikan, "S2");
			pegawai[index].gajiPokok = 5000000;
			break;
		
		// handler salah input
		default:
			gotoxy(29,5); cout << "[INPUT SALAH!, MASUKKAN LAGI!]";
			isiPendidikan(); break;
	}
	
	// menghitung tunjangan anak
	pegawai[index].tunjanganAnak = (0.01 * pegawai[index].gajiPokok) * pegawai[index].anak;
	// menghitung gaji kotor
	pegawai[index].gajiKotor = pegawai[index].tunjanganAnak + pegawai[index].gajiPokok;
	
	clrscr();
}

void laporan(){
	clrscr();
	sort(); // diurutkan
	
	int a; // variabel pembantu loop
	
	// tampilan header
	gotoxy(11,3); cout << "                         Laporan                        ";
	gotoxy(11,4); cout << "+------+---------------+---------------+---------------+";
	gotoxy(11,5); cout << "| No \t | NIP \t\t | Anak \t | Pendidikan \t | Gaji Pokok \t | Tunj. Anak \t | Gaji Kotor";
	gotoxy(11,6); cout << "+------+---------------+---------------+---------------+";

	// perulangan output isi data
	for(a=1; a <= index; a++){
		gotoxy(11,6+a); cout << "| " << a 						<< "\t | " ;
		gotoxy(20,6+a); cout << 		pegawai[a].nip;			gotoxy(34,6+a); cout << "|";
		gotoxy(36,6+a); cout << 		pegawai[a].anak;		gotoxy(50,6+a); cout << "|";
		gotoxy(52,6+a); cout << 		pegawai[a].pendidikan  	<< "\t\t |" << pegawai[a].gajiPokok << "\t" << pegawai[a].tunjanganAnak << "kotor\t" << pegawai[a].gajiKotor;
	}
	// penutup tabel
	gotoxy(11,6+a); cout << "+------+---------------+---------------+---------------+";
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
		case 1:
			do{
				menuInputPegawai(); // menampilkan menu input pegawai
				
				index++; // index array dimulai dari [1]
				isiNip();
				isiAnak();
				isiPendidikan();
				isiLagi();
			} while (lagi == 'y' || lagi == 'Y');
			
			menu(); // kembali ke menu
			break;
			
		case 2:
			// edit
			break;
		
		case 3:
			// delte
			break;
			
		case 4:
			laporan();
			break;
			
		case 5:
			menu_exit();
			break;
			
		// handler salah input
		default:
			// kei tulisan nek salah
			menu();
			break;
	}
}

/// BLOCK UTAMA
main(){
	menu();
}