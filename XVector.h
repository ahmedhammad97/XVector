#ifndef XVECTOR_H
#define XVECTOR_H
#include <vector>
using namespace std;

template <class T>
class XVector{

    private:
        const int b = 1000;
        vector<T*> arr;
        int currentIndex;
        int maxSize;


    protected:
        void expand(){
            T* temp = new T[b];
            arr.push_back(temp);
            maxSize+=(b);

        }

        void shrink(){
            delete[] arr[arr.size()-1];
            arr[arr.size()-1] = NULL;
            arr.pop_back();
            maxSize-=(b);
        }

        pair<int, int> position(int index){
            pair<int, int> pos;
            float result = ((float)index / b);
            pos.first = result; //Row #
            pos.second = index%b; // changed line
            return pos;
        }



        public:

        XVector(){
            currentIndex=0;
            maxSize=b;
            arr.reserve(120);
            arr.push_back(new T[b]);
        }
        ~XVector(){
            for(int i=0;i<arr.size();i++){
                delete[] arr[i];
            }
        }


        void push_back(T value){
            if(currentIndex>=maxSize-1){expand();}
            pair<int,int> indeces = position(currentIndex);
            arr[indeces.first][indeces.second]=value;
            currentIndex++;
        }

        void pop_back(){
            currentIndex--;
            if(maxSize>=currentIndex+(2*b)){shrink();}
        }

        T getValue(int index){
            pair<int,int> indeces = position(index);
            return arr[indeces.first][indeces.second];
        }

        void setValue(int index,T value){
            pair<int,int> indeces = position(index);
            arr[indeces.first][indeces.second] = value;
        }

        int capacity(){
            return maxSize;
        }

        int size(){
            return currentIndex;
        }

        bool empty(){
            return currentIndex==0?true:false;
        }

};
#endif // XVECTOR_H
