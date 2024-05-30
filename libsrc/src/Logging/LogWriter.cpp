#include "Framework/Logging/LogWriter.hpp"

/* STL includes */
#include <string>

/* Libraries includes */

/* Qt includes */

/* Project includes */

namespace Framework {
namespace Logging {

LogWriter::LogWriter() : m_filePath{""}
{
    if (m_fileStream.is_open())
    {
        m_fileStream.close();
    }
}

LogWriter::~LogWriter()
{
    if (m_fileStream.is_open())
    {
        m_fileStream.flush();
        m_fileStream.close();
    }
}

void LogWriter::writeToConsole(const std::string& message)
{
}

void LogWriter::beginWriteToFile(const std::string& filePath)
{
    if (m_filePath != filePath)
    {
        // 1. Close current file stream if it was openned
        endWriteToFile();

        // 2. Open new file stream with new file path
        m_filePath = filePath;
        m_fileStream.open(m_filePath);
    }
}

void LogWriter::writeToFile(const std::string& message)
{
    if (!m_fileStream.is_open())
    {
        return;
    }

    m_fileStream << message << std::endl;
}

void LogWriter::endWriteToFile()
{
    if (m_fileStream.is_open())
    {
        m_fileStream.flush();
        m_fileStream.close();
    }
}

} // namespace Logging
} // namespace Framework
