#pragma once
#include <windows.h>
#include <winternl.h>
 
 
 
#define BINAPI      __stdcall
//读指针  万能T模板 可自己封装  （ 0=普通一 1=CR3解密物理  2=映射物理 3=测试物理 5=页表）
BOOL BINAPI ReadMemory(ULONG64 address, PBYTE Buffer, ULONG size, ULONG moshi);
//写指针  万能T模板 可自己封装  （ 0=普通一 1=CR3解密物理）
BOOL BINAPI WriteMemory(ULONG64 address, PBYTE Buffer, ULONG size, ULONG moshi);
//取模块地址
DWORD64 BINAPI GetModule(const char* Module);
//取模块大小
DWORD64 BINAPI GetModuleSize(const char* Module);
//是否安装
BOOL BINAPI IsInstall();
//取通讯句柄
HANDLE BINAPI GetHANDLE();
//卡号安装驱动
BOOL BINAPI Loaddriver1(const char* key);
//账号安装驱动
BOOL BINAPI Loaddriver2(const char* key, const char* mima);
//申请内存
DWORD64 BINAPI AllocateMemory(ULONG size, DWORD64 addr, BOOL gw);
//释放内存
void BINAPI FreeMemory(DWORD64 Address);
//窗口防止截图
BOOL BINAPI window_hide(DWORD64 window);
//取主模块地址
DWORD64 BINAPI GetModuleAddress();
//设置进程
BOOL BINAPI ESetProcess(ULONG pid);
//键盘按下
void BINAPI EKeyDown(USHORT VirtualKey);
//键盘弹起
void BINAPI EKeyUp(USHORT VirtualKey);
//鼠标侧键1按下
void BINAPI EMouseXButton1Down();
//鼠标侧键1弹起
void BINAPI EMouseXButton1Up();
//鼠标侧键2按下
void BINAPI EMouseXButton2Down();
//鼠标侧键2弹起
void BINAPI EMouseXButton2Up();
//鼠标左键按下
void BINAPI EMouseLeftButtonDown();
//鼠标左键弹起
void BINAPI EMouseLeftButtonUp();
//鼠标右键按下
void BINAPI EMouseRightButtonDown();
//鼠标右键弹起
void BINAPI EMouseRightButtonUp();
//鼠标中键按下
void BINAPI EMouseMiddleButtonDown();
//鼠标中键弹起
void BINAPI EMouseMiddleButtonUp();
//鼠标相对移动
void BINAPI EMouseMoveRELATIVE(LONG dx, LONG dy);
//鼠标绝对移动
void BINAPI EMouseMoveABSOLUTE(LONG dx, LONG dy);
// 向上滚动垂直滚轮
void BINAPI EScrollVerticalUp(USHORT units);
// 向下滚动垂直滚轮
void BINAPI EScrollVerticalDown(USHORT units);
