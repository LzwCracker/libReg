#pragma once
#include <memory>
using namespace std;
enum  RootKeyType
{
	HKCR,
	HKCU,
	HKLM,
	HKU,
	HKCC
};
class CRegKeyImpl;

class CRegKeyEx
{
private:
	unique_ptr<CRegKeyImpl> m_spRegKeyImpl;
public:
	CRegKeyEx();
	~CRegKeyEx();
	CRegKeyEx(RootKeyType rk,LPTSTR subkey);
	BOOL OpenKey(RootKeyType rk, LPTSTR subkey);
	BOOL CreateKey(RootKeyType rk, LPTSTR subkey);
	BOOL ReadValue(LPTSTR valueName, LPDWORD lpdwType, PBYTE lpData, LPDWORD lpSize);
	BOOL WriteValue(LPTSTR valueName, DWORD dwType, PBYTE lpData, UINT nSize);
	BOOL DeleteKey(RootKeyType rk,LPTSTR subkey);
	BOOL DeleteValue(LPTSTR value);
	protected:
};

