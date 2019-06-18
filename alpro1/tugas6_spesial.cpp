////////////////////////////////////
///Nama 	: Nur Raditya Mahardika
///NIM		: A12.2018.06015
////////////////////////////////////
#include <iostream.h>
#include <conio.h>

// deklarasi konstanta dan variabel
#define maksInput 10 // menentukan jumlah maks entri data

int data[maksInput],
	jumlahData;

// fungsi
void loopCetakData(){
	// mencetak data melalui looping array
	for (int x=0; x < jumlahData; x++){
		cout << data[x] << "\t";
	}
	cout << "\n";
}
void sorting(){
	/// referensi: https://www.geeksforgeeks.org/selection-sort/
	int counterTukar = 0,
		indexTerkecil,
		i, j, t;
	
	for(i=0; i < jumlahData-1; i++){
		indexTerkecil = i;
		cout << "\nTahap : " << (i+1) << "\n";
		cout << "=================================\n";
		
		for(j=i+1; j < jumlahData; j++){
			if(data[j] < data[indexTerkecil]){
				indexTerkecil = j;
				
				// menukar data
				t = data[indexTerkecil];
				data[indexTerkecil] = data[i];
				data[i] = t;
				
				counterTukar++; // menghitung pertukaran yg terjadi
			}
			loopCetakData();
		}
	}
	
	// laporan statistik
	cout << endl << endl;
	cout << "Jumlah tahapan\t: " << jumlahData-1 << endl;
	cout << "Jumlah komparasi\t: " << jumlahData-1 << endl;
	cout << "Jumlah tukar\t: " << counterTukar << endl;
	cout << "Hasil urutan\t: "; loopCetakData();
}

void input(){
	do{
		clrscr();
		cout << "===PROGRAM BUBBLE SORT===" << endl << endl;
		
		// peringatan jika sudah input namun nilai diatas maksInput
		if(jumlahData > maksInput){
			cout << "! Jumlah data yang dimasukkan melebihi batas, silahkan input lagi !" << endl;
		}
		
		// input jumlah entri data
		cout << "Masukkan Jumlah Data : "; cin >> jumlahData;
	} while (jumlahData > maksInput); // block akan diulang jika nilai diatas maksInput

	for(int i=0; i < jumlahData; i++){
		cout << endl << "Masukkan data ke " << (i+1) <<" : "; cin >> data[i];
	}
}

main(){
	input();
	clrscr();
	sorting();
	getch();
}
