#include "vmtranslator.h"
#include "string.h"
#include <unordered_map>
#include <assert.h>
#include <string>
#include <sstream>
#include "filereader.h"
#include "dirent.h"

using namespace std;

namespace hack
{
  VMType vm_type(const char* line)
  {
    return VM_ARITHMETIC;
  }

  void vm_parse(const char* line, VMCommand* vmcmd)
  {
  }

  VMTranslator::VMTranslator() : mIdx(0), mSysInit(false) 
  {
  }

  VMTranslator::~VMTranslator() 
  {
  }

  bool VMTranslator::translate(const char* filename_or_dirname)
  {
    mInstructions.clear();

    const char* ext = strstr(filename_or_dirname, ".vm");
    if (ext) // try to load as file
    {
      writeInit();
      return translateFile(filename_or_dirname);
    }
    else // try to load as directory
    {
      DIR *dir = opendir(filename_or_dirname);
      if (!dir) 
      {
        printf("Could not open %s\n", filename_or_dirname);
        return false;
      }

      mSysInit = true;
      writeInit();
      char filename[1024];
      struct dirent *entry;
      while ((entry = readdir(dir)) != NULL) 
      {
        if (!strstr(entry->d_name, ".vm")) continue;
        snprintf(filename, 1024, "%s/%s", filename_or_dirname, entry->d_name);
        translateFile(filename);
      }
      closedir(dir);
    }
    return true;
  }

  bool VMTranslator::translateFile(const char* filename)
  {
    assert(strstr(filename, ".vm"));
    return false;
  }

  bool VMTranslator::write(const char* filename)
  {
    return false;
  }
    
  const std::vector<std::string>& VMTranslator::instructions() const
  {
    return mInstructions;
  }

  void VMTranslator::setFileName(const char* filename)
  {
  }

  void VMTranslator::writeInit()
  {
  }

  void VMTranslator::writeLabel(const VMCommand* cmd)
  {
  }

  void VMTranslator::writeGoto(const VMCommand* cmd)
  {
  }

  void VMTranslator::writeIf(const VMCommand* cmd)
  {
  }

  void VMTranslator::writeCall(const VMCommand* cmd)
  {
  }

  void VMTranslator::writeFunction(const VMCommand* cmd)
  {
  }
  
  void VMTranslator::writeReturn()
  {
  }

  void VMTranslator::writeArithmetic(const VMCommand* cmd)
  {
  }
  
  void VMTranslator::writePushPop(const VMCommand* cmd)
  {
  }
}
