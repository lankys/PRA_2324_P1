#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
	T* arr; 
		//puntero al inicio del array (forma contigua)son tipo t genricos
	int max;
		//tamaño actual del array
	int n;
		//numero de elementos de la lista
	static const int MINSIZE = 2;
		//tamaño minimo del array debe inicializarse a 2
	void resize(int new_size){}

    public:
	ListArray::ListArray(){
	 arr =new T [MINSIZE];
		n=0;
		max=MINSIZE;	
			};//esto crea el objeto inicalizado a 2 y s
	~ListArray(){
	delete arr;
	}

	T operator[](int pos)
	{
		T s=get(pos);	
       		return s;
         }
friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){





}
T get (int pos) override final{
 if(pos=>size()){
         throw std::out_of_range("fuera del intervalo[0-size()-1]");
         }
        else {
		
                 return *(arr+pos); }
}

void resize(int new_size){

}


int size() override final{
return max;
}
		




		};


	
	
	// miembros públicos, incluidos los heredados de List<T>
    
