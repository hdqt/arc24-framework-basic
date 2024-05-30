#include "Framework/Logging/LogComposer.hpp"

/* STL includes */
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>

/* Libraries includes */

/* Qt includes */

/* Project includes */

namespace Framework {
namespace Logging {

void LogComposer::composeDebugMessage(const std::string& tag, std::string& message)
{
    composeMessage("DEBUG", tag, message);
}

void LogComposer::composeInfoMessage(const std::string& tag, std::string& message)
{
    composeMessage("INFO", tag, message);
}

void LogComposer::composeWarningMessage(const std::string& tag, std::string& message)
{
    composeMessage("WARN", tag, message);
}

void LogComposer::composeErrorMessage(const std::string& tag, std::string& message)
{
    composeMessage("ERROR", tag, message);
}

void LogComposer::composeFatalMessage(const std::string& tag, std::string& message)
{
    composeMessage("FATAL", tag, message);
}

void LogComposer::composeMessage(const std::string& level, const std::string& tag, std::string& message)
{
    std::ostringstream oss;
    oss << getThreadId() << " | " << getCurrentTimestamp() << " | " << level << " | " << tag << " | " << message;
    message = oss.str();
}

std::string LogComposer::getThreadId() const
{
    std::ostringstream oss;
    oss << "0x" << std::setw(8) << std::setfill('0') << std::hex << std::this_thread::get_id();
    return oss.str();
}

std::string LogComposer::getCurrentTimestamp() const
{
    std::time_t now = std::time(0);
    std::tm tm;
#if defined(MACH_WINDOWS)
    ::localtime_s(&tm, &now);
#else
    ::localtime_r(&now, &tm);
#endif

    char timestamp[std::size("yyyy-mm-dd hh:mm:ss")];
    std::strftime(std::data(timestamp), std::size(timestamp), "%F %T", &tm);

    return std::string(timestamp);
}

} // namespace Logging
} // namespace Framework
