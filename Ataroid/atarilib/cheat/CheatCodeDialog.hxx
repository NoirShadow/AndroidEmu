//============================================================================
//
//   SSSS    tt          lll  lll       
//  SS  SS   tt           ll   ll        
//  SS     tttttt  eeee   ll   ll   aaaa 
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2010 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//
// $Id: CheatCodeDialog.hxx 2001 2010-04-10 21:37:23Z stephena $
//
//   Based on code from ScummVM - Scumm Interpreter
//   Copyright (C) 2002-2004 The ScummVM project
//============================================================================

#ifndef CHEAT_CODE_DIALOG_HXX
#define CHEAT_CODE_DIALOG_HXX

class DialogContainer;
class CommandSender;
class ButtonWidget;
class StaticTextWidget;
class CheckListWidget;
class InputTextDialog;
class OptionsDialog;

#include "OSystem.hxx"
#include "Dialog.hxx"
#include "Widget.hxx"
#include "CheatManager.hxx"
#include "EditTextWidget.hxx"
#include "Props.hxx"
#include "bspf.hxx"

class CheatCodeDialog : public Dialog
{
  public:
    CheatCodeDialog(OSystem* osystem, DialogContainer* parent,
                   const GUI::Font& font);
    ~CheatCodeDialog();

  protected:
    virtual void handleCommand(CommandSender* sender, int cmd, int data, int id);
    void loadConfig();
    void saveConfig();

  private:
    void addCheat();
    void editCheat();
    void removeCheat();
    void addOneShotCheat();

  private:
    CheckListWidget* myCheatList;
    InputTextDialog* myCheatInput;

    ButtonWidget* myEditButton;
    ButtonWidget* myRemoveButton;

    enum {
      kAddCheatCmd       = 'CHTa',
      kEditCheatCmd      = 'CHTe',
      kAddOneShotCmd     = 'CHTo',
      kCheatAdded        = 'CHad',
      kCheatEdited       = 'CHed',
      kOneShotCheatAdded = 'CHoa',
      kRemCheatCmd       = 'CHTr'
    };
};

#endif
