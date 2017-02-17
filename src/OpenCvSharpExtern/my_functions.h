// Additional functions

#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_

#include <opencv2/opencv.hpp>


#ifdef _WIN32
#include <Windows.h>
static int p(const char *msg, const char caption[] = "MessageBox")
{
    return MessageBoxA(NULL, msg, caption, MB_OK);
}

template <typename T>
static int p(T obj, const std::string &caption = "MessageBox")
{
    std::stringstream ss;
    ss << obj;
    return p(ss.str().c_str(), caption.c_str());
}
#undef min
#undef max
#endif


static inline cv::_InputArray entity(cv::_InputArray *obj)
{
    if (obj != NULL) 
        return *obj;
    return cv::noArray();
}
static inline cv::_OutputArray entity(cv::_OutputArray *obj)
{
    if (obj != NULL)
      return *obj;
    return cv::noArray();
}
static inline cv::Mat entity(cv::Mat *obj)
{
    if (obj != NULL)
      return *obj;
    return cv::Mat();
}
static inline cv::SparseMat entity(cv::SparseMat *obj)
{
	if (obj != NULL)
		return *obj;
	return cv::SparseMat();
}
static inline cv::gpu::GpuMat entity(cv::gpu::GpuMat *obj)
{
    if (obj != NULL) 
      return *obj;
    return cv::gpu::GpuMat();
}
static inline cv::gpu::Stream entity(cv::gpu::Stream *obj)
{
    if (obj != NULL) 
      return *obj;
    return cv::gpu::Stream::Null();
}

template <typename T>
static inline cv::Ptr<T> *clone(const cv::Ptr<T> &ptr)
{
    return new cv::Ptr<T>(ptr);
}

static inline void copyString(const std::string &src, char *dst, int dstLength)
{
    if (src.empty())
        std::strncpy(dst, "", dstLength - 1);
    else
        std::strncpy(dst, src.c_str(), dstLength - 1);
}

template <typename T>
static void dump(T *obj, const std::string &outFile)
{
    int size = sizeof(T);
    std::vector<uchar> bytes(size);
    std::memcpy(&bytes[0], (uchar*)obj, size);

    FILE *fp = fopen(outFile.c_str(), "w");
    for (std::vector<uchar>::iterator it = bytes.begin(); it != bytes.end(); it++)
    {
        std::fprintf(fp, "%x,", (int)*it);
    }
    fclose(fp);
}

static void toVec(
    cv::Mat **inPtr, int size, std::vector<cv::Mat> &outVec)
{
    outVec.resize(size);
    for (int i = 0; i < size; i++)
    {
        outVec[i] = *inPtr[i];
    }
}

template <typename TIn, typename TOut>
static void toVec(
    TIn **inPtr, int size1, const int *size2, std::vector<std::vector<TOut> > &outVec)
{
    outVec.resize(size1);
    for (int i = 0; i < size1; i++)
    {
        int size = size2[i];
		TIn *p = inPtr[i];
		std::vector<TOut> v(p, p + size);
        /*std::vector<cv::Rect> v(size);
        for (int j = 0; j < size; j++)
        {
            v[j] = inPtr[i][j];
        }*/
        outVec[i] = v;
    }
}

#endif
