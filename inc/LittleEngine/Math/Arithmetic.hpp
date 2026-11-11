// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

#pragma once

#include <type_traits>

namespace Le
{
    template <typename T>
    concept Arithmetic = std::is_arithmetic_v<T>;
}

