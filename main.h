#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm> 
#include <windows.h>


using namespace std;

#include "HTML.h"
#include "userInfo.h"


/*Function prototypes*/
void reportInfo();
void reportOne(vector <userInfo> s, int fileSize, vector <string> headers);
void reportTwo(vector <userInfo> s, int fileSize, vector <string> headers);
void reportThree(vector <userInfo> s, int fileSize, vector <string> headers);



