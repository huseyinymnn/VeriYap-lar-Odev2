/** 
* @file AgacDugum.hpp
* @description AgacDugum sınıfına ait fonksiyonlar ve degiskenler vardır. Ikili Arama Agaci olustururken bu sınıfın dugumlerini kullandim.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#ifndef AGACDUGUM_HPP
#define AGACDUGUM_HPP

#include<iostream>


class AgacDugum {
public:
    AgacDugum(int veri);
    int veri;
    AgacDugum* sol;
    AgacDugum* sag;
};

#endif