#include <windows.h>
#include <stdio.h>
#include "hexdump.h"
#include "log.h"

/* make sure we use proper attributes */
#undef SI_USB_XP_EXPORTS
#include "SiUSBXp.h"

#undef SI_USB_XP_API
#define SI_USB_XP_API __declspec(dllexport)

SI_USB_XP_API
SI_STATUS WINAPI proxySI_GetNumDevices(
	LPDWORD lpdwNumDevices
	)
{
  SI_STATUS err = SI_GetNumDevices(lpdwNumDevices);
  fprintf(file, "0x%X = GetNumDevices(NumDevices=>0x%X)\n", err, *lpdwNumDevices);
  return err;
}

SI_USB_XP_API
SI_STATUS WINAPI proxySI_GetProductString(
	DWORD dwDeviceNum,
	LPVOID lpvDeviceString,
	DWORD dwFlags
	)
{
  SI_STATUS err = SI_GetProductString(dwDeviceNum, lpvDeviceString, dwFlags);
  fprintf(file, "0x%X = SI_GetProductString(Device#=0x%X, &DeviceString, Flags=0x%X\n", err, dwDeviceNum, dwFlags);
  hexdump(lpvDeviceString, SI_MAX_DEVICE_STRLEN);
  return err;
}

SI_USB_XP_API
SI_STATUS WINAPI proxySI_Open(
	DWORD dwDevice,
	HANDLE* cyHandle
	) 
{
  SI_STATUS err = SI_Open(dwDevice, cyHandle);
  fprintf(file, "0x%X = SI_Open(dwDevice=0x%X, cyHandle=>0x%X)\n", err, dwDevice, *cyHandle);
  return err;
}

SI_USB_XP_API
SI_STATUS WINAPI proxySI_Close(
	HANDLE cyHandle
	)
{
  SI_STATUS err = SI_Close(cyHandle);
  fprintf(file, "0x%X = SI_Close(cyHandle=0x%X)\n", err, cyHandle);
  return err;
}

