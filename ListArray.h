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
	void resize(int new_size){
		T* att;
		T* aux;
		att=new T [new_size];
		for(int i=0; i>n ; i++){
			*(att + i) = *(arr+i);
		}
		aux = arr;
		arr = att;
		delete att;
		delete aux;
		max=new_size;

	}

    public:

	int size() override final{
		return max;
	}

	//constructor
	ListArray(){
	 arr =new T [MINSIZE];
		n=0;
		max=MINSIZE;	
			};//esto crea el objeto inicalizado a 2 y s
	
	//destructor
	~ListArray(){
		
		delete arr;
	}


	//sobrecargar del operador []
	T operator[](int pos)
	{
		T s=get(pos);	
       			return s;
         }

	
	//el operador<<
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			for( ListArray p:list){
		out<<p<<std::endl;
       			return out;
			}
			}
	
	//get the position
	T get (int pos) override final{
 		if(pos >= size()){
         		throw std::out_of_range("fuera del intervalo[0-size()-1]");
        				 }
        	else {
			return *(arr+pos);}		
					}


	//para insertar un leemnto a la cola
	void insert(int pos, T e)override final { 
	 if (pos >= size()) {
                    throw std::out_of_range("fuera del intervalo[0-size()-1]");
   		         }

	if(n==max){
           resize(n*2);
		*(arr+pos) = e;
		n++; 
			}
	else{
			*(arr + pos) = e;
			n++;
					}
			}	


	//buscador
	int search(T e)override final {

		for(int i=0; i<max;i++ )
			if(*(arr) == e){
				return i;
	
					};	
				}


	//insert al final de la lista
	void append(T e)override final{
		if(n==max){
		resize(n*2);
		*(arr+n)=e;
                       n++;
		}
		else{
			if( *(arr+(max-1))!=0){
			throw std::out_of_range("perdon esa posicion esta ocupada ");
			}	
			else{*(arr+n)=e;
			n++;
			}
				}}

	//inserta al inicio
	void prepend(T e)override final{
 		if(n==max){
           	 resize((n*2)-1);
		     *(arr)=e;
		}
         	else{
               		if( *(arr)!= 0 ){
               			throw std::out_of_range("perdon esa posicion esta ocupada ");
			}
               		else{
	       			*(arr)=e;
				n++;
	       		}
		}}

	       //elimina y devuleve el elemnto que se encontraba en esa posicion
	T remove(int pos)override final{

	 	if(pos >= max){
		 	throw std::out_of_range("fuera del intervalo [0, size()-1])");
			 }
		else{
			T w;
			w=get(pos);
			n-1;
			delete(arr+pos);
		       return w;

	      				 }
	      		 }
		 
		
	//mira si la lisya esta vacia
	bool empty()override final{
		for(int i;i>=max;){
			if(*(arr+i)==0){
				i++;		
			}
		else{
			return false;
		
			}
			}
		return true;
				}
	
	
	};

