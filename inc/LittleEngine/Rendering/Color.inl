// Copyright (c) Antoine Hanna (aka Haiito92, https://github.com/Haiito92)

namespace Le
{
    template <Arithmetic T>
    constexpr Color<T>::Color():
    r(T(0)), 
    g(T(0)), 
    b(T(0)), 
    a(T(0))
    {
    }

    template <Arithmetic T>
    constexpr Color<T>::Color(T r, T g, T b, T a):
    r(r), 
    g(g), 
    b(b), 
    a(a)
    {
    }
}
