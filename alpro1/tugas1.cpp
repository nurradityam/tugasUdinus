#include <stdio.h>
#include <conio.h>
#include <iostream.h>

// deklarasi variabel konstanta global
#define PI 3.14
#define newlineTiga "\n\n\n"
#define newlineDua "\n\n"

void main() {
	///////////////////////////////
	/// Menghitung Volume Kubus ///
	///////////////////////////////

	// deklarasi variabel lokal
	float cariVolumeKubus_sisi = 12.9;
	float cariVolumeKubus_hasil;

	// proses
	cariVolumeKubus_hasil = cariVolumeKubus_sisi * cariVolumeKubus_sisi * cariVolumeKubus_sisi;

	// output layar
	cout << "===========================" << endl;
	cout << "= Menghitung Volume Kubus =" << endl;
	cout << "===========================" << endl;

	cout << "Panjang Sisi Kubus: " <<
   	cariVolumeKubus_sisi <<
      newlineDua;

	cout << "Volume Kubus: " <<
   	cariVolumeKubus_sisi << " * " <<
      cariVolumeKubus_sisi << " * " <<
   	cariVolumeKubus_sisi << " = " <<
      cariVolumeKubus_hasil << newlineTiga;

	//////////////////////////////////
	/// Menghitung Volume Silinder ///
	//////////////////////////////////

	// deklarasi variabel lokal
	float cariVolumeSilinder_jari = 12.5;
	float cariVolumeSilinder_tinggi = 10.7;
	float cariVolumeSilinder_hasil;

	// proses
	cariVolumeSilinder_hasil = PI * cariVolumeSilinder_jari * cariVolumeSilinder_jari * cariVolumeSilinder_tinggi;

	// output layar
	cout << "==============================" << endl;
	cout << "= Menghitung Volume Silinder =" << endl;
	cout << "==============================" << endl;
	cout << "Panjang Jari-Jari Silinder: " << cariVolumeSilinder_jari << endl;
	cout << "Tinggi Silinder: " << cariVolumeSilinder_tinggi << newlineDua;
	cout << "Volume Silinder: " <<
   	PI << " * " <<
      cariVolumeSilinder_jari << " * " <<
      cariVolumeSilinder_jari << " * " <<
      cariVolumeSilinder_tinggi << " = " <<
      cariVolumeSilinder_hasil << newlineTiga;

	/////////////////////////////////
	/// Menghitung Volume Kerucut ///
	/////////////////////////////////

	// deklarasi variabel lokal
	float cariVolumeKerucut_jari = 11.2;
	float cariVolumeKerucut_tinggi = 20.1;
	float cariVolumeKerucut_hasil;

	// proses
	cariVolumeKerucut_hasil = 0.33 * PI * cariVolumeKerucut_jari * cariVolumeKerucut_jari * cariVolumeKerucut_tinggi;

	// output layar
	cout << "=============================" << endl;
	cout << "= Menghitung Volume Kerucut =" << endl;
	cout << "=============================" << endl;
	cout << "Panjang Jari-Jari Kerucut: " << cariVolumeKerucut_jari << endl;
	cout << "Tinggi Kerucut: " << cariVolumeKerucut_tinggi << endl << endl;
	cout << "Volume Kerucut: " <<
   	"0.33" << " * " <<
   	PI << " * " <<
      cariVolumeKerucut_jari << " * " <<
      cariVolumeKerucut_jari << " * " <<
      cariVolumeKerucut_tinggi << " = " <<
      cariVolumeKerucut_hasil << endl;

	getch();
}
