#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <stdint.h>

#include <vector>
#include <list>

#include <atlbase.h>
#include <WinUser.h>
#include <WinDef.h>
#include <WinNT.h>

#include "strhelper.h"

struct ResultData;

typedef std::vector<sunjwbase::tstring> TStrVector;
typedef std::vector<uint64_t> ULLongVector;
typedef std::list<ResultData> ResultList;

#define WM_THREAD_INFO		WM_USER + 1 // �̷߳�����Ϣ
#define WP_WORKING			WM_USER + 2 // ��ʼ����
#define WP_FINISHED			WM_USER + 3 // �߳����
#define WP_STOPPED			WM_USER + 4 // �߳�ֹͣ(δ���)
#define WP_REFRESH_TEXT		WM_USER + 5 // ˢ���ı���
#define WP_PROG				WM_USER + 6 // �ļ�������
#define WP_PROG_WHOLE		WM_USER + 7 // ȫ�ֽ�����

#define MAX_FILES_NUM 8192

struct ResultData // ������
{
	bool bDone; // Done
	sunjwbase::tstring tstrPath; // ·��
	uint64_t ulSize; // ��С
	sunjwbase::tstring tstrMDate; // �޸�����
	sunjwbase::tstring tstrVersion; // �汾
	sunjwbase::tstring tstrMD5; // MD5
	sunjwbase::tstring tstrSHA1; // SHA1
	sunjwbase::tstring tstrSHA256; // SHA256
	sunjwbase::tstring tstrCRC32; // CRC32
	sunjwbase::tstring tstrError; // Error string
};

struct ThreadData // ��������̵߳���Ϣ
{
	bool threadWorking; // �߳��Ƿ��ڹ���

	HWND hWnd; // ������
	bool uppercase; // �Ƿ��д

	uint32_t nFiles; // �ļ�����
	uint64_t totalSize; // �����ļ���С
	bool stop; // ������Ҫ��ֹͣ����

	TStrVector fullPaths; // ������������ļ�·��

	sunjwbase::tstring tstrAll; // ȫ������������Ӧ�ú������resultList ͬ��
	ResultList resultList;
};

#endif
