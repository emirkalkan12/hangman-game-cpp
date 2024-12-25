#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;

int ascii_farki(char c1, char c2);
int harfKontrol(char harf);
int kelimeKontrol();
void kelimeOlustur();
void menu();
void oyunuDevamEttir();
void kaydet(char* tahmin, int tahminSayisi);

// KELIMELER DIZISI
char kelimeler[][20] = { "ORANGE",  "APPLE", "BANANA", "PEACH", "GRAPE", "MELON", "APRICOT", "CHERRY" };
char* kelime;// dizilerde pointer iþlemi için
char* tahmin;//dizilerde pointer iþlemi için
int length;
// IKI KELIME ARASINDAKI ASCII FARK HESAPLAMA,NEGATIF OLURSA MUTLAK DEGER FONKSIYONU KULLANDIK
int ascii_farki(char c1, char c2) {
    return abs(c1 - c2);
}



// Kullanýcýdan harf alýnýr ve kapalý durumdaki harfler ile karþýlaþtýrma yapýlýr
int harfKontrol(char harf)
{
    int i = 0, sonuc = 0;
    while (i < length)
    {
        if (harf == kelime[i])
        {
            if (tahmin[i] == '-')
            {
                tahmin[i] = harf;
                sonuc = 1;
            }
            else
                //Zaten bulunmuþ bir harf tekrar girilirse kullanýcý uyarýlýr
            {
                cout << "THIS LETTER HAS ALREADY BEEN FOUND.PLEASE ENTER ANOTHER LETTER" << endl;
                return 2;
            }
        }
        i++;
    }
    cout << endl;
    return sonuc;
}

int kelimeKontrol()
{
    int i = 0;
    int sonuc = 1;
    while (i < length)
    {
        if (tahmin[i] == '-')
        {
            sonuc = 0;
        }
        i++;
    }

    return sonuc;
}



