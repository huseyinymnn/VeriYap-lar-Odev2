/** 
* @file IkiliAramaAgaci.hpp
* @description IkiliAramaAgaci sınıfına ait fonksiyonlar ve degiskenler vardır.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP

#include "AgacDugum.hpp"
#include "Yigin.hpp"
#include <iostream>
#include <iomanip>

class IkiliAramaAgaci {
public:
    IkiliAramaAgaci();
    ~IkiliAramaAgaci();
    void Ekle(int veri);
	void YigindanAgacaEkle(Yigin* yigin, IkiliAramaAgaci* agac);
    int Yukseklik();
    int ToplamDugumVerisi();
	void postorder();
private:
	void PostOrderYazdir(AgacDugum* dugum);
    int ToplamDugumVerisi(AgacDugum* dugum);
    void AraveEkle(AgacDugum *&altDugum,int yeni);
    void Temizle(AgacDugum* aktifDugum);
    void Temizle();
    int Yukseklik(AgacDugum* dugum);
    AgacDugum* kok;
    
};

#endif