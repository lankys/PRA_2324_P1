#ifndef LIST_H
#define LIST_H

template <typename T> 
class List {
    public:
      
	virtual void insert(int pos, T e);
	virtual void append(T e);
	virtual void prepend(T e);
	virtual T remove(int pos);  
	virtual T get(int pos);
	virtual int search(T e); 
	virtual bool empty();  
	virtual int size();  
	 //consulatr si es necesario el const=0;
	 //este archivo fue relaizado el 27 de septiembre.
};

#endif