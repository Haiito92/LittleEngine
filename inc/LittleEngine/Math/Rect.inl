// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

namespace Le
{
    template <Arithmetic T>
    constexpr Rect<T>::Rect():
    position(),
    size()
    {
    }

    template <Arithmetic T>
    constexpr Rect<T>::Rect(const Vector2<T>& position, const Vector2<T>& size):
    position(position),
    size(size)
    {
    }

    template <Arithmetic T>
    constexpr Rect<T>::Rect(T x, T y, T width, T height):
    position(x, y),
    size(width, height)
    {
        
    }
}
