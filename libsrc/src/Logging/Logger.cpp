#include "Framework/Logging/Logger.hpp"

/* STL includes */
#include <atomic>

/* Libraries includes */

/* Qt includes */

/* Project includes */

namespace Framework {
namespace Logging {

std::shared_ptr<Logger> Logger::m_instance;

std::mutex Logger::m_creationMutex;

std::shared_ptr<Logger> Logger::getInstance()
{
    auto instance = std::atomic_load(&m_instance);
    if (instance == nullptr)
    {
        std::lock_guard<std::mutex> lock{m_creationMutex};
        instance = std::atomic_load(&m_instance);

        if (instance == nullptr)
        {
            struct LoggerInstantiateHelper : public Logger
            {
            };

            instance = std::make_shared<LoggerInstantiateHelper>();
        }
    }

    return m_instance;
}

bool Logger::clearInstance()
{
    bool status{false};

    std::lock_guard<std::mutex> lock{m_creationMutex};
    auto instance = std::atomic_load(&m_instance);

    if (instance != nullptr)
    {
        std::atomic_store(&m_instance, std::shared_ptr<Logger>(nullptr));
        status = true;
    }

    return status;
}

} // namespace Logging
} // namespace Framework
