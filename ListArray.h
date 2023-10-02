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
	T* arr =new T a[MINSIZE];
		n=MINSIZE;
		max=n;	
	}
	

	
	
	// miembros públicos, incluidos los heredados de List<T>
    
};
