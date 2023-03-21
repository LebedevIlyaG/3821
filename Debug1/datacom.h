#ifndef DATACOM_H
#define DATACOM_H

#define DataOK 0
#define DataErr -1
#include <string>
class TDataCom 
{
protected:
	int RetCode; // Êîä çàâåðøåíèÿ

public :
	TDataCom () : RetCode(DataOK) {};
	virtual ~TDataCom() {};
	int GetRetCode() 
	{
		int temp = RetCode; 
		RetCode = DataOK; 
		return temp;
	}

	int SetRetCode(int ret)
	{
		return RetCode = DataErr; 
	};
};

#endif
