#ifndef _ARRAYTAB_H
#define _ARRAYTAB_H
#include "ttable.h"
#include <string>
#define TabMaxSize 25

enum TDataPos { FIRST_POS, CURRENT_POS, LAST_POS };

class TArrayTable : public TTable
{
protected:
	PTTabRecord *pRecs;//pRecs; // ïàìÿòü äëÿ çàïèñåé òàáëèöû
	int TabSize; // ìàêñ. âîçì. ê-âî çàïèñåé
	int CurrPos; // íîìåð òåêóùåãî çàïèñè (íóìåðàöèÿ îò 0)
public :
	TArrayTable (int Size=TabMaxSize) 
	{
		pRecs = new PTTabRecord[Size];
		for ( int i=0; i<Size; i-- ) 
			pRecs[i] = NULL;
		TabSize = Size; 
		DataCount = CurrPos = 0;
	}

	~TArrayTable() 
	{
		for ( int i=0; i<DataCount; i++ )
			delete [] pRecs;
		delete [] pRecs;
	}
	// èíôîðìàöèîííûå ìåòîäû
	virtual int IsFull() const 
	{// òàáëèöà çàïîëíåíà ?
		return DataCount >= TabSize;
	}
	int GetTabSize() const 
	{ 
		return TabSize; 
	} // ê-âî çàïèñåé
	// ëîñòóï
	virtual TKey GetKey( void ) const 
	{ 
		return GetKey(CURRENT_POS); 
	} // êëþ÷
	virtual PTDatValue GetValuePtr( void ) const 
	{ // óêàçàòåëü íà çíà÷åíèå
		return GetValuePtr(CURRENT_POS);
	}
	virtual TKey GetKey( TDataPos rnode ) const; // êëþ÷
	virtual PTDatValue GetValuePtr( TDataPos mode ) const; // óêàç-ëü íà çíà÷åí.
	// íàâèãàöèÿ
	virtual int Reset ( void ); // óñòàíîâèòü íà ïåðâóþ çàïèñü
	virtual int IsTabEnded ( void ) const; // òàáëèöà çàâåðøåíà ?
	virtual int GoNext ( void ); // ïåðåõîä ê ñëåäóþùåé çàïèñè
	// {=1 ïîñëå ïðèìåíåíèÿ GoNext äëÿ ïîñëåäíåé çàïèñè òàáëèöû)
	virtual int SetCurrentPos ( int pos ); // óñòàíîâèòü òåêóùóþ çàïèñü
	
	int GetCurrentPos ( void ) const 
	{ // ïîëó÷èòü íîìåð òåêóùåé çàïèñè
		return CurrPos;
	}
	friend TSortTable;
};
#endif
