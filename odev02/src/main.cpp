/** 
* @file main.cpp
* @description Main sinifinin oldugu dosya. Dosya okuma - yigin olusturma ve ikili arama agaci olusturup ekran ciktisini ekrana bastirma islemleri yapilmaktadir.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include<exception>
#include<unistd.h> 
#include "Kontrol.hpp"
#include "Yigin.hpp"
#include "IkiliAramaAgaci.hpp"

using namespace std;


int main()
{	Kontrol k; //bir kontrol degiskeni olusturuluyor.
	int maxYiginSayisi=k.MaxYiginSayisi(); //okunacak olan dosyada bir satirda olusabilecek maksimum yigin sayisini tutuyorum
    ifstream dosya("Sayilar.txt"); //dosya aciliyor
    
    if (dosya.is_open()) { //dosya okuma
        string satir;
       
        while (getline(dosya, satir)) //yiginlari olusturmak icin satirlari okuyorum
        {	int siradakiSayi;	//satirdaki okunan sayilari siradakiSayi degiskenine atiyorum
            stringstream satirOkuyucu(satir); //satir okuma nesnesi
            Yigin* *yiginlar=new Yigin*[maxYiginSayisi]; //olusabilecek maksimum yigin sayisinde *yiginlar'i isaret eden isaretci dizisi olusturuyorum.
            int okunanElemanSayisi = 0; //okunan eleman sayisini tutuyorum cunku yigin yokken cift eleman gelince hata vermesini onlemek icin
            int yiginSayisi = 0; //yigin sayisini tutuyorum
           // int tepeEleman=-1;
			int yiginlarElemanSayisi=0; //yiginlar[i]'nin eleman sayisini donduruyor
            while (satirOkuyucu >> siradakiSayi) { //her satirdaki sayilari sira ile okuyorum

                if (okunanElemanSayisi > 0 && siradakiSayi % 2 == 0 && siradakiSayi > yiginlar[yiginSayisi - 1]->getir()) { //eger sayi 2'ye bolunuyor ve islem yapilan yiginin tepe elemanindan buyukse buraya geliyor
                   yiginlar[yiginSayisi]=new Yigin(); // isaret edilen yerde yeni bir yigin olusturuluyor
                   yiginlar[yiginSayisi]->ekle(siradakiSayi); //siradaki sayiyi bu yeni yigina ekliyorum
                   yiginSayisi++; //yigin sayisi bir artiliyor
                } else {
                        if (yiginSayisi == 0) { //hic yigin yoksa ilk yigini olusturup eleman ekleme islemi yapiliyor
                        yiginlar[yiginSayisi]=new Yigin();
                        yiginlar[yiginSayisi]->ekle(siradakiSayi);
                        yiginSayisi++; //yigin sayisi bir artiriliyor
                        } else {
                             yiginlar[yiginSayisi - 1]->ekle(siradakiSayi); //yigin olustugunda ve eklenilen sayi yeni yigin olusturma kuralini karsilamiyorsa burada yigina ekleniyor
                            }
                    }
                okunanElemanSayisi++;
            }
			
			cout<<endl;
			
			IkiliAramaAgaci* *agaclar=new IkiliAramaAgaci*[yiginSayisi]; // yiginSayisi adet IkiliAramaAgaci nesnesi içeren bir pointer do IkiliAramaAgaci* dizisi olusturdum.
			for (int i = 0; i < yiginSayisi; i++) { //yiginlar agaclara dongu icinde ekleniyor
				agaclar[i] = new IkiliAramaAgaci();
			    agaclar[i]->YigindanAgacaEkle(yiginlar[i], agaclar[i]);
			}
			
			int maxYukseklik = -1; //maksimum yuksekligi tutan degisken
			int maxToplam = -1; //maksimum dugum veri toplamini tutan degisken
			int maxAgacIndex = -1; //secilecek agacin indeksini belirtecek olan degisken
			for(int i=0;i<yiginSayisi;i++){ //maksimum yukseklikteki agac bulunuyor. eger maksimum yukseklikte agac varsa agacin dugumleri toplami buyuk olan o da esitse ilk olusturanin indeksini secen donguye giriyor
				int yukseklik = agaclar[i]->Yukseklik();
				int toplamDugum = agaclar[i]->ToplamDugumVerisi();
				if (yukseklik > maxYukseklik || (yukseklik == maxYukseklik && toplamDugum > maxToplam)) {
                maxYukseklik = yukseklik;
                maxToplam = toplamDugum;
                maxAgacIndex = i;
				}	
			}
			
            agaclar[maxAgacIndex]->postorder();   //secilen indeksteki agac postorder okunup ekrana sayisal degerlerin ascii karsiligi yaziliyor.   
			sleep(0.1);
			
            for(int i=0;i<yiginSayisi;i++){ //olusan yiginlari siliyorum
                delete yiginlar[i];
   
            }
			for(int i=0;i<yiginSayisi;i++){ //olusan agaclari siliyorum
                delete agaclar[i];
   
            }
             delete[] yiginlar; //yiginlar isaretci dizilerini de siliyorum
			 delete[] agaclar; // agaclar isaretci dizilerini de siliyorum
        }


    }

    return 0;
}