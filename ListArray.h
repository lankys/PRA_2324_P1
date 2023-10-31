#include <ostream>
#include "List.h"
#include <exception>
#include <stdexcept>
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
	void resize(int new_size) {

		T* att = new T[new_size];
		for (int i = 0; i < n; i++) {
			*(att + i) = *(arr + i);
		}
		delete [] arr;
		arr = att;
		max = new_size;

	}


public:

	int size(void) const override {
		return n;
	}


    void insert(int pos, T e) {
	if (pos < 0 || pos > n) {
	throw std::out_of_range("fuera del intervalo de 0 a size()");}

	else{
	for (int i = n; i >= pos + 1; i--) {

	arr[i] = arr[i - 1];}
		arr[pos] = e;
		n++;
		}}

	//constructor
	ListArray() {
		arr = new T[MINSIZE];
		n = 0;
		max = MINSIZE;
	}//esto crea el objeto inicalizado a 2 y s

	//destructor
	~ListArray() {

		delete arr;
	}


	//sobrecargar del operador []
	T operator[](int pos)
	{
		if (pos >= size()) {
			throw std::out_of_range("fuera del intervalot[0-size()-1]");
		}

		return get(pos);

	}


	//el operador<<
	friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
		out << "[";
		for (size_t i = 0; i < list.n; ++i) {
			out << list.arr[i];
			if (i < list.n - 1) {
				out << ", ";
			}
		}
		out << "]";
		return out;
	}


	//get the position
	T get(int pos) override final {
		if ( pos < 0) {
			throw std::out_of_range("fuera del intervalooo[0-size()-1]");
		}
		else {
			return arr[pos];
		}
	}


	
	//buscador
	int search(T e)const override final {

		for (int i = 0; i < max; i++) {
			if (*(arr + i) == e) {
				return i;

			}
		}
		return -1;
	}
	//insert al final de la lista
	void append(T e) override final {
		if (n >= max - 1){
			resize(n * 2);
		}
		insert( n,e);
	}

	//inserta al inicio
	void prepend(T e) override final {
		if (n >= max - 1) {
			resize(n+1);
		}
		insert(0, e);
	}

	//elimina y devuleve el elemnto que se encontraba en esa posicion
	T remove(int pos) override final {
		if ( pos < 0 || pos > n - 1) {
			throw std::out_of_range("fuera del intervalo2 [0, size()-1])");
		}
		else {
			T w;
			w = get(pos);
			for (int i = pos; i < n ; i++) {
				*(arr + i) = arr[i + 1];
			}
			n--;

			return w;

		}
	}


	//mira si la lista esta vacia
	bool empty()const override  {
		if (n == 0) {
			return true;
		}
		return false;
	}


};


/**//**//**/