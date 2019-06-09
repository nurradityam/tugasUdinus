#include <conio.h>
#include <iostream.h>
#include <stdio.h>
#include <iomanip.h>
#include <windows.h>

/// khusus copas konco

struct structPegawai
{
	int nip;
	int anak;
	char pendidikan[90];
};
structPegawai pegawai[90];

int	baris = 1, kolom = 15, kolomMax = kolom + 12, index = 0;
char lagi;

void isiLagi(), isiNip(), isiAnak(), isiPendidikan(), tampilan(), laporan(), sort(), sort_tukar();

main()
{
	do
	{
		index++;
		tampilan();
		isiNip();
		isiAnak();
		isiPendidikan();
		isiLagi();
	} while (lagi == 'y' || lagi == 'Y');

	sort();
	laporan();
	getch();
}

void sort_tukar(int lama, int baru)
{
	structPegawai temporer;

	temporer = pegawai[baru];
	pegawai[baru] = pegawai[lama];
	pegawai[lama] = temporer;
}

void sort()
{
	for(int i=1; i<index; i++){
		for(int	j=1; j<index; j++)
		{
			if(pegawai[j].nip < pegawai[j+1].nip)
			{
				sort_tukar(j, j+1);
			}
		}
	}
}

void isiLagi(){
	if(index == 9) { lagi = 'n'; return;} // maks 9 entry
	
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
	gotoxy(27,6); 	cout << "+-Pilihan-+";
	gotoxy(27,7); 	cout << "| 1 = SD  |";
	gotoxy(27,8);	cout << "| 2 = SMP |";
	gotoxy(27,9); 	cout << "| 3 = SMA |";
	gotoxy(27,10); 	cout << "| 4 = S1  |";
	gotoxy(27,11); 	cout << "| 5 = S2  |";
	gotoxy(27,12);	cout << "+---------+";

	gotoxy(kolomMax, baris+4); cin >> pilihan;
	switch(pilihan){
		case 1: strcpy(pegawai[index].pendidikan, "SD"); break;
		case 2: strcpy(pegawai[index].pendidikan, "SMP"); break;
		case 3: strcpy(pegawai[index].pendidikan, "SMA"); break;
		case 4: strcpy(pegawai[index].pendidikan, "S1"); break;
		case 5: strcpy(pegawai[index].pendidikan, "S2"); break;
	}
	
	clrscr();
}

void tampilan(){
	clrscr();

	cout << "Data Pegawai pada posisi : " << index << endl;
	cout << "=================================" << endl;
	cout << "1. NIP \t\t\t: " << endl;
	cout << "2. Jumlah Anak \t\t: " << endl;
	cout << "3. Pendidikan \t\t: " << endl;
}

void laporan(){
	clrscr();
	
	gotoxy(11,3); cout << "                         Laporan                        ";
	gotoxy(11,4); cout << "+------+---------------+---------------+---------------+";
	gotoxy(11,5); cout << "| No \t | NIP \t\t | Anak \t | Pendidikan \t |";
	gotoxy(11,6); cout << "+------+---------------+---------------+---------------+";

	for(int a =1; a <= index; a++){
		gotoxy(11,6+a); cout << "| " << a 						<< "\t | " ;
		gotoxy(20,6+a); cout << 		pegawai[a].nip;			gotoxy(34,6+a); cout << "|";
		gotoxy(36,6+a); cout << 		pegawai[a].anak;		gotoxy(50,6+a); cout << "|";
		gotoxy(52,6+a); cout << 		pegawai[a].pendidikan  	<< "\t\t |";
		
		// untuk menutup tabel
		if(a == index){
			gotoxy(11,7+a); cout << "+------+---------------+---------------+---------------+";
		}
	}
}
