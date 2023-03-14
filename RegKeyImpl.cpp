#include "stdafx.h"
#include "RegKeyImpl.h"

CRegKeyImpl::CRegKeyImpl()
{
	m_hKey = NULL;
	hRoot = NULL;
	LOpenStatus = 0;
}

CRegKeyImpl::~CRegKeyImpl()
{
	CloseKey(m_hKey);
}

BOOL CRegKeyImpl::OpenKey(RootKeyType rk, LPTSTR subkey)
{
	switch (rk)
	{
	case HKCR:
		hRoot = HKEY_CLASSES_ROOT;
		break;
	case HKCU:
		hRoot = HKEY_CURRENT_USER;
		break;
	case HKLM:
		hRoot = HKEY_LOCAL_MACHINE;
		break;
	case HKU:
		hRoot = HKEY_USERS;
		break;
	default:
		hRoot = HKEY_CURRENT_CONFIG;
		break;
	}
	long LOpenStatus = RegOpenKeyEx(hRoot, subkey, NULL, KEY_ALL_ACCESS | KEY_WRITE | KEY_EXECUTE | KEY_READ | KEY_WOW64_64KEY | KEY_SET_VALUE, &m_hKey);
	return LOpenStatus == ERROR_SUCCESS;
}

BOOL CRegKeyImpl::CreateKey(RootKeyType rk, LPTSTR subkey)
{
	CloseKey(m_hKey);
	switch (rk)
	{
	case HKCR:
		hRoot = HKEY_CLASSES_ROOT;
		break;
	case HKCU:
		hRoot = HKEY_CURRENT_USER;
		break;
	case HKLM:
		hRoot = HKEY_LOCAL_MACHINE;
		break;
	case HKU:
		hRoot = HKEY_USERS;
		break;
	default:
		hRoot = HKEY_CURRENT_CONFIG;
		break;
	}
	LOpenStatus = RegCreateKeyEx(hRoot, subkey, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS | KEY_WRITE | KEY_EXECUTE | KEY_READ | KEY_SET_VALUE, NULL, &m_hKey, NULL);
	return LOpenStatus == ERROR_SUCCESS;
}

BOOL CRegKeyImpl::ReadValue(LPTSTR valueName, LPDWORD lpdwType, PBYTE lpData, LPDWORD lpSize)
{
	if (!m_hKey)
	{
		return FALSE;
	}
	return RegQueryValueEx(m_hKey, valueName, NULL, lpdwType, lpData, lpSize) == ERROR_SUCCESS;
}

BOOL CRegKeyImpl::WriteValue(LPTSTR valueName, DWORD dwType, PBYTE lpData, UINT nSize)
{
	if (!m_hKey)
	{
		return FALSE;
	}
	return RegSetValueEx(m_hKey, valueName, 0, dwType, lpData, nSize) == ERROR_SUCCESS;
}

BOOL CRegKeyImpl::DeleteKey(RootKeyType rk, LPTSTR subkey)
{
	switch (rk)
	{
	case HKCR:
		hRoot = HKEY_CLASSES_ROOT;
		break;
	case HKCU:
		hRoot = HKEY_CURRENT_USER;
		break;
	case HKLM:
		hRoot = HKEY_LOCAL_MACHINE;
		break;
	case HKU:
		hRoot = HKEY_USERS;
		break;
	default:
		hRoot = HKEY_CURRENT_CONFIG;
		break;
	}
	return	RegDeleteKey(hRoot, subkey) == ERROR_SUCCESS;
}

BOOL CRegKeyImpl::DeleteValue(LPTSTR value)
{
	if (!m_hKey)
	{
		return FALSE;
	}
	return RegDeleteValue(m_hKey, value) == ERROR_SUCCESS;
}

BOOL CRegKeyImpl::CloseKey(HKEY hk)
{
	if (m_hKey)
	{
		return	RegCloseKey(m_hKey) == ERROR_SUCCESS;
	}
	return FALSE;
}
