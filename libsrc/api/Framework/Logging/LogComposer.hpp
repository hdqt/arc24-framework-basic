#pragma once

/* STL includes */

/* Libraries includes */

/* Qt includes */

/* Project includes */
#include "Framework/Logging/ILogComposer.hpp"

namespace Framework {
namespace Logging {

class LogComposer : public ILogComposer
{
public: // functions
    explicit LogComposer() = default;

    ~LogComposer() override = default;

    void composeDebugMessage(const std::string& tag, std::string& message) override;

    void composeInfoMessage(const std::string& tag, std::string& message) override;

    void composeWarningMessage(const std::string& tag, std::string& message) override;

    void composeErrorMessage(const std::string& tag, std::string& message) override;

    void composeFatalMessage(const std::string& tag, std::string& message) override;

private: // functions
    void composeMessage(const std::string& level, const std::string& tag, std::string& message);

    std::string getThreadId() const;

    std::string getCurrentTimestamp() const;
};

} // namespace Logging
} // namespace Framework
