//////////////////////////////////////////////////////////////////////
///Nama 	: Nur Raditya Mahardika
///NIM		: A12.2018.06015
///Repo		: github.com/nurradityam/tugasUdinus/tree/master/alpro2
//////////////////////////////////////////////////////////////////////
// raceto dikon gawe stack opo queue, kode iki asale antrian, trs tk tambah fx pop
#include <iostream.h>
#include <conio.h>

/// global variable
const int batasEntri = 10; // menentukan jumlah array data

struct structData{
    int id;
    int golongan;
    int dayaLama;
    int dayaBaru;
};

structData data[batasEntri];

int index = 0; // variabel global untuk mengetahui index keberapa yang terisi

/// class
void enqueue(){
    if(index == batasEntri){
        cout << "Stack Penuh !";
        getch();

        return;
    }

    clrscr();
    cout << "Ini data pada index ke [" << index << "]"  << endl;
    cout << "=========================================" << endl;
    cout << "1. No Pelanggan : ";   cin >> data[index].id;
    cout << "2. Golongan : ";       cin >> data[index].golongan;
    cout << "3. Daya Lama : ";      cin >> data[index].dayaLama;
    cout << "4. Daya Baru : ";      cin >> data[index].dayaBaru;

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

    // REVIEW: hawane secara teknis rausah nganggo kenek an
    data[(index-1)].id = NULL;
    data[(index-1)].golongan = NULL;
    data[(index-1)].dayaLama = NULL;
    data[(index-1)].dayaBaru = NULL;

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

    // REVIEW: hawane secara teknis rausah nganggo kenek an
    data[(index-1)].id = NULL;
    data[(index-1)].golongan = NULL;
    data[(index-1)].dayaLama = NULL;
    data[(index-1)].dayaBaru = NULL;

    index--;

    getch();
}

void view(){
    int i; // variabel pembantu loop
    int x = -6; // adjuster untuk gotoxy, geser kekiri nilai negatif, geser kekanan positif

    clrscr();
    gotoxy(11+x,2); cout << "++++++++++++++++++++++++++++++Laporan Daftar Tunggu Perubahan Daya Listrik++++++++++++++++++++++++++++++";
	gotoxy(11+x,3); cout << "+------+---------------+---------------+---------------+---------------+---------------+---------------+";
	gotoxy(11+x,4); cout << "| No   | No.Pelanggan  | Golongan      | Daya Lama     | Daya Baru     | Bayar         |               |";
	gotoxy(11+x,5); cout << "+------+---------------+---------------+---------------+---------------+---------------+---------------+";

    for(i=0; i < index; i++){
			gotoxy(11+x,6+i); 	cout << "| " << i; 					    gotoxy(18+x,6+i);   cout << "|";
			gotoxy(20+x,6+i); 	cout << 		data[i].id;				gotoxy(34+x,6+i); 	cout << "|";
			gotoxy(36+x,6+i); 	cout << 		data[i].golongan;	    gotoxy(50+x,6+i); 	cout << "|";
			gotoxy(52+x,6+i); 	cout << 		data[i].dayaLama;  		gotoxy(66+x,6+i); 	cout << "|";
			gotoxy(68+x,6+i); 	cout << 		data[i].dayaBaru;  		gotoxy(82+x,6+i);	cout << "|";
			//gotoxy(84+x,6+i); 	cout << 		data[i].tunjanganAnak;  	gotoxy(98,6+i); 	cout << "|";
			//gotoxy(100+x,6+i); 	cout << 		data[i].gajiKotor;  		gotoxy(114,6+i); 	cout << "|";
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
                //dequeue();
                pop();
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
