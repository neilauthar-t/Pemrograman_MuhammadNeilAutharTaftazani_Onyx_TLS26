#include <iostream>

using namespace std;

int main() {
    int N, K;
    
    cout << "MOHON HANYA MASUKKAN BILANGAN BULAT!!" << endl;
    cout << "Jumlah astronaut (N): ";
    cin >> N;
    cout << "Nilai K awal: ";
    cin >> K;

    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        A[i] = i + 1;
    }

    int sisa_astronot = N;
    int indeks_posisi = 0;

    cout << "\n\n----Proses Eliminasi----" << endl << endl;

    while (sisa_astronot > 1) {
        int langkah_terhitung = 0;
        
        while (langkah_terhitung < K) {
            if (A[indeks_posisi] != 0) {
                langkah_terhitung++;
            }
            
            if (langkah_terhitung < K) {
                indeks_posisi++;
                if (indeks_posisi >= N) {
                    indeks_posisi = 0; 
                }
            }
        }

        int astronaut_tereliminasi = A[indeks_posisi];
        cout << "Astronaut tereliminasi: " << astronaut_tereliminasi << "\t(K awal: " << K << ")";
        
        A[indeks_posisi] = 0;
        sisa_astronot--;

        if (astronaut_tereliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }
        cout << "\t-> K baru:\t" << K << endl;

        while (sisa_astronot > 1) {
            indeks_posisi++;
            if (indeks_posisi >= N) {
                indeks_posisi = 0;
            }
            if (A[indeks_posisi] != 0) {
                break;
            }
        }
    }

    cout << "\n------------------------" << endl;
    for (int i = 0; i < N; i++) {
        if (A[i] != 0) {
            cout << "Astronaut terakhir yang bertahan: " << A[i] << endl;
        }
    }

    delete[] A;

    return 0;
}