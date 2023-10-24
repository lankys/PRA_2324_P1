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
		T* att;
		T* aux;
		att = new T[new_size];
		for (int i = 0; i < n; i++) {
			*(att + i) = *(arr + i);
		}
		aux = arr;
		arr = att;
		delete att;
		delete aux;
		max = new_size;

	}


public:

	int size(void) const override {
		return n;
	}

	//constructor
	ListArray() {
		arr = new T[MINSIZE];
		n = 0;
		max = MINSIZE;
	};//esto crea el objeto inicalizado a 2 y s

	//destructor
	~ListArray() {

		delete[] arr;
	}


	//sobrecargar del operador []
	T operator[](int pos)
	{
		if (pos >= size()) {
			throw std::out_of_range("fuera del intervalo[0-size()-1]");
		}

		return get(pos);

	}


	//el operador<<
	friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
		out << "[";
		for (size_t i = 0; i < list.max; ++i) {
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
		if (pos >= size()) {
			throw std::out_of_range("fuera del intervalo[0-size()-1]");
		}
		else {
			return *(arr + pos);
		}
	}


	//para insertar un elemnto a la cola  
	//configurar
	void insert(int pos, T e)  override final {
		if (pos >= size()) {
			throw std::out_of_range("fuera del intervalo[0-size()-1]");
		}

		if (n == max) {
			resize(n * 2);
			*(arr + pos) = e;
			n + 1;
		}
		else {
			for (int i = 0; i < (n - 1 - pos); i++) {
				*(arr + n - i - 1) = *(arr + n - i);
			}
			*(arr + pos) = e;
			n++;
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
		if (n == max) {
			resize(n * 2);
			*(arr + n) = e;
			n++;
		}
		else {
			*(arr + n) = e;
			n++;
		}
	}

	//inserta al inicio
	void prepend(T e) override final {
		if (n == max) {
			resize((n * 2) - 1);
			for (int i = 1; i < n; i++) {
				*(arr + n) = *(arr + n - i);
			}
			*(arr) = e;
			n++;
		}
		if (n == 0) {
			*(arr) = e;
			n++;
		}
		else {
			for (int i = 1; i < n; i++) {
				*(arr + n) = arr[n - i];
			}
			*(arr) = e;
			n++;

		}
	}

	//elimina y devuleve el elemnto que se encontraba en esa posicion
	T remove(int pos) override final {

		if (pos >= max) {
			throw std::out_of_range("fuera del intervalo [0, size()-1])");
		}
		else {
			T w;
			w = get(pos);
			n - 1;
			delete(arr + pos);
			for (int i = pos; i < n - 1 - pos; i++) {
				*(arr + i) = arr[i + 1];
			}
			return w;

		}
	}


	//mira si la lista esta vacia
	bool empty()const override {
		if (n == 0) {
			return true;
		}
		return false;
	}


};
