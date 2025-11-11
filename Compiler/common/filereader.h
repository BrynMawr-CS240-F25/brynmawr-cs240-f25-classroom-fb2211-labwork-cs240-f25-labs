#ifndef _filereader_
#define _filereader_

#include <string>
#define MAX_LINE 1024

namespace hack 
{
  class FileReader 
  {
  public:
    FileReader();
    virtual ~FileReader();

    bool open(const char* filename, bool stripWhitespace = true);
    bool hasMoreLines() const;
    const char* line() const;
    void advance();

  private:
    char mLine[MAX_LINE];
    FILE* mFp;
    bool mHasMoreLines;
  };

}

#endif
