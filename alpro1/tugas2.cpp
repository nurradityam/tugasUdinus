#include <iostream.h>
#include <conio.h>
#include <stdio.h>

main()
{
   // deklarasi variabel
   char pelangganNama[50], pelangganKode[50], barangKode, barangNama[50];
   float hargaSatuan, hargaTotal, diskon, hargaDiskon, bayar;
   int jumlahBeli;
   long kembalian;

   int debug1 = 1;

   cout << "===================================" << endl;
   cout << "Masukkan Kode Pelanggan : "; cin >> pelangganKode; endl;
   cout << "Masukkan Nama Pelanggan : "; gets(pelangganNama); endl; endl;
   clrscr();

   cout << "===================================" << endl;
   cout << "Daftar Barang : " << endl;
   cout << "1. Sandal Swallow" << endl;
   cout << "2. Fidget Spinner" << endl;
   cout << "3. Mouse Razer" << endl << endl;
   cout << "Masukkan kode barang : "; cin >> barangKode;
   clrscr();

   switch (barangKode)
   {
	case '1':
		cout << "===================================" << endl;
      	cout << "Anda membeli sandal swallow" << endl << endl;
        cout << "Anda mau beli berapa? "; cin >> jumlahBeli;

       	strcpy(barangNama, "Sandal Swallow");
      	hargaSatuan = 20000;
        hargaTotal = hargaSatuan * jumlahBeli;

        	if (hargaTotal >= 50000) diskon = 0.02;
        	else if (hargaTotal >= 10000) diskon = 0.035;
        	else diskon = 0;

      	break;

      case '2':
      	cout << "===================================" << endl;
      	cout << "Anda membeli Fidget Spinner" << endl;
        	cout << "Anda mau beli berapa? "; cin >> jumlahBeli;

        	strcpy(barangNama, "Fidget Spinner");
      	hargaSatuan = 30000;
        	hargaTotal = hargaSatuan * jumlahBeli;

        	if (hargaTotal >= 200000) diskon = 0.65;
        	else if (hargaTotal >= 150000) diskon = 0.05;
        	else if (hargaTotal >= 60000) diskon = 0.03;

      	break;

      case '3':
        	cout << "===================================" << endl;
      	cout << "Anda membeli Mouse Razer" << endl;
        	cout << "Anda mau beli berapa? "; cin >> jumlahBeli;

        	strcpy(barangNama, "Mouse Razer");
      	hargaSatuan = 10000;
         hargaTotal = hargaSatuan * jumlahBeli;

        	if (hargaTotal >= 150000) diskon = 0.055;
        	else if (hargaTotal >= 75000) diskon = 0.033;
        	else if (hargaTotal > 20000) diskon = 0.15;
      	else if (hargaTotal <= 20000) diskon = 0;

      	break;
   }

   clrscr();
   cout << "===================================" << endl;
   cout << "Masukkan uang anda : "; cin >> bayar;

   hargaDiskon = hargaTotal - (hargaTotal * diskon);
   kembalian = bayar - hargaDiskon;

   clrscr();
   cout << "===========================================" << endl;
   cout << "Nama Pelanggan \t\t: " << pelangganNama << endl;
   cout << "Kode Pelanggan \t\t: " << pelangganKode << endl;
   cout << "Nama Barang \t\t: " << barangNama << endl;
   cout << "Harga Sebelum Diskon \t: " << hargaTotal << endl;
   cout << "Harga Sesudah Diskon \t: " << hargaDiskon << endl;
   cout << "Kembalian \t\t: " << kembalian << endl;
   cout<<"DEBUG :"<<diskon<<endl;
   cout << "===========================================" << endl;

   getch();
}
