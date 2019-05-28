#include<vector>
#include<cmath>

using namespace std;

namespace itertools{

  template<typename CON>
  class powerset{

    CON A;

  public:

    powerset(CON temp) : A(temp){}


    template<typename T>
    class iterator{

      private :

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

      vector<T> change(const T i,const T j){
        vector<T> ans;
        T runner = i;
        while(runner != j){
          ans.push_back(runner);
          ++runner;
        }
        return ans;
      }

      size_t length(const T start,const T end){
        T runner = start;
        size_t ans = 0;
        while(runner != end){
          ans++;
          ++runner;
        }
        return pow(2,ans);
      }

      public :

      T start;
      T end;

      uint index;

      size_t size;

      vector<vector<T>> vec;

      iterator(T start_temp,T end_temp) : start(start_temp),end(end_temp),size(length(start_temp,end_temp)),index(0){}

      auto operator*(){
        vector<T> v = change(start,end);
        vec = getAllSubsets(v);
        vector<typename remove_const<typename remove_reference<decltype(*start)>::type>::type> vector;
        for(auto i : vec[index]){
        vector.push_back(*i);
        }
        return vector;
      }

      auto operator++() {
        ++index;
        return *this;
      }

      bool operator!= (const iterator & temp){
        return (index != size);
      }

    };

    auto begin() const{return iterator<decltype(A.begin())>(A.begin(), A.end());}
    auto end() const{return iterator<decltype(A.begin())>(A.end(), A.end());}

  };

    template <typename T>
  ostream & operator << (ostream & output, const vector<T> & input){
    output << "{";
    auto it = input.begin();
    if(it != input.end()) {
        output << *it;
        ++it;}
    while (it != input.end()){
        output << ',' << *it;
        ++it;}
    output << "}";
    return output;
}
};