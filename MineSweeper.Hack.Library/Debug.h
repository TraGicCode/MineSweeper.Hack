#pragma once
#include <atlbase.h>


#define ASSERT ATLASSERT

#ifdef _DEBUG
#define VERIFY(expression) ASSERT(expression)
#else
#define VERIFY (expression) expression
#endif