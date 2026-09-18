#include <iostream>


using namespace std;


int hitungPanjang(char arr[]) {
  int count = 0;
  while (arr[count] != '\0') {
      count++;
  }
  return count;
}


int main() {
  char pesan[100];
   cout << "Pesan Anda (Harus huruf kapital A-Z): ";
  cin >> pesan;


  int panjang = hitungPanjang(pesan);


  if (panjang == 0) {
      return 0;
  }


  for (int i = 0; i < panjang; i++) {
      if (pesan[i] < 'A' || pesan[i] > 'Z') {
          cout << "\n----!!!ERROR!!!----" << endl << "Pesan harus berupa huruf kapital (A-Z)!!" << endl;
          return 0;
      }
  }
  cout << "Sandi Anda: ";


  cout << pesan[0];
   int huruf_sebelumnya_nilai = (pesan[0] - 'A') + 1;


  for (int i = 1; i < panjang; i++) {
      int nilai_sekarang = (pesan[i] - 'A') + 1;
      int nilai_baru = nilai_sekarang + huruf_sebelumnya_nilai;
       nilai_baru = ((nilai_baru - 1) % 26) + 1;


      char huruf_baru = (nilai_baru - 1) + 'A';


      cout << huruf_baru;


      huruf_sebelumnya_nilai = nilai_sekarang;
  }


  cout << endl;


  return 0;
}


