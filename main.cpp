
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <chrono>
#include <iterator>
#include <algorithm>
using namespace std;
struct housing_estate {
    int numberHouse;
    int numberApartment;
    int number_of_rooms;
    float square;
    string name;
    int number_of_residents;
    housing_estate() {};
    housing_estate(int numberHouse,int numberApartment,float square,string name){
        this->numberHouse=numberHouse;
        this->numberApartment=numberApartment;
        this->square=square;
        this->name=name;
    }
    bool operator > ( housing_estate& h2)
    {
        if(this->square == h2.square){
                     if (this->numberHouse == h2.numberHouse) {
                                   if (this->numberApartment==h2.numberApartment) {
                                                     if (this->name==h2.name) {
                                                                         return true;
                                                     }
                                                     else {
                                                           int ans = this->name.compare(h2.name);
                                                                       return ans > 0;
                                                     }
                                   }
                                   else{
                                          return this->numberApartment>h2.numberApartment;
                                      }
                     }
                     else{
                        return this->numberHouse > h2.numberHouse;
                     }
        }
        else{
            return this->square > h2.square;
        }
    };

    bool operator >= ( housing_estate& h2)
    {
        if(this->square == h2.square){
                     if (this->numberHouse == h2.numberHouse) {
                                   if (this->numberApartment==h2.numberApartment) {
                                                     if (this->name==h2.name) {
                                                                         return true;
                                                     }
                                                     else {
                                                           int ans = this->name.compare(h2.name);
                                                                       return ans >= 0;
                                                     }
                                   }
                                   else{
                                          return this->numberApartment >= h2.numberApartment;
                                      }
                     }
                     else{
                        return this->numberHouse >= h2.numberHouse;
                     }
        }
        else{
            return this->square >= h2.square;
        }
    };

    bool operator < ( housing_estate& h2)
    {
        if(this->square == h2.square){
                     if (this->numberHouse == h2.numberHouse) {
                                   if (this->numberApartment==h2.numberApartment) {
                                                     if (this->name==h2.name) {
                                                                         return true;
                                                     }
                                                     else {
                                                           int ans = this->name.compare(h2.name);
                                                                       return ans < 0;
                                                     }
                                   }
                                   else{
                                          return this->numberApartment < h2.numberApartment;
                                      }
                     }
                     else{
                        return this->numberHouse < h2.numberHouse;
                     }
        }
        else{
            return this->square < h2.square;
        }
    };
    bool operator <= ( housing_estate& h2)
    {
        if(this->square == h2.square){
                     if (this->numberHouse == h2.numberHouse) {
                                   if (this->numberApartment==h2.numberApartment) {
                                                     if (this->name==h2.name) {
                                                                         return true;
                                                     }
                                                     else {
                                                           int ans = this->name.compare(h2.name);
                                                                       return ans <= 0;
                                                     }
                                   }
                                   else{
                                          return this->numberApartment <= h2.numberApartment;
                                      }
                     }
                     else{
                        return this->numberHouse <= h2.numberHouse;
                     }
        }
        else{
            return this->square <= h2.square;
        }
    };

};
std::ostream& operator << (std::ostream &os, const housing_estate &h)
{
    return os << h.numberHouse << "," << h.numberApartment << "," << h.number_of_rooms << "," << h.square << "," << h.name << "," << h.number_of_residents ;
};



template<class T> void bubbleSort(vector<T>& arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
template<class T> void insertSort(vector<T>& a, long size)
{
T x;
long i, j;
for (i = 0; i < size; i++)
{
x = a[i];
for (j = i - 1; j >= 0 && a[j] > x; j--)
{
a[j + 1] = a[j];
}
a[j + 1] = x;
}
}
template<class T> int partition(vector<T>& nums, int low, int high)
{
int i = low - 1;

T pivot = nums[high];
for (int j = low; j < high; j++)
{
if (nums[j] <= pivot)
{
i++;
swap(nums[i], nums[j]);
}
}
swap(nums[i + 1], nums[high]);
return i + 1;
}

template<class T> void quickSort(vector<T>& nums, int low, int high)
{
if (low < high)
{
int pivot = partition(nums, low, high);
quickSort(nums, low, pivot - 1);
quickSort(nums, pivot + 1, high);
}

}

void File(string file, int sort){
    string path = "C:/Users/Ivan/"+file;
    ifstream f(path);
    string l;
    string fi;
    vector<housing_estate> dannie;
    while ( getline(f,l) )    // get next line in file
    {
        stringstream ss(l);
        int i = 0;
        string name1;
        int numberHouse,number_of_rooms,number_of_residents;
        float square;
        int numberApartment;
        while (getline(ss,fi,','))
        {
            if(i==0){
             name1 = fi;
            }
            if(i==1){
                square = stof(fi);
            }
            if(i==2){
                numberHouse = stoi(fi);
            }
            if(i==3){
                numberApartment = stoi(fi);
            }

            ++i;
         }
         housing_estate house(numberHouse,numberApartment,square,name1);
        dannie.push_back(house);
    }
    auto begin = std::chrono::steady_clock::now();
    if(sort==1) {
        bubbleSort(dannie,dannie.size());
    }

    if (sort==2) {
        insertSort(dannie,dannie.size());
    }
    if (sort==3) {
        quickSort(dannie,0,dannie.size()-1);
    }
    auto end = chrono::steady_clock::now();
    auto elapsed_ms = chrono::duration_cast<chrono::milliseconds>(end - begin);
    cout << "F: " << file << " Alg: " << sort << " time in ms: " << elapsed_ms.count()<<std::endl;
}

int main(){
File("200.txt",1);
File("1000.txt",1);
File("2000.txt",1);
File("10000.txt",1);
File("20000.txt",1);
File("100000.txt",1);
File("150000.txt",1);

cout<<"  "<<endl;

File("200.txt",2);
File("1000.txt",2);
File("2000.txt",2);
File("10000.txt",2);
File("20000.txt",2);
File("100000.txt",2);
File("150000.txt",2);
cout<<"  "<<endl;

File("200.txt",3);
File("1000.txt",3);
File("2000.txt",3);
File("10000.txt",3);
File("20000.txt",3);
File("100000.txt",3);
File("150000.txt",3);
cout<<"  "<<endl;
}
