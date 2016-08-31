/**
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
**/

#ifndef PQSORTH
#define PQSORTH

#ifdef _MSC_VER
  #ifdef BUILDING_DLL
    #define DLLEXPORT  __declspec(dllexport) 
  #else
    #define DLLEXPORT /*__declspec(dllimport)*/
  #endif
#else
  #ifdef HAVE_GCCVISIBILITYPATCH
    #define DLLEXPORT __attribute__ ((visibility("default")))
  #else
    #define DLLEXPORT
  #endif
#endif 



#define MAXTHREADS 256
#define MAXBLOCKS 2048
//#define SBSIZE 1024


/**
* The main sort function
* @param data		Data to be sorted
* @param size		The length of the data
* @param timerValue Contains the time it took to sort the data [Optional]
* @returns 0 if successful. For non-zero values, use getErrorStr() for more information about why it failed.
*/
extern "C" 
DLLEXPORT int gpuqsort(unsigned int* data, unsigned int size, double* timerValue=0, unsigned int blockscount = 0, unsigned int threads = 0, unsigned int sbsize = 0, unsigned int phase = 0);

// Float support removed due to some problems with CUDA 2.0 and templates
// Will be fixed
//extern "C" 
//DLLEXPORT int gpuqsortf(float* data, unsigned int size, double* timerValue=0);

/**
* Returns the latest error message
* @returns the latest error message
*/
extern "C" DLLEXPORT const char* getGPUSortErrorStr();


template <typename element> struct BlockSize;
template <typename element> struct Params;
template <typename element> struct Length;
struct Hist;
struct LQSortParams;

template <typename element>
class GPUQSort
{
	element* ddata; 
	element* ddata2; 
	struct Params<element>* params;
	struct Params<element>* dparams;

	LQSortParams* lqparams;
	LQSortParams* dlqparams;

	Hist* dhists;
	Length<element>* dlength;
	Length<element>* length;
	BlockSize<element>* workset;

	float TK,TM,MK,MM,SM,SK;

	int err;
	bool init;

	bool errCheck(int e);
public:
	GPUQSort();
	~GPUQSort();

	int sort(element* data, unsigned int size, double* timerValue=0, unsigned int blockscount = 0, unsigned int threads = 0, unsigned int sbsize = 0, unsigned int phase = 0);
	const char* getErrorStr();
};


#endif
