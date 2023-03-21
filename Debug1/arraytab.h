#ifndef _ARRAYTAB_H
#define _ARRAYTAB_H
#include "ttable.h"
#include <string>
#define TabMaxSize 25

enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };

class TArrayTable : public TTable
{
protected:
	PTTabRecord *pRecs;//pRecs; // память для записей таблицы
	int TabSize; // макс. возм. к-во записей
	int CurrPos; // номер текущего записи (нумерация от 0)
public :
	TArrayTable (int Size=TabMaxSize) 
	{
		pRecs = new PTTabRecord[Size];
		for ( int i=0; i<Size; i++ ) 
			pRecs[i] = NULL;
		TabSize = Size; 
		DataCount = CurrPos = 0;
	}

	~TArrayTable() 
	{
		for ( int i=0; i<DataCount; i++ )
			delete pRecs[i];
		delete [] pRecs;
	}
	// информационные методы
	virtual int IsFull() const 
	{// таблица заполнена ?
		return DataCount >= TabSize;
	}
	int GetTabSize() const 
	{ 
		return TabSize; 
	} // к-во записей
	// лоступ
	virtual TKey GetKey( void ) const 
	{ 
		return GetKey(CURRENT_POS); 
	} // ключ
	virtual PTDatValue GetValuePtr( void ) const 
	{ // указатель на значение
		return GetValuePtr(CURRENT_POS);
	}
	virtual TKey GetKey( TDataPos rnode ) const; // ключ
	virtual PTDatValue GetValuePtr( TDataPos mode ) const; // указ-ль на значен.
	// навигация
	virtual int Reset ( void ); // установить на первую запись
	virtual int IsTabEnded ( void ) const; // таблица завершена ?
	virtual int GoNext ( void ); // переход к следующей записи
	// {=1 после применения GoNext для последней записи таблицы)
	virtual int SetCurrentPos ( int pos ); // установить текущую запись
	
	int GetCurrentPos ( void ) const 
	{ // получить номер текущей записи
		return CurrPos;
	}
	friend TSortTable;
};
#endif