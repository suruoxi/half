// test - Test application for half-precision floating point functionality.
//
// Copyright (c) 2012-2013 Christian Rau <rauy@users.sourceforge.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation 
// files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, 
// modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE 
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <half.hpp>
#include <sys/time.h>

using half_float::half;

int main(int argc, char *argv[])
{
	half a(float(3.1415926)), b(float(-7)), c(float(0.3333333333));
    float aa(half(3.1415926)), bb(half(-7)),cc(half(0.3333333333)); 
	std::cout << a << ", " << b <<", " << c  <<", " <<sizeof(a)<< '\n';
	std::cout << aa << ", " << bb <<", " << cc  <<", " <<sizeof(aa)<< '\n';
	std::cout << a+a << ", " << a+b <<", " << a*b  <<", "<< a*c <<", " <<sizeof(a+a)<< '\n';

    half * half_query = new half[128];
    float * float_query = new float[128];

    const int NUM = 10000000;
    half* half_base = new half[NUM*128];
    float* float_base = new float[NUM*128];

    int i = 0, j = 0;
    struct  timeval t1,t2;
    gettimeofday(&t1,NULL);
    for(i=0; i<NUM; ++i)
    {
        float t=0;
        for(j=0; j<128; ++j)
        {
            t +=  half_query[j] * half_base[i*128 +j];
        }
    }
    gettimeofday(&t2,NULL);
    std::cout<< (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec-t2.tv_usec) << std::endl;
    
    gettimeofday(&t1,NULL);
    for(i=0; i<NUM; ++i)
    {
        float t=0;
        for(j=0; j<128; ++j)
        {
            t +=  float_query[j] * float_base[i*128 +j];
        }
    }
    gettimeofday(&t2,NULL);
    std::cout<< (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec-t2.tv_usec) << std::endl;



}
