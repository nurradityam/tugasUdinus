//////////////////////////////////////////////////////////////////////
///Nama 	: Nur Raditya Mahardika
///NIM		: A12.2018.06015
///Repo		: github.com/nurradityam/tugasUdinus/tree/master/alpro2
//////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include <conio.h>
#include <stdio.h>

/// global variable
const int batasEntri = 10; // menentukan jumlah array data

struct structData{
    int     id;
    char    nama[20];
    int     dayaLama;
    int     dayaBaru;
    long    tarif;
};

structData data[batasEntri];

int index = 0; // variabel global untuk mengetahui index keberapa yang terisi

/// function
void enqueue(){
    if(index == batasEntri){
        cout << "Stack Penuh !";
        getch();

        return;
    }

    clrscr();
    cout << "Ini data pada index ke [" << index << "]"  << endl;
    cout << "=========================================" << endl;
    cout << "1. No Pelanggan : ";       cin >> data[index].id;
    cout << "2. Nama : ";               gets(data[index].nama); 
    cout << "3. Meter Lama : ";         cin >> data[index].dayaLama;
    cout << "4. Meter Sekarang : ";     cin >> data[index].dayaBaru;
    cout << "5. Tarif : ";              cin >> data[index].tarif;

    index++;
}

void dequeue(){
    if(index == 0){
        cout << "Antrian Kosong !";
        getch();

        return;
    }

	cout << "Nomor pelanggan pada antrian pertama = " << data[0].id << " ,berhasil di pop" << endl;

    // geser data
    for(int a=0; a < (index-1); a++){
        data[a] = data[(a+1)];
    }

    index--;

    getch();
}

void pop(){
    if(index == 0){
        cout << "Stack Kosong !";
        getch();

        return;
    }

	cout << "Nomor pelanggan pada stack paling atas = " << data[index-1].id << " ,berhasil di pop" << endl;

    index--;

    getch();
}

void view(){
    int i; // variabel pembantu loop
    int x = -6; // adjuster untuk gotoxy, geser kekiri nilai negatif, geser kekanan positif

    clrscr();
    gotoxy(11+x,2); cout << "++++++++++++++++++++++++++++++Laporan Daftar Tunggu Perubahan Daya Listrik++++++++++++++++++++++++++++++";
	gotoxy(11+x,3); cout << "+------+---------------+---------------+---------------+---------------+---------------+---------------+";
	gotoxy(11+x,4); cout << "| No   | No.Pelanggan  | Nama          | Meter Lalu    | Meter Sekarang| Tarif         | Bayar         |";
	gotoxy(11+x,5); cout << "+------+---------------+---------------+---------------+---------------+---------------+---------------+";

    for(i=0; i < index; i++){
            long bayar = (data[i].dayaBaru - data[i].dayaLama) * data[i].tarif;

			gotoxy(11+x,6+i); 	cout << "| " << i; 			        gotoxy(18+x,6+i);   cout << "|";
			gotoxy(20+x,6+i); 	cout << 		data[i].id;		    gotoxy(34+x,6+i); 	cout << "|";
			gotoxy(36+x,6+i); 	cout << 		data[i].nama;	    gotoxy(50+x,6+i); 	cout << "|";
			gotoxy(52+x,6+i); 	cout << 		data[i].dayaLama;   gotoxy(66+x,6+i); 	cout << "|";
			gotoxy(68+x,6+i); 	cout << 		data[i].dayaBaru;   gotoxy(82+x,6+i);	cout << "|";
			gotoxy(84+x,6+i); 	cout << 		data[i].tarif;      gotoxy(98+x,6+i); 	cout << "|";
			gotoxy(100+x,6+i); 	cout << 		bayar;  		    gotoxy(114+x,6+i); 	cout << "|";
    }

	gotoxy(11+x,6+i); cout << "+------+---------------+---------------+---------------+---------------+---------------+---------------+";
    gotoxy(43+x,8+i); cout << "Tekan ENTER untuk kembali ke menu.";
    getch();
}

void main(){
    int pilihan = 0;

    do{
        clrscr();

        cout << "Operasi Stack" << endl;
        cout << "==========================" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. View" << endl;
        cout << "Pilih 0 s/d 3 :" << endl; cin >> pilihan;

        switch(pilihan){
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                //pop();
                break;

            case 3:
                view();
                break;

            default:
                break;
        }
    } while (pilihan != 0);

    getch();
}
