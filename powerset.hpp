#include "iostream"

namespace itertools {
    
    template <typename T1> 
    class powerset {
    
    private: 
        T1 iter_1;

    public:
        powerset(T1 start) :  iter_1(start) {}   

    auto begin(){ 
        return  iterator<decltype(iter_1.begin())>(iter_1.begin(); }  

    auto end() {
        return iterator<decltype(iter_1.end())>(iter_1.end(); }  
 
    template <typename T3, typename T4>
        class iterator {

        private:
            T3 iter_3; 
         bool Check;

        public:
            iterator(T3 A, T4 B): iter_3(A) , Check(true)  {}

           iterator<T3>& operator++() {
                if(Check){
                    ++iter_3;
                return *this;
            }

            decltype(*iter_3) operator*() const {

                if(Check){
                    return *iter_3;
            }
            return *iter_3;

            bool operator!=(iterator<T3>Temp){
                if(Check && !(iter_3 != Temp.iter_3)){
                    Check = false;
                }
                    return iter_3 != Temp.iter_3;

            
         
        }; 

    };
}
    
