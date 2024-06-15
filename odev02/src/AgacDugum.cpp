/** 
* @file AgacDugum.hpp
* @description AgacDugum sınıfına ait fonksiyonlar ve degiskenler vardır. Ikili Arama Agaci olustururken bu sınıfın dugumlerini kullandim.
* @course 1.Ogretim B gubu
* @assignment 2.Ödev
* @date 09.08.2023
* @author Huseyin Yaman , Mehmet Efe Goktepe, huseyin.yaman2@ogr.sakarya.edu.tr , efe.goktepe@ogr.sakarya.edu.tr
*/

#include "AgacDugum.hpp"

using namespace std;

 AgacDugum::AgacDugum(int veri){
	    this->veri = veri;
        sol = nullptr;
        sag = nullptr;
 }