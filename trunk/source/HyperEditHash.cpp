// src\HyperEditHash.cpp : ʵ���ļ�
//
#include "stdafx.h"

#include "HyperEditHash.h"


// CHyperEditHash

IMPLEMENT_DYNAMIC(CHyperEditHash, CHyperEdit)

CHyperEditHash::CHyperEditHash()
{

}

CHyperEditHash::~CHyperEditHash()
{
}


BEGIN_MESSAGE_MAP(CHyperEditHash, CHyperEdit)
END_MESSAGE_MAP()



// CHyperEditHash ��Ϣ�������
BOOL CHyperEditHash::PreTranslateMessage(MSG* pMsg)
{  
    // �༭���ݼ�����  
    if(WM_KEYDOWN == pMsg->message)   
    {  
        if(::GetFocus() == m_hWnd && (GetKeyState( VK_CONTROL) & 0xFF00 ) == 0xFF00)   
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
      
            // ճ��  
            if( pMsg->wParam == 'Z' || pMsg->wParam == 'z')  
            {  
                this->Undo();  
                return true;  
             }  
      
        }  
    }  
      
    return CHyperEdit::PreTranslateMessage(pMsg);  
 }  

