#pragma once
#include "Utils/Macro.hpp" 

#include <nlohmann/json.hpp> 

#include <string>


namespace Satori {
namespace Database {

/**
 * @brief Records a player-related event
 * @param eventType Event classification identifier
 * @param playerUUID Unique player identifier
 * @param dimension Game dimension name
 * @param x X coordinate (default: 0)
 * @param y Y coordinate (default: 0)
 * @param z Z coordinate (default: 0)
 * @param target Related entity name (default: empty)
 * @param additionalData JSON payload (default: empty)
 * @note Coordinates are stored with 2 decimal places precision
 */
STAPI void insertPlayerEvent(
    const std::string&    eventType,
    const std::string&    playerUUID,
    const std::string&    dimension,
    double                x              = 0,
    double                y              = 0,
    double                z                   = 0,
    const std::string&    target              = "",
    const std::string&    additionalDataStr = "{}" // Changed from nlohmann::json
);

/**
 * @brief Records a server-level event
 * @param eventType Event classification identifier
 * @param additionalDataStr JSON string payload (default: empty JSON object string "{}")
 */
STAPI void insertServerEvent(const std::string& eventType, const std::string& additionalDataStr = "{}"); // Changed from nlohmann::json

/**
 * @brief Records a world-related event
 * @param eventType Event classification identifier
 * @param trigger Entity/mechanism that initiated the event (default: empty)
 * @param dimension Game dimension name (default: empty)
 * @param x X coordinate (default: 0)
 * @param y Y coordinate (default: 0)
 * @param z Z coordinate (default: 0)
 * @param additionalData JSON payload (default: empty)
 */
STAPI void insertWorldEvent(
    const std::string&    eventType,
    const std::string&    trigger        = "",
    const std::string&    dimension      = "",
    double                x              = 0,
    double                y                   = 0,
    double                z                   = 0,
    const std::string&    additionalDataStr = "{}" // Changed from nlohmann::json
);


// --- Database Querying ---

/// @brief Structure defining filter criteria for querying events.
/// @details Optional fields that are not set (nullopt) will not be used for filtering.
struct EventFilterCriteria {
    /// @brief Which table to query ("player_event", "server_event", "world_event"). Required.
    std::string table;

    // Common Filters
    std::optional<std::string> eventType;       ///< Filter by specific event type name.
    std::optional<std::string> startTime;       ///< Start time (ISO 8601 format, e.g., "YYYY-MM-DD HH:MM:SS.sss").
    std::optional<std::string> endTime;         ///< End time (ISO 8601 format).
    std::optional<std::string> additionalDataContains; ///< Search for text within the additional_data JSON string.

    // Player Event Filters
    std::optional<std::string> playerUUID;      ///< Filter by player UUID.
    std::optional<std::string> target;          ///< Filter by target entity name.

    // World/Player Event Filters
    std::optional<std::string> dimension;       ///< Filter by dimension name.
    std::optional<double>      x;               ///< Center X coordinate for spatial query.
    std::optional<double>      y;               ///< Center Y coordinate for spatial query.
    std::optional<double>      z;               ///< Center Z coordinate for spatial query.
    std::optional<double>      radius;          ///< Radius for spatial query (requires x, y, z).

    // World Event Filters
    std::optional<std::string> trigger;         ///< Filter by trigger entity/mechanism name.

    // Pagination
    int limit = 100;                            ///< Maximum number of records to return.
    int offset = 0;                             ///< Number of records to skip.
};

/**
 * @brief Queries the Satori database for events based on the provided filter criteria.
 * @param criteria An EventFilterCriteria object specifying the filters.
 * @return A vector of nlohmann::json objects, where each object represents a matching event record (row).
 *         Returns an empty vector if no matches are found or an error occurs.
 * @note Spatial queries (using x, y, z, radius) perform a simple bounding box check for efficiency.
 * @throw May throw exceptions on database errors (implementation specific).
 */
STAPI std::vector<nlohmann::json> queryEvents(const EventFilterCriteria& criteria);


} // namespace Database
} // namespace Satori
