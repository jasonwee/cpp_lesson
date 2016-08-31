/**
* Simple Timer
* ------------
* Copyright (c) 2007-2008, Daniel Cederman and Philippas Tsigas
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following 
* conditions are met:
*
* Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer 
* in the documentation and/or other materials provided with the distribution.
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, 
* BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
* SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
**/


#ifdef _MSC_VER

#include <windows.h>

class SimpleTimer
{
	LARGE_INTEGER starttime;
public:
	void start();
	double end(); 
};

void SimpleTimer::start()
{
	QueryPerformanceCounter(&starttime);
}

double SimpleTimer::end()
{
	LARGE_INTEGER endtime,freq;
	QueryPerformanceCounter(&endtime);
	QueryPerformanceFrequency(&freq);

	return ((double)(endtime.QuadPart-starttime.QuadPart))/((double)(freq.QuadPart/1000.0));
}


#else
#include <sys/time.h>

class SimpleTimer
{
	struct timeval starttime;
public:
	void start();
	double end(); 
};

void SimpleTimer::start()
{
	gettimeofday(&starttime,0);
}

double SimpleTimer::end()
{
	struct timeval endtime;
	gettimeofday(&endtime,0);

	return (endtime.tv_sec - starttime.tv_sec)*1000.0 + (endtime.tv_usec - starttime.tv_usec)/1000.0;
}


#endif