void kelimeOlustur()
{
    int indis = rand() % 8;//indis deðiþkeni 0 ile 7 arasýnda rastgele bir sayý olarak atanýyor.Bu sayý kelimeler dizisinden rastgele bir kelime seçmek için kullanýlacak.
    kelime = kelimeler[indis];
    length = strlen(kelime);                           // DÝNAMÝK BELLEK YÖNTEMÝ
    tahmin = new char[length + 1];// Tahmin iþaretçisi, length + 1 kadar bellek alanýna sahip olacak þekilde dinamik  bellek olarak ayýrýyoruz.
    int i = 0;
    while (i < length)
    {
        tahmin[i] = '-';
        i++;
    }
    tahmin[length] = '\0';//Tahmin dizisinin son elemanýna null karakteri atanýyor.

    cout << "LENGTH OF THE WORD :  " << length << endl;
    cout << "CURRENT STATE OF THE WORLD :  " << tahmin << endl;
    


    char harf;
    int tahminSayisi = 0;
    int maxTahmin = 9;
    int cizgi = 0;
    bool game = true;//Game deðiþkeni true olarak baþlatýlýr.Bu deðiþken oyunun devam edip etmeyeceðini belirler.
    while (tahminSayisi < maxTahmin && game)
    {
        cout << "ENTER LETTER : ";
        cin >> harf;

        system("cls");
        
       

        if (harfKontrol(harf))
        {
            cout << "YOU GUESSED THE LETTER CORRECTLY" << endl;
            for (int i = 0; i < length; i++)
            {
                if (kelime[i] == harf)
                {
                    tahmin[i] = harf;
                }
            }
            cout << "CURRENT STATE OF THE WORLD : " << tahmin << endl;
           
            if (kelimeKontrol())
            {
                cout << "YOU WIN" << endl;
                break;
            }
        }
        else
        {
            cout << "SORRY WRONG LETTER" << endl;
            tahminSayisi++;
            cout << "CURRENT STATE OF THE WORLD : " << tahmin << endl;
            //Yanlýþ bir harf girildiði zaman kapalý olan en yakýn harfe göre ceza puaný uygulanýr. 
            //Harfler arasý her 5 birim uzaklýk için aþaðýdaki þekilde yer alan bir parça çizilir.
            //ascýý tablosu ile çizilecek parça sayýsý(cizgi) arasýndaki matematiksel algoritma aþaðýdaki gibidir

            int en_yakin_fark = ascii_farki(harf, kelime[0]);
            for (int i = 1; i < length; i++)
            {
                int fark = ascii_farki(harf, kelime[i]);
                if (en_yakin_fark > fark)
                {
                    en_yakin_fark = fark;
                }
            }

            cizgi += (en_yakin_fark / 5) + 1; // 
            if (cizgi == 1)
            {
                cout << "\t\t\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;


            }
            if (cizgi == 2)
            {
                cout << "\t\t___________\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;

            }
            if (cizgi == 3)
            {
                cout << "\t\t___________\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;


            }
            if (cizgi == 4)
            {
                cout << "\t\t___________\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t     O     |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;


            }
            if (cizgi == 5)
            {
                cout << "\t\t___________\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t     O     |\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;


            }
            if (cizgi == 6)
            {
                cout << "\t\t___________\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t     O     |\n" << endl;
                cout << "\t\t     |\\   |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;


            }
            if (cizgi == 7)
            {
                cout << "\t\t___________\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t     O     |\n" << endl;
                cout << "\t\t    /|\\   |\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;


            }
            if (cizgi == 8)
            {

                cout << "\t\t___________\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t     O     |\n" << endl;
                cout << "\t\t    /|\\   |\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t    /|     |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;


            }
            if (cizgi >= 9)
            {

                cout << "\t\t___________\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t     O     |\n" << endl;
                cout << "\t\t    /|\\   |\n" << endl;
                cout << "\t\t     |     |\n" << endl;
                cout << "\t\t    /|\\   |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t           |\n" << endl;
                cout << "\t\t-----------\n" << endl;
                cout << "\t\t---YOU LOST--- \n" << endl;
                cout << kelime << endl;
                game = false;
            }

        }
        if (tahminSayisi == maxTahmin)
            // MAX TAHMIN SAYISI '9' OLARAK TANIMLADIK CUNKU HANGMAN DOKUZ PARCADAN OLUSUYOR
        {
            cout << "YOUR GUESS IS OVER YOU COULDN'T FIND THE WORLD" << endl;
            cout << " CORRECT WORD : " << kelime << endl;
        }
    }
}              // GÝRÝÞTE KULLANICIYI KARÞILAYAN MENÜ
void menu() {
    cout << "-----------------------------------------WELCOME TO HANGMAN GAME-----------------------------------------" << endl;
    cout << "--------------------------------------PLEASE ENTER CAPITAL LETTERS ONLY--------------------------------------" << endl;
    cout << "******************************************PRESS 1 FOR NEW GAME*********************************************** " << endl;
    cout << "******************************************PRESS 2 TO QUIT GAME**********************************************" << endl;
    cout << "******************************************PRESS 3 FOR SAVE GAME  **********************************************" << endl;
    int secim;
    cin >> secim;
    switch (secim) {
    case 1:
        kelimeOlustur();
        break;
    case 2:
        cout << "YOU LEFT THE GAME";
        exit(0);
        break;
    case 3:
        cout << "ENTER SAVED GAME ";
        oyunuDevamEttir();
        break;
    default:
        cout << "WRONG CHOICE" << endl;
        break;
    }
}                          /////// DOSYA ÝÞLEMLERÝ
void oyunuDevamEttir() {
    ifstream dosya("oyun.txt");

    if (dosya.is_open()) { //Dosyanýn var olup olmadýðý ve açýlabilir olup olmadýðýný kontrol eder.
        string satir;
        while (getline(dosya, satir)) {
            cout << satir << endl;
        }

        dosya.close();
        cout << "THE GAME WAS CONTINUNED" << endl;
    }
    else {
        cout << "AN ERROR OCCURRED WHILE OPENING THE FILE" << endl;
    }
}

void kaydet(char* tahmin, int tahminSayisi) { 
    ofstream dosya("oyun.txt");

    if (dosya.is_open()) {
        dosya << "GUESS: " << tahmin << endl;
        dosya << "NUMBER OF GUESS: " << tahminSayisi << endl;

        dosya.close();
        cout << "GAME SAVED" << endl;
    }
    else {
        cout << "AN ERROR OCCURRED WHILE OPENING THE FILE" << endl;
    }
}

int main()
{
    srand(time(NULL));
    menu();


    return 0;
}