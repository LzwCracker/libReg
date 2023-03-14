#pragma once
#include "RegKeyEx.h"

class CRegKeyImpl
{
public:
	CRegKeyImpl();
	~CRegKeyImpl();
	BOOL OpenKey(RootKeyType rk, LPTSTR subkey);
	BOOL CreateKey(RootKeyType rk, LPTSTR subkey);
	BOOL ReadValue(LPTSTR valueName, LPDWORD lpdwType, PBYTE lpData, LPDWORD lpSize);
	BOOL WriteValue(LPTSTR valueName, DWORD dwType, PBYTE lpData, UINT nSize);
	BOOL DeleteKey(RootKeyType rk, LPTSTR subkey);
	BOOL DeleteValue(LPTSTR value);
private:
	HKEY m_hKey;
	HKEY hRoot;
	long LOpenStatus;
	BOOL CloseKey(HKEY hk);
protected:
};

