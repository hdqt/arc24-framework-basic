#pragma once

/* STL includes */
#include <string>

/* Libraries includes */

/* Qt includes */

/* Project includes */

namespace Framework {
namespace Logging {

class ILogComposer
{
public: // functions
    virtual ~ILogComposer() = default;

    virtual void composeDebugMessage(const std::string& tag, std::string& message) = 0;

    virtual void composeInfoMessage(const std::string& tag, std::string& message) = 0;

    virtual void composeWarningMessage(const std::string& tag, std::string& message) = 0;

    virtual void composeErrorMessage(const std::string& tag, std::string& message) = 0;

    virtual void composeFatalMessage(const std::string& tag, std::string& message) = 0;
};

} // namespace Logging
} // namespace Framework
