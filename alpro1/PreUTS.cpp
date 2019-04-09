#include <iostream.h>
#include <conio.h>
#include <stdio.h>

main(){
	// deklarasi variabel
	char nama[50], kode[50], tipeInput, tipe[50], ulangiProgramInput;
	float meterLama, meterBaru, diskon, jumlahBayar, jumlahPakai, tarif;
	bool ulangiTipe, ulangiProgram;
	long kembalian, totalSemua, totalBayar, totalAkhir;
	
	do{
		// input pertama
		clrscr();
		cout << "=========================================================" << endl;
		cout << "Masukkan Nama Pelanggan : "; gets(nama);
		cout << "Masukkan Kode Pelanggan : "; cin >> kode;
		cout << "Masukkan Bacaan Meteran Lama : "; cin >> meterLama;
		cout << "Masukkan Bacaan Meteran Baru : "; cin >> meterBaru;

		jumlahPakai = meterBaru - meterLama;
		
		// input kedua
		do{
			clrscr();
			cout << "=========================================================" << endl;
			cout << "Daftar Tipe Pelanggan :" << endl;
			cout << "A. Perumahan." << endl;
			cout << "B. Perusahaan." << endl;
			cout << "C. Supermarket." << endl << endl;
			cout << "Masukkan Tipe Sesuai Huruf : "; cin >> tipeInput;

			switch(tipeInput){
				case 'a':
				case 'A':
					strcpy(tipe, "Perumahan");
					tarif = 10000;
					totalSemua = tarif * jumlahPakai;
					
					if(totalSemua > 500000){
						diskon = totalSemua * 0.2;
						totalAkhir = totalSemua - diskon;
						
					} else if(totalSemua > 100000) {
						diskon = totalSemua * 0.2;
						totalAkhir = totalSemua - diskon;
						
					} else {
						diskon = 0;
						totalAkhir = totalSemua - diskon;
					}
					
					ulangiTipe = 0;

					break;

				case 'b':
				case 'B':
					strcpy(tipe, "Perusahaan");
					tarif = 40000;
					totalSemua = tarif * jumlahPakai;
					
					if(totalSemua > 500000){
						diskon = totalSemua * 0.2;
						totalAkhir = totalSemua - diskon;
						
					} else if(totalSemua > 100000) {
						diskon = totalSemua * 0.2;
						totalAkhir = totalSemua - diskon;
						
					} else {
						diskon = 0;
						totalAkhir = totalSemua - diskon;
					}
					
					ulangiTipe = 0;

					break;
					
				case 'c':
				case 'C':
					strcpy(tipe, "Supermarket");
					tarif = 20000;
					totalSemua = tarif * jumlahPakai;
					
					if(totalSemua > 500000){
						diskon = totalSemua * 0.2;
						totalAkhir = totalSemua - diskon;
						
					} else if(totalSemua > 100000) {
						diskon = totalSemua * 0.2;
						totalAkhir = totalSemua - diskon;
						
					} else {
						diskon = 0;
						totalAkhir = totalSemua - diskon;
					}
					
					ulangiTipe = 0;

					break;
					
				default:
					clrscr();
					cout << "=========================================================" << endl;
					cout << "Kode Yang Anda Masukkan Salah!" << endl;
					cout << "Tekan ENTER untuk mengulangi input!";
					getch();
					
					ulangiTipe = 1;
					
					break;
			}
		} while(ulangiTipe == 1);
		
		// output hasil
		clrscr();
		cout << "=========================================================" << endl;
		cout << "Kode Pelanggan : " << kode << endl;
		cout << "Nama Pelanggan : " << nama << endl;
		cout << "Bacaan Meteran Sebelumnya : " << meterLama << endl;
		cout << "Bacaan Meteran Sekarang : " << meterBaru << endl;
		cout << "Jumlah Pemakaian Listrik : " << jumlahPakai << endl;
		cout << "Tipe Golongan Pelanggan : " << tipe << endl;
		cout << "Total Pembayaran Tanpa Diskon : " << totalSemua << endl;
		cout << "Total Pembayaran Dengan Diskon : " << totalAkhir << endl;
		cout << "=========================================================" << endl << endl;
		
		// input jumlah bayar
		cout << "Masukkan Jumlah Uang Anda : "; cin >> jumlahBayar;
		
		kembalian = jumlahBayar - totalAkhir;
		
		clrscr();
		cout << "=========================================================" << endl;
		cout << "Kembalian anda : " << kembalian << endl << endl;
		cout << "Apakah anda ingin input data lagi (Y/N)? "; cin >> ulangiProgramInput;
		
		switch(ulangiProgramInput){
			case 'y':
			case 'Y':
				ulangiProgram = true;
				
				break;
				
			default:
				ulangiProgram = false;
				
				break;
		}
	} while(ulangiProgram == true);
	
	// output salam penutup
	clrscr();
	cout << "=========================================================" << endl;
	cout << "Terima Kasih :)" << endl << endl;
	cout << "Tekan ENTER untuk keluar aplikasi";
	
	getch();
}
