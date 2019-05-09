#include <conio.h>
#include <iostream.h>

main(){
	int index = 0, indexTerkecil = 0, indexTerbesar = 0, array[100];
	float nilaiTotal, nilaiTerkecil, nilaiTerbesar;
	char lagi = 'y';
	
	while(lagi == 'y' || lagi == 'Y'){
		cout << "Masukkan Bilangan ke-" << index << " = ";	cin >> array[index];
		cout << "Ulangi lagi?(Y/N) ";	cin >> lagi;
		cout << endl << "----------------------------------------" << endl;
		
		index++;
	}
	
	nilaiTerkecil = array[0];
	for(int n = 0; n < index; n++){
		if(nilaiTerkecil > array[n]){
			nilaiTerkecil = array[n];
			indexTerkecil = n;
		}
	}
	
	nilaiTerbesar = array[0];
	for(int n = 0; n < index; n++){
		if(nilaiTerbesar < array[n]){
			nilaiTerbesar = array[n];
			indexTerbesar = n;
		}
	}
	
	// output akhir
	for(int n = 0; n < index; n++){		
		cout << "Bilangan ke-" << n << " = " << array[n] << endl << endl;
		
		nilaiTotal += array[n]; // nyambi ngitung total nek dijumlah
	}
	
	cout << "Total Bilangan Adalah : " << nilaiTotal << endl;
	cout << "\tNilai Terkecil = " << nilaiTerkecil << " Terletak pada bilangan ke-" << indexTerkecil << endl;
	cout << "\tNilai Terbesar = " << nilaiTerbesar << " Terletak pada bilangan ke-" << indexTerbesar << endl;
	
	getch();
}