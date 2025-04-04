#pragma once
#include "Utils/Macro.hpp" 

#include <string>
#include <vector> // Added for vector usage

namespace Satori::Listener {

/**
 * @brief Checks if an event with the given name and content should be filtered based on Satori's regex rules.
 * @param eventName The name of the event type (e.g., "PlayerChat").
 * @param content The string representation of the event data (usually JSON).
 * @return True if the event content matches a filter rule and should be ignored, false otherwise.
 */
STAPI bool shouldFilterEvent(const std::string& eventName, const std::string& content);

/// @brief Information about a single regex filter rule.
struct RegexFilterRuleInfo {
    std::string pattern;        ///< The original regex pattern string.
    std::string description;    ///< User-provided description of the rule.
    std::vector<std::string> applyToEvents; ///< List of event names this rule applies to (empty means global).
};

/**
 * @brief Retrieves the currently loaded regex filter rules.
 * @return A vector containing information about each loaded regex filter rule.
 */
STAPI std::vector<RegexFilterRuleInfo> getRegexFilterRules();

} // namespace Satori::Listener
