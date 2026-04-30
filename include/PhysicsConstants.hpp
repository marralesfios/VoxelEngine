#pragma once

#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

struct PhysicsConstants {
    float gravity               = 21.0f;
    float jumpSpeed             =  7.0f;
    float moveSpeed             =  4.5f;
    float crouchSlowdown        =  2.0f;
    float proneSlowdown         =  4.0f;
    float airResistance         =  8.0f;
    float acceleration          = 30.0f;
    float groundFriction        = 15.0f;
    float maxVelocity           =  6.0f;
    float fallingBlockFallSpeed =  5.0f;

    float standHeight       = 1.50f;
    float standEyeFromFeet  = 1.35f;
    float crouchHeight      = 1.25f;
    float crouchEyeFromFeet = 1.15f;
    float crawlHeight       = 0.80f;
    float crawlEyeFromFeet  = 0.70f;
};

// Loads key-value pairs from a plain-text file into 'out'.
// Unknown keys are silently ignored. Returns false if the file cannot be opened.
inline bool LoadPhysicsConstants(const std::string& path, PhysicsConstants& out) {
    std::ifstream file(path);
    if (!file.is_open()) {
        return false;
    }

    const std::unordered_map<std::string, float*> fields = {
        {"gravity",                  &out.gravity},
        {"jump_speed",               &out.jumpSpeed},
        {"move_speed",               &out.moveSpeed},
        {"crouch_slowdown",          &out.crouchSlowdown},
        {"prone_slowdown",           &out.proneSlowdown},
        {"air_resistance",           &out.airResistance},
        {"acceleration",             &out.acceleration},
        {"max_velocity",             &out.maxVelocity},
        {"ground_friction",          &out.groundFriction},
        {"falling_block_fall_speed", &out.fallingBlockFallSpeed},
        {"stand_height",             &out.standHeight},
        {"stand_eye_from_feet",      &out.standEyeFromFeet},
        {"crouch_height",            &out.crouchHeight},
        {"crouch_eye_from_feet",     &out.crouchEyeFromFeet},
        {"crawl_height",             &out.crawlHeight},
        {"crawl_eye_from_feet",      &out.crawlEyeFromFeet},
    };

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') { continue; }
        std::istringstream iss(line);
        std::string key;
        float value = 0.0f;
        if (iss >> key >> value) {
            const auto it = fields.find(key);
            if (it != fields.end()) {
                *it->second = value;
            }
        }
    }
    return true;
}
