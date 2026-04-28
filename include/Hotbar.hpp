#pragma once

#include <array>
#include <cstdint>
#include <string>

#include <SDL3/SDL_opengl.h>

#include "BlockRegistry.hpp"
#include "CubeMesh.hpp"
#include "Shader.hpp"

class Hotbar {
public:
    static constexpr int kSlotCount = 9;

    Hotbar() = default;
    ~Hotbar();

    Hotbar(const Hotbar&) = delete;
    Hotbar& operator=(const Hotbar&) = delete;

    bool Initialize(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);

    void SetSlot(int slot, uint32_t blockID);
    void ClearSlot(int slot);
    bool SlotHasBlock(int slot) const;

    void SelectSlot(int slot);
    void SelectNext();
    void SelectPrev();
    int SelectedSlot() const { return selectedSlot_; }

    uint32_t CurrentBlockID() const;

    void Draw(const BlockRegistry& registry, int viewportW, int viewportH) const;

private:
    struct Slot {
        bool hasBlock = false;
        uint32_t blockID = 0;
    };

    bool LoadGLFunctions();

    std::array<Slot, kSlotCount> slots_{};
    int selectedSlot_ = 0;

    Shader shader_;
    GLuint vao_ = 0;
    GLuint vbo_ = 0;
};
