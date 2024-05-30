#pragma once

/* STL includes */
#include <memory>
#include <mutex>

/* Libraries includes */

/* Qt includes */

/* Project includes */
#include "Framework/Logging/ILogComposer.hpp"
#include "Framework/Logging/ILogWriter.hpp"

namespace Framework {
namespace Logging {

class Logger
{
public: // functions
    static std::shared_ptr<Logger> getInstance();

    static bool clearInstance();

    void setComposer(std::unique_ptr<ILogComposer> composer);

    void setWriter(std::unique_ptr<ILogWriter> writer);

private: // variables
    static std::mutex m_creationMutex;

    static std::shared_ptr<Logger> m_instance;

    std::mutex m_accessMutex;

    std::unique_ptr<ILogComposer> m_composer;

    std::unique_ptr<ILogWriter> m_writer;
};

} // namespace Logging
} // namespace Framework
