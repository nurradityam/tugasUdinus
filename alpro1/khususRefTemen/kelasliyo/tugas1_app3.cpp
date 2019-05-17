#include <conio.h>
#include <iostream.h>

main(){
	const int upahPerjam = 35000;
	const float multiplierLembur = 1.5;
	int input, jamKerjaNormal = 7, jamKerjaLembur, hasilNormal, hasilLembur, hasilTotal;
	
	cout << "Masukkan Jam Kerja : "; cin >> input; cout << endl;
	
	if(input < 7){
	jamKerjaNormal = input;
	hasilNormal = jamKerjaNormal * upahPerjam;
	hasilTotal = hasilNormal;
	
	cout << "Upah Normal : " << jamKerjaNormal << " x " << upahPerjam << " = " << hasilNormal << endl;
	cout << "Upah Total : " << hasilNormal << " = " << hasilTotal << endl;
	} else {
		jamKerjaLembur = input - jamKerjaNormal;
		hasilNormal = jamKerjaNormal * upahPerjam;
		hasilLembur = jamKerjaLembur * upahPerjam * multiplierLembur;
		hasilTotal = hasilNormal + hasilLembur;
		
		cout << "Upah Normal : " << jamKerjaNormal << " x " << upahPerjam << " = " << hasilNormal << endl;
		cout << "Upah Lembur : " << jamKerjaLembur << " x " << upahPerjam << " x " << multiplierLembur << " = " << hasilLembur << endl;
		cout << "Upah Total : " << hasilNormal << " + " << hasilLembur << " = " << hasilTotal << endl;
	}
	
	getch();
}
