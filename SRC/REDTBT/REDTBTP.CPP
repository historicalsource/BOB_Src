/*
	 Battle of Britain
	 Copyright (C) 2000, 2001 Empire Interactive (Europe) Ltd,
	 677 High Road, North Finchley, London N12 0DA

	 Please see the document licence.doc for the full licence agreement

2. LICENCE
 2.1 	
 	Subject to the provisions of this Agreement we now grant to you the 
 	following rights in respect of the Source Code:
  2.1.1 
  	the non-exclusive right to Exploit  the Source Code and Executable 
  	Code on any medium; and 
  2.1.2 
  	the non-exclusive right to create and distribute Derivative Works.
 2.2 	
 	Subject to the provisions of this Agreement we now grant you the
	following rights in respect of the Object Code:
  2.2.1 
	the non-exclusive right to Exploit the Object Code on the same
	terms and conditions set out in clause 3, provided that any
	distribution is done so on the terms of this Agreement and is
	accompanied by the Source Code and Executable Code (as
	applicable).

3. GENERAL OBLIGATIONS
 3.1 
 	In consideration of the licence granted in clause 2.1 you now agree:
  3.1.1 
	that when you distribute the Source Code or Executable Code or
	any Derivative Works to Recipients you will also include the
	terms of this Agreement;
  3.1.2 
	that when you make the Source Code, Executable Code or any
	Derivative Works ("Materials") available to download, you will
	ensure that Recipients must accept the terms of this Agreement
	before being allowed to download such Materials;
  3.1.3 
	that by Exploiting the Source Code or Executable Code you may
	not impose any further restrictions on a Recipient's subsequent
	Exploitation of the Source Code or Executable Code other than
	those contained in the terms and conditions of this Agreement;
  3.1.4 
	not (and not to allow any third party) to profit or make any
	charge for the Source Code, or Executable Code, any
	Exploitation of the Source Code or Executable Code, or for any
	Derivative Works;
  3.1.5 
	not to place any restrictions on the operability of the Source 
	Code;
  3.1.6 
	to attach prominent notices to any Derivative Works stating
	that you have changed the Source Code or Executable Code and to
	include the details anddate of such change; and
  3.1.7 
  	not to Exploit the Source Code or Executable Code otherwise than
	as expressly permitted by  this Agreement.

questions about this file may be asked at bob@rowansoftware.com a
better place to ask is http://www.simhq.com/ or even :-
http://www.simhq.com/cgi-bin/boards/cgi-bin/forumdisplay.cgi?action=topics&forum=Battle+of+Britain&number=40&DaysPrune=20&LastLogin=
*/

// REdtBtPpg.cpp : Implementation of the CREdtBtPropPage property page class.

#include "stdafx.h"
#include "REdtBt.h"
#include "REdtBtP.h"
#include "propdial.h"

#ifdef _DEBUG
//#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

ComboTexts Font_Combo_Texts(PROJDIR "\\src\\h\\fontlist.h",50);

IMPLEMENT_DYNCREATE(CREdtBtPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CREdtBtPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CREdtBtPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CREdtBtPropPage, "REDTBT.REdtBtPropPage.1",
	0x461a1fe4, 0xb81b, 0x11d6, 0xa1, 0xf0, 0x44, 0x45, 0x53, 0x54, 0, 0)


/////////////////////////////////////////////////////////////////////////////
// CREdtBtPropPage::CREdtBtPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CREdtBtPropPage

BOOL CREdtBtPropPage::CREdtBtPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_REDTBT_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CREdtBtPropPage::CREdtBtPropPage - Constructor

CREdtBtPropPage::CREdtBtPropPage() :
	COlePropertyPage(IDD, IDS_REDTBT_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CREdtBtPropPage)
	m_FontNum = -1;
	m_Shadow = FALSE;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CREdtBtPropPage::DoDataExchange - Moves data between page and properties

void CREdtBtPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_COMBO1, m_FontCtrl);
	if (!pDX->m_bSaveAndValidate)
	{
		Font_Combo_Texts.SetComboList(&m_FontCtrl);
	}	

	//{{AFX_DATA_MAP(CREdtBtPropPage)
	DDX_Control(pDX, IDC_COMBO1, m_FontCtrl);
	DDP_CBIndex(pDX, IDC_COMBO1, m_FontNum, _T("FontNum") );
	DDX_CBIndex(pDX, IDC_COMBO1, m_FontNum);
	DDP_Check(pDX, IDC_CHECK1, m_Shadow, _T("Shadow") );
	DDX_Check(pDX, IDC_CHECK1, m_Shadow);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CREdtBtPropPage message handlers
