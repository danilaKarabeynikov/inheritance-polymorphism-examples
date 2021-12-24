#pragma once
#ifdef LET12_EXPORTS
#define LET12_API __declspec(dllexport)
#else
#define LET12_API __declspec(dllimport)
#endif