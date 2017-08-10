#pragma once
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include "Debug.h"

#define SAFE_FREE_PTR(ptr)\
if(ptr)\
{\
    free(ptr);\
    ptr = nullptr;\
}

#define SAFE_DELETE_PTR(ptr)\
if(ptr)\
{\
    delete ptr;\
    ptr = nullptr;\
}