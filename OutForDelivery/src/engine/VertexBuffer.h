#pragma once

#include "glad/glad.h"

class VertexBuffer
{
private:
    unsigned int m_RendererID;

public:
    VertexBuffer(const void *data, unsigned int size);
    ~VertexBuffer();

public:
    void bind() const;
    void unbind() const;
};