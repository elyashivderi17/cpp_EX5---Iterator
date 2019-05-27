#include <iostream>
#include <utility>
using namespace std;

namespace itertools {

    template <typename P1> ostream &operator<<(ostream& Ostr, P1 &pa) {
        Ostr << '{' << pa.first << '}' ;
        return Ostr;
    }

    template <typename P1, typename P2> ostream &operator<<(ostream& Ostr, pair<P1,P2> &pa) {
        Ostr << '{' << pa.first << ',' << pa.second << '}';
        return Ostr;
    }

    template <typename P1, typename P2, typename P3> ostream &operator<<(ostream& Ostr, pair<P1,P2,P3> &pa) {
        Ostr << pa.first << ',' << pa.second;
        return Ostr;
    }

    template <typename T1, typename T2> 
    class product {
    
    private: 
        T1 iter_1;
        T2 iter_2;

    public:
        product(T1 start, T2 end) :  iter_1(start), iter_2(end) {}   

    auto begin() const{ 
        return  iterator<decltype(iter_1.begin()),decltype(iter_2.begin())>(iter_1.begin(), iter_2.begin()); }  

    auto end() const{
        return iterator<decltype(iter_1.end()),decltype(iter_2.end())>(iter_1.end(), iter_2.end()); }  
 
    template <typename T3, typename T4>
        class iterator {

        private:
            T3 iter_3; 
            T4 iter_4;
            bool Check; 
            int count = 0;

        public:
            iterator(T3 A, T4 B): iter_3(A) , iter_4(B), Check(true) {}

            iterator<T3,T4>& operator++() {
                if(Check){
                    ++iter_4;
                    count++;
                }else {
                    ++iter_3;
                    Check = true;
                    for(int i=0 ; i<count ; i++){
                        iter_4--;
                    }
                    count=0;
                }
                return *this;
            }

            auto operator*() const {
                return pair<decltype(*iter_3), decltype(*iter_4)> (*iter_3, *iter_4);
            }

            bool operator!=(const iterator& other){
                if(!(iter_4 != other.iter_4-1)) {
                    Check = false;
                }
                return (iter_3 != other.iter_3) && (iter_4 != other.iter_4); 
            }
         
        }; 

    };
    
}
