// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

namespace Le
{
    template <Arithmetic T>
    constexpr Vector2<T>::Vector2():
    x(T(0)),
    y(T(0))
    {
        
    }

    template <Arithmetic T>
    constexpr Vector2<T>::Vector2(T x, T y):
    x(x),
    y(y)
    {
        
    }
}
