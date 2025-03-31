#pragma once

#include "Utils/Macro.hpp" // For STAPI
#include <nlohmann/json.hpp>
#include <string>

namespace Satori::SDK {

/**
 * @brief Records a player-related event via Satori.
 * @param eventType Event classification identifier.
 * @param playerUUID Unique player identifier.
 * @param dimension Game dimension name.
 * @param x X coordinate (default: 0).
 * @param y Y coordinate (default: 0).
 * @param z Z coordinate (default: 0).
 * @param target Related entity name (default: empty).
 * @param additionalData JSON payload (default: empty).
 * @note This function forwards the call to the Satori plugin's internal logging mechanism.
 */
STAPI void recordPlayerEvent(
    const std::string&    eventType,
    const std::string&    playerUUID,
    const std::string&    dimension,
    double                x              = 0,
    double                y              = 0,
    double                z              = 0,
    const std::string&    target         = "",
    const nlohmann::json& additionalData = {}
);

/**
 * @brief Records a server-level event via Satori.
 * @param eventType Event classification identifier.
 * @param additionalData JSON payload (default: empty string).
 * @note This function forwards the call to the Satori plugin's internal logging mechanism.
 */
STAPI void recordServerEvent(const std::string& eventType, const nlohmann::json& additionalData = "");

/**
 * @brief Records a world-related event via Satori.
 * @param eventType Event classification identifier.
 * @param trigger Entity/mechanism that initiated the event (default: empty).
 * @param dimension Game dimension name (default: empty).
 * @param x X coordinate (default: 0).
 * @param y Y coordinate (default: 0).
 * @param z Z coordinate (default: 0).
 * @param additionalData JSON payload (default: empty).
 * @note This function forwards the call to the Satori plugin's internal logging mechanism.
 */
STAPI void recordWorldEvent(
    const std::string&    eventType,
    const std::string&    trigger        = "",
    const std::string&    dimension      = "",
    double                x              = 0,
    double                y              = 0,
    double                z              = 0,
    const nlohmann::json& additionalData = {}
);

} // namespace Satori::SDK
