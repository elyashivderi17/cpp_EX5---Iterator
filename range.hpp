
namespace itertools {
template <typename T>

class range {

private:
    T Start;
    T End;   

    class iterator {

    public:
        T Temp;
        iterator(T v) : Temp(v){}    
        bool operator!=(iterator const &other) const { 
            return Temp != (other.Temp);
        }

        iterator &operator++() {
            ++Temp;
            return *this;
        }

        auto &operator--() {
            --Temp;
            return *this;
        }
        
        auto operator*() const {
            return Temp;
        }


    };

    public:
       range(T from, T to) : Start(from), End(to) {}                      
       iterator begin() const {
         return iterator(Start);
          }  
        iterator end() const { 
         return iterator(End); 
        }      
  }; 
} 
