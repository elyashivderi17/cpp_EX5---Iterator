#include<cmath>
#include<vector>

using namespace std;

namespace itertools{

  template<typename CON>
  class powerset{

    CON A1;

 public:

    powerset(CON temp) : A1(temp){}

        auto begin() const{return iterator<decltype(A1.begin())>(A1.begin(), A1.end());}
        auto end() const{return iterator<decltype(A1.begin())>(A1.end(), A1.end());}


    template<typename T>
    class iterator{

public :

      T start;
      T end;
      int index;
      int size;
      vector<vector<T>> vec;

      iterator(T start_iter,T end_iter) : start(start_iter),end(end_iter),size(calcPow(start_iter,end_iter)),index(0){}

      auto operator*(){
        vector<T> vecFun = checkSize(start,end);
        vec = getAllSubsets(vecFun);
        vector<typename remove_const<typename remove_reference<decltype(*start)>::type>::type> vector;
        for(auto i : vec[index]){
        vector.push_back(*i);
        }
        return vector;
      }

      bool operator!= (const iterator & temp){
        return (index != size);
      }

      auto operator++() {
        ++index;
        return *this;
      }

private :

      vector<T> checkSize(const T start,const T end){
        vector<T> vec;
        T runner = start;
        while(runner != end){
          vec.push_back(runner);
          ++runner;
        }
        return vec;
      }

      vector<vector<T>>  getAllSubsets(const vector<T> & set){
        vector<vector<T>> subset;
          vector<T> empty;
          subset.push_back( empty );
          for (int i = 0; i < set.size(); i++){
              vector<vector<T>> subsetTemp = subset;
              for (int j = 0; j < subsetTemp.size(); j++)
                  subsetTemp[j].push_back( set[i] );
              for (int j = 0; j < subsetTemp.size(); j++)
                  subset.push_back( subsetTemp[j] );
          }
          return subset;
      }

      int calcPow(const T start,const T end){
        T runner = start;
        int base = 0;
        while(runner != end){
                ++runner;
                base = base+1;   
        }
        return pow(2,base);
      }
    };
  };

template <typename T>
  ostream & operator << (ostream & output, const vector<T> & vec){
    output << "{";
    auto iter = vec.begin();
    if(iter != vec.end()) {
        output << *iter;
        ++iter;}
    while (iter != vec.end()){
        output << ',' << *iter;
        ++iter;}
    output << "}";
    return output;
}
};