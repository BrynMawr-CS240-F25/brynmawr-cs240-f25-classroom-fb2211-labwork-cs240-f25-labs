#ifndef _vmtranslator_H_
#define _vmtranslator_H_

#include "vmcommand.h"
#include "utils.h"
#include <vector>
#include <string>

namespace hack
{
  VMType vm_type(const char* line);
  void vm_parse(const char* line, VMCommand* vmcmd);

  class VMTranslator
  {
  public:
    VMTranslator();
    virtual ~VMTranslator();
    bool translate(const char* filename_or_dirname); 
    bool write(const char* filename); 
    const std::vector<std::string>& instructions() const;

  private:
    bool translateFile(const char* file);
    void setFileName(const char* filename);
    void writeInit();
    void writeLabel(const VMCommand* cmd);
    void writeGoto(const VMCommand* cmd);
    void writeIf(const VMCommand* cmd);
    void writeCall(const VMCommand* cmd);
    void writeFunction(const VMCommand* cmd);
    void writeReturn();
    void writeArithmetic(const VMCommand* cmd);
    void writePushPop(const VMCommand* cmd);

  private:
    std::vector<std::string> mInstructions;
    char mFilename[MAX_CMD];
    int mIdx;
    bool mSysInit;
  };
};

#endif
