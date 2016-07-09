// src\HyperEditHash.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "HyperEditHash.h"
#include "Global.h"

// CHyperEditHash

IMPLEMENT_DYNAMIC(CHyperEditHash, CHyperEditHash_BASE_CLASS)

CHyperEditHash::CHyperEditHash()
{
	COLORREF crBlack = RGB(0, 0, 0);
	SetHyperlinkColors(crBlack, crBlack);
}

CHyperEditHash::~CHyperEditHash()
{
}


BEGIN_MESSAGE_MAP(CHyperEditHash, CHyperEditHash_BASE_CLASS)
END_MESSAGE_MAP()



// CHyperEditHash ��Ϣ�������
BOOL CHyperEditHash::PreTranslateMessage(MSG* pMsg)
{  
    // �༭���ݼ�����  
    if(WM_KEYDOWN == pMsg->message)   
    {
		if(::GetFocus() == GetSafeHwnd() && (GetKeyState( VK_CONTROL) & 0xFF00 ) == 0xFF00)   
        {
            // ȫѡ
            if( pMsg->wParam == 'A' || pMsg->wParam == 'a')  
            {
                this->SetSel(0, -1);
                return true;
            }

            // ����
            if( pMsg->wParam == 'C' || pMsg->wParam == 'c')  
            {
                this->Copy();
                return true;
			}

            // ����
            if( pMsg->wParam == 'X' || pMsg->wParam == 'x')  
            {
                this->Cut();
                return true;
			}

            // ճ��
            if( pMsg->wParam == 'V' || pMsg->wParam == 'v')  
            {
                this->Paste();
                return true;
            }

            // ����
            if( pMsg->wParam == 'Z' || pMsg->wParam == 'z')  
            {
                this->Undo();
                return true;
            }

        }  
    }  

    return CHyperEditHash_BASE_CLASS::PreTranslateMessage(pMsg);  
 }  

HINSTANCE CHyperEditHash::OpenHyperlink(const CString& hyperlink, CPoint point)
{
	if (hyperlink.IsEmpty())
		return 0;

	ClientToScreen(&point);

	m_cstrLastHyperlink = hyperlink;
	m_cpLastScreenPoint = point;
	
	CWnd *parentWnd = GetParent();
	if (parentWnd != NULL)
	{
		::PostMessage(parentWnd->GetSafeHwnd(), WM_CUSTOM_MSG, WM_HYPEREDIT_MENU, 0);
	}

	return 0;
}

