#include "stdafx.h"
#include "RegKeyEx.h"
#include "RegKeyImpl.h"
#include <memory>
using namespace std;

 

CRegKeyEx::CRegKeyEx()
{
	m_spRegKeyImpl.reset(new CRegKeyImpl());
}

CRegKeyEx::CRegKeyEx(RootKeyType rk, LPTSTR subkey)
{
m_spRegKeyImpl->OpenKey(rk, subkey);
}

BOOL CRegKeyEx::OpenKey(RootKeyType rk, LPTSTR subkey)
{

return	m_spRegKeyImpl->OpenKey(rk, subkey);
}

BOOL CRegKeyEx::CreateKey(RootKeyType rk, LPTSTR subkey)
{
	return	m_spRegKeyImpl->CreateKey(rk, subkey);
}

BOOL CRegKeyEx::ReadValue(LPTSTR valueName, LPDWORD lpdwType, PBYTE lpData, LPDWORD lpSize)
{

	return	m_spRegKeyImpl->ReadValue(valueName, lpdwType,lpData,lpSize);
}

BOOL CRegKeyEx::WriteValue(LPTSTR valueName, DWORD dwType, PBYTE lpData,UINT nSize)
{
	return	m_spRegKeyImpl->WriteValue(valueName, dwType, lpData, nSize);
}

BOOL CRegKeyEx::DeleteKey(RootKeyType rk,LPTSTR subkey)
{
	return	m_spRegKeyImpl->DeleteKey(rk, subkey);
}

BOOL CRegKeyEx::DeleteValue(LPTSTR value)
{
	return	m_spRegKeyImpl->DeleteValue(value);
}

CRegKeyEx::~CRegKeyEx()
{
 
}
