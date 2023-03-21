#ifndef TTABLE_H
#define TTABLE_H
#include <iostream>
#include "datacom.h"
#include "tracord.h"
#include <string>
#define TabOK 0 // ошибок нет
#define TabEmpty -101 // таблица полна
#define TabFull -102 // таблица пуста
#define TabNoRec -103 // нет записи
#define TabRecDbl -104 // дублирование записи
#define TabNoMem -105 // нет памяти

class TTable : public TDataCom 
{
protected:
	int DataCount; // количество записей в таблице
	int Efficiency; // показатель эффективности выполнения операции
public :
	TTable () 
	{ 
		DataCount=0; 
		Efficiency=0; 
	}
	virtual ~TTable() 
	{};
	// информационные методы
	int GetDataCount() const 
	{ 
		return DataCount;
	}
	int GetEfficiency () const 
	{
		return Efficiency;
	}
	int IsEmpty() const 
	{ 
		return DataCount == 0;
	}
	virtual int IsFull() const = 0;
	//основные методы R С^лл
	virtual PTDatValue FindRecord ( TKey k ) = 0;
	virtual void InsRecord ( TKey k, PTDatValue pVal )=0; // вставить
	virtual void DelRecord( TKey k ) = 0; // удалить запись
	// навигация
	virtual int Reset ( void ) =0; // установить на первую запись
	virtual int IsTabEnded ( void ) const=0; // таблица завершена ?
	virtual int GoNext ( void ) =0; // переход к следующей записи
	// (=1 после применения GoNext для последней записи таблицы)
	// доступ
	virtual TKey GetKey( void ) const=0;
	virtual PTDatValue GetValuePtr( void ) const=0;
	// Печать таблицы

	friend std::ostream& operator<<(std::ostream &os, TTable &tab ) 
	{
		std::cout << "Печать таблицы" << std::endl;
		//cout  "Table printing"  endl;
		for ( tab.Reset() ; !tab.IsTabEnded() ; tab.GoNext () ) 
		{
			os << " Key: " << tab.GetKey ()
				<< " Val: " << *tab.GetValuePtr(); 
			os << std::endl;
		}
		return os;
	}
};
#endif