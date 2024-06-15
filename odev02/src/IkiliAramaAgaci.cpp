/** 
* @file IkiliAramaAgaci.cpp
* @description IkiliAramaAgaci sınıfına ait fonksiyonlar ve degiskenler vardır.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#include "IkiliAramaAgaci.hpp"
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci(){
        kok = nullptr;
    }
	
IkiliAramaAgaci::~IkiliAramaAgaci() {
        Temizle();
    }

void IkiliAramaAgaci::Ekle(int veri){
            AraveEkle(kok,veri);
        } 
		
void IkiliAramaAgaci::YigindanAgacaEkle(Yigin* yigin, IkiliAramaAgaci* agac){
    Yigin geciciYigin; // Gecici bir yigin olusturdum
	Yigin geciciYigin2; //Gecici yigin elemanlarini tersine cevirerek asil yiginla aynı diziliste olan yigin olusturmak icin bir tane daha gecici yigin olusturdum.
   
   // Yigindaki elemanlari gecici bir yigina tasidim. Cunku ekleme islemini ilk elemandan tepe elemana dogru yapmamiz gerekiyor.
    while (!yigin->bosmu()) {
        geciciYigin.ekle(yigin->getir());
        yigin->cikar();
    }
	while (!geciciYigin.bosmu()) {
        geciciYigin2.ekle(geciciYigin.getir());
        geciciYigin.cikar();
    }
	
   // Elemanlari agaca ekledim.
    while (!geciciYigin2.bosmu()) {
        yigin->ekle(geciciYigin.getir());
        agac->Ekle(geciciYigin2.getir()); 
        geciciYigin2.cikar();
    }
	
    }

int IkiliAramaAgaci::Yukseklik(){
        return Yukseklik(kok);
    }
	
int IkiliAramaAgaci::ToplamDugumVerisi() {
        return ToplamDugumVerisi(kok);

    }
	
void IkiliAramaAgaci::postorder(){
            PostOrderYazdir(kok);
        }
		
void IkiliAramaAgaci::PostOrderYazdir(AgacDugum* dugum) {
		
        if (dugum != nullptr) {
            PostOrderYazdir(dugum->sol);
            PostOrderYazdir(dugum->sag);
            char sayi=static_cast<char>(dugum->veri);
			
			cout<<sayi<<" ";
        }
		
    }
	
int IkiliAramaAgaci::ToplamDugumVerisi(AgacDugum* dugum){
        if (dugum == nullptr) {
            return 0;
        }
        return dugum->veri + ToplamDugumVerisi(dugum->sol) + ToplamDugumVerisi(dugum->sag);
    }
	
void IkiliAramaAgaci::AraveEkle(AgacDugum *&altDugum,int yeni){//bos yeri arayarak ekliyor, ana ekleme islemini yapan yer
            if(altDugum==NULL)//gonderilen alt dugumun oldugu yer bos ise oraya yeni bir dugum olusturuluyor
                altDugum=new AgacDugum(yeni);
            else if(yeni < altDugum->veri)//yeni veri kucukse soldan ilerliyor
                AraveEkle(altDugum->sol, yeni);
            else if(yeni > altDugum->veri)//yeni veri buyukse sagdan ilerliyor
                AraveEkle(altDugum->sag, yeni);
            else return;//veri esitse eklenmiyor
        }
		
void IkiliAramaAgaci::Temizle(AgacDugum* aktifDugum) {
        if (aktifDugum == nullptr) {
            return;
        }
        Temizle(aktifDugum->sol);
        Temizle(aktifDugum->sag);
        delete aktifDugum;
    }
	
void IkiliAramaAgaci::Temizle(){
        Temizle(kok);
        kok = nullptr;
    }
	
int IkiliAramaAgaci::Yukseklik(AgacDugum* dugum) {
        if (dugum)
        {
            return 1 + max(Yukseklik(dugum->sol), Yukseklik(dugum->sag));
        }
        return -1;
    }