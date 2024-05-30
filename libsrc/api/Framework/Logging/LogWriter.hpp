#pragma once

/* STL includes */
#include <fstream>

/* Libraries includes */

/* Qt includes */

/* Project includes */
#include "Framework/Logging/ILogWriter.hpp"

namespace Framework {
namespace Logging {

class LogWriter : public ILogWriter
{
public: // functions
    explicit LogWriter();

    ~LogWriter() override;

    // Copying LogWriter is forbidden because it holds the log file handle resource
    LogWriter(const LogWriter&) = delete;
    LogWriter& operator=(const LogWriter&) = delete;

    void writeToConsole(const std::string& message) override;

    void beginWriteToFile(const std::string& filePath) override;

    void writeToFile(const std::string& message) override;

    void endWriteToFile() override;

private:
    std::ofstream m_fileStream;
    std::string m_filePath;
};

} // namespace Logging
} // namespace Framework
