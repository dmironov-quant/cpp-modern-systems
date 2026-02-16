#pragma once

template <bool Cond, typename T, typename F>
struct if_else;

template <typename T, typename F>
struct if_else<true, T, F> { using type = T; };

template <typename T, typename F>
struct if_else<false, T, F> { using type = F; };

template <bool cond, typename T, typename F>
using if_else_t = if_else<cond, T, F>::type;