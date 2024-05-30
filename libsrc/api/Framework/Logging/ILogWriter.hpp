#pragma once

/* STL includes */
#include <string>

/* Libraries includes */

/* Qt includes */

/* Project includes */

namespace Framework {
namespace Logging {

class ILogWriter
{
public: // functions
    virtual ~ILogWriter() = default;

    virtual void writeToConsole(const std::string& message) = 0;

    virtual void beginWriteToFile(const std::string& filePath) = 0;

    virtual void writeToFile(const std::string& message) = 0;

    virtual void endWriteToFile() = 0;
};

} // namespace Logging
} // namespace Framework
