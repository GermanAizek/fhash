//
//  main.cpp
//  fHashCmd
//
//  Created by Sun Junwen on 15/5/9.
//  Copyright (c) 2015 Sun Junwen. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <string>

#include "Global.h"
#include "OsThread.h"
#include "strhelper.h"
#include "Functions.h"
#include "HashEngine.h"

using namespace std;
using namespace sunjwbase;

OsMutex g_mainMtx;

int main(int argc, char *argv[])
{
    ThreadData thData;
    
    thData.threadWorking = false;
    thData.stop = false;
    thData.uppercase = false;
    thData.nFiles = 0;
    
    string strPath;
    tstring tstrPath;
    
    strPath = "/Users/sunjw/temp/empty";
    tstrPath = strtotstr(strPath);
    thData.fullPaths.push_back(tstrPath);
    thData.nFiles++;
    
    strPath = "/Users/sunjw/temp/phpfm_文件夹/特色同时有iso/It Ended On An Oily Stage.mp3";
    tstrPath = strtotstr(strPath);
    thData.fullPaths.push_back(tstrPath);
    thData.nFiles++;
    
    pthread_t ptHash;
    pthread_create(&ptHash, NULL,
                   (void *(*)(void *))HashThreadFunc, &thData);
    
    pthread_join(ptHash, NULL);
    
    ResultList::const_iterator resItr;
    for (resItr = thData.resultList.begin();
         resItr != thData.resultList.end();
         ++resItr)
    {
        const ResultData& result = *resItr;
        
        printf("File: %s\n", tstrtostr(result.tstrPath).c_str());
        
        if (result.bDone)
        {
            printf("Size: %llu Bytes%s\n",
                   result.ulSize, ConvertSizeToStr(result.ulSize).c_str());
            printf("Modified Date: %s\n", tstrtostr(result.tstrMDate).c_str());
            printf("MD5: %s\n", tstrtostr(result.tstrMD5).c_str());
            printf("SHA1: %s\n", tstrtostr(result.tstrSHA1).c_str());
            printf("SHA256: %s\n", tstrtostr(result.tstrSHA256).c_str());
            printf("CRC32: %s\n", tstrtostr(result.tstrCRC32).c_str());
        }
        else
        {
            printf("Failed\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
