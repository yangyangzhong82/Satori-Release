#pragma once
#include "Utils/Macro.hpp" 

#include <string>

namespace Satori::Listener {

/**
 * @brief Checks if an event with the given name and content should be filtered based on Satori's regex rules.
 * @param eventName The name of the event type (e.g., "PlayerChat").
 * @param content The string representation of the event data (usually JSON).
 * @return True if the event content matches a filter rule and should be ignored, false otherwise.
 */
STAPI bool shouldFilterEvent(const std::string& eventName, const std::string& content);

} // namespace Satori::Listener
