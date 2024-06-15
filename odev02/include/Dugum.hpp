/** 
* @file Dugum.hpp
* @description Dugum sınıfına ait fonksiyonlar ve degiskenler vardır. Yigin olustururken bu sınıfın dugumlerini kullandim.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#ifndef DUGUM_HPP
#define DUGUM_HPP

#include<iostream>

class Dugum {
public:
    Dugum(int veri);
    int veri;
    Dugum* sonraki;
};
#endif