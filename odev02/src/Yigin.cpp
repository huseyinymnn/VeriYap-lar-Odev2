/** 
* @file Yigin.cpp
* @description Yigin sınıfına ait fonksiyonlar ve degiskenler vardır.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#include "Yigin.hpp"

using namespace std;

Yigin::Yigin(){
	    elemanSayisi = 0;
        tepe = nullptr;
	}
Yigin::~Yigin(){
        Dugum* aktif = tepe;
        while (aktif != nullptr) {
            Dugum* sonraki = aktif->sonraki;
            delete aktif;
            aktif = sonraki;
        }
        tepe = nullptr;
    }
void Yigin::ekle(int veri) {
        Dugum* yeni = new Dugum(veri);
        if (tepe != nullptr)
            yeni->sonraki = tepe;
        tepe = yeni;
        elemanSayisi++;
    }
int Yigin::getir(){
        if (elemanSayisi == 0)
            return -1;
        return tepe->veri;
    }
void Yigin::cikar(){
        if (elemanSayisi > 0) {
            Dugum* eskiTepe = tepe;
            tepe = tepe->sonraki;
            delete eskiTepe;
            elemanSayisi--;

        }
    }
bool Yigin::bosmu(){
	 return elemanSayisi==0;
}
int Yigin::yiginElemanSayisi(){
	return elemanSayisi;
}