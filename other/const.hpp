#pragma once

template <class T> static constexpr T inf = numeric_limits<T>::max() / 2;

// 未テスト
// 上から反時計回り
int dx4[] = { 0, -1, 0, 1 };
int dy4[] = { -1, 0, 1, 0 };
int dx8[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy8[] = { -1, -1, 0, 1, 1, 1, 0, -1 };