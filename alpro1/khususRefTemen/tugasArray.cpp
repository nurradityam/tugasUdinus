#include <conio.h>
#include <iostream.h>

main(){
	// inisialisasi variabel
	int nilaiIndex[100]; //array maksimal 100 index //FIX ME: gk dinamis 
	int iterasi; //variabel pembantu untuk pengulangan
	int langkah = 0; //biar tahu ini input ke brp
	double nilaiTotal, nilaiTerkecil, nilaiTerbesar; 
	int indexTerkecil = 0, indexTerbesar = 0;
	char lagi = 'n';
	
	do{
		/*
		*	memasukkan nilai ke nilaiIndex[langkah]
		*	jadi variable langkah dimulai dari 0 atau nilaiIndex[0], karena inisialisasi nya langkah = 0
		*	
		*/
		cout << "Masukkan Bilangan ke-" << langkah << " = ";
		cin >> nilaiIndex[langkah];
		
		cout << "Ulangi lagi?(Y/N) ";
		cin >> lagi;
		
		cout << endl << "----------------------------------" << endl;
		
		langkah++; // iterasi supaya nilaiIndex[0] jadi nilaiIndex[1] dan seterusnya jika ingin diulang
	} while(lagi == 'y' || lagi == 'Y'); // jika user input y/Y maka akan diulang, selain input tersebut dianggap selesai
	
	/*
	*	untuk output semua index dan nilainya brp
	*	iterasi cuma variabel pembantu
	*	jadi nanti subprogram diulang sampai <= langkah  
	*/
	for(iterasi = 0; iterasi < langkah; iterasi++){
		cout << "Bilangan ke-" << iterasi << " = " << nilaiIndex[iterasi] << endl << endl;
	}
	
		
	/*
	*	untuk menghitung pemjumlahan semua nilai index 
	*	iterasi cuma variabel pembantu
	*	jadi nanti subprogram diulang sampai <= langkah  
	*/
	for(iterasi = 0; iterasi < langkah; iterasi++){
		nilaiTotal += nilaiIndex[iterasi];
	}
	
	/*
	*	untuk menghitung nilai terkecil
	*	jadi nilai index pertama dibandingkan dengan nilai index selanjutnya
	*	iterasi cuma variabel pembantu
	*	indexTerkjecil cuma variabel pembantu biar nanti tau nilai tersebut brp di index brp
	*	jadi nanti subprogram diulang sampai <= langkah  
	*/
	nilaiTerkecil = nilaiIndex[0];
	for(iterasi = 0; iterasi < langkah; iterasi++){
		if(nilaiTerkecil > nilaiIndex[iterasi]){
			nilaiTerkecil = nilaiIndex[iterasi];
			indexTerkecil = iterasi;
		}
	}
	
	/*
	*	untuk menghitung nilai terbesar
	*	sama kayak diatas cuma dibalik
	*/
	nilaiTerbesar = nilaiIndex[0];
	for(iterasi = 0; iterasi < langkah; iterasi++){
		if(nilaiTerbesar < nilaiIndex[iterasi]){
			nilaiTerbesar = nilaiIndex[iterasi];
			indexTerbesar = iterasi;
		}
	}
	
	cout << "Total Bilangan Adalah : " << nilaiTotal << endl;
	cout << "Nilai Terbesar = " << nilaiTerbesar << " Terletak pada bilangan ke-" << indexTerbesar << endl;
	cout << "Nilai Terkecil = " << nilaiTerkecil << " Terletak pada bilangan ke-" << indexTerkecil << endl;
	
	getch();
}
