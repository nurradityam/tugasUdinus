#include <conio.h>
#include <iostream.h>

main(){
	int inputAngka, hasil;
	
	cout << "Masukkan Angka Bulat :"; cin >> inputAngka;
	cout << endl << endl; //untuk memberi jarak 2 baris
	
	/*
	*	a itu variabel pembantu utk perulangan
	*	jadi blok kode for dibawah diulangan dari 0 sampe nilai yg diinput
	*/
	for(int a = 0; a <= inputAngka; a++){
		hasil += a; // artinya sama kayak hasil = hasil + a
		
		/*	
		*	block kode if dibawah intinya buat ndeteksi angka terakhir aja
		*	jadi kalo nilai variabel a itu blm sama dgn nilai input, nanti outputnya ada + nya. 
		*	kalo udh sampe bilangan akhir nanti ganti output = trs nyetak var hasil	
		*/
		if(a == inputAngka){
			cout << a << " = " << hasil;
		} else {
			cout << a << " + ";
		}
	}
	
	getch();
}
