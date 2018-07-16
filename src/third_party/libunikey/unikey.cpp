// -*- coding:unix; mode:c++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-
/*------------------------------------------------------------------------------
UniKey - Open-source Vietnamese Keyboard
Copyright (C) 1998-2004 Pham Kim Long
Contact:
  longcz@yahoo.com
  http://unikey.sf.net

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
--------------------------------------------------------------------------------*/

#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <iostream>
#include "unikey.h"
#include "ukengine.h"
#include "uxengine.h"
#include "usrkeymap.h"

using namespace std;

//---- exported variables for use in UkEnginge class ----
UkSharedMem *pShMem = 0;

UkEngine MyKbEngine;
UxEngine MyKbEngine2;

int UnikeyCapsLockOn = 0;
int UnikeyShiftPressed = 0;
//----------------------------------------------------

unsigned char UnikeyBuf[1024];
int UnikeyBackspaces;
int UnikeyBufChars;
UkOutputType UnikeyOutput;

//--------------------------------------------
void UnikeySetInputMethod(UkInputMethod im)
{
  if (im == UkTelex || im == UkVni || im == UkSimpleTelex || im == UkSimpleTelex2) {
    pShMem->input.setIM(im);
    MyKbEngine.reset();
  }
  else if(im == UkEnvi) {
    pShMem->input.setIM(im);
    MyKbEngine2.reset();
  }
  else if (im == UkUsrIM && pShMem->usrKeyMapLoaded) {
    //cout << "Switched to user mode\n"; //DEBUG
    pShMem->input.setIM(pShMem->usrKeyMap);
    MyKbEngine.reset();
  }

  //cout << "IM changed to: " << im << endl; //DEBUG
}


//--------------------------------------------
void UnikeySetCapsState(int shiftPressed, int CapsLockOn)
{
  //UnikeyCapsAll = (shiftPressed && !CapsLockOn) || (!shiftPressed && CapsLockOn);
  UnikeyCapsLockOn = CapsLockOn;
  UnikeyShiftPressed = shiftPressed;
}

//--------------------------------------------
int UnikeySetOutputCharset(int charset)
{
    pShMem->charsetId = charset;
    if (pShMem->input.getIM() != UkEnvi)
        MyKbEngine.reset();
    else
        MyKbEngine2.reset();
    return 1;
}

//--------------------------------------------
void UnikeySetOptions(UnikeyOptions *pOpt)
{
  pShMem->options.freeMarking = pOpt->freeMarking;
  pShMem->options.modernStyle = pOpt->modernStyle;
  pShMem->options.macroEnabled = pOpt->macroEnabled;
  pShMem->options.useUnicodeClipboard = pOpt->useUnicodeClipboard;
  pShMem->options.alwaysMacro = pOpt->alwaysMacro;
  pShMem->options.spellCheckEnabled = pOpt->spellCheckEnabled;
  pShMem->options.autoNonVnRestore = pOpt->autoNonVnRestore;
}

//--------------------------------------------
void UnikeyGetOptions(UnikeyOptions *pOpt)
{
  *pOpt = pShMem->options;
}

//--------------------------------------------
void CreateDefaultUnikeyOptions(UnikeyOptions *pOpt)
{
  pOpt->freeMarking = 1;
  pOpt->modernStyle = 0;
  pOpt->macroEnabled = 0;
  pOpt->useUnicodeClipboard = 0;
  pOpt->alwaysMacro = 0;
  pOpt->spellCheckEnabled = 1;
  pOpt->autoNonVnRestore = 0;
}

//--------------------------------------------
void UnikeyCheckKbCase(int *pShiftPressed, int *pCapsLockOn)
{
  *pShiftPressed = UnikeyShiftPressed;
  *pCapsLockOn = UnikeyCapsLockOn;
}

//--------------------------------------------
void UnikeySetup()
{
    SetupIsoVnMap();
    pShMem = new UkSharedMem;
    pShMem->input.init();
    pShMem->macStore.init();
    pShMem->vietKey = 1;
    pShMem->usrKeyMapLoaded = 0;
    MyKbEngine.setCtrlInfo(pShMem);
    MyKbEngine.setCheckKbCaseFunc(&UnikeyCheckKbCase);
    MyKbEngine2.setCtrlInfo(pShMem);
    MyKbEngine2.setCheckKbCaseFunc(&UnikeyCheckKbCase);
    UnikeySetInputMethod(UkTelex);
    UnikeySetOutputCharset(CONV_CHARSET_XUTF8);
    pShMem->initialized = 1;
    CreateDefaultUnikeyOptions(&pShMem->options);
}

//--------------------------------------------
void UnikeyCleanup()
{
  delete pShMem;
}

//--------------------------------------------
void UnikeyFilter(unsigned int ch)
{
  UnikeyBufChars = sizeof(UnikeyBuf);
  if (pShMem->input.getIM() != UkEnvi)
    MyKbEngine.process(ch, UnikeyBackspaces, UnikeyBuf, UnikeyBufChars, UnikeyOutput);
  else
    MyKbEngine2.process(ch, UnikeyBackspaces, UnikeyBuf, UnikeyBufChars, UnikeyOutput);
}

//--------------------------------------------
void UnikeyPutChar(unsigned int ch)
{
  if (pShMem->input.getIM() != UkEnvi)
    MyKbEngine.pass(ch);
  else
    MyKbEngine2.pass(ch);
  UnikeyBufChars = 0;
  UnikeyBackspaces = 0;
}

//--------------------------------------------
void UnikeyResetBuf()
{
  if (pShMem->input.getIM() != UkEnvi)
    MyKbEngine.reset();
  else
    MyKbEngine2.reset();
}

//--------------------------------------------
void UnikeySetSingleMode()
{
  if (pShMem->input.getIM() != UkEnvi)
    MyKbEngine.setSingleMode();
  else
    MyKbEngine2.setSingleMode();
}

//--------------------------------------------
void UnikeyBackspacePress()
{
  UnikeyBufChars = sizeof(UnikeyBuf);
  if (pShMem->input.getIM() != UkEnvi)
    MyKbEngine.processBackspace(UnikeyBackspaces, UnikeyBuf, UnikeyBufChars, UnikeyOutput);
  else
    MyKbEngine2.processBackspace(UnikeyBackspaces, UnikeyBuf, UnikeyBufChars, UnikeyOutput);
  //  printf("Backspaces: %d\n",UnikeyBackspaces);
}

//--------------------------------------------
int UnikeyLoadMacroTable(const char *fileName)
{
  return pShMem->macStore.loadFromFile(fileName);
}

//--------------------------------------------
int UnikeyLoadUserKeyMap(const char *fileName)
{
  if (UkLoadKeyMap(fileName, pShMem->usrKeyMap)) {
    //cout << "User key map loaded!\n"; //DEBUG
    pShMem->usrKeyMapLoaded = 1;
    return 1;
  }
  return 0;
}

//--------------------------------------------
void UnikeyRestoreKeyStrokes()
{
    UnikeyBufChars = sizeof(UnikeyBuf);
    if (pShMem->input.getIM() != UkEnvi)
      MyKbEngine.restoreKeyStrokes(UnikeyBackspaces, UnikeyBuf, UnikeyBufChars, UnikeyOutput);
    else
      MyKbEngine2.restoreKeyStrokes(UnikeyBackspaces, UnikeyBuf, UnikeyBufChars, UnikeyOutput);
}

bool UnikeyAtWordBeginning()
{
    return MyKbEngine.atWordBeginning();
}

