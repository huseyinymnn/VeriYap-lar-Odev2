/** 
* @file Yigin.hpp
* @description Yigin sınıfına ait fonksiyonlar ve degiskenler vardır.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#ifndef YIGIN_HPP
#define YIGIN_HPP

#include "Dugum.hpp"
#include<iostream>
#include<iomanip>

class Yigin {
public:
    Yigin();
    ~Yigin();
    void ekle(int veri);
    int getir();
    void cikar();
    bool bosmu();
    int yiginElemanSayisi();
   
private:
    Dugum* tepe;
    int elemanSayisi;
};

#endif