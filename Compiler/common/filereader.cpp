#include "filereader.h"
#include "utils.h"
#include <stdio.h>
#include <assert.h>

namespace hack 
{
  FileReader::FileReader() : mFp(NULL), mHasMoreLines(false)
  {
  }

  bool FileReader::open(const char* filename, bool stripWhitespace)
  {
    return false;
  }

  FileReader::~FileReader()
  {
  }
  
  void FileReader::advance()
  {
  }

  bool FileReader::hasMoreLines() const
  {
    return mHasMoreLines;
  }

  const char* FileReader::line() const
  {
    return mLine;
  }
}