SI_USB_XP_API
SI_STATUS WINAPI proxySI_Read(
	HANDLE cyHandle,
	LPVOID lpBuffer,
	DWORD dwBytesToRead,
	LPDWORD lpdwBytesReturned,
	OVERLAPPED* o
	)
{
  SI_STATUS err = SI_Read(cyHandle, lpBuffer, dwBytesToRead, lpdwBytesReturned, o);
  fprintf(file, "0x%X = SI_Read(cyHandle=0x%X, lpBuffer, dwBytesToRead=0x%X, lpdwBytesReturned=>0x%X, o=0x%X)\n", err, cyHandle, dwBytesToRead, *lpdwBytesReturned, o);
  hexdump(lpBuffer, *lpdwBytesReturned);
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_Write(
	HANDLE cyHandle,
	LPVOID lpBuffer,
	DWORD dwBytesToWrite,
	LPDWORD lpdwBytesWritten,
	OVERLAPPED* o
	)
{
  SI_STATUS err = SI_Write(cyHandle, lpBuffer, dwBytesToWrite, lpdwBytesWritten, o);
  fprintf(file, "0x%X = SI_Write(cyHandle=0x%X, lpBuffer, dwBytesToWrite=0x%X, lpdwBytesWritten=0x%X, o=0x%X)\n", err, cyHandle, dwBytesToWrite, *lpdwBytesWritten, o);
  hexdump(lpBuffer, dwBytesToWrite);
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_DeviceIOControl(
	HANDLE cyHandle,
	DWORD dwIoControlCode,
	LPVOID lpInBuffer,
	DWORD dwBytesToRead,
	LPVOID lpOutBuffer,
	DWORD dwBytesToWrite,
	LPDWORD lpdwBytesSucceeded
	)
{
  SI_STATUS err = SI_DeviceIOControl(cyHandle, dwIoControlCode, lpInBuffer, dwBytesToRead, lpOutBuffer, dwBytesToWrite, lpdwBytesSucceeded);
  fprintf(file, "SI_DeviceIOControl(cyHandle, dwIoControlCode, lpInBuffer, dwBytesToRead, lpOutBuffer, dwBytesToWrite, lpdwBytesSucceeded)\n");
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_FlushBuffers(
	HANDLE cyHandle, 
	BYTE FlushTransmit,
	BYTE FlushReceive
	)
{
  SI_STATUS err = SI_FlushBuffers(cyHandle, FlushTransmit, FlushReceive);
  fprintf(file, "0x%X = SI_FlushBuffers(cyHandle=0x%X, FlushTransmit=0x%X, FlushReceive=0x%X)\n", err, cyHandle, FlushTransmit, FlushReceive);
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_SetTimeouts(
	DWORD dwReadTimeout,
	DWORD dwWriteTimeout
	)
{
  SI_STATUS err = SI_SetTimeouts(dwReadTimeout, dwWriteTimeout);
  fprintf(file, "0x%X = SI_SetTimeouts(dwReadTimeout=0x%X, dwWriteTimeout=0x%X)\n", err, dwReadTimeout, dwWriteTimeout);
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_GetTimeouts(
	LPDWORD lpdwReadTimeout,
	LPDWORD lpdwWriteTimeout
	)
{
  SI_STATUS err = SI_GetTimeouts(lpdwReadTimeout, lpdwWriteTimeout);
  fprintf(file, "SI_GetTimeouts(lpdwReadTimeout, lpdwWriteTimeout)\n");
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_CheckRXQueue(
	HANDLE cyHandle,
	LPDWORD lpdwNumBytesInQueue,
	LPDWORD lpdwQueueStatus
	)
{
  SI_STATUS err = SI_CheckRXQueue(cyHandle, lpdwNumBytesInQueue, lpdwQueueStatus);
  fprintf(file, "SI_CheckRXQueue(cyHandle, lpdwNumBytesInQueue, lpdwQueueStatus)\n");
  return err;
}

SI_USB_XP_API
SI_STATUS	WINAPI proxySI_SetBaudRate(
	HANDLE cyHandle,
	DWORD dwBaudRate
	)
{
  SI_STATUS err = SI_SetBaudRate(cyHandle, dwBaudRate);
  fprintf(file, "0x%X = SI_SetBaudRate(cyHandle=0x%X, dwBaudRate=%d)\n", err, cyHandle, dwBaudRate);
  return err;
}

SI_USB_XP_API
SI_STATUS	WINAPI proxySI_SetBaudDivisor(
	HANDLE cyHandle,
	WORD wBaudDivisor
	)
{
  SI_STATUS err = SI_SetBaudDivisor(cyHandle, wBaudDivisor);
  fprintf(file, "SI_SetBaudDivisor(cyHandle, wBaudDivisor)\n");
  return err;
}

SI_USB_XP_API
SI_STATUS	WINAPI proxySI_SetLineControl(
	HANDLE cyHandle, 
	WORD wLineControl
	)
{
  SI_STATUS err = SI_SetLineControl(cyHandle, wLineControl);
  fprintf(file, "SI_SetLineControl(cyHandle, wLineControl)\n");
  return err;
}

SI_USB_XP_API
SI_STATUS	WINAPI proxySI_SetFlowControl(
	HANDLE cyHandle, 
	BYTE bCTS_MaskCode, 
	BYTE bRTS_MaskCode, 
	BYTE bDTR_MaskCode, 
	BYTE bDSR_MaskCode, 
	BYTE bDCD_MaskCode, 
	BOOL bFlowXonXoff
	)
{
  SI_STATUS err = SI_SetFlowControl(cyHandle, bCTS_MaskCode, bRTS_MaskCode, bDTR_MaskCode, bDSR_MaskCode, bDCD_MaskCode, bFlowXonXoff);
  fprintf(file, "SI_SetFlowControl(cyHandle, bCTS_MaskCode, bRTS_MaskCode, bDTR_MaskCode, bDSR_MaskCode, bDCD_MaskCode, bFlowXonXoff)\n");
  return err;
}

SI_USB_XP_API
SI_STATUS WINAPI proxySI_GetModemStatus(
	HANDLE cyHandle, 
	PBYTE ModemStatus
	)
{
  SI_STATUS err = SI_GetModemStatus(cyHandle, ModemStatus);
  fprintf(file, "SI_GetModemStatus\n");
  return err;
}

SI_USB_XP_API
SI_STATUS WINAPI proxySI_SetBreak(
	HANDLE cyHandle, 
	WORD wBreakState
	)
{
  SI_STATUS err = SI_SetBreak(cyHandle, wBreakState);
  fprintf(file, "SI_SetBreak\n");
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_ReadLatch(
	HANDLE cyHandle,
	LPBYTE	lpbLatch
	)
{
  SI_STATUS err = SI_ReadLatch(cyHandle, lpbLatch);
  fprintf(file, "SI_ReadLatch(cyHandle, lpbLatch)\n");
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_WriteLatch(
	HANDLE cyHandle,
	BYTE	bMask,
	BYTE	bLatch
	)
{
  SI_STATUS err = SI_WriteLatch(cyHandle, bMask, bLatch);
  fprintf(file, "SI_WriteLatch(cyHandle, bMask, bLatch)\n");
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_GetPartNumber(
	HANDLE cyHandle,
	LPBYTE	lpbPartNum
	)
{
  SI_STATUS err = SI_GetPartNumber(cyHandle, lpbPartNum);
  fprintf(file, "SI_GetPartNumber(cyHandle, lpbPartNum)\n");
  return err;
}

/*
SI_USB_XP_API
SI_STATUS WINAPI proxySI_GetDeviceProductString(	
	HANDLE	cyHandle,
	LPVOID	lpProduct,
	LPBYTE	lpbLength,
	BOOL	bConvertToASCII
	)
{
  SI_STATUS err = SI_GetDeviceProductString(cyHandle, lpProduct, lpbLength, bConvertToASCII);
  fprintf(file, "0x%X = SI_GetDeviceProductString(cyHandle=0x%X, &Product, &Length=0x%X, bConvertToASCII=%d)\n", err, cyHandle, lpbLength, bConvertToASCII);
  fprintf(file, "lpProduct:\n");
  hexdump(lpProduct, *lpbLength);
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_GetDLLVersion(
	DWORD* HighVersion,
	DWORD* LowVersion
	)
{
  SI_STATUS err = SI_GetDLLVersion(HighVersion, LowVersion);
  fprintf(file, "0x%X = SI_GetDLLVersion(&HighVersion, &LowVersion)\n", err);
  fprintf(file, "HighVersion = %lX, LowVersion = %lX\n", *HighVersion, *LowVersion);
  return err;
}

SI_USB_XP_API 
SI_STATUS WINAPI proxySI_GetDriverVersion(
	DWORD* HighVersion,
	DWORD* LowVersion
	)
{
  SI_STATUS err = SI_GetDriverVersion(HighVersion, LowVersion);
  fprintf(file, "0x%X = SI_GetDriverVersion(&HighVersion, &LowVersion)\n", err);
  fprintf(file, "HighVersion = %lX, LowVersion = %lX\n", *HighVersion, *LowVersion);
  return err;
}
*/
