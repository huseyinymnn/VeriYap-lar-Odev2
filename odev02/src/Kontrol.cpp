/** 
* @file Kontrol.cpp
* @description Kontrol sinifina ait fonksiyon vardir. Bir satirda olusabilecek maksimum yigin sayisini donduren fonksiyonu bu sinirta yazmak istedim.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#include "Kontrol.hpp"
using namespace std;

int Kontrol::MaxYiginSayisi(){ //Dosyayi okuyup bir satirda olusabilecek maksimum yigin sayisini donduren fonksiyon.
		int MaxYiginSayisi=-1;
		ifstream dosya("Sayilar.txt");
		 if (dosya.is_open()) { //dosya okuma
        string satir;
		 while (getline(dosya, satir)) {
			 int siradakiSayi;
			 int yiginSayisi = 0;
			 int okunanElemanSayisi=0;
			 int oncekiSayi=0;
			 stringstream satirOkuyucu(satir); 
			  while (satirOkuyucu >> siradakiSayi) { //her satirdaki sayilari sira ile okuyorum

                if (okunanElemanSayisi > 0 && siradakiSayi % 2 == 0 && siradakiSayi >oncekiSayi) {
                   
                   yiginSayisi++;
                } else {
                        if (yiginSayisi == 0) {
                      
                        yiginSayisi++;
                        } else {
                             
                            }
                    }
                okunanElemanSayisi++;
				oncekiSayi=siradakiSayi;
            }
			if(yiginSayisi>MaxYiginSayisi) MaxYiginSayisi=yiginSayisi;
			 
		 }
		 }
		 return MaxYiginSayisi;
	}