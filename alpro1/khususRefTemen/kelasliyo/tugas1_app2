#include <conio.h>
#include <iostream.h>

main(){
	int input[3], temporer;
	
	cout << "Masukkan A :"; cin >> input[0];
	cout << "Masukkan B :"; cin >> input[1];
	cout << "Masukkan C :"; cin >> input[2];
	
	cout << endl; //untuk memberi jarak 1 baris
	
	// iki nganggo algo bubblesort
	// mbuh ramudeng aku jelaskene, aku mung adaptasi ko iki thecrazyprogrammer.com/2011/11/c-program-to-sort-array-by-using-bubble.html
	for(int i=1; i<3; ++i)
	{
		for(int j=0; j<(3-i); ++j)
			if(input[j]<input[j+1])
			{
				temporer = input[j];
				input[j] = input[j+1];
				input[j+1] = temporer;
			}
	}
	
	for(int i=0;i<3;++i)
		cout << input[i] << "\t";
	
	getch();
}
